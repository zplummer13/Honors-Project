#Makefile

prototype: prototype.cpp
	g++ -o prototype prototype.cpp -framework sfml-graphics -framework sfml-window -framework sfml-system