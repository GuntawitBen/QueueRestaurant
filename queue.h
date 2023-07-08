#include "node.h"
#include <iostream>
using namespace std;

class Queue {
  NodePtr headPtr, tailPtr;
  int size;
public:
  void enqueue(int order, int quantity);
  int dequeue();
  bool isEmpty();
  int getSize();
  Queue();
  ~Queue(); // dequeue all
};

int Queue::getSize(){
  return size;
}

bool Queue::isEmpty() {
  return size == 1;
}

Queue::Queue(){
  size=0;
  headPtr = NULL;
  tailPtr = NULL;
}

Queue::~Queue(){
 int i;
 int n=size;
  //while(size>0)
  for(i=0;i<n;i++)
    dequeue();
}

void Queue::enqueue(int order, int quantity) {
  NodePtr new_node = new NODE(order, quantity);
  if(new_node){
    if (size == 0){ //first node change head
      headPtr = new_node;
    }
    else {
      //if not, current tail will hold new node
      tailPtr->setNext(new_node);
    }
  //either way, tail becomes new node and size increased
   tailPtr = new_node;
   ++size;
  }
  else {
    cout << "memory is full" << endl;
  }
}

int Queue::dequeue() {
  int value;
  NodePtr temp;
  if(headPtr){
    // 1. Save the node to be deleted
   temp = headPtr;
    // 1.5 take the value out to 
   value = temp->getPrice();
    // 2. move (head)
   headPtr = headPtr->getNext();
    // 3. delete
   delete temp;
   size--;
   return value;
  }
  return -1;
}

