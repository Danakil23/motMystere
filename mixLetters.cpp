#include "mixletters.h"

#include <string>
#include <cstdlib>  // For random generator
#include <ctime>    //For random generator, use the current time

using namespace std;


string mixLetters(string word){
    string mixWord(word.size(), 'x');
    string cloneWord = "";
    int position = 0;
    srand(time(0)); // Initialize the random generator

    cloneWord = word;
    for (int i = 0; i < word.size(); i++){
        position = rand() % cloneWord.size();
        mixWord[i] = cloneWord[position];
        cloneWord.erase(position,1);
    }
    return mixWord;
}
