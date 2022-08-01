#include <REGX52.H>
#include "Motor.h"
#include "Delay.h"
#include "ChaoShenBo.h"
#include "BlueTooth.h"

unsigned char tmp_main;		//自动避障的距离参数

void main(){
	
		Timer1_Init();					//超声波
		Timer0_Init_Siqu();			//小车PWM初始化
		UartInit();							//蓝牙串口
	
	while(1){		
		
		/*  自动避障模  
		tmp_main = Chaoshenbo();
		Turn_Around(tmp_main);*/ 
		
	}
}