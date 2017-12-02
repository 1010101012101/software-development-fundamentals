/**
 * CMPE 320 - Fundamentals of Software Development - Assignment 4
 * jumble_15rws.h
 *
 * @author Robert Saunders (Student Number: 10194030, NetId: 15rws)
 * @version 1.0 17/11/2017
 */

#pragma once

#include <string>
#include <iostream>
#include <utility>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef char* charArrayPtr;

/**
 * The JumblePuzzle class declaration.
 * Class used to perform jumble puzzle logic.
 */
class JumblePuzzle {
    public:
        JumblePuzzle(const string, const string);
        JumblePuzzle& operator=(const JumblePuzzle& rhs);
        JumblePuzzle(const JumblePuzzle&);
        ~JumblePuzzle();
        int getSize() const;
        int getRowPos() const;
        int getColPos() const;
        char getDirection() const;
        charArrayPtr* getJumble() const;
    private:
        int* size;
        char generateRandomDirection();
        bool checkPosition(pair<int, int>);
        bool checkCoordinate(int);
        int getDifficultyModifier(string);
        charArrayPtr* jumble;
        int* rowPos;
        int* colPos;
        char* direction;
        void emptyJumble();
        void initializeJumble(const string);
        pair<int, int> updatePosition(pair<int, int>, char);
        pair<int, int> generateRandomPosition();
        char generateRandomCharacter();
};

/**
 * The BadJumbleException class declaration.
 * Used to validate jumbles etc..
 */
class BadJumbleException {
    public:
        explicit BadJumbleException(const string& message);
        string what() const;
    private:
        string exceptionMessage;
};
