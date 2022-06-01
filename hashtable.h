#ifndef _HASHTABLE_
#define _HASHTABLE_

//  USE LL TO HANDLE COLLISIONS
//      USES CHAINING FOR COLLISIONS
//
//  NO OUTPUT

#include "person.h"

class hashtable
{
    private:
        const static int TABLE_SIZE = 9973; // table size
        int count = 0;

        struct node
        {
            person info;
            node* next; 
            node(const person& body): info(body), next(nullptr){}       
        };
        node** table;
        
        int hashKeyFinder(const char * const key);

    public:
        hashtable();
        ~hashtable();

        // getting rid of these two since i'll only be using one list
        hashtable(const hashtable &otherTable) = delete;
        hashtable& operator=(const hashtable &otherTable) = delete; 

        bool isEmpty() const;
        void insert(/*const char * const key,*/ person &individual);
        person* lookup(const char * const key); // finder method
        int printDiagnostics() const; // outputs diagnostics! 
};

#endif
