#include <REGX51.H>
#include "Uart.h"
#include "Wifi.h"
#include "MQTT.h"
#include "delay.h"
#include "distance.h"		   
#include "motor.h"
char Link_status = 0;
unsigned int timp ;
char flag = 3;
char flag2 = 3;
char count2 = 3;
unsigned int heart = 0;
char up = 0;

void main(void){
	UartInit();	//9600bps@11.0592MHz
	init_distance();
	P0_0 = 0;
					DataPro(1450);
					DelayMs(255);	
					DelayMs(255);	
					DelayMs(255);	
					DelayMs(255);	
					DelayMs(255);	
					DataPro(500);
					DelayMs(255);	
					DelayMs(255);	
					DelayMs(255);	
					DelayMs(255);	
					DelayMs(255);	
					DataPro(1450);
					DelayMs(255);	
					DelayMs(255);	
					DelayMs(255);	
					DelayMs(255);	
					DelayMs(255);	
	while(1){
		
		if(Link_status){
			if(Link_status == 1){
				Link_status = Init_MQTT();
			}		
			if(Link_status == 2){
				
				count2 = 3;
				flag = 3;
				while(count2){
					DelayMs(50);
					timp = Conut();
					if(timp > 35){
						flag ++;					
					}
					else{
						flag --;
					}
					count2--;
				}
				
				flag = (flag > 3) ? 0 : 1;
//						MQTT_Publish_off();
				
				// distance2
				count2 = 3;
				flag2 = 3;
				while(count2){
					DelayMs(50);
					timp = Conut2();
					if(timp > 35){
						flag2 ++;					
					}
					else{
						flag2 --;
					}
					count2--;
				}
				
				flag2 = (flag2 > 3) ? 0 : 1;
				
				heart++;
				if(heart>100){
					
					MQTT_Heart_send();
					heart= 0;
				}
				if(flag == 1){		
					if(heart%20==0){
						MQTT_Publish_off();
					}									
				}
				
				if(gate_gate()){
					DataPro(500);
					up = 1;
				}
				else{
					if(up == 1 && flag == 0 && flag2 == 0)
					{
						DataPro(1500);
						up = 0;
						P0_0 = 0;
					}
				}

			}
		}else{			
			Init_WIFI();//…Ë÷√WIFI
			Link_status = 1;
			
		}
	}
}

