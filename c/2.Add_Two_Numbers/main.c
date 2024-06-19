#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // int a_l1 = l1->val;
    // int b_l2 = l2->val;
    // struct ListNode* ptr_l1_next = l1->next;
    // struct ListNode* ptr_l2_next = l2->next;
    int temp = 0;
    int sum = 0;
    struct ListNode current_result_node;
    struct ListNode *ptr_first_result_node = &current_result_node;

    struct ListNode l1_val = *l1;
    struct ListNode l2_val = *l2;

    while ((l1_val.next && l2_val.next) != NULL){
        struct ListNode *ptr_next_result_node;
        struct ListNode next_result_node;
        int value_l1 = l1_val.val;
        int value_l2 = l2_val.val;
        
        if (value_l1 == NULL){
            value_l1 = 0;
        }
        if (value_l2 == NULL){
            value_l2 = 0;
        }
        
        sum = value_l1 + value_l2;
        
        if (temp > 0){
            sum += temp;
            temp = 0;
        }

        if (sum > 9){
            temp = 1;
            sum -= 10;
        }
        
        current_result_node.val = sum;
        current_result_node.next = ptr_next_result_node;

        if (l1->next != NULL){
            struct ListNode l1_next = *l1_val.next;
            l1_val = *l1_val.next;
        }
        if (l2->next != NULL){
            struct ListNode l2_next = *l2_val.next;
            l2_val = *l2_val.next;
        }
        
        
    }

    // Übertrag, wenn a und b gleich Null sind
    if (temp > 0) {
        current_result_node.val = temp;
        temp = 0;    
    }

    return ptr_first_result_node;
}

void main() {
    struct ListNode *ptr_ln2;
    struct ListNode *ptr_ln1;

    struct ListNode ln2;
    ln2.val = 3;
    ln2.next = NULL;
    
    ptr_ln2 = &ln2;

    struct ListNode ln1;
    ln1.val = 1;
    ln1.next = ptr_ln2;
    
    ptr_ln1 = &ln1;
            
    struct ListNode* result = addTwoNumbers(ptr_ln1,ptr_ln2);
    printf("a:%d",result->val);
}