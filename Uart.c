
#include "Uart.h"
#include <REGX51.H>
#include "motor.h"
unsigned char count = 0;
unsigned  char  buffers[80];
unsigned char gate = 0;


// 描述: 串口初始化程序.
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
	ES = 1;
	EA = 1;
}
//COM1发送一个字节
void Send_Data(unsigned char dat)
{
	SBUF = dat;
	while(!TI);
	TI = 0;
	
}
//COM1发送一个字符串
void Send_Str(unsigned char *s, unsigned char length)
{
	while(length){
		Send_Data(*s++);
		length--;
	}
}

unsigned char gate_gate(void){
	if(gate){
		gate = 0;
		return 1;
	}
	return 0;
}

//串口1中断处理程序
void INT_Uart1(void) interrupt 4
{
	if(RI)
	{
		RI = 0;//清空读中断标志位
		buffers[count] = SBUF;
		if(buffers[count]	== '}' && 	buffers[count - 1]	== '1' && buffers[count - 2]	== ':' && buffers[count - 3]	== '"' && buffers[count - 4]	== 'e' && buffers[count- 5]	== 't'){
			P0_0 = 1;
			gate = 1;
		}
		count++;
		count %=80;
	}
}




