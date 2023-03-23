CXXFLAGS +=-std=c++11

main: main.o invert.o imageio.o
	g++ -o main main.o invert.o imageio.o

main.o: main.cpp invert.h

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

invert.o: invert.cpp invert.h 
	g++ -g -c invert.cpp 

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h
clean:
	rm -f main.o sample.o imageio.o invert.o
