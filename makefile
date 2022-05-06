program: main.cpp measurement.cpp prime.cpp timer.cpp
	g++ -o main main.cpp measurement.cpp prime.cpp timer.cpp -g

run: program
	./main
