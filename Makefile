CXXFLAGS +=-std=c++11

main: main.o funcs.o imageio.o
	g++ -o main main.o funcs.o imageio.o

main.o: main.cpp funcs.h

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

invert.o: funcs.cpp funcs.h 
	g++ -g -c funcs.cpp 

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h
clean:
	rm -f main.o sample.o imageio.o funcs.o
