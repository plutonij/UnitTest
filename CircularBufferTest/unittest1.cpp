#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircularBufferTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(CircularBufferTest)
		{
			int * CircularBuffer = (int *)calloc(5, sizeof(int));
			BufferInitialize(CircularBuffer);
			BufferAdd(5);
			Assert::IsTrue(5 == *CircularBuffer);
			// TODO: Your test code here
		}

		TEST_METHOD(CircularBufferGetTest)
		{
			int * CircularBuffer = (int *)calloc(5, sizeof(int));
			int Value = 0;
			BufferInitialize(CircularBuffer);
			BufferAdd(5);
			BufferGet(&Value);
			Assert::IsTrue(5 == Value);
			// TODO: Your test code here
		}

	};
}