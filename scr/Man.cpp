/*
 * Man.cpp
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
 * The default constructor creates an array of type woman
 * pointer and sets the wife pointer to null. Also, uses the
 * people default constructor to initialize size, count,
 * current and name variables.
 */
Man::Man():People() {
	wife = NULL;
	this->preferences = new Woman*[size];
}

/*
 * This constructor takes two parameters, the name and the size
 * of the array, creates the array of the given size and
 * initializes the name of the object.
 */
Man::Man(string name, int size):People(name, size) {
	wife = NULL;
	this->preferences = new Woman*[size];
}

/*
 * The copy constructor helps to set the attributes of the object
 * the same as the object assigned to at initialization
 */
Man::Man(const Man &obj) {

	this->wife = obj.wife;
	this->name = obj.name;
	this->count = obj.count;
	this->current = obj.current;
	this->size = obj.size;
	this->preferences = obj.preferences;
}

/*
 * Returns the name of the Man object in cases
 * when we want to compare or print the actual names
 * as the output.
 */
string Man::getName() {
	return this->name;
}

/*
 * This function comes in help when a woman
 * decides to leave the man. setWife will put
 * the man's pointer 'wife' to spouse which
 * would be a null pointer.
 */
void Man::setWife(Woman* spouse) {
	wife = spouse;
}

/*
 * Return the wife of the object that calles the function
 */
Woman* Man::getWife() {
	return this->wife;
}

/*
 * A function used every time to enter the preferences of
 * the object. Variable count is used to keep track of not
 * going over the size of the preference[] array. It takes
 * a woman pointer.
 */
void Man::setPreferences(Woman* prefer) {
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
 * in the array of each Man object.
 * Prints the names of the man first, then lists
 * all his preferences.
 */
void Man::printPreferences() {

	cout << this->getName() << ":" << endl;

	for (int i = 0; i < this->count; i++) {
		cout << '\t' << (i + 1) << ". " << this->preferences[i]->getName()
				<< endl;
		;
	}
	cout << endl;
}

/*
 * This is the function that checks that is the
 * man is single, he proposes to his preference.
 * If she accepts we set his wife pointer to the
 * preferences otherwise we move to the next
 * preference recursivly.
 */
void Man::propose() {

	if (this->wife == NULL) {
		if (this->preferences[current]->decide(this)) {
			this->wife = preferences[current];
		} else {
			current++;
			propose();
		}

	}
}

/*
 * This function is used to print the spouse the
 * man is engaged with.
 * First, print his name, then her name or "-"
 */
void Man::printSpouse() {
	cout << this->getName() << " is engaged with ";
	if (this->wife == NULL) {
		cout << "-" << endl;
	} else {
		cout << this->wife->getName() << endl;
	}
}

/*
 * The assignment operator overload is important
 * when the created object has to be transferred to
 * the array in the main.cpp file
 */
void Man::operator=(const Man &obj) {

	this->wife = obj.wife;
	this->name = obj.name;
	this->count = obj.count;
	this->current = obj.current;
	this->size = obj.size;
	this->preferences = new Woman*[this->size];
	for (int i = 0; i < size; i++) {
		this->preferences[i] = obj.preferences[i];
	}
}

/*
 * Deletes the array of preference of each man
 */
Man::~Man() {
	delete[] preferences;
}

