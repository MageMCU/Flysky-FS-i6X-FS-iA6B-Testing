## Testing Flysky FS-i6X Transmitter and FS-iA6B Receiver

- namespace ***uno***

## Index

- [About - Testing FS-i6X and FS-iA6B ](#about-testing)
- [MCU Chips](#mcu-chips)

## About Testing <a name="about-testing"></a>

The *Testing FS-i6X and FS-iA6B* products by Flysky is about using code and the Arduino Uno to test (or understand) how the Pulse Width Modulation (PWM) performs with the FS-iA6B Receiver using the default settings on the FS-i6X Transmitter.

The Radio Control is quite inexpensive. Only two test were made to determine whether the testing can be accomplished using Arduino Uno. The first test was a self-test with itself on the Arduino Uno. The reason for the self-test was that the frequencies for Arduino's PWM pins are known. This would be used as a check whether the source code would be viable for testing Flysky. 

The second test was similar to the self-test except FS-iA6B channels 1 and 2 were used at the same time for testing its PWM and the functionality of the right gimbal (joystick).

The Class FSi6X is the heart of the testing. The map() function was also used to normalize its values... See the source code and lab-notes for further information.


## MCU chips  <a name="mcu-chips"></a>

This MCU chip **Atmega328P** is well known and the price is affordable as well as most of the robotic hardware that is used here. The **cheaper** ... the **better**... Knowledge for those who are **starving** to learn.

More testing to come.

revision 20211114 (Article Title)<br/>
initial upload 20211012

## Disclaimer and Terms

Please follow the ***Disclaimer*** and ***Terms*** in the ***Testing FS-i6X and FS-iA6B*** Depository.
