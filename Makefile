main:
	g++ -Wall -pedantic -o game src/main.cpp src/game.cpp src/texture_manager.cpp src/entity.cpp -lSDL2 -lSDL2_image
