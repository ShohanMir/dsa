#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* head = new ListNode(0);
            ListNode* curr = head;
            int carry = 0; // carry is used to store the carry

            while (l1 != NULL || l2 != NULL || carry != 0) {
                int x = l1 ? l1->val : 0;
                int y = l2 ? l2->val : 0;
                int sum = x + y + carry; // sum of current digits
                carry = sum / 10; // carry is the remainder

                curr->next = new ListNode(sum % 10);
                curr = curr->next;
                l1 = l1 ? l1->next : nullptr;
                l2 = l2 ? l2->next : nullptr;
            }

            return head->next;
        }
};

// Driver function
