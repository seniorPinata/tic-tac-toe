CXX=g++
CXXFLAGS=-g
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system

sfml_app: hello_world.o
	$(CXX) $(CXXFLAGS) hello_world.o -o sfml_app $(LDLIBS)
	

hello_world.o: hello_world.cpp
	$(CXX) -c hello_world.cpp

clean:
	rm hello_world.o sfml_app