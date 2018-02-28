/*-----------------------------------------
 "segNumDisplay.ino"
 Simple 7 segment display controller code.
-----------------------------------------*/

byte segmentCodes[10][10] = {
  //0  1  2  3  4  x  x  5  6  7 - pins
  { 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 }, // = 0
  { 1, 1, 0, 1, 0, 0, 0, 1, 1, 1 }, // = 1
  { 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 }, // = 2
  { 0, 1, 0, 1, 0, 0, 0, 0, 1, 0 }, // = 3
  { 1, 1, 0, 1, 0, 0, 0, 1, 0, 0 }, // = 4
  { 0, 1, 0, 1, 1, 0, 0, 0, 0, 0 }, // = 5
  { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 }, // = 6
  { 1, 1, 0, 1, 0, 0, 0, 0, 1, 1 }, // = 7
  { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // = 8
  { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 }  // = 9
};                                  // - digit


void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  TXLED1;
  RXLED1;
}

void loop() {
  int sensValue = analogRead(A3)*0.1;
  writeNum(sensValue);
}

void writeNum(int digit) {
  if (digit > 99) {
    digit = 99;
  } else if (digit < 0) {
    digit = 0;
  }
  int firstDigit  = digit * 0.1;
  int secondDigit = digit - firstDigit * 10;

  for (int segPin = 0; segPin < 10; ++segPin) {
    digitalWrite(segPin, segmentCodes[firstDigit][segPin]);
    digitalWrite(5, 0);
    digitalWrite(6, 1);
    delay(1);
    digitalWrite(segPin, 1);
  }
  for (int segPin = 0; segPin < 10; ++segPin) {
    digitalWrite(segPin, segmentCodes[secondDigit][segPin]);
    digitalWrite(5, 1);
    digitalWrite(6, 0);
    delay(1);
    digitalWrite(segPin, 1);
  }
}








