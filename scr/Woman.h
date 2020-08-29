/*
 * Woman.h
 *
 *  Created on: May 5, 2019
 *      Author: nikolabaci
 */

#ifndef WOMAN_H_
#define WOMAN_H_

#include "People.h"
class Man;

/*
 * Derived from class People.
 * Uses its constuctor and protected
 * member variables.
 */

class Woman: public People {
private:
	Man* husband;				//Pointer to current wife
	Man** preferences;  		//Array of pointer, poining to preferences

public:
	Woman();					//Default Constructor
	Woman(string, int);			//Constructor that takes the name and size of the array
	Woman(const Woman &obj);	//Copy constructor

	string getName();			//Fuction that returns the name of the object
	void setHusband(Man*);
	Man* getHusband();

	void setPreferences(Man*);  //Used to populate the array of preferences
	void printPreferences();	//Used to see/debug/inform about the preferences of each object

	bool decide(Man*);			//The functions that determines weather to accept a proposal or not.
	void printSpouse();			//Used to display the result at the end

	void operator=(const Woman &); //Operator= overload
	~Woman();					   //Destructor

};

#endif /* WOMAN_H_ */
