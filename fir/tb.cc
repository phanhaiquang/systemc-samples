#include "tb.h"

void tb::source() {
	cout << "source" << endl;
	sc_int < 16 > tmp;
	//rest
	inp.write( 0 );
	inp_vld.write(0);
	rst.write( 1 );
	wait();
	rst.write( 0 );
	wait();



	for(int i = 0; i < 64; i++)
	{
		if (i > 23 && i < 29)
			tmp = 256;
		else
			tmp = 0;

		inp_vld.write(1);
		inp.write (tmp);
		starttime[i] = sc_time_stamp();
		do{
			wait();
		}while(!inp_rdy.read());
		inp_vld.write(0);

	}
	//hanging prevent
	wait(10000);
	printf("sim hang stopped by TB \n");
	sc_stop();

}


void tb::sink() {
	cout << "sink" << endl;
	sc_int <16> datain;
	//clk peroid
	sc_clock *clkp = DCAST<sc_clock*>(clk.get_interface());
	clockperiod = clkp->period();

	//int port

	outp_rdy.write(0);
	double totalcycles = 0;
	//open sim file

	char output_file[256];
	sprintf(output_file, "./output.dat");
	outfp = fopen(output_file, "w");
	if(outfp == NULL ){
		printf("couldn't open output.dat \n");
		exit(0);
	}

	for(int i=0; i < 64; i++)
	{
		outp_rdy.write(1);
		do{wait();
		}while(!outp_vld.read());

		datain = outp.read();
		endtime[i] = sc_time_stamp();
		totalcycles += (endtime[i] - starttime[i]) / clockperiod;
		outp_rdy.write(0);

		fprintf(outfp, "%d\n", (int)datain);
		cout << i << " :\t" << datain.to_double() << endl;

	}

	//latancy
	double throughput = (starttime[63] - starttime[0]) / clockperiod;
	printf("average latancy is %g cycles.\n", (double)(totalcycles/64));
	printf("average throughut is %g cycles/input.\n", (double)(throughput/63));
	//end sim
	sc_stop();
	fclose(outfp);
	cout << "sim stop" << endl;
}
