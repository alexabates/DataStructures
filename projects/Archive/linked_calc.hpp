#ifndef LINKED_CALC_HPP
#define LINKED_CALC_HPP

//template class for the node
template <typename T>
class Node{
    public:
        T data;
        Node *next;
        Node *prev;

        //constructor
        Node(T value) : data(value), next(nullptr), prev(nullptr){}
        
};

//template class for LinkedCalc
template <typename T>
class LinkedCalc{
    private:
        Node<T> *head;
        Node<T> *tail;

    public:
        //constructor
        LinkedCalc() : head(nullptr), tail(nullptr) {}
        void insert(T value);
        bool validateExpression();
        float evaluateExpression();
        //helper function
        float convertDigit(Node<T>* &node); //helper function

};

#endif