#ifndef QUEUE_H
#define QUEUE_H

#include "Order.h"

class Queue{
    private: 
        class Node{
            public:
                Node* nodeNext;
                // Node* nodePrev;
                Order* data;
        };
        Node* head;
        Node* tail;
        int numOrders;

    public: 
        Queue();
        ~Queue();
        bool empty() const;
        int size() const;
        Order* peekFirst() const;
        Order* popFirst();
        void addLast(Order* order);
        void print() const;


};

#endif