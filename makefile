program: main.cpp measurement.cpp prime.cpp timer.cpp
	g++ -O0 -o main main.cpp measurement.cpp prime.cpp timer.cpp -g

run: program
	./main
