//============================================================================
// Name        : Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "People.h"
#include "Man.h"
#include "Woman.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
	/*
	 //Creating the objects man and woman
	 int size = 3;
	 Man m1("Alfred", size);
	 Man m2("Bernard", size);
	 Man m3("Charles", size);
	 Woman w1("Diana", size);
	 Woman w2("Elizabeth", size);
	 Woman w3("Fiona", size);

	 //Setting each of their preferences
	 m1.setPreferences(&w2);
	 m1.setPreferences(&w1);
	 m1.setPreferences(&w3);


	 m2.setPreferences(&w1);
	 m2.setPreferences(&w2);
	 m2.setPreferences(&w3);

	 m3.setPreferences(&w2);
	 m3.setPreferences(&w3);
	 m3.setPreferences(&w1);

	 w1.setPreferences(&m1);
	 w1.setPreferences(&m2);
	 w1.setPreferences(&m3);

	 w2.setPreferences(&m3);
	 w2.setPreferences(&m2);
	 w2.setPreferences(&m1);

	 w3.setPreferences(&m3);
	 w3.setPreferences(&m1);
	 w3.setPreferences(&m2);

	 //Creating two arrays of type woman and man
	 //and initializeing the cells
	 Woman arrayW[3];
	 arrayW[0] = w1;
	 arrayW[1] = w2;
	 arrayW[2] = w3;


	 Man arrayM[3];
	 arrayM[0] = m1;
	 arrayM[1] = m2;
	 arrayM[2] = m3;


	 //Run the program until all the man and woman
	 //are engaged

	 for (int j = 0; j < size; j++){
	 for (int i = 0; i < size; i++){
	 arrayM[i].propose();
	 }
	 for (int k = 0; k < size; k++){
	 arrayM[k].printSpouse(); //Print the couples engaged
	 }
	 cout << "---------------------------" << endl;
	 }
	 */

	int size;
	Woman* arrayW;
	Man* arrayM;
	string name;

	cout << "Enter the how many couples you want, size = ";
	cin >> size;

	arrayM = new Man[size];
	arrayW = new Woman[size];

	//Populates the man array with objects with the name
	//entered by the user
	for (int i = 0; i < size; i++) {
		cout << "Enter the name of man " << (i + 1) << " (press enter): ";
		cin >> name;
		Man m(name, size);
		arrayM[i] = m;
	}

	for (int i = 0; i < size; i++) {
		cout << "Enter the name of woman " << (i + 1) << " (press enter): ";
		cin >> name;
		Woman w(name, size);
		arrayW[i] = w;
	}

	/*
	 //Used to debug
	 for(int i = 0; i < size; i++){
	 cout << arrayM[i].getName() << endl;
	 }
	 for(int i = 0; i < size; i++){
	 cout << arrayW[i].getName() << endl;
	 }
	 */

	/*
	 * Here we set every man's preferences if the name
	 * entered matches with any of the woman's name
	 */
	cout << "Enter preferences for man:" << endl;
	for (int i = 0; i < size; i++) {
		cout << arrayM[i].getName() << endl;
		for (int j = 0; j < size; j++) {
			cout << '\t' << (j + 1) << ". ";
			cin >> name;
			for (int k = 0; k < size; k++) {
				if (name == arrayW[k].getName()) {
					arrayM[i].setPreferences(arrayW + k);
				}
			}

		}
	}

	cout << "Enter preferences for woman:" << endl;
	for (int i = 0; i < size; i++) {
		cout << arrayW[i].getName() << endl;
		for (int j = 0; j < size; j++) {
			cout << '\t' << (j + 1) << ". ";
			cin >> name;
			for (int k = 0; k < size; k++) {
				if (name == arrayM[k].getName()) {
					arrayW[i].setPreferences(arrayM + k);
				}
			}
		}
	}
	/*
	 //Used to debug
	 for(int i = 0; i < size; i++){
	 arrayM[i].printPreferences();
	 }

	 cout << "=================================" << endl;

	 for(int i = 0; i < size; i++){
	 arrayW[i].printPreferences();
	 }
	 */

	cout << "---------------------------------" << endl;

	//This loop makes all the man propose to theri preferences
	//until all the men are engaged
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size; i++) {
			arrayM[i].propose();
		}
	}
	for (int k = 0; k < size; k++) {
		arrayM[k].printSpouse(); //Print the couples engaged
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int k = 0; k < size; k++) {
		arrayW[k].printSpouse(); //Print the couples engaged
	}

	return 0;
}
