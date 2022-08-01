#ifndef __CHAOSHENBO_H__
#define __CHAOSHENBO_H__
#include <REGX52.H>

sbit TRIG = P2^0;
sbit ECHO = P2^1;

void Timer1_Init(void);
unsigned int Chaoshenbo(void);
void Delay20us();

#endif