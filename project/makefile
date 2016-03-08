#Makefile

FRAMEWORKS = -framework sfml-graphics -framework sfml-window -framework sfml-system
FILES = main.cpp entity.cpp wall.cpp zone.cpp player.cpp enemy.cpp game.cpp
OUT = main

build: $(FILES)
	g++ -o $(OUT) $(FILES) $(FRAMEWORKS)

