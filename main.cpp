#include <iostream>
#include <vector>
#include "global.h"

using namespace std;

struct evaluateGuessOuput
{
    bool successfulGuess;
    vector<int> indexVector;
};

void printGuessingText(string text)
{
    string guessingText;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            guessingText.push_back(text[i]);
        }
        else
        {
            guessingText.push_back('_');
        }
    }
    cout << guessingText << endl;
}

evaluateGuessOuput evaluateGuess(char letterGuessed, string text)
{
    bool successfulGuess = false;
    vector<int> indexes;
    for (int i = 0; i < text.length(); i++)
    {
        if (letterGuessed == text[i])
        {
            successfulGuess = true;
            indexes.push_back(i);
        };
    };
    return {successfulGuess, indexes};
}

int main()
{
    bool gameRunning = true;
    int currentStageIndex = 0;
    vector<char> guessedCharacters;
    string targetPhrase;
    while (gameRunning)
    {
        char letterGuessed;
        cout << "Please type the word you want to guess " << endl;
        getline(cin, targetPhrase);
        printGuessingText(targetPhrase);
        cout << "What letter do you want to guess? ";
        if (cin >> letterGuessed)
        {
            evaluateGuessOuput data = evaluateGuess(letterGuessed, targetPhrase);
            for (int i = 0; i < data.indexVector.size(); i++)
            {
                
            }
        }
        else
        {
            cout << "Incorrect input. Please try again. " << endl;
            continue;
        }
    }
    return 0;
}