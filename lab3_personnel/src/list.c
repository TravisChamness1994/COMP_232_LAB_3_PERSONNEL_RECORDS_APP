/**
 * Travis Chamness
 * Lab 3
 * 2/19/2020
 **/
#include "list.h"

void add(LIST **head, LIST **tail, void *data)
{
    if(*head == NULL)
    {
        LIST *newNode = calloc(1, sizeof(LIST));
        newNode->data = data;
        newNode->next = NULL;
        *head = newNode;
        *tail = newNode;
    }
    else
        {
            LIST *newNode = calloc(1, sizeof(LIST));
            newNode->data = data;
            newNode->next = *head;
            *head = newNode;
        }
    // TODO implement the function - Add - Work
}

void clearIteratively(LIST **head, LIST **tail)
{
    if (*head == NULL)
        return;

    LIST *currNode = *head;
    LIST *nextNode = NULL;
    do
    {
        nextNode = currNode->next;

        if (currNode->data != NULL)
            free(currNode->data);

        free(currNode);

        currNode = nextNode;

    } while (currNode != NULL);

    *head = NULL;
    *tail = NULL;
}

void clearRecursively(LIST **currNode, LIST **tail)
{
    //if our current node is Null, we have reached the end and will now close the stack
    if(currNode == NULL)
        return;
    else
        {
        //&(*currNode)->next steps once into dereferencing, point to locations next, then reference its own location
            clearRecursively(&(*currNode)->next, tail);
            free((*currNode)->data);
            free(*currNode);
            return;
        }
    // TODO implement the function - clearRecursively - Work
}

void delete(LIST **head, LIST **tail, void *data)
{
    LIST *trailNode = NULL;
    LIST *currNode = *head;

    //list is empty, dont run
    if(*head != NULL)
    {
        //If currNode get to end of List, end
     while(currNode != NULL)
     {
         //if data is found, delete node.
         if(currNode->data == data)
         {
             trailNode->next = currNode->next;
             free(currNode->data);
             free(currNode);
         }
         else
             {
             trailNode = currNode;
             currNode = currNode->next;
             }
     }
    }
    // TODO implement the function - delete - Work
}