#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
#include "Writer.h"
using namespace std;

/**
 *
 * @param FileName is the file's path
 * @param freqWords an unordered map of the frequent words, after reading it
 */
void readFrequentWords(const string FileName, unordered_map <string, int>  & freqWords)
{
	ifstream instream(FileName.c_str());
	if (!instream.is_open())
	{
		cerr << "Error! Can't open file: " << FileName << "." << endl;
	}
	string str;
	while (getline(instream, str))
	{
		// Line contains string of length > 0 then save it in vector
		if(str.size() > 0)
		{
			freqWords[str] = 0;
		}

	}
	//Close The File
	instream.close();
}


/**
 * runs the program. first, reads the frequent words to an unoredred map. then, creating an
 * Writer object to the unknown text. after that, creates a vector of of Writer objects- so the
 * program can claculte fequencies between them and the unknown.
 * @param argc is the number of arguments.
 * @param argv is the input arguments.
 * @return
 */
int main(int argc, char* argv[])
{
	unordered_map <string, int> freqWords;
	readFrequentWords(argv[1], freqWords);

	Writer unknownText =  Writer(argv[2], freqWords);
	int i = 3;
	vector<Writer> writers;
	while (i < argc )
	{ // crating Writer objects to each text file
		Writer writer(argv[i], freqWords);
		writers.push_back(writer);
		i++;
	}
	map<string, double>  results;
	unknownText.results(writers, results); // calculating frequencies related to the 'unknown'.
	string winner = "";
	double max = 0;
	for(auto it = results.begin(); it != results.end(); it++)
	{
		cout << it ->first << it->second << endl; // printing results
		if(it->second > max)
		{
			max = it->second;
			winner = it->first;
		}

	}
	cout << "Best matching author is " << winner << " " << max << endl;

	return 0;
}

