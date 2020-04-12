#include "fir.h"

const sc_uint< 16 > coef[5] =  {18,77,107,77,18};

void fir::fir_main(){

	cout << "fir_main oper" << endl;

	sc_uint< 16 > taps[5];

	//rest is wrote here till first wait

	for (int i = 4; i > 0; i--) {

		taps[i] = 0;

	}
	//intailaize handscack
	inp_rdy.write(0);
	outp_vld.write(0);
	outp.write( 0 );

	wait();

	while(true){


		sc_int < 16 > in_val;
		sc_int < 16 > out_val;

		inp_rdy.write(1);
		do{
			wait();
		}while(!inp_vld.read());

		in_val = inp.read();
		inp_rdy.write(0);
		//read input into shift register
		for (int i = 4; i > 0; i--) {

			taps[i] = taps[i-1];

		}

		taps[0] = in_val;


		// perfom multiplay and accumulate
		for (int i = 0; i < 5; i++) {

			out_val += coef[i]*taps[i];


		}
		outp_vld.write(1);
		outp.write(out_val);
		do{wait();
		}while(!outp_rdy.read());
		outp_vld.write(0);

		wait();

	}//while


}
