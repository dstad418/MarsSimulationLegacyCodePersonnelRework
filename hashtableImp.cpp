#include<cstring>
#include "hashtable.h"


// INITIALIZE THE PERSON OBJECT ARRAY SIZE IN THE CONSTRUCTORS

hashtable::hashtable() : count(0), table(new node*[TABLE_SIZE])
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = nullptr;
    }
}


hashtable::~hashtable()
{
    node* head = nullptr;
    node* curr = nullptr;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        node* head = table[i];
        //node* curr;
        
        while(head)
        {
            curr = head->next;
            head->next = nullptr;
            delete head;
            head = curr;         
        }
    }

    delete [] table;
}


int hashtable::hashKeyFinder(const char * const key)
{    
    int temp = strlen(key);
    size_t index = 0;

    for(int i = 0; i < temp; i++)
    {
        index = (3*index) +(2* int(key[i]));
    }
        
    return (index % TABLE_SIZE);
}


void hashtable::insert(/*const char * const key,*/ person& individual)
{
    char id[10];
    
    individual.getID(id);

    int index = hashKeyFinder(id);


    node *toAdd = new node(individual);

    if(table[index] == nullptr)
    {
        count++;        
    }

    toAdd->next = table[index];
    table[index] = toAdd;
}


person* hashtable::lookup(const char * const key)
{

    int index = hashKeyFinder(key);

    node* curr = table[index];
    person* temp;
    char id[10];
    bool sentinel = false;

    while(curr && (sentinel == false))
    {
        curr->info.getID(id);

        if(strcmp(key, id) == 0)
        {
            temp = (&curr->info);
            sentinel = true;
        }
        else
        {
            curr = curr->next;
        }
    }
   
    //person* temp = new person(curr->info); 
    return temp;//(curr->info);
}


int hashtable::printDiagnostics() const
{
    return count;     
}
