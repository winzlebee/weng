OBJ = game.o main.o sprite.o util.o
OUT = game
LIBS = -lSDL2 -lSDL2_image

release : $(OBJ)
	$(CXX) $(OBJ) -o $(OUT) $(LIBS)

game.o : game.cpp game.h
	$(CXX) -c game.cpp

main.o : main.cpp game.h
	$(CXX) -c main.cpp

sprite.o : sprite.cpp sprite.h util.h
	$(CXX) -c sprite.cpp

util.o : util.cpp util.h
	$(CXX) -c util.cpp

.PHONY : clean
clean:
	rm *.o
