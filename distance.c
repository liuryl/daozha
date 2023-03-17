#include <REGX51.H>
#include "delay.h"
#define  ECHO  P1_6				   //超声波接口定义
#define  TRIG  P1_5				   //超声波接口定义
#define  ECHO2 P2_6				   //超声波接口定义
#define  TRIG2 P2_5				   //超声波接口定义

 /***************************************************/
unsigned int Conut(void)		   //计算距离
{
	unsigned int S=0;	
	  TRIG=1;			                
	  DelayUs2x(12);
	  TRIG=0;
	 while(!ECHO);		       //当RX为零时等待
	  TR0=1;			       //开启计数
	 while(ECHO);			   //当RX为1计数并等待
	  TR0=0;				   //关闭计数
	  S=TH0*256+TL0;		   //读取脉宽长度
	  TH0=0;
	  TL0=0;
	  S=S*0.017;        //算出来是CM
	return S;
}

unsigned int Conut2(void)		   //计算距离
{
	unsigned int S=0;	
	  TRIG2=1;			                
	  DelayUs2x(12);
	  TRIG2=0;
	 while(!ECHO2);		       //当RX为零时等待
	  TR0=1;			       //开启计数
	 while(ECHO2);			   //当RX为1计数并等待
	  TR0=0;				   //关闭计数
	  S=TH0*256+TL0;		   //读取脉宽长度
	  TH0=0;
	  TL0=0;
	  S=S*0.017;        //算出来是CM
	return S;
}


 /***************************************************/
void init_distance(void){
	TMOD &= 0xF0;	
	TMOD |= 0x01;
	TRIG=0;	
	TRIG2=0;	
	TH0=0;	  
	TL0=0;
	TR0= 0;
}

	