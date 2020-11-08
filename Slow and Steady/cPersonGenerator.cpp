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


	std::string theLine;
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
