#include "ChaoShenBo.h"
#include "Motor.h"
#include "Delay.h"
#include <INTRINS.H>
#include <stdio.h>
//定时器1的方式实现
	
unsigned int distance;
unsigned int minDistance = 20;

void Timer1_Init(void)		//100
{
	TMOD &= 0x0F;		
	TMOD |= 0x10;		
	
	TL1 = 0x00;		
	TH1 = 0x00;		
	
	TF1 = 0;		
	TR1 = 0;		
}

	
void Delay20us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 6;
	while (--i);
}

unsigned int Chaoshenbo(void){
	Timer1_Init();
	/*发射脉冲*/
	TRIG = 1;
	Delay20us();
	TRIG = 0;
	
	while(!ECHO);		//等待回响信号高脉冲，取反就退出循环等待
	TR1 = 1;				//开始计数
	
	while(ECHO);	//超声波返回一个低脉冲
	TR1 = 0;			//停止计数
	
	distance = (((TH1*256+TL1)*0.00034)/2)*100;//单位cm

	return distance;
	
}