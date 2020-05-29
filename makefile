
CC=g++
CXXFLAGS=-g -O2 -Wall

DEPS = headers/lex.hpp headers/types.hpp headers/types/syntax_tree.hpp
OBJ = obj/lex.o obj/types.o obj/main.o
BINDIR = /usr/bin

build/surge: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)

obj/%.o: src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean install

clean:
	rm -rf obj/*.o
	rm -rf build/*

install: build/surge
	install -m 557 build/surge -t $(BINDIR)

$(shell [[ -d obj ]] || mkdir obj)
$(shell [[ -d build ]] || mkdir build)
