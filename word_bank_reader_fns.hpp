#ifndef WORD_BANK_READER_FNS_HPP
#define WORD_BANK_READER_FNS_HPP

#include "board.hpp" //to get NUM_WORDS and MAX_WORDS definitions
#include <fstream>
#include <iostream>

//converts a string to all uppercase letters
void str_to_upper(char *str);

//uses private functions contained in file word_bank_reader_fns.cpp to read words from word bank 
void read_words_from_word_bank(char (&words_list)[NUM_WORDS][MAX_WORD]);

#endif