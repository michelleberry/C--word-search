all: game.o board.o word.o word_bank_reader_fns.o score_keeper.o word_search.o word_search

word.o: word.cpp word.hpp
	g++ -std=c++11 -Wall -c word.cpp

board.o: board.cpp board.hpp word.hpp
	g++ -std=c++11 -Wall -c board.cpp

game.o: game.cpp game.hpp board.hpp word.hpp
	g++ -std=c++11 -Wall -c game.cpp

word_bank_reader_fns.o: word_bank_reader_fns.cpp word_bank_reader_fns.hpp board.hpp
	g++ -std=c++11 -Wall -c word_bank_reader_fns.cpp

score_keeper.o: score_keeper.cpp score_keeper.hpp word.hpp
	g++ -std=c++11 -Wall -c score_keeper.cpp

word_search.o: word_search.cpp game.hpp board.hpp word.hpp word_bank_reader_fns.hpp
	g++ -std=c++11 -Wall -c word_search.cpp

word_search: word_search.o game.hpp board.hpp word.hpp word_bank_reader_fns.hpp score_keeper.hpp
	g++ -std=c++11 -Wall -o word_search word_search.o game.o board.o word.o word_bank_reader_fns.o score_keeper.o

clean:
	rm game.o board.o word.o word_search.o word_search word_bank_reader_fns.o score_keeper.o
