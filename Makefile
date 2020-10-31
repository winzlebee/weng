OBJ = main.o
OUT = game
LIBS = -lSDL2 -lSDL2_image -Lweng -lweng

game : $(OBJ) library
	$(CXX) $(OBJ) -o $(OUT) $(LIBS)

main.o : main.cpp weng/game.h
	$(CXX) -c main.cpp $(LIBS)

.PHONY: library
library:
	$(MAKE) -C weng

.PHONY : clean
clean:
	$(MAKE) clean -C weng
	rm game
	rm *.o
