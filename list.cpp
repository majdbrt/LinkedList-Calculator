
#include "list.h"
using namespace std;

Node::Node(){
    next = nullptr;
}
Node::Node(int x){
    val = x;
    next = nullptr;
}
Node::Node(int x, Node* n){
    val = x;
    next = n;
}
    
void Node::setVal(int x){
    val = x;
}
void Node::setNext(Node* n){
    next = n;
}

int Node::getVal(){
    return val;
}

Node* Node::getNext(){
    return next;
}

List::List(){
    head = nullptr;
}
List::~List(){
    while(head != nullptr){
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }// while
}

void List::printList(){
    Node* cur = head;
    while(cur != nullptr){
        cout << cur->getVal();
        cur = cur->getNext();
    }// while
    cout<< endl;
}// printList

void List::push(int x){
    if (head == nullptr){
        head = new Node(x);
        return;
    }// if

    Node* newNode = new Node(x, head);
    head = newNode;
}// push

void List::pushEnd(int x){
    if(head == nullptr){
        head = new Node(x);
        return;
    }// if

    Node* cur = head;
    while(cur->getNext() != nullptr){
        cur = cur->getNext();
    }// while

    Node* newNode = new Node(x);
    cur->setNext(newNode);
}// pushEnd

void List::pop(){
    if(head == nullptr)
        return;
        
    Node* front = head;
    head = head->getNext();
    delete front;
}// pop

void List::popEnd(){
    if (head == nullptr)
        return;

    else if(head->getNext() == nullptr){
        Node* temp = head;
        head = nullptr;
        delete temp;
        return;
    }// else if
        
    Node* cur = head;
    while(cur->getNext()->getNext() != nullptr){
        cur = cur->getNext();
    }// while

    Node* temp = cur->getNext();
    cur->setNext(nullptr);
    delete temp;
}

int List::size(){
    Node* cur = head;
    int i = 0;
    while(cur != nullptr){
        i++;
        cur = cur->getNext();
    }// while
    return i;
}

void List::clear(){
    if(head == nullptr)
        return;
        
    while(head != nullptr){
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }// while
}// clear 

int List::ith(int x){
    int i = 0;
    int val = 0;
    Node* cur = head;
    while(cur != nullptr){
        if(i == x){
            val = cur->getVal();
            break;
        }
        i++;
        cur = cur->getNext();
    }// while
    return  val;
}
/*
int main(){
    List l;

    l.push(2);
    l.push(5);
    l.pushEnd(6);
    l.printList();
    l.popEnd();
    l.popEnd();
    l.popEnd();
    l.printList();
    l.push(3);
    l.printList();

    return 0;
}
*/