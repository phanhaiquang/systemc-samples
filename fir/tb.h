#include "systemc.h"
#include <iostream>


SC_MODULE (tb){

	sc_in < bool > clk;
	sc_out < bool > rst;
	sc_out< sc_int<16> > inp;
	sc_out < bool   > inp_vld;
	sc_in < bool  > inp_rdy;
	sc_in< sc_int<16> > outp;
	sc_in< bool  > outp_vld;
	sc_out < bool > outp_rdy;
	sc_time starttime[64],endtime[64], clockperiod;

	void source();
	void sink();
	FILE *outfp = NULL;

	SC_CTOR(tb){

		SC_CTHREAD ( source, clk.pos());
		SC_CTHREAD ( sink, clk.pos());

	}


};
