/*
Name:		DS18B20.ino
Created:	2017/2/8 19:13:17
Author:	miniqiang
Editor:	http://www.visualmicro.com
*/

#include "DS18B20Lib.h"


DS18B20 no1;
void setup() {
	Serial.begin(115200);
}

// the loop function runs over and over again until power down or reset
void loop() {
	no1.romAddr();
	no1.detection();
	//delay(1000);  //每次转换时间不得小于750mm
	float temp = no1.readTemperature();

	Serial.print("Temperature:");
	Serial.println(temp);
	/****************************************/



}
