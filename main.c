#include <REGX52.H>
#include "Motor.h"
#include "Delay.h"
#include "ChaoShenBo.h"
#include "BlueTooth.h"

unsigned char tmp_main;		//�Զ����ϵľ������

void main(){
	
		Timer1_Init();					//������
		Timer0_Init_Siqu();			//С��PWM��ʼ��
		UartInit();							//��������
	
	while(1){		
		
		/*  �Զ�����ģ  
		tmp_main = Chaoshenbo();
		Turn_Around(tmp_main);*/ 
		
	}
}