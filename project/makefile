#Makefile

FRAMEWORKS = -framework sfml-graphics -framework sfml-window -framework sfml-system
FILES = main.cpp entity.cpp graph.cpp wall.cpp door.cpp doorButton.cpp zone.cpp light.cpp winZone.cpp player.cpp enemy.cpp level.cpp game.cpp
OUT = main

build: $(FILES)
	g++ -o $(OUT) $(FILES) $(FRAMEWORKS)

