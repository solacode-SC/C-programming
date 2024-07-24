#include "../pushswap.h"

// Function to create a new node
stack_t* createNode(int data) {
    stack_t* newNode = (stack_t*)malloc(sizeof(stack_t));
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the linked list
void appendNode(stack_t** head, int data) {
    stack_t* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        stack_t* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


// Function to print the linked list (for testing)
void printList(stack_t* head) {
    stack_t* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int get_listlen(stack_t *head) {
    int len = 0;
    stack_t* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }    
    return len;
}

void free_all(stack_t *heade) {
    stack_t* temp = heade;
    while(temp != NULL) {
        stack_t* next = temp->next;
        free(temp);
        temp = next;
    }
}