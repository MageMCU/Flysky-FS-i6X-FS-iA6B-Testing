# Testing Flysky FS-i6X Transmitter and FS-iA6B Receiver
- namespace ***uno***

## Archived
- I was disappointed with the FS-iA6B Receiver's output but to be fair, many radio receivers behave similarly. It was my hope that its output was similar to the Atmega328P MCU. Unforunately they're not even close to what I needed... Radio Controllers have its purpose but I needed more flexability.
- This project is dead...........
## About Testing <a name="about-testing"></a>
- The *Testing FS-i6X and FS-iA6B* products by Flysky is about using code and the Arduino Uno to test (or understand) how the Pulse Width Modulation (PWM) performs with the FS-iA6B Receiver using the default settings on the FS-i6X Transmitter.
- The Radio Control is quite inexpensive. Only two test were made to determine whether the testing can be accomplished using Arduino Uno. The first test was a self-test with itself on the Arduino Uno. The reason for the self-test was that the frequencies for Arduino's PWM pins are known. This would be used as a check whether the source code would be viable for testing Flysky. 
- The second test was similar to the self-test except FS-iA6B channels 1 and 2 were used at the same time for testing its PWM and the functionality of the right gimbal (joystick).
- The Class FSi6X is the heart of the testing. The map() function was also used to normalize its values... See the source code and lab-notes for further information.

## Disclaimer and Terms
- Please follow the ***Disclaimer*** and ***Terms*** in the ***Testing FS-i6X and FS-iA6B*** Depository.
