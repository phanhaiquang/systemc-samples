MAIN_CPP = main.cc fir.cc tb.cc

all: sim run

sim: *.h *.cc
	g++ -I. -I${SYSTEMC_HOME}/include -L. -L${SYSTEMC_HOME}/lib-linux -o sim ${MAIN_CPP} -lsystemc -lm

run:
	./sim

view:
	gtkwave *.vcd
