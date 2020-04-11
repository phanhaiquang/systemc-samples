// Download from https://www.doulos.com/knowhow/systemc/tutorial/debugging/
// Modification:
//    Add include <iomanip>
//    Change setw() to std::setw()
//      https://stackoverflow.com/questions/28971312/iomanip-errors-or-setw-was-not-declared-in-this-scope
#include "systemc.h"
#include <iomanip>

SC_MODULE(mon)
{
    sc_in<bool> A,B,F;
    sc_in<bool> Clk;

  void monitor()
  {
    cout << std::setw(10) << "Time";
    cout << std::setw(2) << "A" ;
    cout << std::setw(2) << "B";
    cout << std::setw(2) << "F" << endl;
    while (true)
    {
      cout << std::setw(10) << sc_time_stamp();
      cout << std::setw(2) << A.read();
      cout << std::setw(2) << B.read();
      cout << std::setw(2) << F.read() << endl;
      wait();    // wait for 1 clock cycle
    }
  }

  SC_CTOR(mon)
  {
    SC_THREAD(monitor);
    sensitive << Clk.pos();
  }
};