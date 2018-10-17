/*******************************************************************************
File name: TM1638.cpp
Version  : V1.0.0
*******************************************************************************/

/*******************************************************************************

*******************************************************************************/

/*******************************************************************************
File description

*******************************************************************************/
#include "TM1638.h"

const uint8_t digits[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };

TM1638Class::TM1638Class()
{

}
TM1638Class::~TM1638Class()
{

}
/**
* @brief Init TM1638
*/
void TM1638Class::init(uint8_t pinCLK, uint8_t pinDIO, uint8_t pinSTB)
{
	this->pinCLK = pinCLK;
	this->pinDIO = pinDIO;
	this->pinSTB = pinSTB;
	pinMode(this->pinCLK, OUTPUT);
	pinMode(this->pinDIO, OUTPUT);
	pinMode(this->pinSTB, OUTPUT);
	setBrightness(TM1638_BRIGHTNESS_14_16);
	cleanDisplay();
}
/**
* @brief Display data on LED 7 segment
*/
void TM1638Class::displayOnLed7Seg(TM1638_Position_t position, uint8_t value)
{
	sendCommand(0x44);
	digitalWrite(this->pinSTB, LOW);
	shiftOut(this->pinDIO, this->pinCLK, LSBFIRST, 0xc0 | (uint8_t)position);
	shiftOut(this->pinDIO, this->pinCLK, LSBFIRST, value);
	digitalWrite(this->pinSTB, HIGH);
}
/**
* @brief Display data on LED 7 segment
*/
void TM1638Class::displayNumberOnLed7Seg(TM1638_Position_t position, uint8_t value)
{
	if (value > 9)
		return;
	sendCommand(0x44);
	digitalWrite(this->pinSTB, LOW);
	shiftOut(this->pinDIO, this->pinCLK, LSBFIRST, 0xc0 | (uint8_t)position);
	shiftOut(this->pinDIO, this->pinCLK, LSBFIRST, digits[value]);
	digitalWrite(this->pinSTB, HIGH);
}
/**
* @brief Display data on LED
*/
void TM1638Class::displayOnLed(TM1638_Position_t position, uint8_t value)
{
	sendCommand(0x44);
	digitalWrite(this->pinSTB, LOW);
	shiftOut(this->pinDIO, this->pinCLK, LSBFIRST, 0xc0 | (uint8_t)position);
	shiftOut(this->pinDIO, this->pinCLK, LSBFIRST, value);
	digitalWrite(this->pinSTB, HIGH);
}
/**
* @brief Read button
*/
uint8_t TM1638Class::readButton(void)
{
	uint8_t buttons = 0;
	uint8_t bitIn = 0;
	digitalWrite(this->pinSTB, LOW);
	shiftOut(this->pinDIO, this->pinCLK, LSBFIRST, 0x42);
	pinMode(this->pinDIO, INPUT);

	for (uint8_t i = 0; i < 4; i++)
	{
		bitIn = shiftIn(this->pinDIO, this->pinCLK, LSBFIRST) << i;
		buttons |= bitIn;
	}

	pinMode(this->pinDIO, OUTPUT);
	digitalWrite(this->pinSTB, HIGH);
	return buttons;
}
/**
* @brief Send command to TM1638
*/
void TM1638Class::sendCommand(uint8_t cmd)
{
	digitalWrite(this->pinSTB, LOW);
	shiftOut(this->pinDIO, this->pinCLK, LSBFIRST, cmd);
	digitalWrite(this->pinSTB, HIGH);
}
/**
* @brief Clean all display on LED 7 segment and all LED
*/
void TM1638Class::cleanDisplay(void)
{
	this->sendCommand(0x40); // set auto increment mode
	digitalWrite(this->pinSTB, LOW);
	shiftOut(this->pinDIO, this->pinCLK, LSBFIRST, 0xC0);   // set starting address to 0
	for (uint8_t i = 0; i < 16; i++)
	{
		shiftOut(this->pinDIO, this->pinCLK, LSBFIRST, 0x00);
	}
	digitalWrite(this->pinSTB, HIGH);
}
/**
* @brief Set brightness of LED 7 segment
*/
void TM1638Class::setBrightness(TM1638_Brightness_t level)
{
	uint8_t brightness = 0x88 | (uint8_t)level;
	sendCommand(brightness);
}
/*******************************************************************************
********************************END OF FILE*************************************
*******************************************************************************/