#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {} 
    ListNode(int x) : val(x), next(NULL) {}
};

void traversalOfLinkedList(ListNode* head){
    while(head != nullptr){
        cout << head->val;
        if(head->next != nullptr) cout << " -> ";
        head = head->next;
    }
}

//Iterative approach
ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

//Recursive approach
ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;

    ListNode* rest = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head = reverseList(head);
    traversalOfLinkedList(head);
}