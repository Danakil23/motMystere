#include <iostream>
#include <string>

#include "mixletters.h"
#include "getWord.h"

using namespace std;

bool playAgain(){
    bool game = true;
    cout << endl << "Do you want to play again (Y/N) ?" << endl;

    cout << "test github" << endl;

    string input = "";
    cin >> input;
    if (input.compare("Yes") == 0 || input.compare("yes") == 0 ||
        input.compare("y") == 0 || input.compare("o") == 0 || input.compare("oui") == 0){
        game = true;
        cout << "Here we go !! " << endl << endl;
    }
    else{
        game = false;
    }
    return game;
}

int main()
{
    string motMystere ="";
    string mixWord = "";
    int tries = 0;
    int maxTries = 10;

    bool game = true;
    string answer;

    cout << "----------------------------------------" << endl;
    cout << "Welcome to the mystery word's game ! " << endl;
    cout << "You will have " << maxTries << " tries to find the word" << endl;
    cout << "----------------------------------------" << endl;

    while (game == true){

        bool flag = false;
        motMystere = getWord();
        //cin >> motMystere;

        mixWord = mixLetters(motMystere);

        while (flag == false){
            cout << "Guess the word: " << mixWord << endl;

            cin >> answer;

            if (answer.compare(motMystere) == 0){
                cout << tries +1 << "/" << maxTries << "--" << "You are right !" << endl;
                flag = true;
                tries = 0;
                game = playAgain();
            }
            else{
                cout << tries +1 << "/" << maxTries << "--" << "Wrong" << "\n";
                ++tries;
                if (tries >= maxTries){
                    flag = true;
                    cout << endl << "The solution was " << motMystere << endl;
                    tries = 0;
                    game = playAgain();

                }
            }
        }
    }

    cout << "Thank you for playing and Thanks to openClassRoom for the fun !" << endl;
    return 0;
}
