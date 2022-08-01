#include <REGX52.H>
#include "YunTai.h"
#include "Delay.h"
#include <stdio.h>


//问题1：云台和四驱中断冲突
//unsigned char YunTai_Count,YunTai_angle;
//初始化
/*
void Timer0_Init_YunTai(){
			TMOD &= 0xF0;
			TMOD |= 0x01;
	
			TL0 = 0xA4;		
			TH0 = 0xFF;
			
			PT0=0;
			TF0=1;
			ET0=1;
			EA=1;
			TR0=1;
}
*/
/*

		进入中断时间是 100us，即0.1ms  5次是0.5ms，顾以5的倍数
	

// 1次是 100us    5次是0.5ms
void YunTai_Runtine() interrupt 1{
	
	YunTai_Count++;            //100次  0.5ms = 500us 
	YunTai_angle = 10;									//5 -90°  10 -45°  15 0°  20 45° 25 90°
	//判断 angle的值  是否为5的倍数
	if(YunTai_Count >= 200){
		YunTai_Count = 0;
	}
	if(YunTai_Count < YunTai_angle){
		YunTai_PWM = 1;
	}else{
		YunTai_PWM = 0;
	}

}
*/
//设置一个20ms的周期



