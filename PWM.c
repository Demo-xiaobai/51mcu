#include "PWM.h"
#include <REGX52.H>

/*
	舵机和四驱 需要两种 定时器
	T = 20ms = 20000us ,对于舵机的周期是 200次，
*/

/*/工作在计数模式
void Timer0_Siqu_Init(){			//100us 进入一次中断  ，江科大是100us进入一次中断	
	
	TMOD &= 0xF0;
	TMOD |= 0x01;

	//时间 100us, 100us * 100 = 10000us = 10ms	
	TL0 = 0xA4;		
	TH0 = 0xFF;	
	
	TF0 = 0;		
	TR0 = 1;	
	
	ET0=1;
	EA=1;
}*/




//需要给 电机 和 舵机调速 
/*
	Count * 进入中断次数 = 总周期T，Comper 是占空比，电机引脚PWM 


void PWM_DuoJi(unsigned char Count,unsigned char Comper,unsigned int PWM){
	
	Count++;
	if(Count > 40){
		Count = 0;
	}
	if(Count < Comper){
		PWM = 1;
	}
	if(Count > Comper){
		PWM = 0;
	}
}

//四驱TTL电机
void PWM_SiQu(unsigned char Count,unsigned char Comper,unsigned int PWM1,
	unsigned int PWM2,unsigned int PWM3,unsigned int PWM4){
		
	Count++;
	if(Count < Comper){
		PWM1 = 1;
		PWM2 = 1;
		PWM3 = 1;
		PWM4 = 1;
	}
	if(Count > Comper){		// 40 * 500us = 20ms
		PWM1 = 0;
		PWM2 = 0;
		PWM3 = 0;
		PWM4 = 0;
	}
	Count %=40;		// 若范围到 0-40 每20一档  共2档 
}
	*/
	
/*
void Timer0_Routine() interrupt 1{
	
	TL0 = 0x66;
	TH0 = 0xEA;
	Count++;					//计数范围 0-40
	if(Count < Step){
		q_PWM = 1;
		h_PWM = 1;
	}
	if(Count > Step){
		q_PWM = 0;
		h_PWM = 0;
	}
	Count %= 40;
}*/


