#include "../pushswap.h"


// Function to create a new node
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

// Function to add a node to the end of the linked list
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to parse the string and store the numbers in the linked list
void parseAndStoreNumbers(const char* str, Node** head) {
    char* endPtr;
    while (*str) {
        if (isspace(*str)) {
            str++;
            continue;
        }
        int num = strtol(str, &endPtr, 10);
        if (str == endPtr) {
            str++;
        } else {
            appendNode(head, num);
            str = endPtr;
        }
    }
}

// Function to print the linked list (for testing)
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
