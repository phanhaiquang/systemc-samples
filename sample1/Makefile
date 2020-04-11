MAIN_CPP = main.cpp

all: sim run

sim: *.h *.cpp
	g++ -I. -I${SYSTEMC_HOME}/include -L. -L${SYSTEMC_HOME}/lib-linux -o sim ${MAIN_CPP} -lsystemc -lm

run:
	./sim

