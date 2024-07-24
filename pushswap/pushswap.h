#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#ifndef PUSHSWAP_H
#define PUSHSWAP_H

typedef struct stack_s {
    int data;
    struct stack_s* next;
} stack_t;




void appendNode(stack_t** head, int data);
void parseAndStoreNumbers(const char* str, stack_t** head);
void ft_pusha(stack_t **head_a, stack_t **head_b);
void ft_pushb(stack_t **head_a, stack_t **head_b);
void ft_reverse_rotatea(stack_t **head_ref);
void ft_reverse_rotateb(stack_t **head_ref);
void ft_reverse_rotater(stack_t **head_a, stack_t **head_b);
void ft_rotatea(stack_t **head_ref);
void ft_rotateb(stack_t **head_ref);
void ft_rotater(stack_t **head_a, stack_t **head_b);
void ft_swapa(stack_t **head_ref);
void ft_swapb(stack_t **head_ref);
void ft_swaps(stack_t **head_ref1, stack_t **head_ref2);
void free_all(stack_t *heade);
stack_t* createNode(int data);
void printList(stack_t* head);
int get_listlen(stack_t *head);
int is_no_digit(const char *str);
void print_error();

#endif 