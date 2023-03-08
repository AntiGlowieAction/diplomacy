LIBS := -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
CXX := g++

all:
	$(CXX) main.cpp -o res -DSFML_STATIC -I${SFML-2.5.1}\include -L${SFML-2.5.1}\lib $(LIBS)