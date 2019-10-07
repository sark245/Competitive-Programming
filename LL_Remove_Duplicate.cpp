#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node * ptrtonext;
    Node(int d) {
        data = d;
        ptrtonext = NULL;
    }
};
class Linkedlist {
public:
    Node * createlinkedlist(int numofnodes) {
        Node * head = NULL;
        Node * tail = NULL;
        int ctr = 0;
        while (ctr < numofnodes) {
            int d;
            cin >> d;
            Node * newnode = new Node(d);
            if (ctr == 0) {
                head = newnode;
                tail = newnode;
                ctr++;
            }
            else {
                tail -> ptrtonext = newnode;
                tail = newnode;
                ctr++;
            }
        }
        return head;
    }
    void printlinkedlist(Node * head) {
        Node * curnode = head;
        while (curnode != NULL) {
            cout << curnode -> data << " ";
            curnode = curnode -> ptrtonext;
        }
    }
    Node * remove_dup(Node * head){
        Node * curnode = head;
        while(curnode->ptrtonext!=NULL){
            if(curnode->data == curnode->ptrtonext->data){
                curnode-> ptrtonext = curnode->ptrtonext->ptrtonext;
            }
            else{
                curnode = curnode->ptrtonext;
            }
        }
        return head;

    }
};
int main() {
    int numofnodes;
    cin >> numofnodes;
    Linkedlist L;
    Node * head = L.createlinkedlist(numofnodes);
    head = L.remove_dup(head);
    L.printlinkedlist(head);
}
