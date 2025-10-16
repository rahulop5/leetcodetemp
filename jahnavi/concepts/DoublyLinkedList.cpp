#include<bits/stdc++.h>
using namespace std;

struct DoubleListNode {
    int val;
    DoubleListNode* prev;
    DoubleListNode* next;
    DoubleListNode(int x) : val(x), prev(NULL), next(NULL) {}
};

void traversal(DoubleListNode* head){
    while(head != nullptr){
        cout << head->val;
        if(head->next != nullptr) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

DoubleListNode *insertAtBeginning(DoubleListNode* head, int x){
    DoubleListNode* temp = new DoubleListNode(x);
    if(head == nullptr) return temp;
    temp->next = head;
    head->prev = temp;
    return temp;
}

DoubleListNode *insertAtEnd(DoubleListNode* head, int x){
    DoubleListNode* temp = head;
    DoubleListNode* xnode = new DoubleListNode(x);
    if(head == nullptr) return xnode;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = xnode;
    xnode->prev = temp;
    return head;
}

DoubleListNode* insertAtValue(DoubleListNode* head, int val, int x) {
    if (head == nullptr) return new DoubleListNode(x);
    
    DoubleListNode* temp = head;
    while (temp != nullptr && temp->val != val) temp = temp->next;

    if (temp == nullptr) {
        cout << "Value " << val << " not found.\n";
        return head;
    }

    DoubleListNode* xnode = new DoubleListNode(x);
    xnode->next = temp->next;
    xnode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = xnode;

    temp->next = xnode;
    return head;
}

DoubleListNode* delPos(DoubleListNode* head, int x) {
    if(x == 1 && head->next != nullptr){
        head->next->prev = NULL;
        head = head->next;
        return head;
    } else if(x == 1 && head->next == nullptr) return NULL;
    else {
        DoubleListNode* temp = head;
        int curr = 1;
        while(curr != x){
            temp = temp->next;
            curr++;
        }
        if(temp->next != nullptr){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            return head;
        } else if(temp->next == nullptr){
            temp->prev->next = NULL;
            return head;
        }
    }
    return head;

}


int main(){
    DoubleListNode* head = new DoubleListNode(2);
    head->next = new DoubleListNode(3);
    head->next->next = new DoubleListNode(4);
    traversal(head);
    head = insertAtBeginning(head, 1);
    traversal(head);
    head = insertAtEnd(head, 5);
    traversal(head);
    head = insertAtValue(head, 1, 11);
    traversal(head);
    head = delPos(head, 2);
    traversal(head);
}