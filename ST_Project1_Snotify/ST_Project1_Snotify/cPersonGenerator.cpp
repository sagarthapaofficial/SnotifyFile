#include "cPersonGenerator.h"
#include <ctime> 
// Warning C26812 : Prefer 'enum class' over 'enum' (Enum.3)
#pragma warning( disable : 26812 )
#include "cPerson.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>	


using namespace std;

cPersonGenerator::cPersonGenerator(){}
cPersonGenerator::~cPersonGenerator() {}

unsigned int cPersonGenerator:: getNumberOfNamesLoaded(void)
{
	return vecfirstName.getSize();
}
unsigned int cPersonGenerator:: getNumberOfSurnamesLoaded(void)
{
	return SurnameVec.getSize();
}
unsigned int cPersonGenerator:: getNumberOfStreetsLoaded(void)
{
	return streetNameVec.getSize();
}

// Randomly generates a person from the data
// Returns 0, NULL, or nullptr if it can't do this. 
cPerson* cPersonGenerator::generateRandomPerson(void)
{
	cPerson* person= new cPerson();

	srand(((unsigned)time(0)));
	const unsigned int INCREMENT_VALUE = 200;
	int randomIndex = (rand() % INCREMENT_VALUE);
	person->first = this->vecfirstName[randomIndex];
	person->last = this->SurnameVec[randomIndex];
	person->streetName = this->streetNameVec[randomIndex];
	person->streetType = this->streetTypeVec[randomIndex];
	person->streetDirection = this->DirectionVec[randomIndex];
	person->gender= cPerson::eGenderType(rand() % 4);
	return person;
	delete person;

	return 0;
}

bool cPersonGenerator::LoadCensusFiles(
	std::string babyNameFile,
	std::string surnameFile,
	std::string streetNameFile,
	std::string& errorString)
{

	std::ifstream namesFile(babyNameFile);
	std::ifstream opensurname(surnameFile);
	std::ifstream addressFile(streetNameFile);

	string line;
	if (!namesFile)
	{
		errorString = "Unable to open file";
		return false;
	}


	while (getline(namesFile, line))
	{
		std::stringstream ssLine(line);

		std::string token;
		unsigned int tokenCount = 0;
		
		while (std::getline(ssLine, token, ','))
		{
			if (tokenCount == 0)
			{
				vecfirstName.PushAtBack(token);
			}
			// Ignore the other parts of the line
			tokenCount++;

		}
	}
	if (!opensurname)
	{
		errorString = "Unable to open file";
		cout << "unablel to open file" << endl;
			return false;
	}
	getline(opensurname, line);
	while (getline(opensurname, line))
	{
		std::stringstream ssLine(line);

		std::string token;
		unsigned int tokenCount = 0;

		while (std::getline(ssLine, token, ','))
		{
			if (tokenCount == 0)
			{
				SurnameVec.PushAtBack(token);
			}
			// Ignore the other parts of the line
			tokenCount++;

		}
	}

	if (!addressFile)
	{
		errorString = "Unable to open file";
		cout << "unablel to open file" << endl;
			return false;
	}
	getline(addressFile, line);
	while (getline(addressFile, line))
	{
		std::stringstream ssLine(line);

		std::string token=" ";
		unsigned int tokenCount = 0;

		while (std::getline(ssLine, token, ','))
		{
			if (tokenCount == 1)
			{
				streetNameVec.PushAtBack(token);
			}
			else if (tokenCount == 2)
			{
				streetTypeVec.PushAtBack(token);

			}
			else if (tokenCount == 3)
			{
				if (getline(ssLine, token, ' '))
				{
					DirectionVec.PushAtBack(token);
				}

			}
			// Ignore the other parts of the line
			tokenCount++;

		}
		DirectionVec.PushAtBack(token);
	
	}

		return true;
}

// Here's a simple way to load the comma delimited files:
bool readCSVFile()
{
	// Open the file
	std::ifstream namesFile("Names_2010Census.csv");
	if (!namesFile.is_open())
	{
		std::cout << "Didn't open file" << std::endl;
		return false;
	}

	// name,rank,count,prop100k,cum_prop100k,pctwhite,pctblack,pctapi,pctaian,pct2prace,pcthispanic
	// SMITH,1,2442977,828.19,828.19,70.9,23.11,0.5,0.89,2.19,2.4
	//
	// - rank is how popular the last name is, like 1st, 2nd, etc.
	// - count is how many people have that last name, so 2,442,977 people have last name "Smith"
	// - prop100k is the ratio per 100,000 people. Smith is 828.19, 
	//            meaning that there's a 828.19 out of 100,000 chance (0.82819% chance)
	//            that someone is named "Smith"

	std::string theLine;
	unsigned int lineCount = 0;
	
	while (std::getline(namesFile, theLine))
	{
		lineCount++;
		std::stringstream ssLine(theLine);

		std::string token;
		unsigned int tokenCount = 0;
		while (std::getline(ssLine, token, ','))
		{
			if (tokenCount == 0)
			{
				std::cout << token << std::endl;
			}
			// Ignore the other parts of the line
			tokenCount++;

		}
	
	}

	std::cout << "Lines read = " << lineCount << std::endl;

	return true;
}

