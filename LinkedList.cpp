#include "LinkedList.h"
#include <limits>
#include <iostream>
using namespace std;

LinkedList::LinkedList() { head = nullptr; }

Node* LinkedList::traverse(int pos) {
  if (head == nullptr) {
    return head;
  }

  int currPos = 1;
  Node* currNode = head;
  while (currNode->link != nullptr && currPos < pos) {
    currNode = currNode->link;
    currPos++;
  }
  return currNode;
}

LinkedList::LinkedList(int* array, int len) {
  head = nullptr;
  for (int i = 0; i < len; i++) {
    insertPosition(i + 1, array[i]);
  }
};

void LinkedList::insertPosition(int pos, int newNum) {
  if (pos <= 1) {
    head = new Node(newNum, head);
    return;
  }

  Node* prevNode = traverse(pos - 1);
  Node* newNode = new Node(newNum, prevNode->link);
  prevNode->link = newNode;
};

void LinkedList::printList() {
  Node* currNode = head;
  if (currNode == nullptr) {
    cout << endl;
  } else {
    cout << "[";
    while (currNode != nullptr) {
      cout << currNode->data;
      if (currNode->link != nullptr) {
        cout << " ";
      }
      currNode = currNode->link;
    }
    cout << "]" << endl;
  }
};

bool LinkedList::deletePosition(int pos) {
  if (get(pos) == numeric_limits<int>::max()) {
    return false;
  }
  Node* prevNode = traverse(pos - 1);
  Node* node = traverse(pos);
  prevNode->link = node->link;
  delete node;
  return true;
};

int LinkedList::get(int pos) {
  int currPos = 1;
  Node* currNode = head;
  while (currNode != nullptr && currPos < pos) {
    currNode = currNode->link;
    currPos++;
  }
  if (currNode == nullptr) {
    return numeric_limits<int>::max();
  }
  return currNode->data;
};

int LinkedList::search(int target) {
  int currIndex = 0;
  Node* currNode = head;
  while (currNode != nullptr && currNode->data != target) {
    currIndex++;
    currNode = currNode->link;
  }
  if (currNode == nullptr) {
    return -1;
  }
  return currIndex;
};

LinkedList::~LinkedList() {
  Node* node = head;
  while (node != nullptr) {
    Node* next = node->link;
    delete node;
    node = next;
  }
};