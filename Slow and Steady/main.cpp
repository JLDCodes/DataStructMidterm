#include <iostream>
#include <fstream>
#include <sstream>		// String Stream
#include <string>
#include "SmartArray.h"
#include "cPersonGenerator.h"
#include "cContactTracer.h"
#include "cPoint2D.h"





int main()
{
	cPersonGenerator* pGen = new cPersonGenerator;
	std::string error = "Error!!!";
	pGen->LoadCensusFiles("yob1880.txt", "Names_2010Census.csv", "Street_Names.csv", error);

	//std::cout << "Number of names: " << pGen->getNumberOfNamesLoaded() << ", Number of surnames: " << pGen->getNumberOfSurnamesLoaded() << ", number of street names: " << pGen->getNumberOfStreetsLoaded() << "\n";
	//std::cout << "First: " << pGen->nameVec.getAt(0) << ", " << pGen->surnameVec.getAt(0) << ", " << pGen->streetNameVec.getAt(0) << "\n";

	//for (unsigned int i = 0; i < pGen->getNumberOfNamesLoaded(); i++) {
	//	std::cout << pGen->nameVec.getAt(i) << ", " << pGen->surnameVec.getAt(i) << ", " << pGen->streetNameVec.getAt(i) << "\n";
	//}

	SmartArray<cPerson*> pepVec;
	pepVec.addAtEnd(pGen->generateRandomPerson());
	pepVec.addAtEnd(pGen->generateRandomPerson());
	pepVec.addAtEnd(pGen->generateRandomPerson());


	cContactTracer* cTracer = new cContactTracer();

	for (int i = 0; i < 10; i++) {
		cTracer->addPerson(pGen->generateRandomPerson());
	}
	unsigned int sinToFind = cTracer->peopleVec.getAt(7)->SIN;
	//std::cout << sinToFind << "\n";
	for (int i = 0; i < 10; i++) {
		std::cout << cTracer->peopleVec.getAt(i)->first << " " << cTracer->peopleVec.getAt(i)->SIN << "\n";
	}
	cPerson* bob = cTracer->getPerson(sinToFind);

	bob->SIN = 666;

	//std::cout << cTracer->peopleVec.getAt(7)->SIN << "\n";

	cPoint2D point = cPoint2D(10.f, 12.f);
	//std::cout << point.x << " " << point.y << "\n";
	cTracer->movePerson(666, point);
	//std::cout << bob->location.x << " " << bob->location.y << "\n";

	cPerson* people = new cPerson[cTracer->peopleVec.getSize()];
	unsigned int returnNumber = 4;
	//cTracer->getPeople(people, returnNumber);
	//
	//for (int i = 0; i < returnNumber; i++) {
	//	std::cout << people[i].first << "\n";
	//}
	//
	//people[0].first = "FIRSTCOPY";
	//for (int i = 0; i < returnNumber; i++) {
	//	std::cout << people[i].first << "\n";
	//}
	//std::cout << "copy?" << "\n";
	//for (unsigned int i = 0; i < cTracer->peopleVec.getSize(); i++) {
	//	std::cout << cTracer->peopleVec.getAt(i)->first << "\n";
	//}
	//for (int i = 0; i < returnNumber; i++) {
	//	std::cout << people[i].first << "\n";
	//}

	std::cout << "\n\nYEO\n\n";
	cTracer->getPeopleCloserThanThis(666, 20.f, people, returnNumber);
	for (int i = 0; i < returnNumber; i++) {
		std::cout << people[i].first << " distance:" << people[i].distance << "\n";
	}

	
	//SmartArray<int> test;
	//test.addAtEnd(5);
	//test.addAtEnd(4);
	//test.addAtEnd(70);
	//test.addAtEnd(99);
	//test.addAtEnd(69);
	//test.quickSort(0, test.getSize() - 1);
	//for (int i = 0; i < 5; i++) {
	//	std::cout << test.getAt(i) << "\n";
	//}


}

