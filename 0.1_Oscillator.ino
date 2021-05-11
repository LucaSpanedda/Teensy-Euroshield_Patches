#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// This sketch demonstrates the simplest possible generation of a Sawtooth waveform
// from OUT 1/2

// Supported Waveforms
// from the teensy audio library: https://github.com/PaulStoffregen/Audio

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
  // set standard frequency of the waveform
  waveform1.frequency(400);
  // set standard amplitude of the waveform
  waveform1.amplitude(0.99);
}

// loop execute the operations continuosly (in loop)
// after the setup
void loop() {}

// in this program we have used only the setup because we use fixed values
