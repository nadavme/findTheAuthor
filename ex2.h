//
// Created by nadav.meidan on 1/2/19.
//

#ifndef EX2_EX2_H
#define EX2_EX2_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
#include "Writer.h"

//--------------------------------------------------------------------------------------
//      This file contains the implementation of the class ex2cpp-.
//--------------------------------------------------------------------------------------
//------------------ Access methods ------------------------

// ------------------ Modify methods ------------------------

// ------------------ Other methods ------------------------

/**
 *
 * @param FileName is the file's path
 * @param freqWords an unordered map of the frequent words, after reading it
 */

void readFrequentWords(string FileName, unordered_map<string, int>  & freqWords);



#endif //EX2_EX2_H
