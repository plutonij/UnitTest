#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define MSG(msg) [&]{ std::wstringstream _s; _s << msg; return _s.str(); }().c_str()

namespace LedProjectTest
{		
	static uint16_t VirtualLeds = 0;

	TEST_CLASS(LedTest)
	{
	public:
		
		TEST_METHOD_INITIALIZE(LedTestInit)
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

		TEST_METHOD(LedUpperAndLowerBounds)
		{
			TurnLedOn(1);
			TurnLedOn(16);

			Assert::IsTrue(0x8001 == VirtualLeds);
		}

		TEST_METHOD(TurnOnOutOfBoundsTestDoesNoHarm)
		{
			TurnLedOn(-1);
			Assert::IsTrue(0 == VirtualLeds);
			TurnLedOn(0);
			Assert::IsTrue(0 == VirtualLeds);
			TurnLedOn(17);
			Assert::IsTrue(0 == VirtualLeds);
			TurnLedOn(3141);
			Assert::IsTrue(0 == VirtualLeds);
			
		}

		TEST_METHOD(TurnOffOutOfBoundsTestDoesNoHarm)
		{
			uint16_t Result = 0xFFFF;
			TurnAllOn();
			TurnLedOff(-1);
			Assert::IsTrue(0xFFFF == VirtualLeds);
			TurnLedOff(0);
			Assert::IsTrue(0xFFFF == VirtualLeds);
			TurnLedOff(17);
			Assert::IsTrue(0xFFFF == VirtualLeds);
			TurnLedOff(3141);
			Assert::AreEqual(0xFFFF, (int) VirtualLeds, MSG("Value " << (int)VirtualLeds << " failed"));
		}

		TEST_METHOD(OutOfBoundsProducesRunTimeError)
		{
			TurnLedOn(-1);
			Assert::AreEqual("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
			Assert::AreEqual(-1, RuntimeErrorStub_GetLastParameter());
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(OutOfBoudsToDoRuntime)
			TEST_IGNORE()
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(OutOfBoudsToDoRuntime)
		{
			
			/*
				Save for later
			*/
		}

		TEST_METHOD_CLEANUP(LedCleanup)
		{

		}

	};
}