/**
 * Travis Chamness
 * Lab 3
 * 2/19/2020
 * */
#include "person.h"
#include <stdbool.h>

LIST *head = NULL, *tail = NULL;

//name age height mm/dd/yyyy
void inputPersonalData(PERSON *person)
{
    //Input personal data to each section
    scanf("%s", person->name);
    scanf("%d", &person->age);
    scanf("%f", &person->height);
    scanf("%d/%d/%d", &person->bday.month, &person->bday.day, &person->bday.year);
    // TODO implement the function - inputPersonalData - Done
    // or check out part 9 of the c tutorial ;)
}

void addPersonalDataToDatabase(PERSON *person)
{
    add(&head, &tail, person);
    // TODO Implement the function - addPersonalDataToDatabase - Done
    //takes as input a pointer to a populated instance of the PERSON struct
    //adds this pointer to the linked list referenced by the LIST*'s head and tail in person.c
}

void displayDatabase()
{
    LIST *currNode = head;

    while(currNode != NULL)
    {
        displayPerson((PERSON*)(currNode->data));
        currNode = currNode->next;
    }
    // TODO Implement the function - displayDatabase - Done
    //goes through the linked list referenced by head and tail, calling displayPerson on each data pointer in the list
    //note that this will require casting each list node's data field as a PERSON* (it is stored as a generic void*)
}

void displayPerson(PERSON *person)
{

    printf("\n%s :\n      Age : %d\n      Height : %4.1f\n      Birthday : %d/%d/%d\n",person->name,person->age,person->height,person->bday.month,person->bday.day,person->bday.year);
    // TODO Implement the function - displayPerson - Done
    // hmmmm seems familiar....
    //takes as input a PERSON*
    //displays the referenced data
}

PERSON *findPersonInDatabase(char *name) {
    //DUDE! Next time use strcmp
    //DORK!!!!

    LIST *currNode = head;
    PERSON *person = NULL;
    PERSON *input;
    bool same;
    //as long as we have not found value for person or reached the end of the list.
    while (person == NULL && currNode != NULL) {

        //input stores data of currNode
        input = currNode->data;
        //Same is our control for the testing of characters.
        same = true;
        //If the first character of each string is the same.
        if (*(*input).name == *name) {
            for(int i = 0; same && i < sizeof(name); i++)
            {
                //if the subsequent characters are the.
                if(name[i] == input->name[i])
                {
                    //If the characters have been the same and are terminating in the same spot.
                    if(name[i] == '\0' && input->name[i] == '\0')
                        //we can say that the person is who we are looking for.
                        person = input;
                }
                else
                    {
                        same = false;
                        currNode = currNode->next;
                    }
            }
        }
        //if no characters are similar, we need to update the node
        else{
            currNode = currNode->next;
            }
    }
    return person; // if not found, will return null

    // TODO Implement the function - findPersonInDatabase - Done
    //takes as input a char*, the name of the person to be deleted
    // finds the first occurence of a PERSON* stored in the linked list whose referenced name is the same as the input
    //name and returns that PERSON*
    //if no such person is in the database, return NULL.

}

void removePersonFromDatabase(char *name)
{
    delete(&head,&tail,findPersonInDatabase(name));
    // TODO Implement the function - removePersonFromDatabase - Done
    //takes as input a char*, the name of the person to be deleted
    //finds the first person in the list with that name(if one exists) and deletes.
}

void clearDatabase()
{
    clearRecursively(&head, &tail);
    // TODO Implement the function - clearDatabase - Done
    //deletes the linked list referenced by head and tail
    //1-liner, use a utility defined in list.c
}
