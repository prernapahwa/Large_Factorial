#include <stdio.h>
#include<stdlib.h>

#include "factorial.h"
struct Node {
    int data;
    struct Node* next;
};

void large_factorial(struct Node* head, int i) {
    struct Node* temp = head;
    struct Node* prev_temp = head;
    int carry = 0;
    //printf("%d",temp->data);
    while(temp != NULL) {
        int after_multiplication = temp->data * i + carry; 
        temp->data = after_multiplication % 10;
        carry = after_multiplication / 10;
        // printf("%d",temp->data);
        prev_temp = temp;
        temp = temp->next;
        
    }
    
    while(carry != 0) {
        struct Node* for_carry = (struct Node*)malloc(sizeof(struct Node*));
        for_carry->data = carry % 10;
        carry = carry / 10;
        for_carry->next = NULL;
        prev_temp->next = for_carry;
        prev_temp = prev_temp->next;
    }
    
}

void print_in_reverse(struct Node* head) {
    if(head == NULL) {
        return;
    }
    print_in_reverse(head->next);
    printf("%d",head->data);
    
}

void fact(int n) {
      
    struct Node* head = (struct Node*)malloc(sizeof(struct Node*)); 
    head->data = 1;
    head->next = NULL;
    //printf("%d",head->data);
    
    for(int i = 2; i <= n; i++) {
        large_factorial(head,i);
    }
    print_in_reverse(head);
    
}
