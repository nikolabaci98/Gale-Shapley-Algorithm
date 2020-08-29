/*
 * Woman.cpp
 *
 *  Created on: May 5, 2019
 *      Author: nikolabaci
 */

#include "People.h"
#include "Man.h"

#include <iostream>
#include <string>
using namespace std;

/*
 * The default constructor creates an array of type pointer
 * man and sets the husband pointer to null. Also, uses the
 * people default constructor to initialize size, count,
 * current and name variables.
 */
Woman::Woman() :
		People() {
	husband = NULL;
	this->preferences = new Man*[size];
}

/*
 * This constructor takes two parameters, the name and the size
 * of the array, creates the array of the given size and
 * initializes the name of the object.
 */
Woman::Woman(string name, int size) :
		People(name, size) {
	husband = NULL;
	this->preferences = new Man*[size];
}

/*
 * The copy constructor helps to set the attributes of the object
 * the same as the object assigned to at initialization
 */
Woman::Woman(const Woman &obj) {
	cout << "In..." << endl;
	//this = &obj;
	this->husband = obj.husband;
	this->name = obj.name;
	this->count = obj.count;
	this->current = obj.current;
	this->size = obj.size;
	this->preferences = new Man*[this->size];
	for (int i = 0; i < size; i++) {
		this->preferences[i] = obj.preferences[i];
	}
}

/*
 * Returns the name of the Woman object in cases
 * when we want to compare or print the actual names
 * as the output.
 */
string Woman::getName() {
	return this->name;
}

/*
 * Assignes to privatevariable husband the pointer "man"
 * passed as a parameter
 */
void Woman::setHusband(Man* man) {
	this->husband = man;
}

/*
 * Return the husband of the object that calles the function
 */
Man* Woman::getHusband() {
	return this->husband;
}

/*
 * A function used everytime to enter the preferences of
 * the object. Variable count is used to keep track on not
 * going over the size of the preference[] array. It takes
 * a man pointer.
 */
void Woman::setPreferences(Man* prefer) {
	if (count < size) {
		preferences[count] = prefer;
		this->count++;
	} else {
		cout << "Array is full." << endl;
	}
}

/*
 * Return nothing and takes no parameters.
 * This function is used to print the preferences
 * in the array of each Woman object.
 * Prints the names of the woman first, then lists
 * all his preferences.
 */
void Woman::printPreferences() {
	cout << this->getName() << ":" << endl;

	for (int i = 0; i < this->count; i++) {
		cout << '\t' << (i + 1) << ". " << preferences[i]->getName() << endl;
	}
	cout << endl;
}

/*
 * This function is the most important fucntion
 * in this project. Here are taken all the decisions
 * about how the engagements will go.
 * Return type: boolean
 * Parameters: Man* (pointer)
 */
bool Woman::decide(Man* suitor) {

	//If the object is single, say yes to the suitor.
	if (this->getHusband() == NULL) {
		this->setHusband(suitor);
		//Keep track of where the new spouse is located
		//in the preference array
		while (suitor->getName() != this->preferences[current]->getName()) {
			this->current++;
		}
		return true;
	}
	//If she is engaged prviously check is she
	//prefers the new man
	else {
		//Let's check if she would like this suitor
		//over the current husband.
		int i = 0;
		//If suitor's name appears in the array before the
		//name of the current husband, the Woman chooses the
		//suitor and the pointer husband is reinitialized
		while (i < current) {
			if (suitor->getName() == this->preferences[i]->getName()) {
				//Set the current husband's wife pointer to NULL
				//so he is singel now
				this->getHusband()->setWife(NULL);
				this->setHusband(suitor); //new husband
				current = i;
				return true;
			}
			i++;
		}
		return false;
	}
}

/*
 * This function is used to print the spouse the
 * woman is engaged with.
 * First print her name, then his name or "-"
 */
void Woman::printSpouse() {
	cout << this->getName() << " is engaged with ";
	if (this->getHusband() != NULL) {
		cout << this->getHusband()->getName() << endl;
	} else {
		cout << "-" << endl;

	}
}

/*
 * The assignment operator overload is important
 * when the created object has to be transeferred to
 * the array in the main.cpp file
 */
void Woman::operator=(const Woman &obj) {
	this->husband = obj.husband;
	this->name = obj.name;
	this->count = obj.count;
	this->current = obj.current;
	this->size = obj.size;
	if (size > 0)
		delete[] preferences;
	this->preferences = new Man*[this->size];
	for (int i = 0; i < size; i++) {
		this->preferences[i] = obj.preferences[i];
	}
}

/*
 * Deletes the array of preference of each man
 */
Woman::~Woman() {
	delete[] preferences;
}
