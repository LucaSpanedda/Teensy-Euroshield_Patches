// This sketch demonstrates a FAUST (GRAME) code used for DSP on teensy
// whe are using the ADC, DSP into FAUST and after send the signal to DAC.


// import the libraries
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
//
// import the exported code from FAUST: (.cpp and .h files)
#include "ADC_FAUST_DAC.h"


// create an object from the files --> name the object
ADC_FAUST_DAC  ADC_FAUST_DAC;
// audio shield INPUT
AudioInputI2S in;
// audio shield OUTPUT
AudioOutputI2S out;
// import the audio shield for the ADC and DAC connections
AudioControlSGTL5000 audioShield;


// WIRES CONNECTIONS - of the objects:
//
// from the ADC INPUT 1 (0) to the FAUST code INPUT 1 (0)
AudioConnection patchCord0(in,0,ADC_FAUST_DAC,0);
// from the ADC INPUT 2 (1) to the FAUST code INPUT 2 (1)
AudioConnection patchCord1(in,1,ADC_FAUST_DAC,1);
// from the FAUST code OUTPUT 1 (0) to the DAC OUTPUT 1 (0)
AudioConnection patchCord2(ADC_FAUST_DAC,0,out,0);
// from the FAUST code OUTPUT 2 (1) to the DAC OUTPUT 2 (1)
AudioConnection patchCord3(ADC_FAUST_DAC,1,out,1);


// CODE:
// setup of the code (1 single cycle when the program start)
void setup() 
{
  // select a memory space on the disk
  AudioMemory(6);
  // enable the audio shield
  audioShield.enable();
  // select a master volume for the output
  audioShield.volume(0.98);
}

// loop of the code (reading in loop, after the setup of the code)
void loop() 
{}
