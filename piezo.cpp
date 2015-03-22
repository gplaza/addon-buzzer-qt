#include "piezo.h"

Piezo* Piezo::m_Instance = 0;

void Piezo::good(int pin)
{
    softToneWrite (pin, 800) ;
    delay (150) ;
    softToneWrite (pin, 0) ;
}

void Piezo::caution(int pin)
{
    softToneWrite(pin,800);
    delay(50);
    softToneWrite(pin,0);
    delay(50);
    softToneWrite(pin,800);
    delay(50);
    softToneWrite(pin,0);
    delay(50);
    softToneWrite(pin,800);
    delay(50);
    softToneWrite(pin,0);
}

void Piezo::bad(int pin){

    softToneWrite(pin,450);
    delay(100);
    softToneWrite(pin,0);
    delay(50);
    softToneWrite(pin,450);
    delay(100);
    softToneWrite(pin,0);
}
