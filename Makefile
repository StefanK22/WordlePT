all: play

compile: wordle.o
	g++ wordle.o -o wordle

wordle.o:
	g++ -c wordle.cpp

clean:
	rm -rf *o wordle

play: clean compile
	./wordle