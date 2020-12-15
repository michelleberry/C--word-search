#include <chrono>
#include "word_bank_reader_fns.hpp"
#include "score_keeper.hpp"
#include "game.hpp"

void score_record_query(int mins, int secs, Score_Keeper scoreb);

int main(){
    std::cout << "Welcome to word search!" << std::endl; 
    char input[255] = "not an s"; 

    Score_Keeper scoreboard = Score_Keeper(); 

    while(strcmp(input,"S") != 0){

        if(strcmp(input,"R") == 0){
            system("clear"); 
            std::cout << "RULES:\n1. Type in words that you find.\n2. There are " << NUM_WORDS << " words to find.\n" <<  
            "3. If you enter a word and it does not cross out, it is only a coincidence that the random filler letters formed a word.\n" <<
            "4. All valid words are at least 5 letters long.\n5. The words can be vertical, horizontal, or diagonal, but are never backwards.\n6. The board is different every time." << std::endl
            << "Enter T to see best times.\n"; 

        } else if (strcmp(input,"T") == 0){
            scoreboard.print_top_scores(); 
            std::cout << "Enter R to see rules.\n"; 

        } else {
            std::cout << "Enter T to see best times.\nEnter R to see rules.\n";
        }

        std::cout << "Enter S to start.\n>";
        std::cin >> input; 
        str_to_upper(input); 
        system("clear");
    }

    Game my_game = Game();                                                        //start a new game
    std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now(); //record time at start of game

    char wurds[NUM_WORDS][MAX_WORD]; // Reads a randomly chosen array of words from file titled word_bank.bin 
    read_words_from_word_bank(wurds); // Sets the game board's word as the randomly chosen ones
    
    my_game.game_board.set_words(wurds); 
    my_game.game_board.set_board(); //Sets the board with the words in it

    while(my_game.playing ==true){

        system("clear");  

        if(my_game.won == true){    //end-game code
            std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();
            std::chrono::duration<int> time_span = std::chrono::duration_cast<std::chrono::duration<int>>(t2 - t1);
            int minutes = time_span.count() > 59 ? (time_span.count()/60) : 0 ; 
            int seconds = time_span.count() %60;  //calculate time passed since start of game
            std::cout << "Congratulations, you've finished the word search!" << std::endl << "It took you " << minutes << " minutes and " << seconds << " seconds." << std::endl; 
            score_record_query(minutes, seconds, scoreboard); 
            exit(1); 
        }

        my_game.game_board.print_board(); //display word search board
        std::cout << "Words remaining: " << (my_game.score_to_win - my_game.score) << "\nEnter Q to quit.\n>";      //display current score

        std::cin >> input;    //get input
        str_to_upper(input);  //convert input to uppercase
    
        if(strcmp(input, "Q") == 0){ // exit game if input was q
            system("clear"); 
            std::cout << "Thank you for playing word search." << std::endl; 
            return 1; 
        }

        my_game.check_input(input); //check input (crosses out found words)
        my_game.update_score();     //update score in game
    }
}

//ask for name to record score
void score_record_query(int mins, int secs, Score_Keeper scoreb){
    char input[255] = "not y"; 

    while(strcmp(input, "Y") != 0){
        std::cout << "Would you like to record your time? Enter Y/N:\n>";
        std::cin >> input;
        str_to_upper(input); 
        system("clear");

        if(strcmp(input,"N") == 0){
            std::cout << "Thank you for playing word search." << std::endl; 
            exit(1);  
        }
    }

    std::cout << "Please enter your name:\n>";
    std::cin >> input;
    scoreb.add_new_score(input, mins, secs); 
}

