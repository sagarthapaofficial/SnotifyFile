#include "cMusicGenerator.h"
#include <fstream>
#include <iostream>
#include "cSmartArrayVector.h"
#include <string>
#include <sstream>
#include <ctime>
#include "cSong.h"
using namespace std;


cMusicGenerator::cMusicGenerator()
{
	
}
cMusicGenerator::~cMusicGenerator()
{

}

bool cMusicGenerator::LoadMusicInformation(std::string musicFileName, std::string& errorString)
{

	std::ifstream musicFile(musicFileName);
	string line;
	if (!musicFile)
	{
		errorString = "Unable to open file";
		return false;
	}
	getline(musicFile, line);
	while (getline(musicFile, line))
	{
		std::stringstream ssLine(line);

		std::string token;
		unsigned int tokenCount = 0;

		while (std::getline(ssLine, token, ','))
		{
			if (tokenCount==3 )
			{
				this->songNameVec.PushAtBack(token);
			}
			 if (tokenCount == 4)
			{

				this->artistNameVec.PushAtBack(token);
			}
			// Ignore the other parts of the line
			tokenCount++;

		}
	}	
}

cSong* cMusicGenerator::getRandomSong(void)
{
	cSong *song= new cSong();
	if (true)
	{
		;
		const unsigned int INCREMENT_VALUE = songNameVec.getSize();
		int randomIndex=10;
		srand(((unsigned)time(0)));
		randomIndex += rand()%219;
		song->name = songNameVec[randomIndex];
		song->artist = artistNameVec[randomIndex];
		song->numberOfTimesPlayed++;
		return song;
	}
	else
	{
		return 0;
	}

}

// Returns 0, NULL, or nullptr if no song is found
// This must be an EXACT MATCH for what's in the billboard100 file. 
// So case sensitive, etc. 
cSong* cMusicGenerator:: findSong(std::string songName, std::string artist)
{
	cSong* song = new cSong();
	for (int i = 0; i < songNameVec.getSize(); i++)
	{
		if (songName == songNameVec[i] && artist ==artistNameVec[i])
		{
		 song->artist= this->artistNameVec[i];
		 song->name = this->songNameVec[i];
		 return song;

		}

	}
	return nullptr;
}
