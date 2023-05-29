#include <Servo.h>
#include <SoftwareSerial.h>
#define pinServo 8
#define pinSerialRX 10
#define pinSerialTX 11

Servo cancela;
SoftwareSerial serialBT(pinSerialRX, pinSerialTX);

String comando;

void setup() {
  Serial.begin(9600);
  serialBT.begin(38400);
  cancela.attach(pinServo);
  cancela.write(120);

}

void loop() {

if (serialBT.available()) {
  char recebido = serialBT.read();
  
  comando += recebido;
  if (recebido == ';'){

    if (comando == "A;") {
      cancela.write(120);
    }else if (comando == "F;") {
      cancela.write(10);
    }else{
      cancela.write(comando.toInt());
    }

    comando = "";

  }
  }

}
