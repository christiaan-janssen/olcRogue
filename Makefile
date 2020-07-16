all:
	g++ -o rogue rogue.cpp olcPixelGameEngine.cpp Actor.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
