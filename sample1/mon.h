#include "systemc.h"
SC_MODULE(mon)
{
  sc_in<bool> A, B, F, Clk;

  void MonDisplay()
  {
    cout << "A\tB\tF\n";
    cout << "-----------------\n";
    while(1) {
      cout << A.read() << "\t" << B.read() << "\t" << F.read() << "\n";
      wait();
    }
  }

  SC_CTOR(mon)
  {
    SC_THREAD(MonDisplay);
    sensitive << Clk.pos();
  }
};
