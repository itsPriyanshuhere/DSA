#include <iostream>

struct Node {
  int data;
  Node* left;
  Node* right;
};

struct ListNode {
  int data;
  ListNode* next;
};

void insert(ListNode*& head, int data) {
  ListNode* newNode = new ListNode{data, nullptr};
  if (head == nullptr) {
    head = newNode;
  } else {
    ListNode* curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

void addElement(Node* root, int data) {
  if (root == nullptr) {
    return;
  }
  if (data < root->data) {
    addElement(root->left, data);
  } else if (data > root->data) {
    addElement(root->right, data);
  } else {
    // data already exists in the tree
    return;
  }
  insert(root->list, data);
}

int main() {
  Node* root = new Node{5, nullptr, nullptr};
  addElement(root, 3);
  addElement(root, 7);
  addElement(root, 2);
  addElement(root, 4);
  addElement(root, 6);
  addElement(root, 8);

  // print the linked list for each node
  std::cout << "Linked lists for each node:" << std::endl;
  std::cout << root->data << ": ";
  ListNode* curr = root->list;
  while (curr != nullptr) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  std::cout << std::endl;

  std::cout << root->left->data << ": ";
  curr = root->left->list;
  while (curr != nullptr) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  std::cout << std::endl;

  std::cout << root->right->data << ": ";
  curr = root->right->list;
  while (curr != nullptr) {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  std::cout << std::endl;

  return 0;
}