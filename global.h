#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H
#include <iostream>

using namespace std;

// This is a declaration of your variable, which tells the linker this value
// is found elsewhere.  Anyone who wishes to use it must include global.h,
// either directly or indirectly.
const string stages[7] = {"   +-+ |\n"
                          "   |   |\n"
                          "       |\n"
                          "       |\n"
                          "       |\n"
                          "       |\n"
                          "========\n",
                          "   +-+ |\n"
                          "   |   |\n"
                          "   O   |\n"
                          "       |\n"
                          "       |\n"
                          "       |\n"
                          "========\n",
                          "   +-+ |\n"
                          "   |   |\n"
                          "   O   |\n"
                          "   |   |\n"
                          "       |\n"
                          "       |\n"
                          "========\n",
                          "   +-+ |\n"
                          "   |   |\n"
                          "   O   |\n"
                          "  /|   |\n"
                          "       |\n"
                          "       |\n"
                          "========\n",
                          "   +-+ |\n"
                          "   |   |\n"
                          "   O   |\n"
                          "  /|\\ |\n"
                          "       |\n"
                          "       |\n",
                          "========\n"
                          "   +-+ |\n"
                          "   |   |\n"
                          "   O   |\n"
                          "  /|\\ |\n"
                          "  /    |\n"
                          "       |\n"
                          "========\n",
                          "   +-+ |\n"
                          "   |   |\n"
                          "   O   |\n"
                          "  /|\\ |\n"
                          "  / \\ |\n"
                          "       |\n"
                          "========\n"};
#endif