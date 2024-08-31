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
  ListNode* oddEvenList(ListNode* head) {
    if (!head) return nullptr;
    ListNode* odd = head;
    ListNode* even = head->next;
    while (even != nullptr) {
      if (!even->next) break;
      ListNode* tempE = even->next->next;
      ListNode* tempO = odd->next;
      odd->next = even->next;
      odd->next->next = tempO;
      even->next = tempE;
      odd = odd->next;
      even = even->next;
    }
    return head;
  }
};

int main() {



  return 0;
}