#include "word_bank_reader_fns.hpp"

//converts a string to all uppercase letters
void str_to_upper(char *str){
    for(unsigned int i=0; i < strlen(str); i++){
        str[i] = toupper(str[i]); 
    }
}

//ensures number chosen is unique from rest of numbers in array.
int choose_unique_rand_num(int *nums, int i, int total_words){
    int num = rand() % total_words; 
    for(int j=0; j<i; j++){
        if(nums[j] == num){
            //if not unique, recursion happens
            return choose_unique_rand_num(nums, i, total_words); 
        }
    }
    return num;  
}

//choose random numbers between 0 and total_words -- which represents the total no. of words contained in the bin file
void choose_rand_indexes(int (&indexes)[NUM_WORDS], int total_words){
    srand(time(NULL)); 
    for(int i=0; i<NUM_WORDS; i++){
        indexes[i] = choose_unique_rand_num(indexes, i, total_words); 
    }
}

//determine number of words in file from filestream fpp
int num_words_in_file(std::ifstream &fpp){
    fpp.seekg(0, fpp.end); 
    int returnme = (fpp.tellg())/(sizeof(char) * MAX_WORD);
    fpp.seekg(0,fpp.beg); //return filestream pointer to beginning of file, where it was before
    return returnme; 
}

//read word at a certain index in file
void get_word(std::ifstream &fpp, int i, char (&word)[MAX_WORD]){
    fpp.seekg(i*(sizeof(char)*MAX_WORD)); 
    fpp.read((char *) &word, sizeof(char)*MAX_WORD); 
    fpp.seekg(0,fpp.beg); //return filestream pointer to beginning of file, where it was before
}

void read_words_from_word_bank(char (&words_list)[NUM_WORDS][MAX_WORD]){
    //open binary file stream for reading
    std::ifstream ifp("word_bank.bin", std::ios::out | std::ios::binary);
    //check it was opened correctly 
    if(!ifp){
        std::cout << "Could not open word_bank.bin file for reading. Program Exiting." << std::endl; 
        exit(1); 
    }

    int total_words = num_words_in_file(ifp);
    int indexes[NUM_WORDS]; 
    choose_rand_indexes(indexes, total_words); 

    for(int i=0; i < NUM_WORDS; i++){
        get_word(ifp, indexes[i], words_list[i]);  
    }

    ifp.close(); 
    if(!ifp.good()){
        std::cout << "Error reading from word_bank.bin. Program Exiting." << std::endl; 
        exit(0);  
    }
} 