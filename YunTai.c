#include <REGX52.H>
#include "YunTai.h"
#include "Delay.h"
#include <stdio.h>


//����1����̨�������жϳ�ͻ
//unsigned char YunTai_Count,YunTai_angle;
//��ʼ��
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

		�����ж�ʱ���� 100us����0.1ms  5����0.5ms������5�ı���
	

// 1���� 100us    5����0.5ms
void YunTai_Runtine() interrupt 1{
	
	YunTai_Count++;            //100��  0.5ms = 500us 
	YunTai_angle = 10;									//5 -90��  10 -45��  15 0��  20 45�� 25 90��
	//�ж� angle��ֵ  �Ƿ�Ϊ5�ı���
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
//����һ��20ms������



