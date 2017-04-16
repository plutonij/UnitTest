// LedProject.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>
#include "RuntimeErrorStub.h"

#define RUNTIME_ERROR(description, parameter) RuntimeError(description, parameter, __FILE__, __LINE__)

static uint16_t * LedAddress;
static uint16_t LedImage;



enum
{
	ALL_LEDS_ON = ~0,
	ALL_LEDS_OFF = ~ALL_LEDS_ON
};

void UpdateHardware()
{
	*LedAddress = LedImage;
}

void
InitializeLed(
	uint16_t	* Address
)
{
	LedAddress = Address;
	LedImage = ALL_LEDS_OFF;
	UpdateHardware();
}

uint16_t convertLedNumberToBit(int LedNumber)
{
	return 1 << (LedNumber - 1);
}
void TurnLedOn(uint16_t LED)
{
	if (LED <= 0 || LED > 16)
	{
		RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
		return;
	}

	LedImage |= convertLedNumberToBit(LED);
	UpdateHardware();
	
}

void TurnLedOff(uint16_t LED)
{
	if (LED <= 0 || LED > 16)
	{
		return;
	}

	LedImage &= ~convertLedNumberToBit(LED);
	UpdateHardware();
}

void TurnAllOn()
{
	LedImage = ALL_LEDS_ON;
	UpdateHardware();
}


