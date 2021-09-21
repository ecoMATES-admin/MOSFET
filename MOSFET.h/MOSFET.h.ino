#ifndef MOSFET_H
#define MOSFET_H


class MOSFET{
  private:
    uint8_t _gate;

  public:
    MOSFET(uint8_t gate): _gate(gate)
    {};
    void on();
    void off();
};


#endif
