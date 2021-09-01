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
  // set a parameter for the control
  FAUST_Code.setParamValue("freq",random(50,1000));
  // the parameter is read (and refreshed) every 500ms.
  delay(500);
}
