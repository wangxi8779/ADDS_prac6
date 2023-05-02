#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList {
public:
  LinkedList();
  LinkedList(int* array,int len);
  ~LinkedList();
  void insertPosition(int pos, int newNum);
  bool deletePosition(int pos);
  int get(int pos);
  int search(int target);
  void printList();
private: 
  Node* head;
  Node* traverse(unsigned int index);
};

#endif