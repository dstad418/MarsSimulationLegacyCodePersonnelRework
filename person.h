#ifndef _PERSON_
#define _PERSON_


// INCLUDING THESE TWO FOR THE OVERLOADED OUTPUT OPERATOR
#include<iostream>
using namespace std;



class person
{   
    private:
        char *ID;
        char *fName;
        char *lName;
        char *familyID;

    public: 
        // Constructors
        person();
        person(char *iden, char *firstN, char *lastN, char *fID);
        person(const person &pType);

        // destructors
        ~person();    
      
        // Overloaded assignment operator & output overload
        const person& operator=(const person& otherPerson);
        friend ostream& operator<<(ostream& out, const person& personType);
        
        void clear();

        // getters for the copy constructor
        void getID(char* iden) const;
        void getfName(char* first) const;
        void getlName(char* last) const;
        void getfamilyID(char* family) const;

        // setters for the data variables
        void setID(char *iden);
        void setFName(char *firstN);
        void setLName(char *lastN);
        void setFamilyID(char *fID);
};

#endif
