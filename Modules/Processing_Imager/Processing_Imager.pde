
// Graphing sketch for Spetra


// This program takes ASCII-encoded strings
// from the serial port at 9600 baud and graphs them. It expects values in the
// range 0 to 1023, followed by a newline, or newline and carriage return

// Created 20 Apr 2005
// Updated 18 Jan 2008
// by Tom Igoe
// Refactored to read the output of the ClockGenerator_0_3_1.ino 
// by João Alveirinho Correia
// This example code is in the public domain.

import processing.serial.*;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
float dataValue = 0;
int count = 0;

void setup () {
  // set the window size:
  size(1024, 420);        

  // List all the available serial ports
  println(Serial.list());
  // I know that the first port in the serial list on my mac
  // is always my  Arduino, so I open Serial.list()[0].
  // Open whatever port is the one you're using.
  myPort = new Serial(this, Serial.list()[0], 1000000);
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
  // set inital background:
  background(0);
}
void draw () {
  // everything happens in the serialEvent()
  
}

void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {

    if (inString != "#1" || inString !="#2")
    {
      if (inString.length() == 5)
      {
        dataValue = parseFloat(inString.substring(0, 3));
        //println(inString);
      } else {
        dataValue = 0;
      }

      dataValue = map(dataValue, 280, 704, 0, 420);

      stroke(255, 13, 13);
      point(xPos, height - dataValue);

      // at the edge of the screen, go back to the beginning:
      if (xPos >= width) {
        xPos = 0;
        background(0);
      } else {
        // increment the horizontal position:
        xPos++;
      }
    }
  }
}

