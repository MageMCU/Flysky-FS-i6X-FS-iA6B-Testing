// Carpenter Software
// File: main.cpp (Tesing version)
// Date: 20211010
// Test: FS-i6X (TX) & FS-iA6B (RX) Transceivers.
// Purpose: Review and Product Affirmation Report.
// Note: Inexpensive...
//
// MIT LICENSE
//
// See LabNotes for further information

#include <Arduino.h>
#include "FSi6X.h"
#include "Math.h"
#include "Timer.h"

// MCU
// Arduino Uno Rev3

// GLOBAL VARIABLE Declarations
// Keep global variables to a minimum...
uno::FSi6X flysky;
uno::Timer debugTimer;

void setup()
{
  // Debug
  Serial.begin(9600);
  while (!Serial)
  {
    // Waiting
  }
  Serial.println("FS-i6X & FS-iA6B Testing");

  // TEMPORARY VARIABLES
  // Note: Temp variables will Scope-Out.
  //
  // Step (1) Self-Test Output PWM
  // Test any of the following pins
  // as generators.
  // ------------------------
  // Uno-Pin ~ Frequency Output
  // ------------------------
  // Pin 3 ~ Frequency 492Hz
  // Pin 5 ~ Frequency 981Hx
  // Pin 6 ~ Frequency 981Hz
  // Pin 9 ~ Frequency 492Hz
  // Pin 10 ~ Frequency 492Hz
  // Pin 11 ~ Frequency 492Hz
  // Note: These are the expected
  //       output PWM-Frequency values...
  //       Do self-test to confirm
  //       both the validity for the
  //       frequency and the duty-cycle
  //       from these Arduino pins.
  ////////////////////////////////////
  // Focus on Step (1) Add wiring...
  ////////////////////////////////////
  // Step (1) Self-Test
  const int GeneratorPWM = 3;
  pinMode(GeneratorPWM, OUTPUT);
  const int _PWM_InputPin = 7;
  pinMode(_PWM_InputPin, INPUT);
  // Note: Connect directly From-Pin3-To-Pin7...
  //          Duty Cycle 100/255 = 0.3921
  //          Duty Cycle 200/255 = 0.7843
  //          Note: Expected Duty Cycles...
  //          Self-Test Passed ***************** OK
  ////////////////////////////////////
  // While Arduino Uno is Powered-Down.
  // Ignore Step (1) Remove wiring...
  // Focus on Step (2) Add wiring...
  ////////////////////////////////////
  // Step (2) FS-i6X & FS-iA6B
  //          FS-i6X PANEL SETTINGS
  //          System: Output mode:
  //          PWM (and i-BUS)
  //          Default PWM at 50Hz  ------- PWM
  //          System: Sticks mode:
  //          RIGHT Gimbal (jotstick)
  //          Channel-1 Horizontal (x) ------- CH1
  //                    connected to pin-2.
  const int _PWM_InputPin1 = 2;
  pinMode(_PWM_InputPin1, INPUT);
  //          Channel-2 Vertical (y) --------- CH2
  //                    connected to pin-4.
  const int _PWM_InputPin2 = 4;
  pinMode(_PWM_InputPin2, INPUT);
  //          See _FSi6X_Mapping() Method
  //          for further observed data...
  //
  ////////////////////////////////////////////
  // IMPORTANT SETUP FOR THE CLASS uno::FSi6X
  ////////////////////////////////////////////
  // Instantiate flysky
  // Step (1) Self-Test
  // flysky = uno::FSi6X(_PWM_InputPin);
  // Note: Has Generator...
  // Step (2) FS-i6X & FS-iA6B
  flysky = uno::FSi6X(_PWM_InputPin1, _PWM_InputPin2);
  // Note: Pay Attention to the Arduino Pin Numbers.
  //       Step (2) has NO Adrduino generator except
  //       what comes from the FS-iA6B Receiver.
  ////////////////////////////////////////////
  // Instantiate debugTimer
  debugTimer = uno::Timer();
}

void testFrequency(bool hasTwoPins)
{
  int freq1 = (int)flysky.Frequency();
  int freq2 = 0;

  if (hasTwoPins)
  {
    freq2 = (int)flysky.Frequency(2);
  }

  Serial.print("freq(x, y) = (");
  Serial.print(freq1);
  Serial.print(", ");
  Serial.print(freq2);
  Serial.println(") Hz");
}

void testDutyCycle(bool hasTwoPins)
{
  double dutyCycle1 = flysky.DutyCycle();
  double dutyCycle2 = 0.0;
  if (hasTwoPins)
  {
    dutyCycle2 = flysky.DutyCycle(2);
  }

  Serial.print("dutyCycle(x, y) = (");
  Serial.print(dutyCycle1, 4);
  Serial.print(", ");
  Serial.print(dutyCycle2, 4);
  Serial.println(")");
}

void testDutyCyclePercent(bool hasTwoPins)
{
  double dutyCycle1 = flysky.DutyCyclePercent();
  double dutyCycle2 = 0.0;
  if (hasTwoPins)
  {
    dutyCycle2 = flysky.DutyCyclePercent(2);
  }

  Serial.print("dutyCycle%(x, y) = (");
  Serial.print(dutyCycle1, 4);
  Serial.print(", ");
  Serial.print(dutyCycle2, 4);
  Serial.println(")%");
}

void mapDutyCycle()
{
  //////////////////////////////////////////
  // FS-i6X & FS-iA6B Duty Cycle Right Gimbal Readings
  // Channel 1 & 2
  double Lo1 = 0.0501; // Observed dutyCycle Value = 0.0501
  double Hi1 = 0.1001; // Observed dutyCycle Value = 0.1001
  double Lo2 = 0.0505; // Observed dutyCycle Value = 0.0505
  double Hi2 = 0.1000; // Observed dutyCycle Value = 0.1000
                       //////////////////////////////////////////

  double dutyCycle = flysky.DutyCycle();
  double x = nmr::map(dutyCycle, Lo1, Hi1, 0.0, 1.0);
  if (x < 0.0)
    x = 0.0;
  if (x > 1.0)
    x = 1.0;

  dutyCycle = flysky.DutyCycle(2);
  double y = nmr::map(dutyCycle, Lo2, Hi2, 0.0, 1.0);
  if (y < 0.0)
    y = 0.0;
  if (y > 1.0)
    y = 1.0;

  Serial.print("Normalized(x, y) = (");
  Serial.print(x, 4);
  Serial.print(", ");
  Serial.print(y, 4);
  Serial.println(")");
}

void debugDrawLine()
{
  Serial.println("---------------------");
}

void selfTest_Step1()
{
  if (debugTimer.isTimer(1000))
  {
    bool hasTwoPins = false;

    debugDrawLine();

    testFrequency(hasTwoPins);
    testDutyCycle(hasTwoPins);
    // testDutyCyclePercent(hasTwoPins);
  }
}

void testFSi6X_Step2()
{
  // bool hasTwoPins = true;

  if (debugTimer.isTimer(1000))
  {
    debugDrawLine();

    // Frequency should be 50HZ
    // testFrequency(hasTwoPins);

    // Duty Cycle Unknown
    // Write down the lows and highs...
    // See mapDutyCycle() function.
    // testDutyCycle(hasTwoPins);

    // Normailize Duty Cycle
    mapDutyCycle();

    // Same but uses Percent value...
    // testDutyCyclePercent(hasTwoPins);
  }
}

void loop()
{
  flysky.Update();

  // selfTest_Step1(); /////////////////// Self-Test OK
  testFSi6X_Step2(); ///////////////////// Right Gimbal OK
}
