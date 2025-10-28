#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {} 
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*> st;
    while(head != nullptr){
        if(st.find(head) != st.end()) return head;
        st.insert(head);
        head = head->next;
    }
    return nullptr;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    head->next = node2;
    node2->next = node3;
    node3->next = node2;
    ListNode* soln = detectCycle(head);
    if(soln) cout << soln->val;
    else cout << "No cycle detected";
}