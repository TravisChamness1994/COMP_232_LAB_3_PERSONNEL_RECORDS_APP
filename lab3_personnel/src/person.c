/**
 * Travis Chamness
 * Lab 3
 * 2/19/2020
 * */
#include "person.h"

LIST *head = NULL, *tail = NULL;

//name age height mm/dd/yyyy
void inputPersonalData(PERSON *person)
{
    //Input personal data to each section
    scanf("%s", person->name);
    scanf("%d", &person->age);
    scanf("%f", &person->height);
    scanf("%d/%d/%d", &person->bday.month, &person->bday.day, &person->bday.year);
    // TODO implement the function - inputPersonalData - Work
    // or check out part 9 of the c tutorial ;)
}

void addPersonalDataToDatabase(PERSON *person)
{
    add(&head, &tail, person);
    // TODO Implement the function - addPersonalDataToDatabase - Work
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
    // TODO Implement the function - displayDatabase
    //goes through the linked list referenced by head and tail, calling displayPerson on each data pointer in the list
    //note that this will require casting each list node's data field as a PERSON* (it is stored as a generic void*)
}

void displayPerson(PERSON *person)
{
    printf("\n%s :\n      Age : %d\n      Height : %4.1f\n      Birthday : %d/%d/%d\n",person->name,person->age,person->height,person->bday.month,person->bday.day,person->bday.year);
    // TODO Implement the function - displayPerson
    // hmmmm seems familiar....
    //takes as input a PERSON*
    //displays the referenced data
}

PERSON *findPersonInDatabase(char *name) {
    LIST *currNode = head;
    while (currNode != NULL) {
        if ((currNode->data) == name) {
            return (PERSON*)currNode;
        }
        else
            currNode = currNode->next;
    }
    //If list does not contain
    return NULL; // if not found

    // TODO Implement the function - findPersonInDatabase
    //takes as input a char*, the name of the person to be deleted
    // finds the first occurence of a PERSON* stored in the linked list whose referenced name is the same as the input
    //name and returns that PERSON*
    //if no such person is in the database, return NULL.

}

void removePersonFromDatabase(char *name)
{
    // TODO Implement the function - removePersonFromDatabase
    //takes as input a char*, the name of the person to be deleted
    //finds the first person in the list with that name(if one exists) and deletes.
}

void clearDatabase()
{
    // TODO Implement the function - clearDatabase
    //deletes the linked list referenced by head and tail
    //1-liner, use a utility defined in list.c
}
