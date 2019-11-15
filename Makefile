OBJ = game.o main.o
OUT = game
LIBS = -lSDL2

release : $(OBJ)
	$(CXX) $(OBJ) -o $(OUT) $(LIBS)

game.o : game.cpp game.h
	$(CXX) -c game.cpp

main.o : main.cpp game.h
	$(CXX) -c main.cpp

.PHONY : clean
clean:
	rm *.o
