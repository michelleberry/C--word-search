#include "word.hpp"

Word :: Word(){
    set_xy(0,0); 
    set_len(0);
    char def[MAX_WORD] = "empty"; 
    set_str(def); 
    set_dir(' ');
    set_crossed(false);   
}

Word :: Word(int newx, int newy, char w[MAX_WORD]){
    set_xy(newx, newy); 
    set_len(strlen(w)); 
    set_str(w); 
}

void Word :: set_len(int newlen){
    len = newlen; 
}

void Word :: set_xy(int newx, int newy){
    x = newx; 
    y = newy; 
}

void Word :: set_str(char w[MAX_WORD]){
    strcpy(str,w); 
}

void Word :: set_dir(char newdir){
    dir = newdir; 
}

void Word :: set_crossed(bool value){
    crossed = value; 
}