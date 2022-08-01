#include <REGX52.H>
#include "Motor.h"
#include "Delay.h"

unsigned char Count,YunTai_Count,speed,YunTai_angle;

//前进
void Go_Ahead(){
	
	q_IN1 = 1;q_IN2 = 0;	q_IN3 = 0;q_IN4 = 1;
	
	h_IN1 = 1;h_IN2 = 0;	h_IN3 = 0;	h_IN4 = 1;
		
}
//后退
void Back(){
	q_IN1 = 0;q_IN2 = 1;	q_IN3 = 1;q_IN4 = 0;
	
	h_IN1 = 0;h_IN2 = 1;	h_IN3 = 1;	h_IN4 = 0;
}
//左转
void Turn_Left(){
	
	q_IN1 = 0;q_IN2 = 0;	
	q_IN3 = 0;q_IN4 = 1;
	
	h_IN1 = 1;h_IN2 = 0;	
	h_IN3 = 0;	h_IN4 = 0;
	
}

//右转
void Turn_Right(){
	
	q_IN1 = 1;q_IN2 = 0;	q_IN3 = 0;q_IN4 = 0;
	
	h_IN1 = 0;h_IN2 = 0;	h_IN3 = 0;	h_IN4 = 1;
}
// Letf_up
void Letf_up(){
	//左前轮  10 正转				//右前轮 		01 正转
	q_IN1 = 1;q_IN2 = 0;		q_IN3 = 1;q_IN4 = 1;
	//左后轮  10  正转				右后轮  	10 正转
	h_IN3 = 1;	h_IN4 = 1;	h_IN1 = 1;h_IN2 = 0;	
}

void Right_up(){
	//左前轮  10 正转				//右前轮 		01 正转
	q_IN1 = 1;q_IN2 = 1;		q_IN3 = 0;q_IN4 = 1;
	//左后轮  01  正转				右后轮  	10 正转
	h_IN3 = 0;	h_IN4 = 1;	h_IN1 = 1;h_IN2 = 1;
}
void Left_Bottom(){
	//左前轮  10 正转				//右前轮 		01 正转
	q_IN1 = 1;	q_IN2 = 1;		q_IN3 = 1;q_IN4 = 0;
	//左后轮  01  正转				右后轮  	10 正转
	h_IN3 = 1;	h_IN4 = 0;	h_IN1 = 1;h_IN2 = 1;
}
void Right_Bottom(){
	//左前轮  10 正转				//右前轮 		01 正转
	q_IN1 = 0;q_IN2 = 1;		q_IN3 = 1;q_IN4 = 1;
	//左后轮  10  正转				右后轮  	10 正转
	h_IN3 = 1;	h_IN4 = 1;	h_IN1 = 0;h_IN2 = 1;
}

void Stop(){
	q_IN1 = 1;
	q_IN2 = 1;
	
	q_IN3 = 1;
	q_IN4 = 1;
	
	h_IN1 = 1;
	h_IN2 = 1;
	
	h_IN3 = 1;
	h_IN4 = 1;
}

//转圈
void Turn_Circle(){
	
	q_IN1 = 1;	q_IN2 = 0;				//1左前轮  10 正转
	
	q_IN3 = 1;	q_IN4 = 0;				//2右 前轮  10 反 转
	

	h_IN1 = 0;	h_IN2 = 1;				//  右后 轮  10 正转
		
	h_IN3 = 0;	h_IN4 = 1;			  //4左 后 轮  10 反转

}

/*
	20Khz = 20000hz,T = 0.00005s = 0.05ms /100 = 0.0005ms = 0.5us 
*/

/*
	T=10ms = 10000us   100次 * 100us 
	进入	200次 * 100us = 20ms

*/
void Timer0_Init_Siqu(){		//100us	进入中断 
	
	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	
	TL0 = 0xA4;	
	TH0 = 0xFF;		
	
	TF0 = 0;		
	TR0 = 1;	
	
	
	ET0=1;
	EA =1;
	
	PT0 = 1;
	
}


void Timer0_Rountine() interrupt 1{
	
		TL0 = 0xA4;	
		TH0 = 0xFF;
	
		speed = 27;

		Count++;					//四驱
		YunTai_Count++;		//云台
	
		if(Count >= 100){
			Count = 0;
		}
		//前轮 
		if(Count < 30){
			q_Letf_PWM =1;
			q_Right_PWM = 1;
		
		}else{		
			q_Letf_PWM = 0;
			q_Right_PWM = 0;
		}
		
		/*
		后轮
		*/
		if(Count < 29){
			h_Letf_PWM =1;
			h_Right_PWM =1;
		}else{
			h_Letf_PWM = 0;
			h_Right_PWM = 0;
		}
		
		if(YunTai_Count >=200){		//达到云台周期 就清零
			YunTai_Count = 0;
		}
		if(YunTai_Count<YunTai_angle){
			YunTai_PWM = 1;
			
		}else{	
			YunTai_PWM = 0;
		}
}
//超声波  转向控制
void Turn_Around(unsigned int temp){
	
	if(temp < 20){
				
		Back();
		Delayms(800);
		
		Turn_Left();
		Delayms(800);
		//YunTai_angle+=5;

	}
	else{
		YunTai_angle = 15;			//舵机摆正
		Go_Ahead();
	}
	
}


