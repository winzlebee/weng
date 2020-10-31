OBJ = game.o sprite.o util.o controller.o
OUT = libweng.a
LIBS = -lSDL2 -lSDL2_image

library : $(OBJ)
	ar -rcs $(OUT) $(OBJ)

game.o : game.cpp game.h
	$(CXX) -c game.cpp

sprite.o : sprite.cpp sprite.h util.h
	$(CXX) -c sprite.cpp

util.o : util.cpp util.h
	$(CXX) -c util.cpp

controller.o : sprite.h
	$(CXX) -c controller.cpp

.PHONY : clean
clean:
	rm *.o
	rm $(OUT)
