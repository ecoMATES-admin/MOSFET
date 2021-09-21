#ifndef MOSFET_H
#define MOSFET_H

// High Frequncy Mode wird nur auf Pin 9 und 10 unterstützt, denn nur Timer 1 wird verändert
class MOSFET{
  private:
    uint8_t _gate;
    bool _hfPwm;
    const byte _mask = B11111000;
    int _prescale = 2;

  public:
    MOSFET(uint8_t gate, bool hfPwm): _gate(gate), _hfPwm(hfPwm)
    {
      if(_hfPwm){
        TCCR1B = (TCCR1B & _mask)| _prescale;
      }
    };
    void on(){
      analogWrite(_gate, 255);
    };
    void off(){
      analogWrite(_gate, 0);
    };
    void pwm(uint8_t dc){
      analogWrite(_gate, dc); 
    }
};


#endif
