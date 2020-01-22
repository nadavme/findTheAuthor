//
// Created by prinm on 1/2/2019.
//

#ifndef EX2_WRITER_H
#define EX2_WRITER_H


#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
#include <string>
#include <iostream>
#include <boost/tokenizer.hpp>

using namespace std;

/**
 *A class of object Writer that holds textWords, frequencies, path and norm.
 */
class Writer
{

private:

    string _name;
    unordered_map <string, int> _freqWords;
    vector<string> _textWords;
    double _norm;

public:

    /**
     *define the attributes of object Writer
     * @param name file path
     * @param freqWords map of the frequent words
     */
    Writer(string name, unordered_map<string, int> & freqWords);

    /**
     * results of the scalar multipication related to the a single Writer instant.
     * @param writers
     * @param results
     */
    void results(const vector<Writer> & writers , map<string, double> & results);

    /**
     * reding the text file and separating it by lines and get rid of the separators
     * @param filename file path
     * @param _textWords map of the frequent words
     */
    void getTextWords(string filename , vector<string> & textWords);

    /**
     *counting the frequencies on the instant Writer object related to the freqWords.
     */
    void getFrequencies();

    /**
     * calculate the scalar multipication comparing to a given textWords
     * @param unknown is the Writer object we calculate for
     * @return ad double which represent the result
     */
    const double calculate(const Writer & unknown) const;

    /**
     * clculate the norm
     * @return double
     */
    double calculateNorm() const;

    /**
     * A getter
     */
    const double& getNorm() const;

    /**
     * A getter
     * @return
     */
    const string& getName() const;

    /**
     * destructor
     */
    ~Writer();

};


#endif //EX2_WRITER_H
