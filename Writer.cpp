//
// Created by prinm on 1/2/2019.
//

#include "Writer.h"

using namespace std;
using namespace boost;

/**
 *define the attributes of object Writer
 * @param name file path
 * @param freqWords map of the frequent words
 */
Writer::Writer(const string name, unordered_map <string, int> & freqWords)
{
    _name = name;
    _freqWords = freqWords;
    getTextWords(_name, _textWords);
    getFrequencies();
    _norm = calculateNorm();
}

/**
 * reding the text file and separating it by lines and get rid of the separators
 * @param filename file path
 * @param _textWords map of the frequent words
 */
void Writer::getTextWords(const string filename , vector<string> & _textWords)
{
    ifstream instream(filename.c_str());
    if (!instream.is_open())
    {
        std::cerr << "Error! Can't open file: " << filename << "." << std::endl;
    }
    string str;
    while (getline(instream, str))
    {
        // Line contains string of length > 0 then save it in vector after parsing the separators
        if (!str.empty())
        {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            typedef tokenizer<boost::char_separator<char>> tokenizer;
            char_separator<char> sep{",!:;\"\n\r "};
            tokenizer tok{str, sep};
            for (const auto &t : tok)
            {
                _textWords.push_back(t);
            }
        }
    }
//    Close The File
    instream.close();
}

/**
 * counting the frequncies at each file
 * @param freqWords map
 */
void Writer::getFrequencies()
{
    for (const auto &_textWord : _textWords)
    {
        auto it = _freqWords.find(_textWord);
        if(it != _freqWords.end())
        {
            _freqWords[_textWord]++;
        }
    }
}
/**
 * In header file
 * @param writers
 * @param results
 */
void Writer::results(const vector<Writer> & writers , map<string, double> & results)
{
	for (const auto &writer : writers)
	{
		results[writer.getName()] = calculate(writer);
	}
}

/**
 * In header file
 * @param unknown
 * @return
 */
const double Writer::calculate(const Writer & unknown) const
{
    double  res = 0;
    double vecMult = 0;
    auto it_unknown = unknown._freqWords.begin();
    for (const auto &_freqWord : _freqWords)
    {
        vecMult += (_freqWord.second * it_unknown->second);
        ++it_unknown;
    }
    if ((getNorm() * unknown.getNorm()) != 0) 
    {
        res = vecMult / (getNorm() * unknown.getNorm());
        return res;
    }
    return 0;
}

/**
 * In header file
 * @return
 */
double Writer::calculateNorm() const
{
    double norm = 0;
    for (const auto &_freqWord : _freqWords)
    {
        norm += pow(_freqWord.second, 2);
    }
    return sqrt(norm);
}

/**
 * In header file
 * @return
 */
const double& Writer::getNorm() const
{
	return _norm;
}

/**
 * In header file
 * @return
 */
const string& Writer::getName() const
{
	return _name;
}
Writer::~Writer() = default;
