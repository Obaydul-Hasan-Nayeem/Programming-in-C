
#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int data;
    node * nxt;
    node * prv;
};

class DoublyLinkedList {
public:
    node * head;
    int sz;
    DoublyLinkedList() {
        head = NULL;
        sz = 0;
    }

    // function to create a new node with given data and insert it O(1)
    node * CreateNewNode(int data) {
        node *newnode = new node;
        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    // Insert at head with given data O(1)
    void InsertAtHead(int data) {
        sz++;
        node *newnode = CreateNewNode(data);
        if(head == NULL) {
            head = newnode;
            return;
        }
        node *a = head;
        newnode->nxt = a;
        a->prv = newnode;
        head = newnode;
    }

    // Insert at anywhere with the given data and index O(n)
    void Insert(int index, int data) {
        if(index > sz) {
            return;
        }

        if(index == 0) {
            InsertAtHead(data);
            return;
        }

        node *a = head;
        int cur_index = 0;
        while(cur_index != index-1) {
            a = a->nxt;
            cur_index++;
        }
        // now, a = cur_index-1
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        newnode->prv = a;
        node *b = a->nxt;
        a->nxt = newnode;
        sz++;
    }

    // Delete at head
    void DeleteAtHead() {
        node* a = head;
        node* b = head->nxt;
        delete a;
        if(b != NULL) {
            b->prv = NULL;
        }
        head = b;
        sz--;
    }

    // Delete the node with given index O(n)
    void Delete(int index) {
        if(index > sz) {
            cout << index << " doesn't exists.";
            return;
        }

        node *a = head;
        int cur_index = 0;
        while(cur_index != index) {
            a = a->nxt;
            cur_index++;
        }
        // a = index
        node *b = a->prv;
        node *c = a->nxt;
        if(b != NULL) {
            b->nxt = c;
        }
        if(c != NULL) {
            c->prv = b;
        }

        delete a;

        if(index == 0) {
            head = c;
        }
        sz--;
    }

    // Print the linked list O(n)
    void Traverse() {
        node * a;
        a = head;
        while(a != NULL) {
            cout << a->data << " ";
            a = a->nxt;
        }
        cout << "\n";
    }

    // reverse the doubly linked list O(2*n) = O(n)
    void Reverse(){
        if(head == NULL) {
            return;
        }
        node * a = head;
        int cur_index = 0;
        while(cur_index != sz-1) {
            a = a->nxt;
            cur_index++;
        }
        // now a = last index (sz-1)

        node *b = head;

        while(b != NULL) {
            swap(b->prv, b->nxt);
            b = b->prv;
        }
        head = a;
    }


    // print the size of the linked list O(1)
    int getSize() {
        return sz;
    }
};

// Stack using doubly linked list
class Stack {
public:
    DoublyLinkedList dl;

    Stack() {

    }

    int top() {
        if(dl.getSize() == 0) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return dl.head->data;
    }

    void push(int val) {
        dl.InsertAtHead(val);
    }

    void pop() {
        if(dl.getSize() == 0) {
            cout << "Stack is empty!\n";
            return;
        }
        dl.DeleteAtHead();
    }
};


int main() {
//
//DoublyLinkedList dl;
//dl.InsertAtHead(5);
//dl.InsertAtHead(10);
//dl.InsertAtHead(15);
//dl.InsertAtHead(35);
//dl.Traverse();
//dl.Reverse();
//dl.Traverse();

Stack st;
st.push(5);
st.push(6);
st.push(7);
st.push(8);
cout << st.top();

return 0;
}