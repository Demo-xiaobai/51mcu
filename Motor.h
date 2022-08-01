#ifndef __MOTOR_H__
#define __MOTOR_H__

//ǰ��
sbit q_IN1 = P0^0;
sbit q_IN2 = P0^1;
sbit q_IN3 = P0^2;
sbit q_IN4 = P0^3;
//ǰ��2��PWM ����
sbit q_Letf_PWM = P0^4;
sbit q_Right_PWM = P0^5;


//����
sbit h_IN1 = P1^0;
sbit h_IN2 = P1^1;
sbit h_IN3 = P1^2;
sbit h_IN4 = P1^3;
//���� 2��PWM ����
sbit h_Letf_PWM = P1^4;  //ENA
sbit h_Right_PWM = P1^5; //ENB

//��̨
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