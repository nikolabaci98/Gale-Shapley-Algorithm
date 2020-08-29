/*
 * People.h
 *
 *  Created on: May 5, 2019
 *      Author: nikolabaci
 */

#ifndef PEOPLE_H_
#define PEOPLE_H_

#include <string>
using namespace std;

/*
 * Class People is the base class
 * from which we derive the Man and Woman
 * classes.
 */

class People{

protected:
	int size;      //Size of the array preferences[]
	int count;	   //used to keep track of the number of preferences
	int current;   //used to keep track of the current spouse
	string name;   //the name give to the Man/Woman object

public:
	People();				//Default Constructor
	People(string, int);	//Constructor that takes the name and size of the array
};

#endif /* PEOPLE_H_ */
