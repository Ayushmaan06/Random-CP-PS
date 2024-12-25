#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
Node* head=NULL;
void insert(int data){
    Node* temp=new Node();
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        Node* temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}
void reverse() {
    Node* current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}
Node* reverseDLL(Node* head)
{
    Node* current = head;
    Node* temp = NULL;
    
    while(current != NULL) {
        // Swap the next and prev pointer
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // Move to the next node (which is stored in current->prev)
        current = current->prev;
    }
    
    // If the list is not empty, update the head
    if(temp != NULL) {
        head = temp->prev;
    }
    
    return head;
}
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(mid));
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1 != nullptr) ? l1 : l2;
        return dummy.next;
    }
};