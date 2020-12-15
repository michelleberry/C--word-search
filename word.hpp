#ifndef WORD_HPP
#define WORD_HPP

#define MAX_WORD 15
#include <cstring>

//word stores a word string and information about where it is on the board, & whether it has been found (crossed)
class Word{
    public: 
        int x; //coordinates of first letter in board 
        int y; 
        int len; //length of word in str (#letters)
        char dir; //can be V (vertical) H (horizontal) or D (diagonal)
        char str[MAX_WORD]; 
        bool crossed; 
        Word();
        Word( int newx, int newy, char w[MAX_WORD]);  
        void set_xy(int newx, int newy);
        void set_len(int newlen); 
        void set_str(char w[MAX_WORD]); 
        void set_dir(char newdir);
        void set_crossed(bool value);   
}; 

#endif