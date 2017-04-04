// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

// Headers for CppUnitTest
#include "CppUnitTest.h"

void
InitializeLed(
	uint16_t	* VirtualLeds
);

void TurnLedOn(uint16_t LED);

void TurnLedOff(uint16_t LED);

void TurnAllOn();

// TODO: reference additional headers your program requires here
