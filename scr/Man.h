/*
 * Man.h
 *
 *  Created on: May 5, 2019
 *      Author: nikolabaci
 */

#ifndef MAN_H_
#define MAN_H_

#include "People.h"
#include "Woman.h"

/*
 * Derived from class People.
 * Uses its constuctor and protected
 * member variables.
 */
class Man: public People {
private:
	Woman* wife;				//Pointer to current wife
	Woman** preferences;		//Array of pointer, poining to preferences

public:
	Man();						//Default Constructor
	Man(string, int);	 		//Constructor that takes the name and size of the array
	Man(const Man &obj);		//Copy constructor

	string getName();
	void setWife(Woman*);		 //Used to cut the link when the man is replaced by another man
	Woman* getWife();			 //Fuction that returns the name of the object

	void setPreferences(Woman*); //Used to populate the array of preferences
	void printPreferences();	 //Used to see/debug/inform about the preferences of each object

	void propose();				 //The fuction that proposes the preferences
	void printSpouse();			 //Used to display the result at the end

	void operator=(const Man &obj); //Operator= overload
	~Man();							//Destructor


};

#endif /* MAN_H_ */
