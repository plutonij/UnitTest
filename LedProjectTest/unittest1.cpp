#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LedProjectTest
{		
	static uint16_t VirtualLeds = 0;

	TEST_CLASS(LedTest)
	{
	public:
		

		TEST_CLASS_INITIALIZE(LedTestInit)
		{
			InitializeLed(&VirtualLeds);
		}

		TEST_METHOD(LedTurnOnTest)
		{
			TurnLedOn(1);
			Assert::IsTrue(VirtualLeds == 1);
		}

		TEST_METHOD(LedTurnOffTest)
		{
			TurnLedOn(1);
			TurnLedOff(1);
			Assert::IsTrue(VirtualLeds == 0);
		}

		TEST_METHOD(LedTurnMultipleLeds)
		{
			TurnLedOn(8);
			TurnLedOn(9);
			Assert::IsTrue(0x180 == VirtualLeds);
		}

		TEST_METHOD(LedTurnOffAnyLed)
		{
			TurnAllOn();
			TurnLedOff(8);
			Assert::IsTrue(0xFF7F == VirtualLeds);
		}

		TEST_METHOD(LedAllOn)
		{
			TurnAllOn();
			Assert::IsTrue(0xFFFF == VirtualLeds);
		}

		TEST_METHOD(LedMemoryNotReadable)
		{
			VirtualLeds = 0xFFFF;
			TurnLedOn(8);
			Assert::IsTrue(0x80 == VirtualLeds);
		}


		TEST_CLASS_CLEANUP(LedCleanup)
		{

		}

	};
}