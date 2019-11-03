/********************************************************
  /****** Scalextric Lap Counter Unit ********************
  /****** by Matt Little **********************************
  /****** Date: 13/08/2019 **********************************
  /****** info@re-innovation.co.uk ************************
  /****** www.re-innovation.co.uk *************************
  /********************************************************

  /*
  Code for Sure 8 x 32 LED matrix HT1632 controller board 12V Type: DE-DP131112V200
  These have a CS and a CS CLOCK to control up to 8 boards.

  D0:
  D1:
  D2:
  D3:
  D4: CS pin
  D5:
  D6:
  D7: WR
  B8: DATA
  B9: LED - Blink!
  D10: CS_CLK
  D11:
  D12:
  D13:

  This is code for a plug-in board for these Sure Electronics LED displays.
  http://www.sureelectronics.net/goods.php?id=1119

  The PCB has been developed by Renewable Energy Innovation.
  http://www.re-innovation.co.uk/

  The HT1632 code was obtained from here:

  https://github.com/gauravmm/HT1632-for-Arduino

  Additional notes for http://store3.sure-electronics.com/de-dp13119
  Using this info
  http://cdn2.boxtec.ch/pub/sure/LED_Dot_Matrix-Display_Users-Guide.pdf
  Need to also clock through the CS
  Need to clock through 8 digital HIGH to get the correct CS as low to all the boards
  In future this will need clocking in correctly
  This has been added to this HT1632C arduino library, but probably not in a very nice way!



  Code started:  18/10/19
  By:  Matt Little (matt@re-innovation.co.uk)

  TO DO:
  DONE - Do correct CS and CS_CLK function - Got working by pulseing CS line 3/11/2019
  DONE - Sort out sending to different LED boards
  Sort out code to fit with library - Future work!!

*/

#include "HT1632.h"
#include "font_5x4.h"
#include "font_8x4.h"
#include "images.h"


// ******* Variables *************

int LED = 9;
int WR_CLK = 7;
int DATA = 8;
int test = 0;

// ******* END Variables *************

void setup() {
  Serial.begin(9600);    // Set up a serial output for data display and changing parameters
  pinMode(LED, OUTPUT);

  // Want to set CS high and then clock through high to the correct module

  //  // Where pinCS1, pinWR and pinDATA are the numbers of the output pins
  //  // that are connected to the appropriate pins on the HT1632.
  //  HT1632.begin(pinCS1, pinWR, pinDATA);
  //  This has been changed for these displays to: CS, CS_CLK,WR_CLK,DATA
  //  HT1632.begin(pinCS, pinWR, pinDATA);
  // In this example the pinCS is not used - CS and CS_CLK are set in HT1632.h.
  HT1632.begin(5, WR_CLK, DATA);
  HT1632.clear(); // This zeroes out the internal memory.
  HT1632.render(); // This updates the screen display.
  delay(100);
  digitalWrite(LED , HIGH);
}

void loop ()
{
  // The definitions for IMG_HEART and its width and height are available in images.h.
  // This step only performs the drawing in internal memory.
  digitalWrite(LED , HIGH);
  HT1632.drawImage(IMG_HEART, IMG_HEART_WIDTH,  IMG_HEART_HEIGHT, (OUT_SIZE - IMG_HEART_WIDTH) / 2, 0);
  HT1632.renderTarget(0);
  HT1632.render(); // This updates the display on the screen.

  HT1632.fillAll(); // This zeroes out the internal memory.
  HT1632.renderTarget(1);
  HT1632.render(); // This updates the screen displ

  delay(500);



  digitalWrite(LED , LOW);

  HT1632.clear(); // This zeroes out the internal memory.
  HT1632.renderTarget(0);
  HT1632.render(); // This updates the screen display.

  HT1632.clear(); // This zeroes out the internal memory.
  HT1632.renderTarget(1);
  HT1632.render(); // This updates the screen display.
  delay(200);

  HT1632.fillAll();; // This zeroes out the internal memory.
  HT1632.renderTarget(0);
  HT1632.render(); // This updates the screen display.

  HT1632.clear(); // This zeroes out the internal memory.
  HT1632.drawImage(IMG_HEART, IMG_HEART_WIDTH,  IMG_HEART_HEIGHT, (OUT_SIZE - IMG_HEART_WIDTH) / 2, 0);
  HT1632.renderTarget(1);
  HT1632.render(); // This updates the display on the scre

  delay(500);

  HT1632.renderTarget(0);
  HT1632.clear(); // This zeroes out the internal memory.
  HT1632.render(); // This updates the screen display.
  HT1632.renderTarget(1);
  HT1632.clear(); // This zeroes out the internal memory.
  HT1632.render(); // This updates the screen displ
  delay(200);

  Serial.println(test);
  //  // Delay and slow things down
  //  delay(500);  // Slow things down
  test++;

}
