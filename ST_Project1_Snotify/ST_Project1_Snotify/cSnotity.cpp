#include "cSnotify.h"
#include "cPerson.h";
#include "cSong.h"
#include <string>
#include <iostream>
#include <sstream>
#include "cSmartArrayVector.h"
#include <ctime>


using namespace std;

cSnotify::cSnotify()
{


}

// User Vec Vector
cSmartArrayVector<cPerson>userVec;
cSmartArrayVector<cSong>songVec;
cSmartArrayVector<cSong>libraryVec;
cSnotify::~cSnotify()
{

	// Nothing to do here

}

bool cSnotify:: AddUser(cPerson* pPerson, std::string& errorString)
{
	// Add user to the cSnotify	
	userVec.PushAtBack(*pPerson);
	return true;
	
}

// Add songs to the library
bool cSnotify::AddSong(cSong* pSong, std::string& errorString)
{
		songVec.PushAtBack(*pSong);
		return true;
}

// Deletes the user from the list
bool cSnotify::DeleteUser(unsigned int SnotifyUserID, std::string& errorString)
{

	for (int i = 0; i < userVec.getSize(); i++)
	{
		if (SnotifyUserID == userVec[i].getSnotifyUniqueUserID())
		{
			userVec.remove(i);
			return true;
		}
	}
	return false;

}
// This will overwrite the data contained in user 
	// NOTE: It "finds" the user by matching BOTH the "unique Snofity ID" AND the "SIN" 
	//        (Social Insurance Number)
	// So if either of these don't match (or aren't found) then it reutrns false. 

bool cSnotify:: UpdateUser(cPerson* pPerson, std::string& errorString)
{
	for (int i = 0; i < userVec.getSize(); i++)
	{
		if (pPerson->getSnotifyUniqueUserID()== pPerson->SIN)
		{
			pPerson->first = "Sagar";
			pPerson->last = "Thapa";
			pPerson->age = 19;
			pPerson->streetName ="ABC";
			pPerson->streetNumber =1234;
			pPerson->city = "London";
			pPerson->SIN = 9884373;
			return true;
		
		}

	}
		return false;
}

 //This finds a match, based on the "unique ID", and overwrites the data. 
bool cSnotify:: UpdateSong(cSong* pSong, std::string& errorString)
{
	cSong* song = new cSong();
	for (int i = 0; i < songVec.getSize(); i++)
	{
		if (pSong->getUniqueID())
		{
			pSong->name = "Adam";
			pSong->artist ="Byran";
			pSong->numberOfTimesPlayed++;
			pSong->rating = song->rating;
			return true;
		}
	}

	delete song;
return false;

}


 //Update the rating of the song
bool cSnotify ::UpdateRatingOnSong(unsigned int SnotifyUserID, unsigned int songUniqueID, unsigned int newRating)
{

	for (int i = 0; i < songVec.getSize(); i++)
	{
		if (songVec[i].getSnotifyUniqueUserID()== SnotifyUserID && songVec[i].getUniqueID()== songUniqueID)
		{
			songVec[i].rating=newRating;
			return true;
		}
	}

	return false;
}

// Returns 0, NULL, or nullptr if you can't find the song.
// (Can return optional information on errorString)
// 
// ****************************************************************************
// NOTE: This updates the "numberOfTimesPlayed" in THIS USER'S playlist-library

cSong* cSnotify:: GetSong(unsigned int SnotifyUserID, unsigned int songUniqueID, std::string& errorSt)
{
	cSong* song = new cSong();
	for (int i = 0; i < songVec.getSize(); i++)
	{
		if (songUniqueID == songVec[i].getUniqueID() && SnotifyUserID == songVec[i].getSnotifyUniqueUserID())
		{
			song[i].numberOfTimesPlayed++;
			return song;
		}
	}
	return 0;
}



bool cSnotify:: DeleteSong(unsigned int UniqueSongID, std::string& errorString)
{
	cSong* song = new cSong();
	if (song->getUniqueID()== UniqueSongID)
	{
		delete song;
		return true;
	}
	else
	{
		return false;
	}
}

//This associates a particular song with a particular user. 
//(returns true if the song is already there)

bool cSnotify:: AddSongToUserLibrary(unsigned int snotifyUserID, cSong* pNewSong, std::string& errorString)
{
	for (int i = 0; i < songVec.getSize(); i++)
	{
		if (snotifyUserID == songVec[i].getSnotifyUniqueUserID())
		{
			return true;
		}
		else
		{
			libraryVec.PushAtBack(*pNewSong);
			return true;

		}

	}

	return false;
}


bool cSnotify::RemoveSongFromUserLibrary(unsigned int snotifyUserID, unsigned int SnotifySongID, std::string& errorString)
{
	
	for (int i = 0; i < libraryVec.getSize(); i++)
	{
		if (snotifyUserID == libraryVec[i].getSnotifyUniqueUserID() && SnotifySongID == libraryVec[i].getUniqueID())
		{
			libraryVec.remove(i);
		}
	}
	return false;

}

// Note that the songRating is "returned" by reference. 
// If it can't find a match (i.e. returns false), then the rating isn't valid.

bool cSnotify:: GetCurrentSongRating(unsigned int snotifyUserID, unsigned int songUniqueID, unsigned int& songRating)
{
	cSong* song = new cSong();
	for (int i = 0; i < songVec.getSize(); i++)
	{
		if (snotifyUserID == songVec[i].getSnotifyUniqueUserID() && songUniqueID == songVec[i].getUniqueID())
		{
			song->rating = songVec[i].rating;
			song->numberOfTimesPlayed++;
			return true;

		}
	
	}
	delete song;
	return false;
}

bool cSnotify::GetCurrentSongNumberOfPlays(unsigned int snotifyUserID, unsigned int songUniqueID, unsigned int& numberOfPlays)
{
	cSong *song = new cSong();
	for (int i = 0; i < songVec.getSize(); i++)
	{
		if (snotifyUserID == songVec[i].getSnotifyUniqueUserID() && songUniqueID == songVec[i].getUniqueID())
		{
			numberOfPlays =song->numberOfTimesPlayed;
			return true;
		}
		else
		{

			return false;
		}
	}
	delete song;
}


// Returns 0, NULL, or nullptr if these fail
cPerson* cSnotify:: FindUserBySIN(unsigned int SIN)
{
	cPerson* person = new cPerson();
	for (int i = 0; i < userVec.getSize(); i++)
	{
		if (SIN == userVec[i].SIN)
		{
			person->SIN=userVec[i].SIN;
			return person;
		}
	}
	delete person;
	return 0;
}

// Finding user by snotify ID
cPerson* cSnotify::FindUserBySnotifyID(unsigned int SnotifyID)
{
	cPerson* person = new cPerson();

	for (int i = 0; i < userVec.getSize(); i++)
	{

		if (SnotifyID == userVec[i].getSnotifyUniqueUserID())
		{
			person->first= userVec[i].first;
			return person;
		}
	}
	delete person;
	return 0;
}

// Finding the song based on title and artist
cSong* cSnotify:: FindSong(std::string title, std::string artist)
{
	cSong* song= new cSong();
	for (int i = 0; i < songVec.getSize(); i++)
	{
		if (title == songVec[i].name && artist == songVec[i].artist)
		{
			song->name = songVec[i].name;
			song->artist = songVec[i].artist;
			return song;
		}
	}
	return 0;
}

// finding the song based on the unique ID
cSong* cSnotify::FindSong(unsigned int uniqueID)
{
	cSong* song= new cSong();
	for (int i = 0; i < songVec.getSize(); i++)
	{
		if (uniqueID == songVec[i].getUniqueID())
		{
			song->name = songVec[i].name;
			return song;
		}
	}
	return 0;
}

// Returns false if these don't work
	// This returns a COPY of the users library, in the form of a regular dynamic array.
// See the cSnotify.cpp file for more infomration on how this is supposed to work
// It will return false if it can't find that user

bool cSnotify::GetUsersSongLibrary(unsigned int snotifyUserID, cSong* & pLibraryArray, unsigned int& sizeOfLibary)
{
	// The caller would do something like this (assume the user ID = 28472382)
		
	/*	cSong* pTheSongs = 0;
		unsigned int arraySize = 0;
		GetUsersSongLibrary( 28472382, pTheSongs, arraySize );*/
	 
	 //Inside this method, you'd do something like this:

	// Alloate a heap based array to hold all the songs...
	// TODO: Find that user... 
	cSong* song = new cSong[sizeOfLibary];
	for (int i = 0; i < sizeOfLibary; i++)
	{
		if (true/*snotifyUserID == songVec[i].getSnotifyUniqueUserID()*/)
		{

			// TODO: Copy all the songs over
			song[i].name= songVec[i].name;
			song[i].artist=songVec[i].artist;
			song[i].rating=songVec[i].rating;
			song[i].numberOfTimesPlayed = songVec[i].numberOfTimesPlayed;
		}
	}

	cout << "After sorting" << endl;
	for (int i = 0; i < sizeOfLibary; i++)
	{
		pLibraryArray[i].name = song[i].name;
		pLibraryArray[i].artist = song[i].artist;
		pLibraryArray[i].numberOfTimesPlayed = song[i].numberOfTimesPlayed;
		pLibraryArray[i].rating = song[i].rating;
	}
	return true;


}

// Sorts based on the title of the song
void SortByTitle(cSong *song, unsigned int sizeOfArray)
{
	bool bDidSwap = false;

	do
	{
		// Reset the "did swap" flag
		bDidSwap = false;
		for (unsigned int index = 0; index < (sizeOfArray - 1); index++)
		{
			// Compare the "index" location with the next one
			// If they are out of order, then swap
			if (song[index].name > song[index + 1].name)
			{
				// Out of order, so swap
				cSong temp=song[index];
				song[index] = song[index + 1];
				song[index + 1] = temp;
				bDidSwap = true;
			}
		}
	} while (bDidSwap);

	return;
}

// Sort function that sorts the list based on artist
void SortByArtist(cSong* song, unsigned int sizeOfArray)
{
	bool bDidSwap = false;

	do
	{
		// Reset the "did swap" flag
		bDidSwap = false;
		for (unsigned int index = 0; index < (sizeOfArray - 1); index++)
		{
			// Compare the "index" location with the next one
			// If they are out of order, then swap
			if (song[index].artist> song[index + 1].artist)
			{
				// Out of order, so swap
				cSong temp = song[index];
				song[index] = song[index + 1];
				song[index + 1] = temp;
				bDidSwap = true;
			}
		}
	} while (bDidSwap);

	return;
}







// Same, but array is sorted by song title in ascending order ("A to Z")
bool cSnotify::GetUsersSongLibraryAscendingByTitle(unsigned int snotifyUserID, cSong*& pLibraryArray, unsigned int& sizeOfLibary)
{
	cSong* song = new cSong[sizeOfLibary];
	for (int i = 0; i < sizeOfLibary; i++)
	{
		if (true/*snotifyUserID == songVec[i].getSnotifyUniqueUserID()*/)
		{

			// TODO: Copy all the songs over
			song[i].name = songVec[i].name;
			song[i].artist = songVec[i].artist;
			song[i].rating = songVec[i].rating;
			song[i].numberOfTimesPlayed = songVec[i].numberOfTimesPlayed;
		}
	}
	
	SortByTitle(song,sizeOfLibary);
	
	for (int i = 0; i < sizeOfLibary; i++)
	{
		pLibraryArray[i].name = song[i].name;
		pLibraryArray[i].artist = song[i].artist;
		pLibraryArray[i].numberOfTimesPlayed = song[i].numberOfTimesPlayed;
		pLibraryArray[i].rating = song[i].rating;
	}
	return true;


}

// Same, but array is sorted by artist name, ascending ("A to Z")

bool cSnotify::GetUsersSongLibraryAscendingByArtist(unsigned int snotifyUserID, cSong*& pLibraryArray, unsigned int& sizeOfLibary)
{
	cSong* song = new cSong[sizeOfLibary];
	for (int i = 0; i < sizeOfLibary; i++)
	{
		if (true/*snotifyUserID == songVec[i].getSnotifyUniqueUserID()*/)
		{

			// TODO: Copy all the songs over
			song[i].name = songVec[i].name;
			song[i].artist = songVec[i].artist;
			song[i].rating = songVec[i].rating;
			song[i].numberOfTimesPlayed = songVec[i].numberOfTimesPlayed;
		}
	}

	SortByArtist(song, sizeOfLibary);

	for (int i = 0; i < sizeOfLibary; i++)
	{
		pLibraryArray[i].name = song[i].name;
		pLibraryArray[i].artist = song[i].artist;
		pLibraryArray[i].numberOfTimesPlayed = song[i].numberOfTimesPlayed;
		pLibraryArray[i].rating = song[i].rating;
	}
	return true;

}

// Get user details from ther user library

bool cSnotify::GetUsers(cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray)
{

	pAllTheUsers = new cPerson[sizeOfUserArray];

	for (int i = 0; i < sizeOfUserArray; i++)
	{
		pAllTheUsers[i].first = userVec[i].first;
		pAllTheUsers[i].last = userVec[i].last;
		pAllTheUsers[i].gender = userVec[i].gender;
		pAllTheUsers[i].gender = userVec[i].gender;
		pAllTheUsers[i].streetName = userVec[i].streetName;
		pAllTheUsers[i].streetNumber = userVec[i].streetNumber;
		pAllTheUsers[i].province = userVec[i].streetNumber;

	}

	return true;
}
// sorts the list based on userID
void SortByUserID(cPerson* person, unsigned int sizeOfArray)
{
	bool bDidSwap = false;

	do
	{
		// Reset the "did swap" flag
		bDidSwap = false;
		for (unsigned int index = 0; index < (sizeOfArray - 1); index++)
		{
			// Compare the "index" location with the next one
			// If they are out of order, then swap
			if (person[index].getSnotifyUniqueUserID() > person[index + 1].getSnotifyUniqueUserID())
			{
				// Out of order, so swap
				cPerson temp = person[index];
				person[index] = person[index + 1];
				person[index + 1] = temp;
				bDidSwap = true;
			}
		}
	} while (bDidSwap);

	return;
}



// Sorded ascending by Snotify ID
bool cSnotify:: GetUsersByID(cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray)
{
	cPerson* person = new cSong[sizeOfUserArray];
	for (int i = 0; i < sizeOfUserArray; i++)
	{
		if (true/*snotifyUserID == songVec[i].getSnotifyUniqueUserID()*/)
		{
			person[i].first = userVec[i].first;
			person[i].last = userVec[i].last;
			person[i].gender = userVec[i].gender;
			person[i].gender = userVec[i].gender;
			person[i].streetName = userVec[i].streetName;
			person[i].streetNumber = userVec[i].streetNumber;
			person[i].province = userVec[i].streetNumber;
		}
	}

	SortByUserID(person, sizeOfUserArray);

	for (int i = 0; i < sizeOfUserArray; i++)
	{
		pAllTheUsers[i].first = person[i].first;
		pAllTheUsers[i].last = person[i].last;
		pAllTheUsers[i].gender = person[i].gender;
		pAllTheUsers[i].gender = person[i].gender;
		pAllTheUsers[i].streetName = person[i].streetName;
		pAllTheUsers[i].streetNumber = person[i].streetNumber;
		pAllTheUsers[i].province = person[i].streetNumber;
	}
	return true;

}

// sorts based on user firstName
void SortByFirstname(cPerson* person, unsigned int sizeOfArray)
{
	bool bDidSwap = false;

	do
	{
		// Reset the "did swap" flag
		bDidSwap = false;
		for (unsigned int index = 0; index < (sizeOfArray - 1); index++)
		{
			// Compare the "index" location with the next one
			// If they are out of order, then swap
			if (person[index].first > person[index + 1].first)
			{
				// Out of order, so swap
				cPerson temp = person[index];
				person[index] = person[index + 1];
				person[index + 1] = temp;
				bDidSwap = true;
			}
		}
	} while (bDidSwap);

	return;
}



// These should all be sorted ascending ("A to Z") IF there are duplicates
bool cSnotify:: FindUsersFirstName(std::string firstName, cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray)
{
	cPerson* person = new cSong[sizeOfUserArray];
	for (int i = 0; i < sizeOfUserArray; i++)
	{
		if (userVec[i].first==firstName)
		{
			person[i].first = userVec[i].first;
		}
	}

	SortByFirstname(person, sizeOfUserArray);

	for (int i = 0; i < sizeOfUserArray; i++)
	{
		pAllTheUsers[i].first = person[i].first;
	}
	return true;

}

// sorts based on lastName
void SortByLastname(cPerson* person, unsigned int sizeOfArray)
{
	bool bDidSwap = false;

	do
	{
		// Reset the "did swap" flag
		bDidSwap = false;
		for (unsigned int index = 0; index < (sizeOfArray - 1); index++)
		{
			// Compare the "index" location with the next one
			// If they are out of order, then swap
			if (person[index].last > person[index + 1].last)
			{
				// Out of order, so swap
				cPerson temp = person[index];
				person[index] = person[index + 1];
				person[index + 1] = temp;
				bDidSwap = true;
			}
		}
	} while (bDidSwap);

	return;
}




// Find the user based on lastName
bool cSnotify::FindUsersLastName(std::string lastName, cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray)
{
	cPerson* person = new cSong[sizeOfUserArray];
	for (int i = 0; i < sizeOfUserArray; i++)
	{
		if (userVec[i].last== lastName)
		{
			person[i].last = userVec[i].last;
		}
	}

	SortByLastname(person, sizeOfUserArray);

	for (int i = 0; i < sizeOfUserArray; i++)
	{
		pAllTheUsers[i].first = person[i].first;
	}
	return true;

}



// Sorted ascending by last name THEN first name.
bool cSnotify:: FindUsersFirstLastNames(std::string firstName, std::string lastName, cPerson*& pAllTheUsers, unsigned int& sizeOfUserArray)
{
	cPerson* person = new cSong[sizeOfUserArray];
	for (int i = 0; i < sizeOfUserArray; i++)
	{
		if (userVec[i].last == lastName && userVec[i].first== firstName)
		{
			person[i].last = userVec[i].last;
			person[i].first = userVec[i].first;

		}
	}
	// sort byy lastname 
	SortByLastname(person, sizeOfUserArray);
	SortByFirstname(person, sizeOfUserArray);

	for (int i = 0; i < sizeOfUserArray; i++)
	{
		pAllTheUsers[i].first = person[i].first;
	}
	return true;
	

}


ostream& operator <<(ostream& os, cSong& cSong)
{
	return os << cSong.artist << " " << cSong.name << " ";
}



int main()
{
	cSnotify *c1= new cSnotify;
	cSnotify *c2= new cSnotify;
	string error;
	cMusicGenerator* music = new cMusicGenerator();
	cMusicGenerator* music1 = new cMusicGenerator();


	music->LoadMusicInformation("Hot Stuff.csv", error);
	music1->LoadMusicInformation("Hot Stuff.csv", error);


		cSong*song = music->getRandomSong();
		cPerson* person = new cPerson();
		cSong* song1 = new cSong("ram", "Sagar");
		song1 = new cSong("hari", "Asish");
		 song1 = new cSong("radhe", "Manish");
		cSong* song4 = new cSong("radhe", "Lanish");
		cSong *song5 = new cSong();

		c1->AddSong(song, error);
		c2->AddSong(song1, error);
		c2->AddSong(song4, error);
		c2->AddSong(song5, error);
		c2->AddSong(song4, error);

		c2->AddUser(person, error);




		for (int i = 0; i < songVec.getSize(); i++)
		{
			cout << songVec[i] << endl;
		}

		unsigned int arraySize = songVec.getSize();
		
		cSong* pTheSongs= new cSong[songVec.getSize()];

	
		c1->GetUsersSongLibraryAscendingByTitle(10021, pTheSongs, arraySize);
		cout << "After Sorting" << endl;
		for (int i = 0; i < songVec.getSize(); i++)
		{
			cout << pTheSongs[i].name << " " << pTheSongs[i].artist <<" "<<pTheSongs[i].getUniqueID()<<" "<<pTheSongs[i].rating<< endl;

		}


		delete []pTheSongs;
	
		return 0;
		
}