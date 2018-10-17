/*******************************************************************************
File name: TM1638.h
Version  : V1.0.0
*******************************************************************************/

/*******************************************************************************

*******************************************************************************/

/*******************************************************************************
File description

*******************************************************************************/
#ifndef _TM1638_h
#define _TM1638_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

typedef enum
{
	TM1638_LED7SEG_POS0 = 0,
	TM1638_LED7SEG_POS1 = 2,
	TM1638_LED7SEG_POS2 = 4,
	TM1638_LED7SEG_POS3 = 6,
	TM1638_LED7SEG_POS4 = 8,
	TM1638_LED7SEG_POS5 = 10,
	TM1638_LED7SEG_POS6 = 12,
	TM1638_LED7SEG_POS7 = 14,
	TM1638_LED7SEG_POS8 = 16,
	TM1638_LED7SEG_POS9 = 18,

	TM1638_LED_POS0 = 1,
	TM1638_LED_POS1 = 3,
	TM1638_LED_POS2 = 5,
	TM1638_LED_POS3 = 7,
	TM1638_LED_POS4 = 9,
	TM1638_LED_POS5 = 11,
	TM1638_LED_POS6 = 13,
	TM1638_LED_POS7 = 15,
}TM1638_Position_t;


typedef enum
{
	TM1638_BRIGHTNESS_1_16 = 0,
	TM1638_BRIGHTNESS_2_16,
	TM1638_BRIGHTNESS_4_16,
	TM1638_BRIGHTNESS_10_16,
	TM1638_BRIGHTNESS_11_16,
	TM1638_BRIGHTNESS_12_16,
	TM1638_BRIGHTNESS_13_16,
	TM1638_BRIGHTNESS_14_16,
}TM1638_Brightness_t;

class TM1638Class
{
public:
	TM1638Class();
	~TM1638Class();
	/**
	* @brief Init TM1638
	* @retval none
	*/
	void init(uint8_t pinCLK, uint8_t pinDIO, uint8_t pinSTB);
	/**
	* @brief Display data on LED 7 segment
	* @param position Position of LED
	* @param value Data to display on LED
	* @retval none
	*/
	void displayOnLed7Seg(TM1638_Position_t position, uint8_t value);
	/**
	* @brief Display number on LED 7 segment
	* @param position Position of LED
	* @param value Data to display on LED
	* @retval none
	*/
	void displayNumberOnLed7Seg(TM1638_Position_t position, uint8_t value);
	/**
	* @brief Display data on LED
	* @param position Position of LED
	* @param value Data to display on LED
	* @retval none
	*/
	void displayOnLed(TM1638_Position_t position, uint8_t value);
	/**
	* @brief Set brightness of LED 7 segment
	* @param level Position of LED
	* @retval none
	*/
	void setBrightness(TM1638_Brightness_t level);
	/**
	* @brief Read button
	* @retval Button value
	*/
	uint8_t readButton(void);
	/**
	* @brief Clean all display on LED 7 segment and all LED
	* @retval none
	*/
	void cleanDisplay(void);
private:
	uint8_t pinCLK;
	uint8_t pinDIO;
	uint8_t pinSTB;
	/**
	* @brief Send command to TM1638
	* @param cmd Command to send
	* @retval none
	*/
	void sendCommand(uint8_t cmd);
};

#endif
/*******************************************************************************
********************************END OF FILE*************************************
*******************************************************************************/
