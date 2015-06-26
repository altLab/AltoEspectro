
// Graphing sketch


// This program takes ASCII-encoded strings
// from the serial port at 9600 baud and graphs them. It expects values in the
// range 0 to 1023, followed by a newline, or newline and carriage return

// Created 20 Apr 2005
// Updated 18 Jan 2008
// by Tom Igoe
// This example code is in the public domain.

import processing.serial.*;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph

void setup () {
  // set the window size:
  size(1000, 600);        

  // List all the available serial ports
  println(Serial.list());
  // I know that the first port in the serial list on my mac
  // is always my  Arduino, so I open Serial.list()[0].
  // Open whatever port is the one you're using.
  myPort = new Serial(this, Serial.list()[0], 9600);
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
  // set inital background:
  background(0);
}
void draw () {
  // everything happens in the serialEvent()
  // but we have to draw the lines of reference for the temperature scales
  stroke(255, 255, 255);
  line(0, height*25/30, width, height*25/30);
  text("25", 0, height - height*25/30);
  line(0, height*20/30, width, height*20/30);
  text("20", 0, height - height*20/30);
  line(0, height*15/30, width, height*15/30);
  text("15", 0, height - height*15/30);
  line(0, height*10/30, width, height*10/30);
  text("10", 0, height - height*10/30);
  line(0, height*5/30, width, height*5/30);
  text(" 5", 0, height - height*5/30);
  line(0, 0, width, 0);
  text("-5", 0, 0);
  line(0, height*-5/30, width, height*-5/30);
}

void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    // trim off any whitespace:

    inString = trim(inString);

    float inByte1 = parseFloat(inString.substring(0, 4));
    String tstr = inString.substring(0, 4);  
    print(tstr);
    print(' ');
    float inByte2 = parseFloat(inString.substring(4));
    String tstr1 = inString.substring(4);
    println(tstr1);
    println(inString.length());

    //    println(inString);  

    //      print(inByte1);
    //      println(inByte2);

    // convert to an int and map to the screen height:
    //float inByte = float(inString); 
    inByte1 = map(inByte1, -5, 30, 0, height);
    inByte2 = map(inByte2, -5, 30, 0, height);

    smooth();
    // draw the line:
    stroke(255, 13, 13);
    point(xPos, height - inByte1);

    stroke(13, 255, 13);
    point(xPos, height - inByte2);


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

