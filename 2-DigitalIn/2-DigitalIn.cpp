#include "mbed.h"
#include "DigitalPort.hpp"

DigitalOut leds[6] = {D3, D4, D5, D6, D11, D12}; // leds est un tableau de 6 DigitalOut

DigitalIn buttons[2] = {A3, A4};

int main()
{
	DigitalPort::
}