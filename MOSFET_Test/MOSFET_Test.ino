#include "MOSFET.h"

MOSFET L1(8);
MOSFET L2(9);
MOSFET L3(10);

unsigned long programPeriod = 100; //in ms
unsigned long previousTime = 0;
int switchVar = 0;
int counter = 0;

uint8_t dc = 255;


void setup() {
  Serial.begin(9600);
  L2.initHfPwm(1);
  L1.off();
  L2.off();
  L3.off();

}

void loop() {
  //Rampe
  /*
     überprüfe Lüfter Datasheet auf was für eine Spannung sie maximal gedrosselt werden können
      --> beide auf 8V --> PWM: dc,min = 170
     Rampe ohne HF PWM
     Rampe mit HF PWM
     Vergleich
     Lüfter 2 funktioniert mit f=32kHz und bis zu 8 V
     Lüfter 3 funktioniert nicht mit 8V

  */

  if (millis() - previousTime >= programPeriod) {
    previousTime = millis();

    switch (switchVar) {
      case 0:

        L1.on();
        counter++;
        if ( counter == 170) {
          L1.off();
          counter = 0;
          switchVar = 5;
        }

        break;

      case 1:
        L2.pwm(dc);
        dc--;
        if ( dc == 170) {
          switchVar++;
        }

        break;

      case 2:

        L2.pwm(dc);
        dc++;
        if ( dc == 255) {
          L2.off();
          switchVar++;
        }
        break;

      case 3:
        L3.pwm(dc);
        dc--;
        if ( dc == 170) {
          switchVar++;
        }
        break;

      case 4:
        L3.pwm(dc);
        dc++;
        if ( dc == 255) {
          L3.off();
          switchVar = 0;
        }
        break;

      case 5:
        L2.pwm(170);
        counter++;
        if ( counter == 170) {
          L2.off();
          counter = 0;
          switchVar++;
        }
        break;

      case 6:
        L3.pwm(200);
        counter++;
        if ( counter == 170) {
          L3.off();
          counter = 0;
          switchVar = 0;
        }
        break;
    }

  }
}
