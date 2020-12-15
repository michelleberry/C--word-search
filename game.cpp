#include "game.hpp"

Game :: Game(){
    Board new_board = Board(); 
    set_board(new_board); 
    set_score(0); 
    set_score_to_win(NUM_WORDS); 
    set_playing(true); 
    set_won(false); 
}

void Game :: set_board( Board newboard ){
    game_board = newboard; 
}

void Game :: set_score( int newscore ){
    score = newscore; 
} 

void Game :: set_score_to_win(int newscore ){
    score_to_win = newscore; 
}

void Game :: set_playing( bool value ){
    playing = value; 
}

void Game :: set_won( bool value ){
    won = value; 
}

void Game :: update_score(){
    if(score_to_win - score == 0){
        set_won(true); 
    }
}

void Game :: check_input( char *input ){
    int match = -1; 
    for(int i=0; i < score_to_win; i++){
        if(strcmp(input, game_board.words[i].str) == 0){
            match = i; 
            break;  
        }
    }

    if(match != -1 && game_board.words[match].crossed == false){
        if(game_board.words[match].dir == 'V'){
            cross_vert(game_board.words[match]); 
        } else if(game_board.words[match].dir == 'H'){
            cross_horiz(game_board.words[match]); 
        } else if(game_board.words[match].dir == 'D'){
            cross_diag(game_board.words[match]); 
        }
        score++;  
    }
    // if it do get the direction and invoke one of fn's below
}

void Game :: cross_horiz(Word &word){
    int x = word.x; 
    int y = word.y; 
    for(int i = 0; i < word.len; i++){
        game_board.board[y][x] = '*'; 
        x++; 
    }
    word.set_crossed(true); 
} 

void Game :: cross_vert(Word &word){
    int x = word.x; 
    int y = word.y; 
    for(int i = 0; i < word.len; i++){
        game_board.board[y][x] = '*'; 
        y++; 
    }
    word.set_crossed(true); 
}

void Game :: cross_diag(Word &word){
    int x = word.x; 
    int y = word.y; 
    for(int i = 0; i < word.len; i++){
        game_board.board[y][x] = '*'; 
        x++;
        y++;  
    }
    word.set_crossed(true); 
}
