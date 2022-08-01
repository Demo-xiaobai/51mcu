#ifndef __MOTOR_H__
#define __MOTOR_H__

//前驱
sbit q_IN1 = P0^0;
sbit q_IN2 = P0^1;
sbit q_IN3 = P0^2;
sbit q_IN4 = P0^3;
//前轮2个PWM 调速
sbit q_Letf_PWM = P0^4;
sbit q_Right_PWM = P0^5;


//后驱
sbit h_IN1 = P1^0;
sbit h_IN2 = P1^1;
sbit h_IN3 = P1^2;
sbit h_IN4 = P1^3;
//后轮 2个PWM 调速
sbit h_Letf_PWM = P1^4;  //ENA
sbit h_Right_PWM = P1^5; //ENB

//云台
sbit YunTai_PWM = P0^6;

void Go_Ahead();
void Back();
void Turn_Left();
void Turn_Right();
void Letf_up();
void Right_up();
void Left_Bottom();
void Right_Bottom();

void Stop();


void Timer0_Init_Siqu();
void Turn_Around(unsigned int temp);

#endif