#ifndef NODE_H
#define NODE_H

class Node {
  friend class LinkedList;
public:
  Node(int,Node*);
private: 
int data;
Node* link;  
};

#endif