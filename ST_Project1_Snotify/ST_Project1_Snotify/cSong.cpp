#include "cSong.h"

cSong::cSong()
{
	srand(time(0));
	this->uniqueID =nextuniqueID;
	this->rating = rand() % 6;
	this->numberOfTimesPlayed = 0;
	nextuniqueID++;
}

cSong::cSong(std::string artist, std::string songName) : artist(artist), name(songName) {

	this->numberOfTimesPlayed = 0;
	this->uniqueID += rand() % 6;
	this->rating = rand() % 6;
}

unsigned int cSong::nextuniqueID = 1000;