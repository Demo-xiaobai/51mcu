#include <REGX52.H>
#include "Motor.h"
#include "Delay.h"

unsigned char Count,YunTai_Count,speed,YunTai_angle;

//ǰ��
void Go_Ahead(){
	
	q_IN1 = 1;q_IN2 = 0;	q_IN3 = 0;q_IN4 = 1;
	
	h_IN1 = 1;h_IN2 = 0;	h_IN3 = 0;	h_IN4 = 1;
		
}
//����
void Back(){
	q_IN1 = 0;q_IN2 = 1;	q_IN3 = 1;q_IN4 = 0;
	
	h_IN1 = 0;h_IN2 = 1;	h_IN3 = 1;	h_IN4 = 0;
}
//��ת
void Turn_Left(){
	
	q_IN1 = 0;q_IN2 = 0;	
	q_IN3 = 0;q_IN4 = 1;
	
	h_IN1 = 1;h_IN2 = 0;	
	h_IN3 = 0;	h_IN4 = 0;
	
}

//��ת
void Turn_Right(){
	
	q_IN1 = 1;q_IN2 = 0;	q_IN3 = 0;q_IN4 = 0;
	
	h_IN1 = 0;h_IN2 = 0;	h_IN3 = 0;	h_IN4 = 1;
}
// Letf_up
void Letf_up(){
	//��ǰ��  10 ��ת				//��ǰ�� 		01 ��ת
	q_IN1 = 1;q_IN2 = 0;		q_IN3 = 1;q_IN4 = 1;
	//�����  10  ��ת				�Һ���  	10 ��ת
	h_IN3 = 1;	h_IN4 = 1;	h_IN1 = 1;h_IN2 = 0;	
}

void Right_up(){
	//��ǰ��  10 ��ת				//��ǰ�� 		01 ��ת
	q_IN1 = 1;q_IN2 = 1;		q_IN3 = 0;q_IN4 = 1;
	//�����  01  ��ת				�Һ���  	10 ��ת
	h_IN3 = 0;	h_IN4 = 1;	h_IN1 = 1;h_IN2 = 1;
}
void Left_Bottom(){
	//��ǰ��  10 ��ת				//��ǰ�� 		01 ��ת
	q_IN1 = 1;	q_IN2 = 1;		q_IN3 = 1;q_IN4 = 0;
	//�����  01  ��ת				�Һ���  	10 ��ת
	h_IN3 = 1;	h_IN4 = 0;	h_IN1 = 1;h_IN2 = 1;
}
void Right_Bottom(){
	//��ǰ��  10 ��ת				//��ǰ�� 		01 ��ת
	q_IN1 = 0;q_IN2 = 1;		q_IN3 = 1;q_IN4 = 1;
	//�����  10  ��ת				�Һ���  	10 ��ת
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

//תȦ
void Turn_Circle(){
	
	q_IN1 = 1;	q_IN2 = 0;				//1��ǰ��  10 ��ת
	
	q_IN3 = 1;	q_IN4 = 0;				//2�� ǰ��  10 �� ת
	

	h_IN1 = 0;	h_IN2 = 1;				//  �Һ� ��  10 ��ת
		
	h_IN3 = 0;	h_IN4 = 1;			  //4�� �� ��  10 ��ת

}

/*
	20Khz = 20000hz,T = 0.00005s = 0.05ms /100 = 0.0005ms = 0.5us 
*/

/*
	T=10ms = 10000us   100�� * 100us 
	����	200�� * 100us = 20ms

*/
void Timer0_Init_Siqu(){		//100us	�����ж� 
	
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

		Count++;					//����
		YunTai_Count++;		//��̨
	
		if(Count >= 100){
			Count = 0;
		}
		//ǰ�� 
		if(Count < 30){
			q_Letf_PWM =1;
			q_Right_PWM = 1;
		
		}else{		
			q_Letf_PWM = 0;
			q_Right_PWM = 0;
		}
		
		/*
		����
		*/
		if(Count < 29){
			h_Letf_PWM =1;
			h_Right_PWM =1;
		}else{
			h_Letf_PWM = 0;
			h_Right_PWM = 0;
		}
		
		if(YunTai_Count >=200){		//�ﵽ��̨���� ������
			YunTai_Count = 0;
		}
		if(YunTai_Count<YunTai_angle){
			YunTai_PWM = 1;
			
		}else{	
			YunTai_PWM = 0;
		}
}
//������  ת�����
void Turn_Around(unsigned int temp){
	
	if(temp < 20){
				
		Back();
		Delayms(800);
		
		Turn_Left();
		Delayms(800);
		//YunTai_angle+=5;

	}
	else{
		YunTai_angle = 15;			//�������
		Go_Ahead();
	}
	
}


