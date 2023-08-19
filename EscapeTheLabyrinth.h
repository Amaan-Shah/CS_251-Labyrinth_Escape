// Amaan Shah, UIC, Spring 2021
// EscapeTheLabyrinth.h
//
// In this file I take in the starting node of a maze
// and a list of moves and check if the list is
// a valid list to freedom from the labyrinth.

#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

const string kYourName = "Amaan Shah";
const string kPathOutOfRegularMaze = "SENEWSWSEENSWSEEN";
const string kPathOutOfTwistyMaze = "NNSNSWENSNW";

// Helper Function Prototypes:
void checkCell(MazeCell* cur, bool &sb, bool &p, bool &w);
MazeCell* checkNext(MazeCell* cur, char nextMove, bool &valid);

// isPathToFreedom:
bool isPathToFreedom(MazeCell *start, const string& moves) {
    bool sb = false;
    bool p = false;
    bool w = false;
    bool valid = true;
    char nextMove;
    int index = 0;
    int length = moves.length();
    
    MazeCell* cur = start;
    checkCell(cur, sb, p, w);
    while (index < length){
        nextMove = moves.at(index);
        cur = checkNext(cur, nextMove, valid);
        if (valid == false) {
            break;
        }
        checkCell(cur, sb, p, w);
        index++;
    }
    if (valid && sb && p && w) {
        return true;
    }
    return false;
}


void checkCell(MazeCell* cur, bool &sb, bool &p, bool &w) {
    if (cur->whatsHere == "Potion") {
        p = true;
    } else if (cur->whatsHere == "Spellbook") {
        sb = true;
    } else if (cur->whatsHere == "Wand") {
        w = true;
    } 
}


MazeCell* checkNext(MazeCell* cur, char nextMove, bool &valid) {
    if (nextMove == 'N'){
        if (cur->north == nullptr) {
            valid = false;
        }
        cur = cur->north;
    } else if (nextMove == 'S') {
        if (cur->south == nullptr) {
            valid = false;
        }
        cur = cur->south;
    } else if (nextMove == 'E') {
        if (cur->east == nullptr) {
            valid = false;
        }
        cur = cur->east;
    } else if (nextMove == 'W') {
        if(cur->west == nullptr) {
            valid = false;
        }
        cur = cur->west;
    } else { // invalid letter
        valid = false;
    }
    return cur;
}


















