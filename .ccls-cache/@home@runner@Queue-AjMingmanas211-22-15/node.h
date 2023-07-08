#ifndef node_h
#define  node_h
#include <iostream>
using namespace std;

class NODE {
	int OrderNumber, quantity;
	NODE* nextPtr;
public:
	NODE(int, int = 1);
	~NODE();
  int getPrice();
	void setNext(NODE*);
	NODE* getNext();
};

typedef NODE* NodePtr;

NODE::NODE(int order, int quan){
	OrderNumber = order;
	quantity = quan;
}

NODE* NODE::getNext(){
	return nextPtr;

}

void NODE::setNext(NODE *t){
	 nextPtr=t;

}

NODE::~NODE(){

}


int NODE::getPrice(){
  int price;
  switch (OrderNumber){
    case 1: 
      price = 200 * quantity; break;
    case 2:
      price = 100 * quantity; break;
    case 3:
      price = 50 * quantity; break;
    default:
      price = 0; break;
  }
	return price;
}
#endif