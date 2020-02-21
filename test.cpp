#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "ctype.h"

int main()
{
	std::string line, word;
	std::ifstream myFile("test.fits", std::ios::in | std::ios::binary);
	std::vector<std::string> words;
	std::vector<std::string>::iterator iter;
	int dist, naxis, length, width;

	getline(myFile, line);

	for(int i = 0; i < line.length(); i++)
	{
		if(!isspace(line[i]))
		{
			word += line[i];
		}
		else
		{
			if(word != "")
			{
				words.push_back(word);
			}
			word = "";
		}
	}

	iter = std::find(words.begin(), words.end(), "NAXIS");
	dist = std::distance(words.begin(), iter);

	if(iter != words.end())
	{
		naxis = stoi(words[dist + 2]);
	}

	iter = std::find(words.begin(), words.end(), "NAXIS1");
	dist = std::distance(words.begin(), iter);

	if(iter != words.end())
	{
		length = stoi(words[dist + 2]);
	}

	iter = std::find(words.begin(), words.end(), "NAXIS2");
	dist = std::distance(words.begin(), iter);

	if(iter != words.end())
	{
		width = stoi(words[dist + 2]);
	}

	std::cout << "NAXIS: " << naxis << std::endl << "NAXIS1: " << length << std::endl << "NAXIS2: " << width << std::endl;
	return 0;
}
