#include <iostream>
#include <fstream>
#include <sstream>
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

	std::cout << "\n\nYEO\n\n";
	cTracer->getPeopleCloserThanThis(666, 20.f, people, returnNumber);
	for (int i = 0; i < returnNumber; i++) {
		std::cout << people[i].first << " distance:" << people[i].distance << "\n";
	}

	cTracer->getPeopleCloserThanThis(20, people, returnNumber);
	std::cout << "\n\n";
	for (int i = 0; i < returnNumber; i++) {
		std::cout << people[i].first << " " << people[i].SIN << " "<< people[i].distance << "\n";
	}

}

