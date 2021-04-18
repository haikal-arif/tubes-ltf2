#include <ShiftRegister74HC595.h>

int numberOfShiftRegisters = 1; // number of shift registers attached in series
int serialDataPin = 0; // DS
int clockPin = 1; // SHCP
int latchPin = 2; // STCP

ShiftRegister74HC595<numberOfShiftRegisters> sr(serialDataPin, clockPin, latchPin);
