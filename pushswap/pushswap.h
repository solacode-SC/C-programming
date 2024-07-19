#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct a
{
    int x;
    struct a *next;
};

struct b
{
    int x;
    struct a *next;
};

// Define the structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;


void parseAndStoreNumbers(const char* str, Node** head);
void appendNode(Node** head, int data);
Node* createNode(int data);
void printList(Node* head);
