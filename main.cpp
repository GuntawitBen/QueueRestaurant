#include <iostream>
#include "queue.h"

using namespace std;

void printMenu();
void getOrder(int& orderNumber, int& quantity);
void payment(Queue&);

int main() {
  Queue order;
  int orderNumber, quantity;
  
  cout << "Welcome to Queue Restaurant!" << endl;
  printMenu();
  
  int count = 0;
  getOrder(orderNumber, quantity);
  order.enqueue(orderNumber, quantity);
  do {
    if (order.isEmpty()){
      getOrder(orderNumber, quantity);
      order.enqueue(orderNumber, quantity);
    } 
    else { //pay money
      payment(order);
      count++;
    }
  } while (count < 5);
  
  cout << "========================="<< endl;
  cout << "The restaurant is closed!" << endl;
  int size = order.getSize();
  cout << "There are " << size << " people left in the queue" << endl;
  cout << "========================="<< endl;
  return 0;
}

void printMenu() {
  cout << "========= Menu ==========" << endl;
  cout << " 1. Chicken         200 " << endl;
  cout << " 2. Fries           100 " << endl;
  cout << " 3. Coke             50 " << endl;
  cout << "========================="<< endl;
}

void getOrder(int& orderNumber, int& quantity) {
  static int number = 0;
  ++number;
  cout << "========================="<< endl;
  cout << "Customer number " << number << endl;  
  do {
    cout << "What would you like to have? : ";
    cin >> orderNumber;
    if (orderNumber > 3) {
      cout << "Come on! That's not in the menu!" << endl;
    }
    else {
      break;
    }
  } while (true);

  
  cout << "How many? : ";
  cin >> quantity;
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
