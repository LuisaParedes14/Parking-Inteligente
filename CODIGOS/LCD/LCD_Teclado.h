// include the library code:
#include <LiquidCrystal.h>
// with the arduino pin number it is connected to
const int rs1 = 22, en1 = 24, d4_1 = 26, d5_1 = 28, d6_1 = 30, d7_1 = 32;
const int rs2 = 2, en2 = 3, d4_2 = 4, d5_2 = 5, d6_2= 6, d7_2 = 7;

LiquidCrystal lcd1(rs1, en1, d4_1, d5_1, d6_1, d7_1);
LiquidCrystal lcd2(rs2, en2, d4_2, d5_2, d6_2, d7_2);

#include <Adafruit_Keypad.h>
const byte ROWS = 4; // rows
const byte COLS = 4; // columns
//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {38, 40, 42, 44}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {46, 48, 50, 52}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);
