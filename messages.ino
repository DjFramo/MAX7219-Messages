//22.06.2026

//We always have to include the library
#include "LedControl.h"
#include <Vector.h>

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,10,11,1);

const int MAX_CHAR_ELEMENTS = 300;
const int MAX_BYTE_ELEMENTS = 2000;



void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,0);
  /* and clear the display */
  lc.clearDisplay(0);

  Serial.begin(9600);
}




Vector<byte> createString(String quote) {

  char charStorageArray[MAX_CHAR_ELEMENTS];
  Vector<char> text(charStorageArray);

  byte byteStorageArray[MAX_BYTE_ELEMENTS];
  Vector<byte> textBytes(byteStorageArray);


  for (int i = 0; i < quote.length(); i++) {
    text.push_back(quote[i]); 
  }

  for (int i = 0; i < 8; i++) {
    textBytes.push_back(B00000000);
  }

  bool quotation = false;

  for (int i = 0; i < text.size(); i++) {

    switch (text[i]) {
      case 'a':
        textBytes.push_back(B00111110);
        textBytes.push_back(B00100010);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000000);
        break;
      case 'b':
        textBytes.push_back(B01111110);
        textBytes.push_back(B00001010);
        textBytes.push_back(B00001110);
        textBytes.push_back(B00000000);
        break;
      case 'c':
        textBytes.push_back(B00111110);
        textBytes.push_back(B00100010);
        textBytes.push_back(B00100010);
        textBytes.push_back(B00000000);
        break;
      case 'd':
        textBytes.push_back(B00001110);
        textBytes.push_back(B00001010);
        textBytes.push_back(B01111110);
        textBytes.push_back(B00000000);
        break;
      case 'e':
        textBytes.push_back(B00111110);
        textBytes.push_back(B00101010);
        textBytes.push_back(B00111010);
        textBytes.push_back(B00000000);
        break;
      case 'f':
        textBytes.push_back(B00010000);
        textBytes.push_back(B01111110);
        textBytes.push_back(B01010000);
        textBytes.push_back(B00000000);
        break;
      case 'g':
        textBytes.push_back(B00111001);
        textBytes.push_back(B00101001);
        textBytes.push_back(B00111111);
        textBytes.push_back(B00000000);
        break;
      case 'h':
        textBytes.push_back(B01111110);
        textBytes.push_back(B00001000);
        textBytes.push_back(B00001110);
        textBytes.push_back(B00000000);
        break;
      case 'i':
        textBytes.push_back(B01011110);
        textBytes.push_back(B00000000);
        break;
      case 'j':
        textBytes.push_back(B00000001);
        textBytes.push_back(B00000001);
        textBytes.push_back(B01011111);
        textBytes.push_back(B00000000);
        break;
      case 'k':
        textBytes.push_back(B01111110);
        textBytes.push_back(B00001000);
        textBytes.push_back(B00110110);
        textBytes.push_back(B00000000);
        break;
      case 'l':
        textBytes.push_back(B01111100);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000000);
        break;
      case 'm':
        textBytes.push_back(B00111110);
        textBytes.push_back(B00100000);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00100000);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000000);
        break;
      case 'n':
        textBytes.push_back(B00111110);
        textBytes.push_back(B00100000);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000000);
        break;
      case 'o':
        textBytes.push_back(B00111110);
        textBytes.push_back(B00100010);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000000);
        break;
      case 'p':
        textBytes.push_back(B00111111);
        textBytes.push_back(B00101000);
        textBytes.push_back(B00111000);
        textBytes.push_back(B00000000);
        break;
      case 'q':
        textBytes.push_back(B00111000);
        textBytes.push_back(B00101000);
        textBytes.push_back(B00111111);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000100);
        textBytes.push_back(B00000000);
        break;
      case 'r':
        textBytes.push_back(B00111110);
        textBytes.push_back(B00010000);
        textBytes.push_back(B00100000);
        textBytes.push_back(B00010000);
        textBytes.push_back(B00000000);
        break;
      case 's':
        textBytes.push_back(B00111010);
        textBytes.push_back(B00101010);
        textBytes.push_back(B00101110);
        textBytes.push_back(B00000000);
        break;
      case 't':
        textBytes.push_back(B00010000);
        textBytes.push_back(B01111110);
        textBytes.push_back(B00010010);
        textBytes.push_back(B00000000);
        break;
      case 'u':
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000000);
        break;
      case 'v':
        textBytes.push_back(B00111100);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00111100);
        textBytes.push_back(B00000000);
        break;
      case 'w':
        textBytes.push_back(B00111100);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00111100);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00111100);
        textBytes.push_back(B00000000);
        break;
      case 'x':
        textBytes.push_back(B00110110);
        textBytes.push_back(B00001000);
        textBytes.push_back(B00110110);
        textBytes.push_back(B00000000);
        break;
      case 'y':
        textBytes.push_back(B00111001);
        textBytes.push_back(B00001001);
        textBytes.push_back(B00111111);
        textBytes.push_back(B00000000);
        break;
      case 'z':
        textBytes.push_back(B00100110);
        textBytes.push_back(B00101010);
        textBytes.push_back(B00110010);
        textBytes.push_back(B00000000);
        break;
      case '1':
        textBytes.push_back(B00100010);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000000);
        break;
      case '2':
        textBytes.push_back(B00101110);
        textBytes.push_back(B00101010);
        textBytes.push_back(B00111010);
        textBytes.push_back(B00000000);
        break;
      case '3':
        textBytes.push_back(B00101010);
        textBytes.push_back(B00101010);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000000);
        break;
      case '4':
        textBytes.push_back(B00111000);
        textBytes.push_back(B10001000);
        textBytes.push_back(B10111110);
        textBytes.push_back(B00000000);
        break;
      case '5':
        textBytes.push_back(B00111010);
        textBytes.push_back(B00101010);
        textBytes.push_back(B00101110);
        textBytes.push_back(B00000000);
        break;
      case '6':
        textBytes.push_back(B00111110);
        textBytes.push_back(B00101010);
        textBytes.push_back(B00101110);
        textBytes.push_back(B00000000);
        break;
      case '7':
        textBytes.push_back(B00100000);
        textBytes.push_back(B00100000);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000000);
        break;
      case '8':
        textBytes.push_back(B00111110);
        textBytes.push_back(B00101010);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000000);
        break;
      case '9':
        textBytes.push_back(B00111000);
        textBytes.push_back(B00101000);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000000);
        break;
      case '0':
        textBytes.push_back(B00111110);
        textBytes.push_back(B00100010);
        textBytes.push_back(B00111110);
        textBytes.push_back(B00000000);
        break;
      case ' ':
        textBytes.push_back(B00000000);
        textBytes.push_back(B00000000);
        break;
      case '!':
        textBytes.push_back(B11111010);
        textBytes.push_back(B00000000);
        break;
      case '@':
        textBytes.push_back(B11111111);
        textBytes.push_back(B10000001);
        textBytes.push_back(B10111101);
        textBytes.push_back(B10100101);
        textBytes.push_back(B10111101);
        textBytes.push_back(B10000101);
        textBytes.push_back(B11111101);
        textBytes.push_back(B00000000);
        break;
      case '#':
        textBytes.push_back(B00101000);
        textBytes.push_back(B11111110);
        textBytes.push_back(B00101000);
        textBytes.push_back(B11111110);
        textBytes.push_back(B00101000);
        textBytes.push_back(B00000000);
        break;
      case '$':
        textBytes.push_back(B01110100);
        textBytes.push_back(B01010100);
        textBytes.push_back(B11111110);
        textBytes.push_back(B01010100);
        textBytes.push_back(B01011100);
        textBytes.push_back(B00000000);
        break;
      case '%':
        textBytes.push_back(B00110010);
        textBytes.push_back(B00110100);
        textBytes.push_back(B00001000);
        textBytes.push_back(B00010110);
        textBytes.push_back(B00100110);
        textBytes.push_back(B00000000);
        break;
      case '^':
        textBytes.push_back(B00100000);
        textBytes.push_back(B01000000);
        textBytes.push_back(B10000000);
        textBytes.push_back(B01000000);
        textBytes.push_back(B00100000);
        textBytes.push_back(B00000000);
        break;
      case '&':
        textBytes.push_back(B01101100);
        textBytes.push_back(B10010010);
        textBytes.push_back(B01101010);
        textBytes.push_back(B00000100);
        textBytes.push_back(B00001010);
        textBytes.push_back(B00000000);
        break;
      case '*':
        textBytes.push_back(B01010000);
        textBytes.push_back(B11100000);
        textBytes.push_back(B01010000);
        textBytes.push_back(B00000000);
        break;
      case '(':
        textBytes.push_back(B01111110);
        textBytes.push_back(B10000001);
        textBytes.push_back(B10000001);
        textBytes.push_back(B00000000);
        break;
      case ')':
        textBytes.push_back(B10000001);
        textBytes.push_back(B10000001);
        textBytes.push_back(B01111110);
        textBytes.push_back(B00000000);
        break;
      case '-':
        textBytes.push_back(B00001000);
        textBytes.push_back(B00001000);
        textBytes.push_back(B00001000);
        textBytes.push_back(B00000000);
        break;
      case '_':
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000000);
        break;
      case '=':
        textBytes.push_back(B00010100);
        textBytes.push_back(B00010100);
        textBytes.push_back(B00010100);
        textBytes.push_back(B00000000);
        break;
      case '+':
        textBytes.push_back(B00001000);
        textBytes.push_back(B00011100);
        textBytes.push_back(B00001000);
        textBytes.push_back(B00000000);
        break;
      case '{':
        textBytes.push_back(B00001000);
        textBytes.push_back(B01110110);
        textBytes.push_back(B10000001);
        textBytes.push_back(B10000001);
        textBytes.push_back(B00000000);
        break;
      case '}':
        textBytes.push_back(B10000001);
        textBytes.push_back(B10000001);
        textBytes.push_back(B01110110);
        textBytes.push_back(B00001000);
        textBytes.push_back(B00000000);
        break;
      case '\\':
        textBytes.push_back(B01000000);
        textBytes.push_back(B00100000);
        textBytes.push_back(B00010000);
        textBytes.push_back(B00001000);
        textBytes.push_back(B00000100);
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000000);
        break;
      case '|':
        textBytes.push_back(B01111110);
        textBytes.push_back(B00000000);
        break;
      case ';':
        textBytes.push_back(B00000001);
        textBytes.push_back(B00010110);
        textBytes.push_back(B00000000);
        break;
      case ':':
        textBytes.push_back(B00100100);
        textBytes.push_back(B00000000);
        break;
      case '\'':
        textBytes.push_back(B00100000);
        textBytes.push_back(B11000000);
        textBytes.push_back(B00000000);
        break;
      case '"':
        if (quotation == false) {
          quotation = true;
          textBytes.push_back(B01100000);
          textBytes.push_back(B10000000);
          textBytes.push_back(B01100000);
          textBytes.push_back(B10000000);
          textBytes.push_back(B00000000);
        }
        else {
          quotation = false;
          textBytes.push_back(B00100000);
          textBytes.push_back(B11000000);
          textBytes.push_back(B00100000);
          textBytes.push_back(B11000000);
          textBytes.push_back(B00000000);
        }
        break;
      case ',':
        textBytes.push_back(B00000001);
        textBytes.push_back(B00000110);
        textBytes.push_back(B00000000);
        break;
      case '<':
        textBytes.push_back(B00001000);
        textBytes.push_back(B00010100);
        textBytes.push_back(B00100010);
        textBytes.push_back(B01000001);
        textBytes.push_back(B00000000);
        break;
      case '.':
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000000);
        break;
      case '>':
        textBytes.push_back(B01000001);
        textBytes.push_back(B00100010);
        textBytes.push_back(B00010100);
        textBytes.push_back(B00001000);
        textBytes.push_back(B00000000);
        break;
      case '/':
        textBytes.push_back(B00000010);
        textBytes.push_back(B00000100);
        textBytes.push_back(B00001000);
        textBytes.push_back(B00010000);
        textBytes.push_back(B00100000);
        textBytes.push_back(B01000000);
        textBytes.push_back(B00000000);
        break;
      case '?':
        textBytes.push_back(B01011010);
        textBytes.push_back(B01010000);
        textBytes.push_back(B01110000);
        textBytes.push_back(B00000000);
        break;
      case '`':
        textBytes.push_back(B01110000);
        textBytes.push_back(B11111000);
        textBytes.push_back(B11111100);
        textBytes.push_back(B01111110);
        textBytes.push_back(B11111100);
        textBytes.push_back(B11111000);
        textBytes.push_back(B01110000);
        textBytes.push_back(B00000000);
        break;
      case '~':
        dance();
        break;
    }
  }

  return textBytes;
}



void writeMessageOnMatrix() {
  
  byte byteStorageArray[MAX_BYTE_ELEMENTS];
  Vector<byte> message(byteStorageArray);

  for (int i = 0; i < 4; i++) {
    message.push_back(B01000010);
    message.push_back(B00011000);
  }


  while (1) {

    if (Serial.available()) {
      String quote = Serial.readStringUntil('\n');
      quote.toLowerCase();
      message = createString(quote);
      Serial.println("Message Accepted!");
      Serial.print("Received message: ");
      Serial.println(quote);
    }
    else {
      Serial.println("Awaiting new message");
    }

      
    for (int i = 0; i < (message.size() - 7); i++) {
      lc.setColumn(0,0,message[i]);
      lc.setColumn(0,1,message[i+1]);
      lc.setColumn(0,2,message[i+2]);
      lc.setColumn(0,3,message[i+3]);
      lc.setColumn(0,4,message[i+4]);
      lc.setColumn(0,5,message[i+5]);
      lc.setColumn(0,6,message[i+6]);
      lc.setColumn(0,7,message[i+7]);
      delay(150);
    }
    delay(5000);
  }
}



void dance() {

  const byte dance[] = {B00000000, B00001000, B01101011, B10011100};

  for (int i = 0; i < 16; i++) {
    lc.setColumn(0,0,dance[0]);
    lc.setColumn(0,1,dance[1]);
    lc.setColumn(0,2,dance[2]);
    lc.setColumn(0,3,dance[3]);
    lc.setColumn(0,4,dance[3]);
    lc.setColumn(0,5,dance[2]);
    lc.setColumn(0,6,dance[1]);
    lc.setColumn(0,7,dance[0]);
    delay(250);


    lc.setColumn(0,0,dance[1]);
    lc.setColumn(0,1,dance[2]);
    lc.setColumn(0,2,dance[3]);
    lc.setColumn(0,3,dance[3]);
    lc.setColumn(0,4,dance[2]);
    lc.setColumn(0,5,dance[1]);
    lc.setColumn(0,6,dance[0]);
    lc.setColumn(0,7,dance[0]);
    delay(250);


    lc.setColumn(0,0,dance[0]);
    lc.setColumn(0,1,dance[1]);
    lc.setColumn(0,2,dance[2]);
    lc.setColumn(0,3,dance[3]);
    lc.setColumn(0,4,dance[3]);
    lc.setColumn(0,5,dance[2]);
    lc.setColumn(0,6,dance[1]);
    lc.setColumn(0,7,dance[0]);
    delay(250);


    lc.setColumn(0,0,dance[0]);
    lc.setColumn(0,1,dance[0]);
    lc.setColumn(0,2,dance[1]);
    lc.setColumn(0,3,dance[2]);
    lc.setColumn(0,4,dance[3]);
    lc.setColumn(0,5,dance[3]);
    lc.setColumn(0,6,dance[2]);
    lc.setColumn(0,7,dance[1]);
    delay(250);


    lc.setColumn(0,0,dance[0]);
    lc.setColumn(0,1,dance[1]);
    lc.setColumn(0,2,dance[2]);
    lc.setColumn(0,3,dance[3]);
    lc.setColumn(0,4,dance[3]);
    lc.setColumn(0,5,dance[2]);
    lc.setColumn(0,6,dance[1]);
    lc.setColumn(0,7,dance[0]);
    delay(350);
  }
}



void loop() { 
  writeMessageOnMatrix();
}
