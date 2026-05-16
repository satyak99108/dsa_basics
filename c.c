#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void ins_beg(int value){
    struct Node* new_node = createNode(value);
    new_node->next = head;
    head = new_node;
}

void ins_end(int value){
    struct Node* new_node = createNode(value);

    struct Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = head;

}