MAIN_CPP = first_counter_tb.cpp

all: sim run

sim: *.cpp
	g++ -I. -I${SYSTEMC_HOME}/include -L. -L${SYSTEMC_HOME}/lib-linux -o sim ${MAIN_CPP} -lsystemc -lm

run:
	./sim

view:
	gtkwave *.vcd
