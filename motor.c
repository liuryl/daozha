

#include <REGX51.H>
#include "delay.h"
sbit OUT = P1^3;
unsigned char TH_H,TL_H,TH_L,TL_L;


void DataPro(unsigned int temp){
 
				 	 TH_H=(65536-temp)/256;
					TL_H=(65536-temp)%256;
					TH_L=(46536+temp)/256;
					TL_L=(46536+temp)%256;
					EA=1;           
					ET0=1;          
					TR0=1;	
				DelayMs(222);
	DelayMs(222);
	DelayMs(222);
	ET0=0;
	TR0=0;
	TH0=0;	  
	TL0=0;
}


void Timer0_isr(void) interrupt 1
{
if(OUT)
 {
 TH0=TH_L;		 
 TL0=TL_L;
 }
else
 {
  TH0=TH_H;		  
  TL0=TL_H;
  }
OUT=!OUT;
}