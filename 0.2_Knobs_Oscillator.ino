#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// This sketch demonstrates the generation of a waveform
// controlled with the 2 Knobs mounted on the Euroshield Board

// Supported Waveforms:
// WAVEFORM_SINE
// WAVEFORM_SAWTOOTH
// WAVEFORM_SAWTOOTH_REVERSE
// WAVEFORM_SQUARE
// WAVEFORM_TRIANGLE
// WAVEFORM_TRIANGLE_VARIABLE
// WAVEFORM_ARBITRARY
// WAVEFORM_PULSE
// WAVEFORM_SAMPLE_HOLD

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=110,75
AudioOutputI2S           audioOutput;        // audio shield: headphones & line-out
AudioConnection          patchCord1(waveform1, 0, audioOutput, 0);
AudioConnection          patchCord2(waveform1, 0, audioOutput, 1);
AudioControlSGTL5000 audioShield;
// GUItool: end automatically generated code

// PIN 20 and 21:
// Knobs 1 and 2 of the board - declared here 
int upperPotInput = 20;
int lowerPotInput = 21;

// setup execute the operations only one time
// at the start of the program
void setup()
{
  // enable audio shield
  audioShield.enable();
  // set standard output volume
  audioShield.volume(0.82);
  // allocate audio memory max.
  AudioMemory(15);
  // declare here waveform from the audio library
  waveform1.begin(WAVEFORM_SQUARE);
}

// loop execute the operations continuosly (in loop)
// after the setup
void loop() 
{
  // read the PIN 20
  int upperPotValue = analogRead(upperPotInput);
  // use the PIN 20 value to give a parameter here
  waveform1.frequency(float(upperPotValue) / 1);
// read the PIN 21
  int lowerPotValue = analogRead(lowerPotInput);
  // use the PIN 21 value to give a parameter here
  waveform1.amplitude(float(lowerPotValue) / 1024);
}
