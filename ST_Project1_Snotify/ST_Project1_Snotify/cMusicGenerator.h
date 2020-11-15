#ifndef cMusicGenerator_HG_
#define cMusicGenerator_HG_

#include "cSong.h"
class cMusicGenerator
{
public:
	cMusicGenerator();
	virtual ~cMusicGenerator();

	bool LoadMusicInformation(std::string musicFileName, std::string& errorString);

	cSong* getRandomSong(void);

	// Returns 0, NULL, or nullptr if no song is found
	// This must be an EXACT MATCH for what's in the billboard100 file. 
	// So case sensitive, etc. 
	cSong* findSong(std::string songName, std::string artist);
	cSmartArrayVector<std::string>songNameVec;
	cSmartArrayVector<std::string>artistNameVec;


};

#endif

