#include "node.h"

class Queue {
  NodePtr headPtr, tailPtr;
  int size;

public:
  void enqueue(int);
  int dequeue();
  Queue();
  ~Queue(); // dequeue all
};

Queue::Queue(){
  size=0;
  headPtr=NULL;
  tailPtr=NULL;
}

Queue::~Queue(){
 int i;
 int n=size;

  //while(size>0)
  for(i=0;i<n;i++)
    dequeue();
  
}
void Queue::enqueue(int x) {
  NodePtr new_node = new NODE(x); // 1.Create
 // 2 Connect

// 3 change tai
// 4. increase size
  }
}

int Queue::dequeue() {
  int value;
  NodePtr t;
 if(headPtr){
  // 1. Save the node to be deleted
 

    // 1.5 take the value out to value
    // 2. move (head)
   
    //if(size==1) tailPtr=NULL;
    // 3. delete
   
  }
  return -1;
}