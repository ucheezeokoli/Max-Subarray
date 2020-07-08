CC = g++

all:
	$(CC) -std=c++11 -o a.exe MaxSubarray.cpp

clean:
	rm -f a.exe

