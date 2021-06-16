#include <iostream>
#include <string>

using namespace std;

struct node{
    int val;
    node* next;

};

void push(node** head, int x){
    if(*head == nullptr){
        *head = new node();
        (*head)->val = x;
        (*head)->next = nullptr;
        return;
    }// if

    node* newNode = new node();
    newNode->val = x;
    newNode->next = *head;
    *head = newNode;
}

void pushEnd(node** head, int x){
    if(*head == nullptr){
        *head = new node();
        (*head)->val = x;
        (*head)->next = nullptr;
        return;
    }// if

    node* cur = *head;
    while(cur->next != nullptr){
        
        cur = cur->next;
    }

    node* newNode = new node();
    newNode->val = x;
    newNode->next = nullptr;
    cur->next = newNode;
}

void printList(node* head){
    while(head != nullptr){
        cout << head->val;
        head = head->next;
    }// while
    cout << endl;
}

void insertNumber(node** head){
    cout << "Enter a valid number: ";
    int number = 0;
    cin >> number;
    while(number!= 0){
        int digit = number % 10;
        pushEnd(&(*head), digit);
        number = number/10;
    }
}

int sizeList(node* head){
    int i = 0;
    while(head != nullptr){
        i++;
        head = head->next;
    }
    return i;
}

node* addNumber(node** l1, node** l2){
    node* l3 = nullptr;
    int size1 = sizeList(*l1);
    int size2 = sizeList(*l2);

    node* cur1 = *l1;
    node* cur2 = *l2;

    if(size1 == size2){
        int sum = 0;
        int remainder = 0;
        while(cur1 != nullptr){
            sum = cur1->val + cur2->val;
            sum = sum+ remainder;
            if(sum - 10 >=0){
                remainder = 1;
                sum = sum - 10;
            }

            push(&l3, sum );
            cur1 = cur1->next;
            cur2 = cur2->next;
        }// while

        if(remainder != 0){
            push(&l3, remainder);
        }// if
    }// if

    else if( size1 > size2){
        int sum = 0;
        int remainder = 0;

        while(cur2 != nullptr){
            sum = cur1->val + cur2->val;
            sum = sum+ remainder;
            if(sum - 10 >=0){
                remainder = 1;
                sum = sum - 10;
            }

            push(&l3, sum );
            cur1 = cur1->next;
            cur2 = cur2->next;
        }// while

        while(cur1 != nullptr){
            push(&l3, cur1->val + remainder);
            remainder = 0;
            cur1 = cur1->next;
        }// while
    }

    else{
        int sum = 0;
        int remainder = 0;

        while(cur1 != nullptr){
            sum = cur1->val + cur2->val;
            sum = sum+ remainder;
            if(sum - 10 >=0){
                remainder = 1;
                sum = sum - 10;
            }

            push(&l3, sum );
            cur1 = cur1->next;
            cur2 = cur2->next;
        }// while

        while(cur2 != nullptr){
            push(&l3, cur2->val + remainder);
            remainder = 0;
            cur2 = cur2->next;
        }// while
    }// else

    return l3;
}

int main(){

    node* l1 = nullptr;
    node* l2 = nullptr;

    insertNumber(&l1);
    insertNumber(&l2);

    node* l3 = addNumber(&l1, &l2);
    printList(l3);
    
    return 0;
}