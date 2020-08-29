/*
 * People.cpp
 *
 *  Created on: May 5, 2019
 *      Author: nikolabaci
 */

#include "People.h"
#include <iostream>
#include <string>
using namespace std;


People::People(){
	this->size = 0;
	this->name = "-";
	this->count = 0;
	this->current = 0;
}

People::People(string name, int size){
	this->size = size;
	this->name = name;
	this->count = 0;
	this->current = 0;
}



