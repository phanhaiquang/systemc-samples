// Download from https://www.youtube.com/watch?v=NCFxBGLB5xs&t=4s

#include "systemc.h"
#include "fir.h"
#include "tb.h"
//module connecting fir to tb and run sim

SC_MODULE( systb ){

    tb  * tb0;
    fir * fir0;


    sc_signal < sc_int < 16 > > inp_sig;
    sc_signal <  bool > inp_sig_vld;
    sc_signal <  bool > inp_sig_rdy;
    sc_signal < bool > rst_sig;

    sc_signal < sc_int < 16 > >  outp_sig;
    sc_signal <  bool > outp_sig_vld;
    sc_signal <  bool > outp_sig_rdy;

    sc_clock  clk_sig;

    SC_CTOR( systb )

	: clk_sig ("clk_sig", 10, SC_NS)
	{

	    cout << "constructor" << endl;

	    tb0 = new tb("tb0");

	    tb0->clk( clk_sig );
	    tb0->rst( rst_sig );
	    tb0->inp( inp_sig );
	    tb0->inp_vld( inp_sig_vld );
	    tb0->inp_rdy( inp_sig_rdy );
	    tb0->outp( outp_sig );
	    tb0->outp_vld( outp_sig_vld );
	    tb0->outp_rdy( outp_sig_rdy );

	    fir0 = new fir("fir0");

	    fir0->clk( clk_sig );
	    fir0->rst( rst_sig );
	    fir0->inp( inp_sig );
	    fir0->inp_vld( inp_sig_vld );
	    fir0->inp_rdy( inp_sig_rdy );
	    fir0->outp( outp_sig );
	    fir0->outp_vld( outp_sig_vld );
	    fir0->outp_rdy( outp_sig_rdy );

	}


    ~systb(){
		delete tb0;
		delete fir0;
		cout << "delete" << endl;
    }
};




systb *top = NULL;

int sc_main(int, char* [])
{

    top = new systb("top");
    cout << "sim start" << endl;

    sc_trace_file *fp;

    fp=sc_create_vcd_trace_file("wave");
    fp->set_time_unit(100, SC_PS);

    sc_trace(fp,top->clk_sig , "clk_sig");
    sc_trace(fp,top->rst_sig , "rst_sig");
    sc_trace(fp,top->fir0->clk,"fir0->clk");
    sc_trace(fp,top->fir0->rst,"fir0->rst");
    sc_trace(fp,top->fir0->inp,"fir0->inp");
    sc_trace(fp,top->fir0->inp_vld,"fir0->inp_vld");
    sc_trace(fp,top->fir0->inp_rdy,"fir0->inp_rdy");
    sc_trace(fp,top->fir0->outp,"fir0->outp");
    sc_trace(fp,top->fir0->outp_vld,"fir0->outp_vld");
    sc_trace(fp,top->fir0->outp_rdy,"fir0->outp_rdy");

    sc_start(200, SC_NS);
    sc_close_vcd_trace_file(fp);

    return 0;

}
