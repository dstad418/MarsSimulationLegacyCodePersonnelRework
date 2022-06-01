
#ifndef _PERSONMGR_
#define _PERSONMGR_

#include "person.h"
#include "hashtable.h"

//      NO IMPLEMENTATION OF HASHTABLE



class personmgr
{
    private:
        hashtable table; // used to hold person objects
    
    
    public:  
        /*
        //  YET TO BE DETERMINED IF THIS CLASS WILL HAVE POINTERS
        personmgr();
        ~personmgr();
        
        // In case pointers are used
        personmgr(const personmgr &otherMgr) = delete;
        personmgr& operator=(const personmgr &otherMgr) = delete;
        */
           
        void addPerson(person &individual);

        // find person method using the ID
        person* findPerson(const char * const identification);
        
        // returns diagnostic method from the hashtable function
        void printHtStats();
        
};

#endif
