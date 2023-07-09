#include <iostream>
#include "queue.h"

using namespace std;

void printMenu();
void payment(Queue&);

int main(int argc, char* argv[]) {
  Queue order;
  
  cout << "Welcome to Queue Restaurant!" << endl;
  printMenu();

  int count = 0;
  for (int i = 1; i < argc; i += 2) {
  static int number = 0;
    number ++;
    int orderNumber = atoi(argv[i]);
    cout << "========================="<< endl;
    cout << "Customer number " << number << " order is " << orderNumber << endl;
    int quantity = atoi(argv[i + 1]);
    cout << "quantity " << quantity << endl;
    order.enqueue(orderNumber, quantity);
    count++;
    if (!order.isEmpty() && count>=2){
    payment(order);
    }
    else {
    continue;
    }
  }
  
  cout << "========================="<< endl;
  cout << "The restaurant is closed!" << endl;
  int size = order.getSize();
  cout << "There is " << size << " person left in the queue" << endl;
  cout << "========================="<< endl;
  return 0;
}

void printMenu() {
  cout << "========= Menu ==========" << endl;
  cout << " 1. Chicken         200 " << endl;
  cout << " 2. Fries           100 " << endl;
  cout << " 3. Coke             50 " << endl;
}



void payment(Queue& order) {
  static int number = 0;
  int cash = 0;
  int price = 0;
  number++;
  
  cout << "========================="<< endl;
  cout << "Customer number " << number << ": Your Order is Here!" << endl;
  price = order.dequeue();
  cout <<"You have to pay: " <<  price << endl;
  
  while (cash < price) {
    cout << "Give me money: ";
    cin >> cash;
  }
  
  if (cash > price) {
    cout << "Change: " << cash - price << endl;
    cout << "Thank you!" << endl;
  }
  else {
    cout << "Thank you!" << endl;
  }
}
