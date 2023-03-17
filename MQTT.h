#ifndef __MQTT_H__
#define __MQTT_H__

extern unsigned char buffers[80];
extern unsigned char count;

char Init_MQTT(void);
char subscribe(void);
void MQTT_Publish_off(void);
void MQTT_Heart_send(void);



#endif