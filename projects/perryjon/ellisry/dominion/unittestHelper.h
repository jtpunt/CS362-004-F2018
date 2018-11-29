#ifndef _UNITTESTHELPER_H
#define _UNITTESTHELPER_H
#include <stdio.h>

#include <stdbool.h>
void printTestResult(bool result, char str[], int a, int b);
bool assertTrue(char str[], int a, int b);
void printFinalResult(bool results[], int numTests);
#endif