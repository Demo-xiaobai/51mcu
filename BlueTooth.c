#include <REGX52.H>
#include "BlueTooth.h"
#include "Motor.h"
#include "Delay.h"

unsigned char ReciveData;
unsigned char Flag;
void UartInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		
	SCON = 0x50;		
	TMOD &= 0x0F;		
	TMOD |= 0x20;		
	TL1 = 0xFD;		
	TH1 = 0xFD;		
	
	ET1 = 0;		
	TR1 = 1;		
	
	//忘记开中断了
	EA=1;
	ES=1;		//串口中断
}


void move(unsigned char ch){
	switch (ch){
		case '1':
			Letf_up();break;
		case '2':
			Go_Ahead();break;
		case '3':
			Right_up();break;
		case '4':
			Turn_Left();break;
		case '5':
			Stop();	break;
		case '6':
			Turn_Right();
			break;
		case '7':
			Left_Bottom();
			break;
		case '8':
			Back();
			break;
		case '9':
			Right_Bottom();
			break;
		case '0':
			Flag = 1;
			break;
	}
}


void Timer1_Rountine() interrupt 4 {
	
		if(RI==1){				//接收寄存器开
			Stop();
			ReciveData = SBUF;
			Delayms(1);
			move(ReciveData);
		}
		RI = 0;					//接收寄存器关
		
}