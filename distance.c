#include <REGX51.H>
#include "delay.h"
#define  ECHO  P1_6				   //�������ӿڶ���
#define  TRIG  P1_5				   //�������ӿڶ���
#define  ECHO2 P2_6				   //�������ӿڶ���
#define  TRIG2 P2_5				   //�������ӿڶ���

 /***************************************************/
unsigned int Conut(void)		   //�������
{
	unsigned int S=0;	
	  TRIG=1;			                
	  DelayUs2x(12);
	  TRIG=0;
	 while(!ECHO);		       //��RXΪ��ʱ�ȴ�
	  TR0=1;			       //��������
	 while(ECHO);			   //��RXΪ1�������ȴ�
	  TR0=0;				   //�رռ���
	  S=TH0*256+TL0;		   //��ȡ������
	  TH0=0;
	  TL0=0;
	  S=S*0.017;        //�������CM
	return S;
}

unsigned int Conut2(void)		   //�������
{
	unsigned int S=0;	
	  TRIG2=1;			                
	  DelayUs2x(12);
	  TRIG2=0;
	 while(!ECHO2);		       //��RXΪ��ʱ�ȴ�
	  TR0=1;			       //��������
	 while(ECHO2);			   //��RXΪ1�������ȴ�
	  TR0=0;				   //�رռ���
	  S=TH0*256+TL0;		   //��ȡ������
	  TH0=0;
	  TL0=0;
	  S=S*0.017;        //�������CM
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

	