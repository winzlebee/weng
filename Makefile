OBJ = game.o main.o sprite.o
OUT = game
LIBS = -lSDL2

release : $(OBJ)
	$(CXX) $(OBJ) -o $(OUT) $(LIBS)

game.o : game.cpp game.h
	$(CXX) -c game.cpp

main.o : main.cpp game.h
	$(CXX) -c main.cpp

sprite.o : sprite.cpp sprite.h math.h
	$(CXX) -c sprite.cpp

.PHONY : clean
clean:
	rm *.o
