#include <bits/stdc++.h>
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

int lengthOfLinkedList(ListNode* head){
    int soln = 0;
    while(head != nullptr){
        soln++;
        head = head->next;
    }
    return soln;
}

bool findElement(ListNode* head, int x){
    while(head != nullptr){
        if(head->val == x) return true;
        head = head->next;
    }
    return false;
}

ListNode *insertAtEnd(ListNode *head, int x) {
    ListNode* newNode = new ListNode(x);
    if(head == nullptr) return newNode;
    ListNode* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    cout << lengthOfLinkedList(head) << endl;
    cout << findElement(head, 4) << endl;
    head = insertAtEnd(head, 4);
    traversalOfLinkedList(head);
}