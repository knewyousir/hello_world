// listCopy.cpp
// this a program that copies a list from one file to another one
// it stores and sorts the list alphabetically before copying it to a new file
// by knewyousir

#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <set>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;
using std::set;
using std::ios;

int main ()
{

// Declare some variables
// var1 is last name, var2 first name, var3 id, var4 jobType, var5 isAdmin
// string input, nameLast, nameFirst, id, jobType, isAdmin;

string nameFirst;
set<string> setNames;
set<string>::iterator setIt;

// Open file streams

ifstream readNames;
readNames.open("names1.txt", ios::in);

ofstream writeNames;
writeNames.open("names2.txt", ios::out);

// Populate the string matrix

while (std::getline(readNames, nameFirst, '\n'))
{
//	Names >> nameFirst;
	setNames.insert(nameFirst);
//	readNames.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
}

// Print the output file

for (setIt = setNames.begin(); setIt != setNames.end(); setIt++){
	writeNames << *setIt << endl;
}

return 0;

}
