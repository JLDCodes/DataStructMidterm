#include "cContactTracer.h"
#include <iostream>

cContactTracer::cContactTracer() {

}
void cContactTracer::addPerson(cPerson* pPerson) {
	peopleVec.addAtEnd(pPerson);
}

cPerson* cContactTracer::getPerson(unsigned int SIN) {
	for (int i = 0; i < peopleVec.getSize(); i++) {
		if (peopleVec.getAt(i)->SIN == SIN) {
			return peopleVec.getAt(i);
		}
	}
	return nullptr;
}

void cContactTracer::movePerson(unsigned int SIN, cPoint2D amountToMove) {
	for (int i = 0; i < peopleVec.getSize(); i++) {
		if (peopleVec.getAt(i)->SIN == SIN) {
			peopleVec.getAt(i)->location.x += amountToMove.x;
			peopleVec.getAt(i)->location.y += amountToMove.y;
		}
	}
}


void cContactTracer::getPeople(cPerson*& people, unsigned int& numberOfPeople) {
	int count = 0;
	for (int i = 0; i < numberOfPeople; i++) {
		if (peopleVec.getAt(i) != nullptr) {
			count++;
			people[i] = *peopleVec.getAt(i);
		}
	}
	numberOfPeople = count;
}


bool operator < (cPerson const& lhs, cPerson const& rhs) {
	return lhs.distance < rhs.distance;
}

bool operator <= (cPerson const& lhs, cPerson const& rhs) {
	return lhs.distance <= rhs.distance;
}

void cContactTracer::getPeopleCloserThanThis(unsigned int SIN, float distance, cPerson*& people, unsigned int& numberOfPeople) {
	
	cPerson* prototype = cContactTracer::getPerson(SIN);
	if (prototype == nullptr) {
		numberOfPeople = 0;
		return;
	}

	SmartArray<cPerson> vec;
	unsigned count = 0;
	for (int i = 0; i < peopleVec.getSize(); i++) {
		if ((cPerson::getDistanceBetween(prototype->location, peopleVec.getAt(i)->location) < distance)) {
			
			count++;
			peopleVec.getAt(i)->distance = cPerson::getDistanceBetween(prototype->location, peopleVec.getAt(i)->location);
			vec.addAtEnd(*peopleVec.getAt(i));
		
		}
	}

	
	vec.quickSort(0, count-1);

	for (int i = 0; i < count; i++) {
		people[i] = vec.getAt(i);
	}

	numberOfPeople = count;

}