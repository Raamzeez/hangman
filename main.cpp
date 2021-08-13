#include <iostream>
#include <vector>
#include "global.h"

using namespace std;

struct evaluateGuessOuput
{
    bool successfulGuess;
    vector<int> indexVector;
};

bool victory(string guessingText)
{
    bool victory = true;
    for (int i = 0; i < guessingText.length(); i++)
    {
        if (guessingText[i] == '_')
        {
            victory = false;
        }
    }
    return victory;
}

string generateGuessingText(string originalText)
{
    string guessingText;
    for (int i = 0; i < originalText.length(); i++)
    {
        if (originalText[i] == ' ')
        {
            guessingText.push_back(originalText[i]);
        }
        else
        {
            guessingText.push_back('_');
        }
    }
    return guessingText;
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
    bool win = false;
    bool gameRunning = true;
    bool askForPhrase = true;
    int currentStageIndex = 0;
    vector<char> guessedCharacters;
    string targetPhrase;
    char letterGuessed;
    string guessingText;
    while (gameRunning)
    {
        if (askForPhrase)
        {
            cout << "Please type the word you want to guess " << endl;
            getline(cin, targetPhrase);
            // if (cin.fail())
            // {
            //     cout << "You typed an incorrect input. Please try again. " << endl;
            //     continue;
            // }
            // else
            // {
            guessingText = generateGuessingText(targetPhrase);
            askForPhrase = false;
            // }
        }
        if (currentStageIndex == 6)
        {
            cout << stages[currentStageIndex] << endl;
            gameRunning = false;
            break;
        }
        if (victory(guessingText))
        {
            win = true;
            gameRunning = false;
            break;
        }
        cout << stages[currentStageIndex] << endl;
        cout << guessingText << endl;
        cout << "What letter do you want to guess? ";
        cin >> letterGuessed;
        if (!cin.fail())
        {
            guessedCharacters.push_back(letterGuessed);
            evaluateGuessOuput data = evaluateGuess(letterGuessed, targetPhrase);
            if (data.successfulGuess)
            {
                for (int i = 0; i < data.indexVector.size(); i++)
                {
                    guessingText[data.indexVector.at(i)] = letterGuessed;
                }
                cout << "You guessed the correct letter " << letterGuessed << endl;
            }
            else
            {
                cout << "You guessed an incorrect letter" << endl;
                currentStageIndex++;
            }
            continue;
        }
        else
        {
            cin.clear();
            cout << "Incorrect input. Please try again. " << endl;
            continue;
        }
    }
    if (win)
    {
        cout << "Congratulations you won the game!" << endl;
    }
    else
    {
        cout << "Sorry, you lost the game! The correct phrase was " << targetPhrase << endl;
    }
    return 0;
}