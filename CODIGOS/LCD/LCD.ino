/*Parking Inteligente*/
#include <Servo.h>
Servo Talanquera;
bool Camara = false;
bool Disponible = false;
String TipoAuto;
int Task = 0;
String Lugar = "";
#define SensorEntrada  35
bool Ingresando = false;

#include "LCD_Teclado.h"
#include "Funciones.h"

void setup() {
  Serial.begin(115200);
  
  lcd1.begin(16, 2);
  lcd2.begin(16, 2);
  MensajeTareas(Task);
  customKeypad.begin();
  Talanquera.attach(10);
  delay(10);
  Talanquera.write(0);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
}

void loop() {
  bool SI = digitalRead(SensorEntrada);
  if (SI == 1 && Task == 0) {
    Task = 1;
    MensajeTareas(Task);
    Disponible = false;
    TipoAuto = "";
    Lugar = "";
    Ingresando = false;
  } else if (SI == 0 && Task > 0){
    Task = 0;
    MensajeTareas(Task);
  }
  customKeypad.tick();
  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    if (Task == 1) {
      if((char)e.bit.KEY == '*') {
        Serial.println("Clasificar");
        Task = 2;
        MensajeTareas(Task);
      }
    }
    if (Task == 3) {
      if((char)e.bit.KEY == '*') {
        Serial.println("Asignar");
        Task = 4;
        MensajeTareas(Task);
      }
    }
    if (Task == 5) {
      if((char)e.bit.KEY == '*') {
        Task = 6;
        MensajeTareas(6);
        Talanquera.write(90);
        digitalWrite(11, HIGH);
        Ingresando = true;
      }
    }
    if (Task > 1) {
      if((char)e.bit.KEY == '#') {
        Task = 0;
        lcd1.clear();
        lcd2.clear();
        MensajeTareas(Task);
      }
    }
  }
  if (Serial.available()>0) {
    String Dato = Serial.readString();
    Dato = Dato.substring(0, Dato.length()-2);
    if (Task == 2) {
      if (Dato.equals("Angosto") || Dato == "Ancho") {
        TipoAuto = Dato;
        Task = 3;
        MensajeTareas(Task);
      }
    }
    if (Task == 4) {
      if (Dato != "No disponible") {
        Lugar = Dato;
        Disponible = true;
      } else {
        Disponible = false;
      }
      Task = 5;
      MensajeTareas(Task);
    }
  }
  SI = digitalRead(SensorEntrada);
  if (Task == 6 && Ingresando && SI == 0) {
    Task = 0;
    MensajeTareas(Task);
    Talanquera.write(0);
    digitalWrite(11, LOW);
  }
}
