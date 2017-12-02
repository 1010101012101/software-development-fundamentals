/**
 * CMPE 320 - Fundamentals of Software Development - Assignment 1
 * insultgenerator_15rws.h
 * Purpose: Implement a shakespearean insult generator.
 *
 * @author Robert Saunders (Student Number: 10194030, , NetId: 15rws)
 * @version 1.0 03/10/2017
 */

#ifndef ASSN1_15RWS_INSULTGENERATOR_15RWS_H_H
#define ASSN1_15RWS_INSULTGENERATOR_15RWS_H_H

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

const string INSULTS_SOURCE("InsultsSource.txt"); // constant to reference insult text file.
const string FILE_EXCEPTION__READ_ERROR("The input file could not be read correctly!");
const string FILE_EXCEPTION__WRITE_ERROR("The output file could not be written correctly!");
const string BOUND_EXCEPTION_ERROR("The number of insults must be within the correct bounds!");
const int INSULTS_UPPER_BOUND(10000); // constant to reference upper bound for number of insults to generate.
const int INSULTS_LOWER_BOUND(1); // const to reference lower bound for number of insults to generate.

/**
 * The insult generator class declaration.
 * Class used to generate shakespearean insults.
 */
class InsultGenerator {
    public:
        InsultGenerator(); // empty class constructor
        void initialize(); // intializes the insult generator, reads file
        string talkToMe(); // generates one random insult
        vector<string> generate(int numInsults); // generates a number of unique insults
        void generateAndSave(string filename, int numInsults); // generates insults and saves to file
    private:
        int totalInsults; // counter used for bound of rand() function
        vector<string> col1; // stores contents of first column in input file
        vector<string> col2; // stores contents of second column in input file
        vector<string> col3; // stores contents of third column in input file
        int randomInt(int) const; // generates a random number
};

/**
 * The file exception class declaration.
 * Class used to define file operation exceptions.
 */
class FileException {
    public:
        explicit FileException(const string&); // constructor that takes reference to sting type, marked explicit to avoid possible implicit conversion
        string what() const; // method to return the exception message
    private:
        const string exceptionMessage; // exception message
};

/**
 * The num insults out of bounds class declaration.
 * Class used to define max insult bound exceptions.
 */
class NumInsultsOutOfBounds {
    public:
        explicit NumInsultsOutOfBounds(const string&); // constructor that takes reference to sting type, marked explicit to avoid possible implicit conversion
        string what() const; // method to return the exception message
    private:
        const string exceptionMessage; // exception message
};

#endif
