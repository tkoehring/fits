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
	int dist, naxis, length, width, i;
	int s = 2880;
	char *buffer = new char[s*3];
	char *buf2 = new char[s*3];

	//getline(myFile, line);
	//word = "";

	myFile.read(buffer, s*3);

	if(myFile)
	{
		std::cout << "Read all chars" << std::endl;
	}
	else
	{
		std::cout << "error onyl read " << myFile.gcount() << std::endl;
	}
	std::cout << "Data" << std::endl << buffer << std::endl;

	myFile.read(buf2, s*3);
	std::cout << "First data block" << std::endl << buf2 << std::endl;

	/*
	i = 0;
	while(i < line.length() && word != "END")
	{
		if(!isspace(line[i]))
		{
			word += line[i];
		}
		else
		{
			if(word != "")
			{
				std::cout << "Adding: " << word << std::endl;
				words.push_back(word);
			}
			word = "";
		}
		i++;
	}
	words.push_back(word);
	std::cout << "Added " << i << " chars" << std::endl;
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
	std::cout << "Last Word: " << words.back() << std::endl;*/
	return 0;
}
