#pragma once

void RuntimeErrorStub_Reset();
const char * RuntimeErrorStub_GetLastError();
int RuntimeErrorStub_GetLastParameter();
void RuntimeError(const char * m, int p, const char * f, int l);
