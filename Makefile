NAME = "splay"

local :
	g++ -std=c++0x *.cpp -o $(NAME) 

lab :
	g++11 *.cpp -o $(NAME)