// This sketch demonstrates a FAUST (GRAME) code compilated for the teensy
// and imported into this sketch.
// whe are using a waveform coded in FAUST that goes to the OUT 1/2 for this example.


// import the libraries
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
//
// import the exported code from FAUST: (.cpp and .h files)
#include "FAUST_Code.h"


// PIN 20 and 21:
// Knobs 1 and 2 of the board - declared here 
int upperPotInput = 20;
int lowerPotInput = 21;


// create an object from the files --> name the object
FAUST_Code  FAUST_Code;
// audio shield: headphones & line-out
AudioOutputI2S out;
// import the audio shield for the ADC and DAC connections
AudioControlSGTL5000 audioShield;


// WIRES CONNECTIONS - of the objects:
//
// from FAUST_Code,0 (out 1) to out,0 (out 1 - DAC of the shield)
AudioConnection patchCord0(FAUST_Code,0,out,0);
// from FAUST_Code,0 (out 1) to out,1 (out 2 - DAC of the shield)
AudioConnection patchCord1(FAUST_Code,0,out,1);


// CODE:
// setup of the code (1 single cycle when the program start)
void setup() 
{
  // select a memory space on the disk
  AudioMemory(2);
  // enable the audio shield
  audioShield.enable();
  // select a master volume for the output
  audioShield.volume(0.8);
}

// loop of the code (reading in loop, after the setup of the code)
void loop() 
{
  // read the PIN 20
int upperPotValue = analogRead(upperPotInput);
  // use the PIN 20 value to give a parameter here
  FAUST_Code.setParamValue("freq",float(upperPotValue)/1);


// read the PIN 21
int lowerPotValue = analogRead(lowerPotInput);
  // use the PIN 21 value to give a parameter here
  FAUST_Code.setParamValue("gain",float(lowerPotValue)/1024);

  delay(100);
}
