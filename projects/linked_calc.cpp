#include "linked_calc.hpp"
#include <iostream>
#include <cctype> //needed for isdigit() function
#include <string>
#include <sstream> //needed for stringstream
using namespace std;


template <typename T>
void LinkedCalc<T> :: insert(T value){
    //create a new node for the given value
    Node<T> *newNode = new Node<T>(value);

    //if the list is empty, make the new node the head
    if(head == nullptr){
        head = newNode;
    } else {
        //if not empty, traverse to the end of the list to insert the new node
        Node<T> *curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = newNode; //link the last node to the new node
    }
}

template <typename T>
bool LinkedCalc<T>::validateExpression() {
    if (head == nullptr) {
        cout << "No expression given" << endl;
        return false; //return false if the expression given is empty
    }

    Node<T>* curr = head;
    char lastSeen = '\0'; //tracks the last seen character type
    bool seenDigit = false; //tracks whether we've seen at least one digit
    bool seenDecimal = false; //tracks if a decimal point has been seen

    while (curr != nullptr) {
        char c = curr->data;

        if (isdigit(c)) {
            seenDigit = true;
            lastSeen = 'd'; //mark last seen as a digit
            seenDecimal = false; //reset decimal flag on seeing a digit
        } else if (c == '.') {
            if (lastSeen != 'd' || seenDecimal) {
                //a decimal should follow a digit and only occur once
                return false;
            }
            seenDecimal = true; //mark decimal as seen
            lastSeen = '.'; //mark last seen as a decimal
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (lastSeen != 'd') {
                //operators must follow a digit
                return false;
            }
            lastSeen = 'o'; //mark the last seen as an operator
        } else {
            //return false if the character is not a digit, operator, or decimal
            return false;
        }

        curr = curr->next; //move to the next node
    }
    //expression is only valid if it ends with a digit
    return seenDigit && lastSeen != 'o' && lastSeen != '.';
}


template <typename T>
float LinkedCalc<T>::evaluateExpression() {
    if (head == nullptr) {
        cout << "No expression given" << endl;
        return -1; //return error if list is empty
    }

    //first pass: Handle multiplication and division
    Node<T>* curr = head;
    Node<T>* prev = nullptr;

    while (curr != nullptr) {
        if (curr->data == '*' || curr->data == '/') {
            Node<T>* leftNode = prev; //points at left number
            Node<T>* rightNode = curr->next; //points at right number

            if (leftNode && rightNode) { //ensure there are valid left and right operands

                //convert the operands to float
                float leftNum = convertDigit(leftNode);
                float rightNum = convertDigit(rightNode);
                float intermediateResult = 0.0;

                //perform operation
                if (curr->data == '*') {
                    intermediateResult = leftNum * rightNum;
                } else {
                    intermediateResult = leftNum / rightNum;
                }

                //replace the result in the leftNode and fix the list pointers
                leftNode->data = intermediateResult;

                //update pointers: remove operator and right number nodes
                leftNode->next = rightNode->next; //skip the operator and right operand

                delete curr;    //delete the operator node
                delete rightNode; //delete the right operand node

                curr = leftNode; //move current back to the result node
            }
        } else {
            prev = curr; //move previous pointer
        }
        curr = curr->next; //move current pointer
    }

    //second pass: handle addition and subtraction
    curr = head; //reset current pointer
    prev = nullptr;

    while (curr != nullptr) {
        if (curr->data == '+' || curr->data == '-') {
            Node<T>* leftNode = prev;
            Node<T>* rightNode = curr->next;

            if (leftNode && rightNode) {
                //convert operands to float
                float leftNum = convertDigit(leftNode);
                float rightNum = convertDigit(rightNode);
                float intermediateResult = 0.0;

                //perform operations
                if (curr->data == '+') {
                    intermediateResult = leftNum + rightNum;
                } else {
                    intermediateResult = leftNum - rightNum;
                }

                //replace the result in the leftNode and fix the list pointers
                leftNode->data = intermediateResult;
                leftNode->next = rightNode->next; //skip the operator and right operand

                delete curr; //delete the operator node
                delete rightNode; //delete the right operand node

                curr = leftNode; //move current back to the result node
            }
        } else {
            prev = curr; //move previous pointer
        }
        curr = curr->next; //move current pointer
    }

    //at the end of evaluation, the head should contain the result
    return head->data; //ensure you return the final computed result
}


template <typename T>
float LinkedCalc<T>::convertDigit(Node<T>* &node) {

    stringstream ss;
    Node<T>* current = node;

    //traverse backward to find the start of the number for left operand (if there are multiple nodes for a float)
    while (current->prev != nullptr && (isdigit(current->prev->data) || current->prev->data == '.')) {
        current = current->prev;
    }

    //now traverse forward to collect the digits for the entire number
    while (current != nullptr && (isdigit(current->data) || current->data == '.')) {
        ss << current->data;
        current = current->next;
    }

    float value;
    ss >> value; //convert the stringstream to float

    return value;
}

//explicit template instantiation for char
//my compiler wouldn't work without this line
template class LinkedCalc<char>;