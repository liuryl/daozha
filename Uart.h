#ifndef __Uart_H__
#define __Uart_H__


void UartInit(void)	;
void Send_Data(unsigned char dat);
void Send_Str(unsigned char *s, unsigned char length);
unsigned char gate_gate(void);

#endif