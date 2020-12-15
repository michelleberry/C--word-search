#include "score_keeper.hpp"
#include <iomanip>

Score_Keeper :: Score_Keeper(){

    for(int i=0; i<5; i++){
        top_five[i].total_sec = 0;
        top_five[i].sec = 0; 
        top_five[i].min = 0; 
        strncpy(top_five[i].name, "empty", MAX_WORD); 
    }
}

void Score_Keeper :: print_top_scores(){
    read_bin_top_five(); 
    std::cout << "HIGH SCORES -- LOWEST TIMES\nRank       Name      Time" << std::endl; 
    for(int i=0; i < 5; i++){
        std::cout << i+1 << ". " << std::setw(MAX_WORD) << std::setfill(' ') << top_five[i].name << "   "; 
        std::cout << std::setw(2) << std::setfill('0') << top_five[i].min << ":" << std::setw(2) << top_five[i].sec << std::endl; 
    }
}

void Score_Keeper :: add_new_score(char *name, int min, int sec){
    int total_secs = (min*60) + sec;  

    for(int i=0; i<5; i++){
        if(top_five[i].total_sec > total_secs || top_five[i].total_sec == 0){
            insert_to_array(name, min, sec, total_secs, i); 
            break; 
        }
    }
    write_bin_top_five(); 
}

//move rest of array back and insert new struct score insert
void Score_Keeper :: insert_to_array(char *name, int mins, int secs, int total_secs, int idx){
    for(int i = 4; i > idx; i--){
        top_five[i] = top_five[i-1]; 
    }
    top_five[idx].total_sec = total_secs; 
    top_five[idx].sec = secs; 
    top_five[idx].min = mins; 
    strncpy(top_five[idx].name, name, MAX_WORD);
}

void Score_Keeper :: read_bin_top_five(){
    std::ifstream ifp("scores.bin", std::ios::out | std::ios::binary);
    if(!ifp){
        std::cout << "Could not open scores.bin file for reading. Program Exiting." << std::endl; 
        exit(1); 
    }

    int i = 0;  
    while(i < 5 && ifp.eof() == false){
        ifp.read((char *) &top_five[i], sizeof(struct score));
        i++; 
    }

    ifp.close(); 
    if(!ifp.good()){
        std::cout << "Error reading from scores.bin. Program Exiting." << std::endl; 
        exit(1);  
    }
}

void Score_Keeper :: write_bin_top_five(){
    std::ofstream ofp("scores.bin", std::ios::out | std::ios::binary);
    if(!ofp){
        std::cout << "Could not open scores.bin file for writing. Program Exiting." << std::endl; 
        exit(1); 
    }
 
    for(int i = 0; i < 5; i++){
        ofp.write((char *) &top_five[i], sizeof(struct score));
    }

    ofp.close(); 
    if(!ofp.good()){
        std::cout << "Error writing to scores.bin. Program Exiting." << std::endl; 
        exit(1);  
    }
}
