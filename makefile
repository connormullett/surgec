
CC=g++
CXXFLAGS=-g -O2 -Wall

DEPS = headers/lex.hpp headers/lexem.hpp headers/enums.hpp headers/parser.hpp headers/syntax_tree.hpp
DEPS += headers/ast_node.hpp headers/symbol.hpp

OBJ = obj/main.o obj/lexem.o obj/lex.o obj/parser.o obj/syntax_tree.o obj/ast_node.o

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
