NAME = "splay"

local :
	g++ -g -std=c++0x -Wall -Werror *.cpp -o $(NAME) 

lab :
	g++11 *.cpp -o $(NAME)