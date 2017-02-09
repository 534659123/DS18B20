/*
Name:		DS18B20Lib.h
Created:	2017/2/8 19:13:17
Author:	miniqiang
Editor:	http://www.visualmicro.com
*/

#ifndef _DS18B20Lib_h
#define _DS18B20Lib_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
class  DS18B20
{
public:
	DS18B20();
	void begin();
	void romAddr();
	void romAddr(byte *ADDR);
	void detection();  //获取温度
	float readTemperature(); //读出温度
private:
	byte _ADDR[8];
};

#endif

