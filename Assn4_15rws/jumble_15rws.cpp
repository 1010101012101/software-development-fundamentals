/**
 * CMPE 320 - Fundamentals of Software Development - Assignment 4
 * jumble_15rws.cpp
 *
 * @author Robert Saunders (Student Number: 10194030, NetId: 15rws)
 * @version 1.0 17/11/2017
 */


#include "jumble_15rws.h"

using namespace std;

/* /////////////////////// */
/* Jumble Implementation */
/* /////////////////////// */

/* Constructors */

/**
 * Creates a jumble given a word and difficulty level.
 * @param word The word to be in jumble.
 * @param difficulty The difficulty of the jumble.
 */
JumblePuzzle::JumblePuzzle(const string word, const string difficulty) {

	if (word.empty()) {
		throw BadJumbleException("You must supply a word to add to the jumble!");
	}

	size = new int;

	int modifier = getDifficultyModifier(difficulty);

	*size = word.length() * modifier;

	jumble = new char*[*size];

	for(int i = 0; i < *size; i++) {
		jumble[i] = new char[*size];
	}

	emptyJumble();

	initializeJumble(word);
}


/**
 * Copy constructor for a jumble.
 * @param original The original jumbo puzzel to copy.
 */
JumblePuzzle::JumblePuzzle(const JumblePuzzle& original) {
	size = new int;
	*size = original.getSize();

	jumble = new char*[*size];
	for(int i = 0; i < *size; i++) {
		jumble[i] = new char[*size];
	}

	charArrayPtr* originalJumble = original.getJumble();

	for(int i = 0; i < *size; i++) {
		for(int j = 0; j < *size; j++) {
			jumble[i][j] = originalJumble[i][j];
		}
	}

	rowPos = new int;
	*rowPos = original.getRowPos();

	colPos = new int;
	*colPos = original.getColPos();

	direction = new char;
	*direction = original.getDirection();
}

/**
 * Initializes a jumble.
 * @param word The word passed into the jumble.
 */
void JumblePuzzle::initializeJumble(const string word) {

	if(word.length() == 0) {
		throw BadJumbleException("You must supply a word to hide in the jumble!");
	}

	bool placed = false;
	pair<int, int> position;

	while(!placed) {
		position = generateRandomPosition();
		rowPos = new int;
		*rowPos = position.first;
		colPos = new int;
		*colPos = position.second;
		direction = new char;
		*direction = generateRandomDirection();
		for(int i = 0; i < word.length(); i++) {
			if(checkPosition(position)) {
				jumble[position.second][position.first] = word.at(i);
				position = updatePosition(position, *direction);
			} else {
				emptyJumble();
				break;
			}

			if(i + 1 == word.length()) {
				placed = true;
			}
		}
	}

	for(int i = 0; i < *size; i++) {
		for(int j = 0; j < *size; j++) {
			if(jumble[i][j] == NULL) {
				jumble[i][j] = generateRandomCharacter();
			}
		}
	}

}

/**
 * Assignment override.
 * @param original The original to compare against.
 * @return The new jumble after operation.
 */
JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& original) {
	if(this != &original) {
		size = new int;
		*size = original.getSize();

		jumble = original.getJumble();

		rowPos = new int;
		*rowPos = original.getRowPos();

		colPos = new int;
		*colPos = original.getColPos();

		direction = new char;
		*direction = original.getDirection();
	}

	return *this;
}

/* Destructor */

/**
 * Destructor for a jumble.
 */
JumblePuzzle::~JumblePuzzle() {
	for(int i = 0; i < *size; i++) {
		delete[] jumble[i];
	}
	delete[] jumble;
	delete size;
	delete rowPos;
	delete colPos;
	delete direction;
}

/* Getters */

/**
 * Gets the row position.
 * @return The row position.
 */
int JumblePuzzle::getRowPos() const {
	return *rowPos;
}

/**
 * Gets the column position.
 * @return The column position.
 */
int JumblePuzzle::getColPos() const {
	return *colPos;
}

/**
 * Gets the direction.
 * @return The direction.
 */
char JumblePuzzle::getDirection() const {
	return *direction;
}

/**
 * Gets the size attribute of jumble.
 * @return The size.
 */
int JumblePuzzle::getSize() const {
	return *size;
};

/**
 * Gets the jumble!
 * @return The jumble!
 */
charArrayPtr* JumblePuzzle::getJumble() const {
	charArrayPtr* jumbleCopy = new char*[*size];

	for(int i = 0; i < *size; i++) {
		jumbleCopy[i] = new char[*size];
	}

	for(int i = 0; i < *size; i++) {
		for(int j = 0; j < *size; j++) {
			jumbleCopy[i][j] = jumble[i][j];
		}
	}

	return jumbleCopy;
}

/* Implementation Methods */

/**
 * Resets the jumble, i.e. emptys it.
 * Iterates every column and row and sets to null.
 */
void JumblePuzzle::emptyJumble() {
	for(int i = 0; i < *size; i++) {
		for(int j = 0; j < *size; j++) {
			jumble[i][j] = NULL;
		}
	}
}

/* Utility Methods */

/**
 * Given the difficulty as a string this will return the modifier.
 * @param difficulty The difficulty as a string.
 * @return The modifier to be used for that difficulty.
 */
int JumblePuzzle::getDifficultyModifier(string difficulty) {
	if (difficulty == "easy") {
		return  2;
	} else if(difficulty == "medium") {
		return 3;
	} else if(difficulty == "hard") {
		return 4;
	} else {
		throw BadJumbleException("Invalid difficulty. Please select 'easy', 'medium', or 'hard'.");
	}
}

/**
 * Generate a random position in the jumble.
 * @return A pair or coordinates to represent a position int he jumble.
 */
pair<int, int> JumblePuzzle::generateRandomPosition() {
	return make_pair(int(rand() % *size), int(rand() % *size));
}

/**
 * Generates a random character.
 * @return A random character.
 */
char JumblePuzzle::generateRandomCharacter() {
	return char(rand() % 26 + 97);
}

/**
 * Gets one random direction.
 * @return The directions first character.
 */
char JumblePuzzle::generateRandomDirection() {
	switch(rand() % 4) {
		case 0:
			return 'n';
		case 1:
			return 'e';
		case 2:
			return 's';
		case 3:
			return 'w';
	}
}

/**
 * Checks whether a position in the jumble is valid.
 * @param position A position in the jumble (int pairing)
 * @return True if the position is valid, otherwise false.
 */
bool JumblePuzzle::checkPosition(pair<int, int> position) {
	return (checkCoordinate(position.first) && checkCoordinate(position.second));
}

/**
 * Helper method to the position validator.
 * @param coordinate The coordinate in the puzzel.
 * @return True if coordinate is valid, false otherwise.
 */
bool JumblePuzzle::checkCoordinate(int coordinate) {
	return (coordinate >= 0 && coordinate < *size);
}

/**
 * Increment positon in th jumble, increment is specific to the direction.
 * @param position Position in the jumble.
 * @param direction Direction traveling.
 * @return New position after increment.
 */
pair<int, int> JumblePuzzle::updatePosition(pair<int, int> position, char direction) {
	switch(direction) {
		case 'n':
			position.second -= 1;
			break;
		case 'e':
			position.first += 1;
			break;
		case 's':
			position.second += 1;
			break;
		case 'w':
			position.first -= 1;
			break;
	}
	return position;
}

/* /////////////////////////////////////*/
/* Bad Jumble Exception Implementation */
/* ////////////////////////////////// */

/**
 * BadJumbleException constructor.
 * Utilizes initialisation list to intialize message member.
 * @param message The error message, or description of the exception.
 */
BadJumbleException::BadJumbleException(const string& message) : exceptionMessage(message) {}

/**
 * BadJumbleException error message method definition.
 * @return The error message that was passed when exception created.
 */
string BadJumbleException::what() const {
	return exceptionMessage; // output error message, initialized in constructor.
}
