#pragma once

#include "cPerson.h"
#include "SmartArray.h"
class cContactTracer
{
public:
	
	SmartArray<cPerson*> peopleVec;

	cContactTracer();
	void addPerson(cPerson* pPerson);
	void movePerson(unsigned int SIN, cPoint2D amountToMove);
	cPerson* getPerson(unsigned int SIN);
	void getPeople(cPerson*& people, unsigned int& numberOfPeople);
	void getPeopleCloserThanThis(float distance, cPerson*& people, unsigned int& numberOfPeople);
	void getPeopleCloserThanThis(unsigned int SIN, float distance,
		cPerson*& people, unsigned int& numberOfPeople);
};
