# HT1632C_DEDP131112
An update and hacked library to make DEDP131112 12V LED matrix from Sure Electronics work

The initial HT1632 code was obtained from here:
  https://github.com/gauravmm/HT1632-for-Arduino
  Additional notes for http://store3.sure-electronics.com/de-dp13119
  Using this info
  http://cdn2.boxtec.ch/pub/sure/LED_Dot_Matrix-Display_Users-Guide.pdf
  Need to also clock through the CS
  Need to clock through 8 digital HIGH to get the correct CS as low to all the boards
  
  This has been added to this HT1632C arduino library, but probably not in a very nice way!
  
  This has been tested with two boards in series and each can be controlled. Up to 8 boards can feasibly be used, but the code will need updates to get that working.
  
  This code is supplied just to get you started, as I found it very hard to find information about this issue. It's not a fully tested amazing library - but I can now get all the functions from the initial library working on my LED displays.
  

