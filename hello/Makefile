all: sim run

sim: hello.cpp
	g++ -I. -I${SYSTEMC_HOME}/include -L. -L${SYSTEMC_HOME}/lib-linux -o sim $< -lsystemc -lm

run:
	./sim

