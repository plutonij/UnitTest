// CircularIntBuffer.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

static int * CircularBuffer;
void BufferInitialize(int * circularBuffer)
{
	CircularBuffer = circularBuffer;
}
void BufferAdd(int value)
{
	* CircularBuffer = value;
}


void BufferGet(int * value)
{
	* value = * CircularBuffer;
}
