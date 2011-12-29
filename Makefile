all:
	g++ src/commandopts.cpp src/main.cpp -o dsh

debug:
	g++ -g src/commandopts.cpp src/main.cpp -o dsh
