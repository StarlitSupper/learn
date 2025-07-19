#ifndef LIST_H
#define LIST_H

typedef struct User {
	int id;
	char name[20];
	char pwd[20];
	char tel[20];
} User;

typedef struct Node {
	User user;
	struct Node* next;
} Node, *LinkList;

void initList(LinkList* L);
void CreateList(LinkList L, char* filename);
void printList(LinkList L);
void insertList(LinkList L);
void deleteList(LinkList L);
void updateList(LinkList L);
void searchList(LinkList L);
void destroyList(LinkList L);
int listLength(LinkList L);
void writeToFile(LinkList L, char* filename);

#endif
