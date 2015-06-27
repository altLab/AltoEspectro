/**
 * ControlP5 Button
 * this example shows how to create buttons with controlP5.
 * 
 * find a list of public methods available for the Button Controller 
 * at the bottom of this sketch's source code
 *
 * by Andreas Schlegel, 2012
 * www.sojamo.de/libraries/controlp5
 *
 */
 
import controlP5.*;
import processing.serial.*;

ControlP5 cp5;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
float dataValue = 0;
int count = 0;


int myColor = color(255);

int c1,c2;

float n,n1;


void setup() {
  size(1024,680);
  noStroke();
  cp5 = new ControlP5(this);
  
  // create a new button with name 'buttonA'
  cp5.addButton("Setup")
     .setValue(0)
     .setPosition(100,10)
     .setSize(133,19)
     ;
  
  // and add another 2 buttons
  cp5.addButton("Connect")
     .setValue(100)
     .setPosition(234,10)
     .setSize(133,19)
     ;
     
  cp5.addButton("Expose")
     .setPosition(367,10)
     .setSize(133,19)
     .setValue(0)
     ;

  // List all the available serial ports
  println(Serial.list());
  // I know that the first port in the serial list on my mac
  // is always my  Arduino, so I open Serial.list()[0].
  // Open whatever port is the one you're using.
  myPort = new Serial(this, Serial.list()[0], 1000000);
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');

  
}

void draw() {
  background(myColor);
  myColor = lerpColor(c1,c2,n);
  n += (1-n)* 0.1; 
}

public void controlEvent(ControlEvent theEvent) {
  println(theEvent.getController().getName());
  n = 0;
}

// function Connect will receive changes from 
// controller with name colorA
public void Connect(int theValue) {
  println("a button event from Connect: "+theValue);
}

// function Expose will receive changes from 
// controller with name Expose
public void Expose(int theValue) {
  myPort.write('C'); 
  println("a button event from Expose: "+theValue);
}

void serialEvent (Serial myPort) 
{
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

