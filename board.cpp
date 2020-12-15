#include <iostream>
#include "board.hpp"

//constructor
Board :: Board(){
    set_size(DIMENSIONS);  

    //initialize board to be blank chars 
    set_blank(); 

    //initialize word objects in words[] array 
    for(int i = 0; i < NUM_WORDS; i++){
        words[i] = Word(); 
    }
}

//set board's size -- default size is 16x16
void Board :: set_size(int newsize){
    size = newsize; 
}

//set board's word array to given array
void Board :: set_words(char new_words[NUM_WORDS][MAX_WORD]){
    for(int i=0; i < NUM_WORDS; i++){
        strcpy(words[i].str, new_words[i]);
        words[i].set_len(strlen(words[i].str)); 
    }
}

//print entire board, w/a space between each column
void Board :: print_board(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            std::cout << board[i][j]; 
            std::cout << ' ';  
        }
        std::cout << std::endl; 
    }
}

//set all characters in board to a space
void Board :: set_blank(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            board[i][j] = ' '; 
        }
    }
}

//places random letters in parts of board not occupied by placed words
void Board :: place_scramble(){
    char rand_let = 0; 
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(board[i][j] == ' '){
                //get a random capital letter
                rand_let = (rand() % 25) + 65;
                //code below prevents vowels AEIOU from being placed --- without doing this the game is extremely hard 
                if(rand_let == 65 || rand_let == 69 || rand_let == 73 || rand_let == 79 || rand_let == 85){
                    rand_let++; 
                } 
                //place the random consonant letter in the board
                board[i][j] = rand_let;  
            }  
        } 
    }
}

//place a given word horizontally at a random location 
//do not intersect w/ other words
void Board :: place_horiz(Word &word){
    int x = rand() % (size - word.len); 
    int y = rand() % size;
     
    int i = 0; 
    bool clear = true;
    int tempx = x;  
    while(i < word.len && clear == true){  //ensure placement of the word at x,y will not intersect other words
        if(board[y][tempx] != ' '){
            clear = false; 
        }
        i++;
        tempx++; 
    }

    if(clear == true){ //if no intersection occurs, 
        word.set_xy(x,y); //set word's x, y
        word.set_dir('H'); //set word's direction
        for(int j = 0; j < word.len; j++){ //place word 
            board[y][x] = word.str[j]; 
            x++; 
        }
    } else { //if intersection would occur, fn is called again & word assigned new random location 
        place_horiz(word); 
    }
}

//place a given word veritcally in a random location on the board
//do not intersect w/ other words
void Board :: place_vert(Word &word){
    int x = rand() % size; 
    int y = rand() % (size - word.len);
    
    int i = 0; 
    bool clear = true;
    int tempy = y;  
    while(i < word.len && clear == true){ //ensure placement of the word at x,y will not intersect other words
        if(board[tempy][x] != ' '){
            clear = false; 
        }
        i++;
        tempy++; 
    }

    if(clear == true){ //if no intersection occurs,
        word.set_xy(x,y); //set word's x, y
        word.set_dir('V'); //set word's direction
        for(int j = 0; j < word.len; j++){ //place word 
            board[y][x] = word.str[j]; 
            y++; 
        }
    } else { //if intersection would occur, fn is called again & word assigned new random location 
        place_vert(word); 
    }
}        

//place a given word diagonally at a random location on the board
//do not intersect w/ other words
void Board :: place_diag(Word &word){
    int x = rand() % (size - word.len); 
    int y = rand() % (size - word.len);
     
    int i = 0; 
    bool clear = true;
    int tempy = y;
    int tempx = x;   
    while(i < word.len && clear == true){ //ensure placement of the word at x,y will not intersect other words
        if(board[tempy][tempx] != ' '){
            clear = false; 
        }
        i++;
        tempy++;
        tempx++;  
    }

    if(clear == true){ //if no intersection occurs,
        word.set_xy(x,y); //set word's x, y
        word.set_dir('D'); //set word's direction
        for(int j = 0; j < word.len; j++){ //place word in board 
            board[y][x] = word.str[j]; 
            y++;
            x++;  
        }
    } else { //if intersection would occur, fn is called again & word assigned new random location 
        place_diag(word); 
    }
}

//use private functions above to place array of words randomly in word search "board". 
void Board :: set_board(){

    set_blank(); //in case of re-setting board 
    srand(time(NULL)); //seed random with time so when rand() is used it is truly random

    for(int i = 0; i < NUM_WORDS; i++){ //place words
        
        if(i%2 == 0){
            place_vert(words[i]); 
        }else if(i%3 == 0){
            place_horiz(words[i]); 
        }else{
            place_diag(words[i]); 
        }
        
    }

    place_scramble(); //place random letters 

}
