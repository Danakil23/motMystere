#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <cstdlib>  // For random generator
#include <ctime>    //For random generator, use the current time

using namespace std;

string getWord(){

    string wordPicked = "";
    vector<string> myArray; // creates a dynamical array to hold words
    string line; //this will contain the data read from the file
    short i=0; //short for loop for input
    int number_of_lines = 0;
    int randomNumber = 0;

    srand(time(0)); // Initialize the random generator

    ifstream fichier("word_dict.txt");

    if(fichier.is_open()){

        while (! fichier.eof()){ //while the end of file is NOT reached
            getline (fichier,line); //get one line from the file
            myArray.push_back(line);
            //cout << myArray[number_of_lines] << endl; //and output it
            number_of_lines++;
        }
        fichier.close(); //closing the file
        number_of_lines = number_of_lines -1;
        randomNumber = rand() % number_of_lines;
        /*cout << "randomNumber: " << randomNumber << endl;
        cout << "Nombre de ligne: " << number_of_lines << endl;
        cout << "word picked: " << myArray[randomNumber] << endl;*/
        wordPicked = myArray[randomNumber];
    }
    else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        wordPicked = "erreur";
        //return 0;
    }


    return wordPicked;
}
