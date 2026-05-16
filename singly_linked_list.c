//Singly Linked List

#include <stdio.h>
#include <stdlib.h>

//initialization of node
struct node {
    int data; //node ka data
    struct node *next; //node type ka pointer, which is pointing towards next node
};

//node ka head
struct node *head = NULL;

//insertion at end of linked list
void ins_end(int value){
    struct node *newnode; //creating newnode of type node "node"

    //initialize storage (memory) for newnode
    newnode = (struct node *)malloc(sizeof(struct node));
    
    //adding values to newnode variable
    newnode->data = value;
    newnode->next = NULL;
    
    //if empty linked list
    if (head == NULL){
        head = newnode;
    }
    //else karna kya hai with node
    else {
        //temp variable made, and gave it's location of head
        struct node *temp = head; 

        //jab tak temp ke next mai NULL na ho
        while(temp->next != NULL){
            temp = temp->next;
        }

        //jab null aajaye toh, temp ke next mai newnode daal diya jaaye
        temp->next = newnode;
    }
}

//to display all elements of a linked list
void display(){
    //temp variable made and assigned it with head
    struct node *temp = head;
    
    //head == NULL hai toh matlab linked list empty hai
    if (head == NULL){
        printf("List is empty");
    }

    //agar linked list khaali nahi hai toh
    else {
        //jab tak temp, NULL ke barabar na ho tab tak
        while (temp != NULL){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

//insertion of a node at beginning
void ins_beg(int value){
    //newnode variable made, of type node
    struct node *newnode;
    //assigned memory for node
    newnode = (struct node *)malloc(sizeof(struct node));
    
    //newnode ke data mai "value" aajaye
    newnode->data = value;
    
    //agar linked list khaali hai
    if (head == NULL){
        newnode->next = NULL;
        head = newnode;
    }
    //agar nhi hai toh
    else{
        //newnode ke next mai head daal de
        newnode->next = head;

        //aur head = newnode karde
        head = newnode;

        //issi sequence mai values assign hogi, agar ulta sidha kiya toh galat ho jayega.
        //agar head = newnode pehle kardiya, toh you will lose access to initial linked list.
    }
}

void del_beg(){
    //checks for empty linked list
    if (head == NULL){
        printf("\nNo linked List exists.");
    }
    //if not empty
    else{
        //assign temp = head
        struct node *temp = head;

        //assign pointer head to head->next (temp is keeping track of first node now)
        head = head->next;

        //free the temp (first node)
        free(temp);

        //now remove the memory address of temp
        temp = NULL; 
        
        printf("\nDeleted First Node!\n");
    }
}

//baaki main wali chiz, samjh aa hi gaya hoga
int main(){
    int ch, value;
    
    while(1){
        printf("1. Ins at end\n");
        printf("2. Ins at beg\n");
        printf("3. Display\n");
        printf("4. Del at beg.\n");
        printf("5. Del at end.\n");
        printf("Enter option : \n");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("Enter Value to be inserted : ");
                scanf("%d",&value);
                ins_end(value);
                break;
            case 2:
                printf("Enter value to be inserted : ");
                scanf("%d",&value);
                ins_beg(value);
                break;
            case 3:
                display();
                break;
            case 4:
                del_beg();
                break;
        }}
    return 0;
}