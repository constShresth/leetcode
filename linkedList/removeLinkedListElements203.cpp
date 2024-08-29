#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* curr = head;
    ListNode* prevNode = curr;

    while (curr != nullptr) {
      if (curr->val == val) {
        if (curr == head) {
          curr = curr->next;
          head = curr;
          prevNode = curr;
        }
        else {
          prevNode->next = curr->next;
          curr = curr->next;
        }
      }
      else {
        prevNode = curr;
        curr = curr->next;
      }
    }
    return head;
  }

};

int main() {



  return 0;
}