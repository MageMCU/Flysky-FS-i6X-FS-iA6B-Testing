// Carpenter Software
// File: FSi6X.h (Tesing version)
// Date: 20211010
// Test: FS-i6X (TX) & FS-iA6B (RX) Transceivers.
// Purpose: Review and Product Affirmation Report.
// Note: Inexpensive...
//
// MIT LICENSE
//
// See LabNotes for further information

#ifndef _UNO_FSI6X_H_
#define _UNO_FSI6X_H_

#include <Arduino.h>

namespace uno
{
    class FSi6X
    {
    private:
        // Arduino Uno Pins Used
        int _numberOfPins;

        // Arduino Input Pin Numbers
        int _PWM_InputPin1;
        int _PWM_InputPin2;

        // Arduino impulseIn() 1
        double _ONCycle1;
        double _OFFCycle1;

        // Calculations 1
        double _period1;
        long _frequency1;
        double _dutyCycle1;

        // Arduino impulseIn() 2
        double _ONCycle2;
        double _OFFCycle2;

        // Calculations 2
        double _period2;
        long _frequency2;
        double _dutyCycle2;

        void _calculate();

    public:
        FSi6X(){};
        FSi6X(int PWM_InputPin);
        FSi6X(int PWM_InputPin1, int PWM_InputPin2);
        ~FSi6X(){};

        void Update();

        double Period(int pinNumber = 1);
        long Frequency(int pinNumber = 1);
        double DutyCycle(int pinNumber = 1);
        double DutyCyclePercent(int pinNumber = 1);
    };

    FSi6X::FSi6X(int PWM_InputPin)
    {
        _PWM_InputPin1 = PWM_InputPin;
        _numberOfPins = 1;
    }

    FSi6X::FSi6X(int PWM_InputPin1, int PWM_InputPin2)
    {
        _PWM_InputPin1 = PWM_InputPin1;
        _PWM_InputPin2 = PWM_InputPin2;
        _numberOfPins = 2;
    }

    void FSi6X::Update()
    {
        _calculate();
    }

    double FSi6X::Period(int pinNumber)
    {
        if (pinNumber == 1)
            return _period1;

        if (_numberOfPins == 2 && pinNumber == 2)
            return _period2;

        return -1;
    }

    long FSi6X::Frequency(int pinNumber)
    {
        if (pinNumber == 1)
            return _frequency1;

        if (_numberOfPins == 2 && pinNumber == 2)
            return _frequency2;

        return -1;
    }

    double FSi6X::DutyCycle(int pinNumber)
    {
        if (pinNumber == 1)
        {
            return _dutyCycle1;
        }

        if (_numberOfPins == 2 && pinNumber == 2)
        {
            return _dutyCycle2;
        }

        return -1;
    }

    double FSi6X::DutyCyclePercent(int pinNumber)
    {
        if (pinNumber == 1)
        {
            return _dutyCycle1 * 100.0;
        }

        if (_numberOfPins == 2 && pinNumber == 2)
        {
            return _dutyCycle2 * 100.0;
        }

        return -1;
    }

    void FSi6X::_calculate()
    {
        _ONCycle1 = pulseIn(_PWM_InputPin1, HIGH);
        _OFFCycle1 = pulseIn(_PWM_InputPin1, LOW);

        _period1 = _ONCycle1 + _OFFCycle1;
        _frequency1 = (long)(1000000.0 / _period1);
        _dutyCycle1 = _ONCycle1 / _period1;

        if (_numberOfPins == 2)
        {
            _ONCycle2 = pulseIn(_PWM_InputPin2, HIGH);
            _OFFCycle2 = pulseIn(_PWM_InputPin2, LOW);

            _period2 = _ONCycle2 + _OFFCycle2;
            _frequency2 = (long)(1000000.0 / _period2);
            _dutyCycle2 = _ONCycle2 / _period2;
        }
    }
}

#endif