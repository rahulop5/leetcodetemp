#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {} 
    ListNode(int x) : val(x), next(NULL) {}
};

int lengthOfLinkedList(ListNode* head){
    int soln = 0;
    while(head != nullptr){
        soln++;
        head = head->next;
    }
    return soln;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    cout << lengthOfLinkedList(head);
}