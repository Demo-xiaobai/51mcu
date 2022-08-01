#include "ChaoShenBo.h"
#include "Motor.h"
#include "Delay.h"
#include <INTRINS.H>
#include <stdio.h>
//��ʱ��1�ķ�ʽʵ��
	
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
	/*��������*/
	TRIG = 1;
	Delay20us();
	TRIG = 0;
	
	while(!ECHO);		//�ȴ������źŸ����壬ȡ�����˳�ѭ���ȴ�
	TR1 = 1;				//��ʼ����
	
	while(ECHO);	//����������һ��������
	TR1 = 0;			//ֹͣ����
	
	distance = (((TH1*256+TL1)*0.00034)/2)*100;//��λcm

	return distance;
	
}