#include "mbed.h"

class DigitalPort 
{
private:
	int _state[]; 
	const int _pins; 

public: 
	DigitalPort(PinName pins[]) : _pins(pins)
	{
	}

	DigitalPort(PinName pins[], int initialState[]) : _pins(pins), _state(initialState) {}

	virtual int readState(); 
}

class DigitalPortIn : public DigitalPort
{
private: 
	DigitalIn _inputs[]; 

public:  
	DigitalPortIn(PinName pins[]) : DigitalPort(pins), _inputs(pins) {} 
	virtual int readState() override; 
}

class DigitalPortOut : public DigitalPortOut
{
private:
	DigitalOut _outputs[]; 

public:
	DigitalPortOut(PinName pins[]) : DigitalPort(pins), _outputs(pins) {}
	
	virtual int readState() override; 
	void writeState(int _state[]); 
}

DigitalOut leds[6] = {D3, D4, D5, D6, D11, D12}; // leds est un tableau de 6 DigitalOut

DigitalIn buttons[2] = {A3, A4};