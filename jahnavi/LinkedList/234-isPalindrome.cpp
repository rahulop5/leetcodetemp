#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {} 
    ListNode(int x) : val(x), next(NULL) {}
};

// Approaches-
// 1) Convert Linked List to an array and use two pointers for simple palindrome check.
// 2) Push all elements of list to stack and then traverse from beginning again to compare
// 3) Reverse only second half of linked list (my approach is better)

bool isPalindrome(ListNode* head) {
    int length = 0;
    ListNode* temp = head;
    while(temp != nullptr){
        length++;
        temp = temp->next;
    }

    int count = 0;
    vector<int> stck;
    while(count < (length / 2)){
        stck.push_back(head->val);
        head = head->next;
        count++;
    }

    if((length % 2) == 1) head = head->next;

    while(head != nullptr){
        if(head->val != stck.back()) return false;
        stck.pop_back();
        head = head->next;
    }

    return true;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(1);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    int soln = isPalindrome(head);
    cout << soln;
}