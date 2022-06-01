
// TESTER MAYBE
#include<iostream>
using namespace std;


#include "personmgr.h"



// Adds data to the HT
//  Find person uses an ID to find data, key determined based on ID?
void personmgr::addPerson(person &individual)
{
   // char* temp = new char[100];
   // individual.getID(temp);
    
    table.insert(individual);   

  //  temp = nullptr;
}


/*
 *  Takes an !!!ID!!!
 *  Looks up ID in HT
 *  Returns the person object
*/
person* personmgr::findPerson(const char* const identification)
{
    return (table.lookup(identification));
}



// Returns the total number of rows used, allowed to have output! 
void personmgr::printHtStats()
{
    cout << "Table uses " << table.printDiagnostics() << " out of 9973 entries." << endl;
}

