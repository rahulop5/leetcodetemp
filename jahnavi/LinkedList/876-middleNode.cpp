#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {} 
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* soln = head;
    ListNode* temp = head;
    while(temp->next != nullptr){
        soln = soln->next;
        if(temp->next->next == nullptr) temp = temp->next;
        else temp = temp->next->next;
    }

    return soln;
}


int main(){
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6; //Comment out to check odd length case

    ListNode* soln = middleNode(head);
    cout << soln->val;
}