all:
	g++ main.cpp -o main -Wall -fsanitize=leak,address,undefined
