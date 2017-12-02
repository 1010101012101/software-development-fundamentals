/**
 * CMPE 320 - Fundamentals of Software Development - Assignment 1
 * insultgenerator_15rws.cpp
 * Purpose: Implement a shakespearean insult generator.
 *
 * @author Robert Saunders (Student Number: 10194030, NetId: 15rws)
 * @version 1.0 03/10/2017
 */

#include "insultgenerator_15rws.h"

/* Insult Generator Implementation */

/**
 * Empty constructor for the Insult Generator class.
 * Overrides compiler creating default constructor.
 */
InsultGenerator::InsultGenerator() = default;

/**
 * Initialize method for the Insult Generator.
 * Fetches the insults from the source file and populates vectors.
 * NOTE: One task to improve code could be to implement a 3D vector.
 * @throws FileException when the input file cannot be read properly.
 */
void InsultGenerator::initialize() {
    string line;
    ifstream fileIn(INSULTS_SOURCE); // ref to input file
    totalInsults = 0; // begin counter of number of insults

    // populate the column vectors
    if (fileIn.is_open()){ // if the file is open continue
        while (!fileIn.eof()) { // if not the end of file
            fileIn >> line;
            col1.push_back(line);
            fileIn >> line;
            col2.push_back(line);
            fileIn >> line;
            col3.push_back(line);
            totalInsults++;
        }
        fileIn.close(); // close file
    }
    else if (fileIn.fail()) { // if file open error
        throw FileException(FILE_EXCEPTION__READ_ERROR);
    }
}

/**
 * Generates on single random insult.
 * @return The random insult.
 */
string InsultGenerator::talkToMe() {
    string insult("Thou ");
    insult += col1.at(randomInt(totalInsults)); // retrieve random insult from col1
    insult += ", " + col2.at(randomInt(totalInsults)) + " "; // retrieve random insult from col2
    insult += col3.at(randomInt(totalInsults)) + "!"; // retrieve random insult from col3
    return insult;
}

/**
 * Generates random unique number of insults.
 * @param numInsults The number of insults to generate.
 * @return vector of the insults
 */
vector<string> InsultGenerator::generate(const int numInsults) {

    // fist check if the number of insults requested is outside of bounds, throw exception if so.
    if (numInsults < INSULTS_LOWER_BOUND || numInsults > INSULTS_UPPER_BOUND){
        throw NumInsultsOutOfBounds(BOUND_EXCEPTION_ERROR);
    }

    set<string> setOfInsults;  // define set, special store that validates uniqueness, note elements are sorted using the internal weak comparison object, so by default alphabetical is achieved
    string insult; // define a single insult for reuse in loop

    while (numInsults > setOfInsults.size()) { //
        insult = string(talkToMe()); // retrieve one random insult
        setOfInsults.insert(insult); // populate the set, will skip if the insult is not unique
    }

    vector<string> insults; // create an insult vector
    copy(setOfInsults.begin(), setOfInsults.end(), back_inserter(insults)); // copy contents of set into vector

    return insults;
}

/**
 * Generates random insults and saves to the designated file.
 * @param filename The desired filename to save the insults to.
 * @param numInsults The number of insults to save to file.
 */
void InsultGenerator::generateAndSave(const string filename, const int numInsults){
    int lineNumber = 0; // reference to the line in output file
    vector <string> insultVector = generate(numInsults); // generate insults
    ofstream fileOut(filename); // create reference to output file

    // first check if we can output, throw exception if cannot.
    if (fileOut.fail()) {
        throw FileException(FILE_EXCEPTION__WRITE_ERROR);
    }

    // iterate through insults and populate output document.
    while (lineNumber < numInsults) {
        fileOut << insultVector[lineNumber] <<endl; // print the insult on the line
        lineNumber++; // move to the next line number
    }

    fileOut.close(); // close the output file
}

/**
 * Generates a random integer.
 * NOTE: Could use the <random> library in C++ 11 for better results.
 * Told not to use it to support more systems, for now this is sufficient.
 * @param limit The limit for the random function.
 * @return A random number, based upon rand limit.
 */
int InsultGenerator::randomInt(const int limit) const {
    return rand() % limit; // see method comment, about random implementation
}

/* File Exception Implementation */

/**
 * File exception constructor.
 * Utilizes initialisation list to intialize message member.
 * @param m The error message.
 */
FileException::FileException(const string& message) : exceptionMessage(message) {}

/**
 * File exception error message method definition.
 * @return The error message that was passed when exception created.
 */
string FileException::what() const {
    return exceptionMessage; // output error message, initialized in constructor.
}

/* Number Insults Out of Bounds Exception Implementation */

/**
 * Number of insults out of bounds exception constructor.
 * Utilizes initialisation list to intialize message member.
 * @param m The error message.
 */
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : exceptionMessage(message) {}

/**
 * Number of insults out of bounds error message method definition.
 * @return The error message that was passed when exception created.
 */
string NumInsultsOutOfBounds::what() const {
    return exceptionMessage; // output error message, initialized in constructor.
}