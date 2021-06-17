#include <iostream>
class Node{
    private:
    int val;
    Node* next;

    public:
    Node();
    Node(int x);
    Node(int x, Node* n);
    void setVal(int x);
    void setNext(Node* n);
    int getVal();
    Node* getNext();
};

class List{
    private:
    Node* head;

    public:
    List();
    ~List();

    void printList();
    void push(int x);
    void pushEnd(int x);
    void pop();
    void popEnd();
    int size();
    void clear();
    int ith(int x);
}; 

