#include "cPersonGenerator.h"
#include "SmartArray.h"
#include <random>
// Warning C26812 : Prefer 'enum class' over 'enum' (Enum.3)
#pragma warning( disable : 26812 )

#include <iostream>
#include <fstream>
#include <sstream>		// String Stream
#include <string>


cPersonGenerator::cPersonGenerator() {
	this->numNames = 0;
	this->numSurname = 0;
	this->numStreets = 0;
}
cPersonGenerator::~cPersonGenerator() {

}


bool cPersonGenerator::LoadCensusFiles(std::string babyNameFile, std::string surnameFile, std::string streetNameFile, std::string& errorString)
{
	// TODO: Put YOUR amazing code here!
	//std::ifstream ifSurnameFile(surnameFile);
	//if (!ifSurnameFile.is_open())
	//{
	//	std::cout << "Failed to open file: " << surnameFile << std::endl;
	//	std::cout << errorString << std::endl;
	//	return false;
	//}
	std::string theLine;
	////skip first entry column name
	//std::getline(ifSurnameFile, theLine);


	//while (std::getline(ifSurnameFile, theLine))
	//{

	//	std::stringstream ssLine(theLine);
	//	this->numSurname++;
	//	std::string token;
	//	unsigned int tokenCount = 0;
	//	while (std::getline(ssLine, token, ','))
	//	{
	//		if (tokenCount == 0)
	//		{
	//			this->surnameVec.addAtEnd(token);
	//		}
	//		// Ignore the other parts of the line
	//		tokenCount++;
	//	}
	//}


	std::ifstream ifBabyNameFile(babyNameFile);
	if (!ifBabyNameFile.is_open())
	{
		std::cout << "Failed to open file: " << babyNameFile << std::endl;
		std::cout << errorString << std::endl;
		return false;
	}



	while (std::getline(ifBabyNameFile, theLine))
	{
		this->numNames++;
		std::stringstream ssLine(theLine);

		std::string token;
		unsigned int tokenCount = 0;
		while (std::getline(ssLine, token, ','))
		{
			if (tokenCount == 0)
			{
				this->nameVec.addAtEnd(token);
			}
			// Ignore the other parts of the line
			tokenCount++;
		}
	}

	//std::ifstream ifStreetNameFile(streetNameFile);
	//if (!ifStreetNameFile.is_open())
	//{
	//	std::cout << "Failed to open file: " << streetNameFile << std::endl;
	//	std::cout << errorString << std::endl;
	//	return false;
	//}


	//skip first entry column name
	//std::getline(ifStreetNameFile, theLine);


	//while (std::getline(ifStreetNameFile, theLine))
	//{
	//	std::stringstream ssLine(theLine);
	//	this->numStreets++;
	//	std::string token;
	//	unsigned int tokenCount = 0;
	//	while (std::getline(ssLine, token, ','))
	//	{
	//		if (tokenCount == 1)
	//		{
	//			this->streetNameVec.addAtEnd(token);
	//		}
	//		if (tokenCount == 2) {
	//			this->streetTypeVec.addAtEnd(token);
	//		}
	//		if (tokenCount == 3) {
	//			this->streetDirec.addAtEnd(token);
	//		}
	//		// Ignore the other parts of the line
	//		tokenCount++;
	//	}
	//}


	return true;
}

unsigned int cPersonGenerator::getNumberOfNamesLoaded(void) {
	return this->numNames;
}
unsigned int cPersonGenerator::getNumberOfSurnamesLoaded(void) {
	return this->numSurname;
}
unsigned int cPersonGenerator::getNumberOfStreetsLoaded(void) {
	return this->numStreets;
}

// Randomly generates a person from the data
// Returns 0, NULL, or nullptr if it can't do this. 
//#include <random>
cPerson* cPersonGenerator::generateRandomPerson(void) {

	cPerson* newPerson = new cPerson();
	std::random_device rd;
	std::uniform_int_distribution<int> dist(100000000, 999999999);
	newPerson->SIN = dist(rd);

	if (nameVec.getSize() > 0) {
		std::uniform_int_distribution<int> distName(0, nameVec.getSize());
		newPerson->first = nameVec.getAt(distName(rd));
		std::uniform_int_distribution<int> distLocation(1, 20);
		newPerson->location.x = distLocation(rd);
		newPerson->location.y = distLocation(rd);
	}

	return newPerson;
}

// Here's a simple way to load the comma delimited files:
bool readCSVFile(void)
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