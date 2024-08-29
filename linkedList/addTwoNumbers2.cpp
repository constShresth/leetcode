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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode();
    ListNode* curr = head;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int digit1 = l1 != nullptr ? l1->val : 0;
      int digit2 = l2 != nullptr ? l2->val : 0;
      int sum = digit1 + digit2 + carry;
      int digit = sum % 10;
      carry = sum / 10;
      ListNode* node = new ListNode(digit);
      curr->next = node;
      curr = curr->next;
      if (l1 != nullptr) l1 = l1->next;
      if (l2 != nullptr) l2 = l2->next;
    }
    return head->next;
  }
};

int main() {



  return 0;
}