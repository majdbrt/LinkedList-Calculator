#include "list.h"

using namespace std;

// inserNumber
// takes user input and inserts the digits into linked-list backward. 
//
void insertNumber(List& head);

// addNumber
// takes two linked-list of numbers and adds them resulting in a new linked-list.
// the new linked-list is returned.
//
List addNumber(List& l1, List& l2);

int main(){


    List l1;
    List l2;

    insertNumber(l1);
    insertNumber(l2);

    List l3 = addNumber(l1, l2);
    
    cout << "The result is: ";
    l3.printList();
    return 0;
}

void insertNumber(List& head){
    cout << "Enter a valid number: ";
    int number = 0;
    cin >> number;
    while(number!= 0){
        int digit = number % 10;
        head.pushEnd(digit);
        number = number/10;
    }// while
}// insertNumber

List addNumber(List& l1, List& l2){
    List l3;
    int size1 = l1.size();
    int size2 = l2.size();

    if(size1 == size2){
        int sum = 0;
        int remainder = 0;

        for(int i = 0; i < size1; i++){
            sum = l1.ith(i) + l2.ith(i);
            sum = sum + remainder;
            if (sum - 10 >= 0){
                remainder = sum/10;
                sum = sum - 10;
            }// if

            l3.push(sum);

        }// for

        if(remainder != 0){
            l3.push(remainder);
        }// if
    }// if

    else if( size1 > size2){
        int sum = 0;
        int remainder = 0;
        int i = 0;

        for(i = 0; i < size2; i++){
            sum = l1.ith(i) + l2.ith(i);
            sum = sum + remainder;

            if(sum - 10 >=0){
                remainder = sum/10;
                sum = sum - 10;
            }// if
            l3.push(sum);
        }// for

        for(;i<size1; i++){
            sum = l1.ith(i)+ remainder;
            if(sum - 10 >=0){
                remainder = sum/10;
                sum = sum - 10;
            }// if
            l3.push(sum);
        }// for

        if(remainder != 0){
            l3.push(remainder);
        }// if
    }// else if

    else{
        int sum = 0;
        int remainder = 0;
        int i = 0;

        for(i = 0; i < size1; i++){
            sum = l1.ith(i) + l2.ith(i);
            sum = sum + remainder;

            if(sum - 10 >=0){
                remainder = sum/10;
                sum = sum - 10;
            }// if
            l3.push(sum);
        }// for
        for(;i<size2; i++){
             sum = l2.ith(i)+ remainder;
            if(sum - 10 >=0){
                remainder = sum/10;
                sum = sum - 10;
            }// if
            l3.push(sum);
        }// for
        if(remainder != 0){
            l3.push(remainder);
        }// if
    }// else

    return l3;
}// addNumber