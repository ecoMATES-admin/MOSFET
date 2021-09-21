#ifndef MOSFET_H
#define MOSFET_H


class MOSFET{
  private:
    uint8_t _gate;

  public:
    MOSFET(uint8_t gate): _gate(gate)
    {};
    void on(){
      analogWrite(_gate, 255);
    };
    void off(){
      analogWrite(_gate, 0);
    };  
};


#endif
