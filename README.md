# C++ Word Search
Word search game wherein a unique word search is randomly generated each time it is played.

## How to Compile + Run
assuming you have the g++ compiler installed , type these in your bash terminal ...

to compile:
  $make all

to run:
  $./word_search
  
## Details
* The top 5 lowest times to finish a word search are recorded in binary file scores.bin
* All possible words are held in word_bank.bin -- each time the program is run, 6 different words are selected and read out of word_bank.bin
* Follows an OOP program structure

## Rules
1. Enter in words that you find (Type the word then press enter).
2. There are 6 words to find.  
3. All valid words are at least 5 letters long.
4. If you enter a word and it does not cross out, it is only a crazy coincidence that the random filler letters formed a word.
5. The words can be vertical, horizontal, or diagonal, but are never backwards.
6. The board is different every time.

## Contact Information
* Michelle Berry
* mberry05@uoguelph.ca
