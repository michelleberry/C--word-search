#ifndef BOARD_HPP
#define BOARD_HPP

#include "word.hpp"
#define NUM_WORDS 6 
#define DIMENSIONS 16 //Note: YOU CANNOT make DIMENSIONS < MAX_WORD or it will cause seg faults. 

//board is responsible for the game board & the words that are hidden in it
class Board{
    public: 
        int size;    //DIMENSIONSxDIMENSIONS board 
        Word words[NUM_WORDS];  //array of 6 words
        char board[DIMENSIONS][DIMENSIONS]; 
        Board(); 
        void set_size(int newsize); 
        void set_words(char new_words[NUM_WORDS][MAX_WORD]);
        void set_board(); 
        void print_board();  
    private:
        //for set_board:
        void place_vert(Word &word); 
        void place_horiz(Word &word);
        void place_diag(Word &word); 
        void place_scramble(); 
        void set_blank(); 
}; 

#endif