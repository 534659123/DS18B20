/*
Name:		DS18B20Lib.cpp
Created:	2017/2/8 19:13:17
Author:	miniqiang
Editor:	http://www.visualmicro.com
*/

#include "DS18B20Lib.h"

#include <OneWire.h>

OneWire  ds(8);

DS18B20::DS18B20()
{

}

void DS18B20::begin()
{
}

void DS18B20::romAddr()
{
	byte addr[8];
	if (!ds.search(addr))
	{
		ds.reset_search();
	}
	else
	{
		
		for (byte a = 0;a < 8;a++) //将地址数据存入私有变量
		{
			_ADDR[a] = addr[a];
		}
	}
}

void DS18B20::romAddr(byte *ADDR)
{
	byte addr[8];
		if (!ds.search(addr))
		{
			ds.reset_search();
		}
		else
		{
			for (byte a = 0;a<8;a++)
			{
				*(ADDR + a) = addr[a];
				_ADDR[a] = addr[a];
			}	

		}
}

void DS18B20::detection()
{


	ds.reset();  //复位总线
	ds.select(_ADDR);  //选择地址
	ds.write(0x44, 1);        // 写一个字节并且加电
}

float DS18B20::readTemperature()
{
	byte data[12];
	ds.reset();   //复位总线
	ds.select(_ADDR);     //选择地址设备
	ds.write(0xBE);         // Read Scratchpad
	
	for (byte i = 0; i < 9; i++) // we need 9 bytes
	{
		data[i] = ds.read();
	}
	
	int16_t raw = (data[1] << 8) | data[0];
	byte cfg = (data[4] & 0x60);
	// at lower res, the low bits are undefined, so let's zero them
	if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
	else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
	else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
	float celsius = (float)raw / 16.0;
	return celsius;
}