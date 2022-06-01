
#include "person.h"
#include <cstring>

// Used for overload outout
#include <iostream>
using namespace std;


//      ALL MANNER OF CONSTRUCTORS
person::person() : ID(NULL), fName(NULL), lName(NULL), familyID(NULL)
{
}

person::person(char *iden, char *firstN, char *lastN, char *fID) : ID(NULL), fName(NULL), lName(NULL), familyID(NULL)
{
    setID(iden);
    setFName(firstN);
    setLName(lastN);
    setFamilyID(fID);
}


person::person(const person &pType) : ID(NULL), fName(NULL), lName(NULL), familyID(NULL)
{
    setID(pType.ID);
    setFName(pType.fName);
    setLName(pType.lName);
    setFamilyID(pType.familyID);        
}



//      DESTRUCTOR JUST CALLS CLEAR
person::~person()
{
    clear();
}



//      ASSIGNMENT OPERATOR
const person& person::operator=(const person &otherPerson)
{
    if(this != &otherPerson)
    {
        this->clear();

        setID(otherPerson.ID);
        setFName(otherPerson.fName);
        setLName(otherPerson.lName);
        setFamilyID(otherPerson.familyID);
    }

    return *this;
}



//      OVERLOADED OUTPUT OPERATOR
ostream& operator<<(ostream& out, const person& personType)
{  
    // OUTPUT THE FORMATTED INFORMATION HERE
    out << "ID: " << personType.ID << endl << "First Name: " << personType.fName << endl << "Last Name: " << personType.lName << endl;

    return out;
}



//      CLEAR FUNCTION, USED IN THE DESTRUCTOR AND ASSIGNMENT OPERATOR
void person::clear()
{
     if(ID)
     {
         delete [] ID;
         ID = nullptr;
     }
     if(fName)
     {
         delete [] fName;
          fName = nullptr;
     }
     if(lName)
     {
         delete [] lName;
         lName = nullptr;

     }
     if(familyID)
     {
         delete [] familyID;
         familyID = nullptr;
     }        
}



//      GETTERS FOR DATA VARIABLES
void person::getID(char* iden) const
{
    strcpy(iden, this->ID);
}

void person::getfName(char* first) const
{
    strcpy(first, this->fName);
}

void person::getlName(char *last) const
{
    strcpy(last, this->lName);
}

void person::getfamilyID(char* family) const
{
    strcpy(family, this->familyID);
}



//      SETTERS FOR THE DATA VARIABLES
void person::setID(char *iden)
{
    /*if(this->ID)
    {
        delete [] this->ID;        
    }
    */
    this->ID = new char[strlen(iden +1)];
    strcpy(this->ID, iden);
}

void person::setFName(char *firstN)
{
    /*if(this->fName)
    {
        delete [] this->fName;        
    }*/

    this->fName = new char[strlen(firstN + 1)];
    strcpy(this->fName, firstN);

}

void person::setLName(char *lastN)
{
    /*if(this->lName)
    {
        delete [] this->lName;        
    }*/

    this->lName = new char[strlen(lastN+1)];
    strcpy(this->lName, lastN);
}

void person::setFamilyID(char *fID)
{
    /*if(this->familyID)
    {
        delete [] this->familyID;        
    }*/

    this->familyID = new char[strlen(fID + 1)];
    strcpy(this->familyID, fID);    
}
