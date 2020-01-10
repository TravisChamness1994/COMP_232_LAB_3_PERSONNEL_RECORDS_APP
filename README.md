# COMP 232 Lab 3 - Personnel Records Application (Linked Lists)

In this lab, you will use [lab3_personnel.zip](./lab3_personnel.zip) as a starting point to create an application which:

* reads a specified number of personnel records from the standard input.
* creates a database (in linked list form) of the data.
* implemenets utilities to add to, delete from, search, display and clear the database.

The test driver in `main.c` is nearly complete. The first thing you should do is add a line to the start of the `main` function in `main.c` to overwrite the `stdin` input stream with a stream from the file, `in.txt`, which will serve as a test input.

Open `in.txt`; there is the number `7`, specifying that 7 records will be entered initially, followed by 7 people's information. After these intial 7, there are 2 more people's information; these extra two exist for other tests done in the `main` function.

Read through the `main` function. When you are sure that you understand what tests are being performed and where, you are ready to start working.

### Linked Lists

The skeleton of a linked list implementation is provided in `list.h` and `list.c`. Check out the struct definition of a `LIST` node in `list.h` to get an idea how data will be stored.

Your task is to complete and test this implementation. This will require you to fill out the definitions for the following functions in `list.c`:

```c
void add(LIST **head, LIST **tail, void *data);
void clearRecursively(LIST **currNode, LIST **tail);
void delete(LIST **head, LIST **tail, void *data);
```

You will also need to make an additional `main` function to test the `LIST` utilities.

#### `add` :

The goal of the `add` function is to create a new linked list node, populate it with the data provided in the `void *data`, and append it to the linked list with head (i.e. the start of the list) referenced by `LIST **head` and tail (i.e. the end of the list) referenced by `LIST **tail`.

The following cases must be handled:

* The list is empty (so `head` and `tail` are `NULL`).
* The list has at least one element (so neiter `head` nor `tail` is `NULL`).

#### `delete` : 

The goal of the `delete` function is to free the node containing the specified data pointer (and its contents), and then remove said node from the list.

The following cases must be handled:

* The list is empty.
* The list is not empty, but the specified data is not in the list.
* The specified data is in the list.
	* The node being deleted is the head.
		* It is the only node (there is only 1 node).
		* It is not the only node (there are multiple nodes).
	* The node being deleted is neither the nead nor the tail.
	* The node being deleted is the tail (but you don't need to worry about it being the head too, because that case was handled above).

You may wish to draw pictures of each of the cases above to determine what needs to be done in each case.

Note that whenever the list is empty, the `head` and `tail` should both be `NULL`; otherwise, the `head` is the start of the list and the `tail` is the end of the list.

#### `clearRecursively`:

The goal of this function is to free every node in the list (and its content) and set the `head` and `tail` to `NULL`.

This is the recursive version of `clearIteratively`, which is provided.

### Personnel Database

Once the linked list utilities are complete and tested, you are ready to move on to `person.c`, which contains skeletons for the following functions:

```c
void inputPersonalData(PERSON *person);
void addPersonalDataToDatabase(PERSON *person);
void displayDatabase();
void displayPerson(PERSON *person);
PERSON *findPersonInDatabase(char *name);
void removePersonFromDatabase(char *name);
void clearDatabase();
```

These functions should work as follows:

#####`inputPersonalData`:
* takes as input a pointer to allocated space for a `PERSON`.
* populates the space referenced by that pointer with data gotten from `stdin` (which you've overwritten in the `main` with `freopen` to stream from `../in.txt`.

#####`addPersonalDataToDatabase`:

* takes as input a pointer to a populated instance of the `PERSON` struct.
* adds this pointer to the linked list referenced by the `LIST *`s `head` and `tail` in `person.c`.

#####`displayDatabase`:

* goes through the linked list referenced by `head` and `tail`, calling `displayPerson` on each data pointer in the list.
* note that this will require casting each list node's `data` field as a `PERSON *` (it is stored as a generic `void *`).

#####`displayPerson`

* takes as input a `PERSON *`.
* displays the referenced data.

#####`findPersonInDatabase`:

* takes as input a `char *`, the name of the person to be deleted.
* finds the first occurence of a `PERSON *` stored in the linked list whose referenced name is the same as the input name and returns that `PERSON *`.
* if no such person is in the database, returns `NULL`.

#####`deletePersonFromDatabase`:

* takes as input a `char *`, the name of the person to be deleted.
* finds the first person in the list with that name (if one exists) and deletes them.

#####`clearDatabase`:

* deletes the linked list referenced by `head` and `tail`.
* 1-liner, use a utility defined in `list.c`.

A sample run of the provided `main.c` (with the provided `in.txt` occupying `stdin`) and a completed project looks like:

```
Enter the initial number of records:

--> Reading Personnel Records...

--> Displaying Database...

Zach : age 22, height 5.8, birthday 2/20/1989
Maya : age 21, height 5.9, birthday 8/2/1990
Ange : age 23, height 5.6, birthday 7/3/1987
Greg : age 22, height 6.2, birthday 4/15/1989
Matt : age 24, height 6.5, birthday 6/5/1986
Bob : age 50, height 8.0, birthday 3/23/1900
Frank : age 100, height 9.0, birthday 5/4/1923

--> Searching database for Maya...

Maya : age 21, height 5.9, birthday 8/2/1990

--> Removing Maya from database...

Zach : age 22, height 5.8, birthday 2/20/1989
Ange : age 23, height 5.6, birthday 7/3/1987
Greg : age 22, height 6.2, birthday 4/15/1989
Matt : age 24, height 6.5, birthday 6/5/1986
Bob : age 50, height 8.0, birthday 3/23/1900
Frank : age 100, height 9.0, birthday 5/4/1923

--> Searching database for Frank...

Frank : age 100, height 9.0, birthday 5/4/1923

--> Removing Frank from database

Zach : age 22, height 5.8, birthday 2/20/1989
Ange : age 23, height 5.6, birthday 7/3/1987
Greg : age 22, height 6.2, birthday 4/15/1989
Matt : age 24, height 6.5, birthday 6/5/1986
Bob : age 50, height 8.0, birthday 3/23/1900

--> Removing Miro from database...

Zach : age 22, height 5.8, birthday 2/20/1989
Ange : age 23, height 5.6, birthday 7/3/1987
Greg : age 22, height 6.2, birthday 4/15/1989
Matt : age 24, height 6.5, birthday 6/5/1986
Bob : age 50, height 8.0, birthday 3/23/1900

--> Adding new record to database...

Zach : age 22, height 5.8, birthday 2/20/1989
Ange : age 23, height 5.6, birthday 7/3/1987
Greg : age 22, height 6.2, birthday 4/15/1989
Matt : age 24, height 6.5, birthday 6/5/1986
Bob : age 50, height 8.0, birthday 3/23/1900
AJ : age 100, height 88.0, birthday 1/1/1920

--> Clearing database...

The database is empty.

--> Adding new record to database...

OtherAJ : age 1000, height 88.0, birthday 1/1/1020

Process finished with exit code 0
```

Don't forget to run with Valgrind and fix any memory errors, and to provide documentation of your project with sample runs!