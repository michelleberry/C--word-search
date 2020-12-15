#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"

//game holds the game_board object, is responsible for handling user input/commands (crossing words off the game board), holding game data like the score & state of play
class Game{
    public:
        Board game_board;
        int score; 
        int score_to_win; 
        bool playing;  
        bool won; 
        Game(); 
        void set_board( Board newboard ); 
        void set_score( int newscore ); 
        void set_score_to_win(int newscore ); 
        void set_playing( bool value ); 
        void set_won( bool value ); 
        void check_input( char *input );
        void update_score(); 
    private:
        void cross_horiz(Word &word); 
        void cross_vert(Word &word); 
        void cross_diag(Word &word); 

};

#endif