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

    // TODO Implement the function
}

void displayDatabase()
{
    // TODO Implement the function
}

void displayPerson(PERSON *person)
{
    // TODO Implement the function
    // hmmmm seems familiar....
}

PERSON *findPersonInDatabase(char *name)
{
    // TODO Implement the function

    return NULL; // if not found
}

void removePersonFromDatabase(char *name)
{
    // TODO Implement the function
}

void clearDatabase()
{
    // TODO Implement the function
}
