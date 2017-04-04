// LedProject.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>

static uint16_t * LedAddress;
static uint16_t LedImage;

enum
{
	ALL_LEDS_ON = ~0,
	ALL_LEDS_OFF = ~ALL_LEDS_ON
};

void
InitializeLed(
	uint16_t	* Address
)
{
	LedAddress = Address;
	LedImage = ALL_LEDS_OFF;
	* LedAddress = LedImage;
}

uint16_t convertLedNumberToBit(int LedNumber)
{
	return 1 << (LedNumber - 1);
}
void TurnLedOn(uint16_t LED)
{
	LedImage |= convertLedNumberToBit(LED);
	*LedAddress = LedImage;
}

void TurnLedOff(uint16_t LED)
{
	LedImage &= ~convertLedNumberToBit(LED);
	*LedAddress = LedImage;
}

void TurnAllOn()
{
	LedImage = ALL_LEDS_ON;
	*LedAddress = LedImage;
}


