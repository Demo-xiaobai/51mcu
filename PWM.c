#include "PWM.h"
#include <REGX52.H>

/*
	��������� ��Ҫ���� ��ʱ��
	T = 20ms = 20000us ,���ڶ���������� 200�Σ�
*/

/*/�����ڼ���ģʽ
void Timer0_Siqu_Init(){			//100us ����һ���ж�  �����ƴ���100us����һ���ж�	
	
	TMOD &= 0xF0;
	TMOD |= 0x01;

	//ʱ�� 100us, 100us * 100 = 10000us = 10ms	
	TL0 = 0xA4;		
	TH0 = 0xFF;	
	
	TF0 = 0;		
	TR0 = 1;	
	
	ET0=1;
	EA=1;
}*/




//��Ҫ�� ��� �� ������� 
/*
	Count * �����жϴ��� = ������T��Comper ��ռ�ձȣ��������PWM 


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

//����TTL���
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
	Count %=40;		// ����Χ�� 0-40 ÿ20һ��  ��2�� 
}
	*/
	
/*
void Timer0_Routine() interrupt 1{
	
	TL0 = 0x66;
	TH0 = 0xEA;
	Count++;					//������Χ 0-40
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


