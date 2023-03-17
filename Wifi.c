#include <REGX51.H>
#include "Uart.h"
#include "Wifi.h"
#include "delay.h"
code char *Exit = "+++";
code char *client = "AT+CWMODE=1\r\n";
code char *RST = "AT+RST\r\n";
code char *link = "AT+CWJAP=\"liuryl\",\"123321123\"\r\n";
code char *configSerer = "AT+CIPSTART=\"TCP\",\"a1rTZKqoE4e.iot-as-mqtt.cn-shanghai.aliyuncs.com\",1883\r\n";
code char *Transparent_mode = "AT+CIPMODE=1\r\n";
code char *Transparent_Stat = "AT+CIPSEND\r\n";

void Init_WIFI(void){
	
	count = 1;
	
		Send_Str(Exit,3);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
	

	
	do{
		count = 1;
		Send_Str(client,15);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
	}while(buffers[count - 4] != 'O'  || buffers[count-3] != 'K' && buffers[count-2] != 0x0D || buffers[count-1] != 0x0A); 
	
	
	do{
		count = 1;
		Send_Str(RST,10);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
	}while(buffers[count - 4] != 0x64  || buffers[count-3] != 0x79 || buffers[count-2] != 0x0D || buffers[count-1] != 0x0A); 
	
	
	do{
		count = 1;
		Send_Str(link,38);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
	}while(buffers[count - 4] != 'O'  || buffers[count-3] != 'K' && buffers[count-2] != 0x0D || buffers[count-1] != 0x0A); 
	
	
	do{
		count = 1;
		Send_Str(configSerer,77);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
	}while(buffers[count - 4] != 'O'  || buffers[count-3] != 'K' && buffers[count-2] != 0x0D || buffers[count-1] != 0x0A); 


	
	do{
		count = 1;
		Send_Str(Transparent_mode,16);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
	}while(buffers[count - 4] != 'O'  || buffers[count-3] != 'K' && buffers[count-2] != 0x0D || buffers[count-1] != 0x0A); 


	
	do{
		count = 1;
		Send_Str(Transparent_Stat,14);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
		DelayMs(255);
	}while(buffers[count-3] != 0x0D || buffers[count-2] != 0x0A || buffers[count-1] != 0x3E); 

	
}


