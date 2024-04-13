/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int findLen(Node *slow,Node *fast){
  fast=fast->next;
  int len=1;
  while(slow!=fast){
      len++;
      fast=fast->next;
  }
  return len;
}
int lengthOfLoop(Node *head) {
    Node *slow = head;
  Node *fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return findLen(slow, fast);
  }
  return 0;
}
