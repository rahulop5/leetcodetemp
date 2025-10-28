#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {} 
    ListNode(int x) : val(x), next(NULL) {}
};

int lengthOfLoop(ListNode *head) {
    unordered_set<ListNode*> st;
    ListNode* curr = head;
    
    while(curr != nullptr){
        if(st.find(curr) != st.end()){
            int count = 1;
            ListNode* target = curr;
            curr = curr->next;
            while(curr != target){
                count++;
                curr = curr->next;
            }
            return count;
        } else {
            st.insert(curr);
            curr = curr->next;
        }
    }
    
    return 0;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    head->next = node2;
    node2->next = node3;
    node3->next = node2;
    int soln = lengthOfLoop(head);
    cout << soln;
}