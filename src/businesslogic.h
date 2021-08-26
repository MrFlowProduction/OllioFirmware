#ifndef BUSINESSLOGIC_H /* include guards */
#define BUSINESSLOGIC_H

#include <Arduino.h> /* we need arduino functions to implement this */
#include <globals.h>
#include <enum.h>

extern int m_counter;

void stateMachine();

void ClosingState();

void NoneState();

void ShortingState();

void SeparateState();

void MeasState();

void PrintingState();

void FaultState();

void SystemCheck();

void Reset();

void ErrorState();

void WaitForButton();

#endif