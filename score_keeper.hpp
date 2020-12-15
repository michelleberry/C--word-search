#ifndef SCORE_KEEPER_HPP
#define SCORE_KEEPER_HPP

#include "word.hpp"
#include <fstream>
#include <iostream>

//manages the top 5 scores held in file "scores.bin"
class Score_Keeper{
    public:
        struct score{
            char name[MAX_WORD]; 
            int total_sec; 
            int min; 
            int sec; 
        };
        struct score top_five[5]; 
        Score_Keeper(); 
        void print_top_scores();
        void add_new_score(char *name, int min, int sec);
    private: 
        void insert_to_array(char *name, int mins, int secs, int total_secs, int idx);
        void read_bin_top_five(); 
        void write_bin_top_five(); 
};

#endif
