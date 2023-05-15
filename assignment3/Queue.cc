#include "Queue.h"

Queue::Queue(){
    head = NULL;
    tail = NULL;
    numOrders = 0;
}

Queue::~Queue(){
    Node* cur=head;
    Node* prev;
    while(cur != NULL){
        prev= cur;
        cur = cur->nodeNext;
        delete prev;
    }
}

bool Queue::empty()   const{
    bool temp=  numOrders==0? true: false;
    return temp;
}

int Queue::size() const{
    return numOrders;
}

Order* Queue::peekFirst() const{
    if(head==NULL) return nullptr;
    return head->data;
}

Order* Queue::popFirst(){
    if(head==NULL) return nullptr;
    Node* temp = head;
    head = head->nodeNext;
    Order* tempOrder = temp->data; 
    delete temp;
    --numOrders;
    return tempOrder;    
}

void Queue::addLast(Order* order) {
    if(head==NULL){
        Node* node = new Node;
        node->nodeNext = NULL;
        node->data = order;
        head = node;
        tail = node;
        ++numOrders;
        return;
    }
    Node* cur = tail;
    Node* newNode = new Node;
    newNode->data = order;
    newNode->nodeNext = NULL;
    cur->nodeNext = newNode;
    tail = newNode;
    ++numOrders;
}

void Queue::print() const{
    Node* temp = head;
    while((temp->nodeNext) != nullptr){
        (temp->data)->print();
        temp = temp->nodeNext;
    }
}