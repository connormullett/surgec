
CC=g++
CXXFLAGS=-g -O2 -Wall

DEPS = headers/lex.hpp headers/types.hpp
OBJ = obj/lex.o obj/types.o obj/main.o

build/surge: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)

obj/%.o: src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean 

clean:
	rm -rf obj/*.o
	rm -rf build/*

$(shell [[ -d obj ]] || mkdir obj)
$(shell [[ -d build ]] || mkdir build)
