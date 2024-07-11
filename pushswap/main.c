#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append data to the end of the linked list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void is_valid(char *str) {
    int i = 0;
    int *list = split_to_int(char *str);
    while (list[i]) {
        append();
        i++;
    }
    return 0;
}

void get_arg(char *str) {
    if (is_valid(str))
        return NULL;
    else {

    }
}



int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("number of arguments is not valid \n");
    }
    else {
        char *str;
        int i = 1;
        while (i < argc) {
            get_arg(argc[i]);
            i++;
        }

    }
    return 0;
}