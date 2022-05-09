program: main.cpp measurement.cpp prime.cpp timer.cpp
	g++ -O3 -o main main.cpp measurement.cpp prime.cpp timer.cpp -g

run: program
	./main

plot:
	python3 plotter.py
