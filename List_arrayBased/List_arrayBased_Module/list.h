#ifndef LIST_H_
#define LIST_H_

/* definitions */
#define MAXLIST   100

/* dataTypes */
typedef int ListEntry;

typedef struct{
	ListEntry entry[MAXLIST];
	int size;
}List;


/* functions declaration */
void createList(List *);
int listEmpty(List *);
int listFull(List *);
int listSize(List *);
void destroyList(List *);
void insertList(int p, ListEntry e, List *pl);
void deleteList(int p, ListEntry *pe, List *pl);
void retrieveList(int p, ListEntry *pe, List *pl);
void replaceList(int p, ListEntry e, List *pl);
void traverseList(List *pl, void (*)(ListEntry));



#endif /* LIST_H_ */
