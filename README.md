# Waveform Generator

This project is an implementation of a waveform generator using an Arduino Uno R3.

I don't test it at the maximum, but I can send 3 sinus at 100 Hz maximum at the same time. It's important to note than the output is a pwm for 0 to 5V, so to have a real sinus you should use a RC filter.

Here is the resultat read by [my own oscilloscope](https://github.com/ThibaultTostain/oscilloscope) of the output :

![oscilloscope](/oscilloscope.png)