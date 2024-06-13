#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addOrCreateNode(struct ListNode* head, int digit);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    int temp = 0;
    int sum = 0;
    int flag = 0;

    while (flag == 0) {
        int v1;
        int v2;
        
        if (l1 == NULL) {
            v1 = 0;
        }
        else {
            v1 = l1->val;
        }
        if (l2 == NULL) {
            v2 = 0;
        }
        else {
            v2 = l2->val;
        }
        
        sum = v1 + v2;

        if (temp > 0) {
            sum += temp;
            temp = 0;
        }

        if (sum > 9) {
            temp = 1;
            sum -= 10;
        }

        head = addOrCreateNode(head, sum);

        if (l1 != NULL) {
        l1 = l1->next;
        }
        if (l2 != NULL) {
        l2 = l2->next;
        }

        if (l1 == NULL && l2 == NULL) {
            flag = 1;
        }

    }

    // Übertrag, wenn a und b gleich Null sind
    if (temp > 0) {
        head = addOrCreateNode(head, temp);
        temp = 0;    
    }

    return head;
}

struct ListNode* addOrCreateNode(struct ListNode* head, int digit){
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(*temp));
    temp->val = digit;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    }
    else {
        struct ListNode* rhead = head;
        while (rhead->next != NULL) {
            rhead = rhead->next;
        }
        rhead->next = temp;
    }
    return head;
}

int main(){
    /*
    struct ListNode* v2 = (struct ListNode*)malloc(sizeof(*v2));
    v2->next = NULL;
    v2->val = 3;

    struct ListNode* v1 = (struct ListNode*)malloc(sizeof(*v1));
    v1->next = v2;
    v1->val = 2;

    struct ListNode* ptr_head = addOrCreateNode(NULL,1);
    int val = ptr_head->val;
    printf("Pointer: %p\n", ptr_head);
    printf("Value: %d\n", val);
    
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(*tmp));
    tmp = v1;
    
    addOrCreateNode(v1, 6);

    while (tmp->next != NULL) {
        printf("Value: %d\n", tmp->val);
        tmp = tmp->next;
    }
    printf("Value: %d\n", tmp->val);

    struct ListNode* newlist = addOrCreateNode(NULL,5);
    printf("newValue: %d\n", newlist->val);
    */
    
    struct ListNode* b1 = (struct ListNode*)malloc(sizeof(*b1));
    struct ListNode* b2 = (struct ListNode*)malloc(sizeof(*b2));
    b1 = NULL;
    b2 = NULL;
    b1 = addOrCreateNode(b1, 9);
    b1 = addOrCreateNode(b1, 9);
    b1 = addOrCreateNode(b1, 9);
    b1 = addOrCreateNode(b1, 9);
    b1 = addOrCreateNode(b1, 9);
    b2 = addOrCreateNode(b2, 2);
    b2 = addOrCreateNode(b2, 2);
    b2 = addOrCreateNode(b2, 2);
    b2 = addOrCreateNode(b2, 2);

    struct ListNode* result = addTwoNumbers(b1, b2); 

    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(*tmp));
    tmp = result;

    while (tmp->next != NULL) {
        printf("Value: %d\n", tmp->val);
        tmp = tmp->next;
    }
    printf("Value: %d\n", tmp->val);
}
