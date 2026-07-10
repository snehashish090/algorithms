#include <iostream>
using namespace std;
/*
* 61 - Rotate List - MEDIUM [Acceptance Rate : 42.7%]
* https://leetcode.com/problems/rotate-list
*
* Given the head of a linked list, rotate the list to the right by k places.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (k<=0 || head==nullptr || head->next == nullptr){return head;}
        // two pointer approach
        ListNode* y = nullptr;
        ListNode* x = head;

        int size=1;
        for (; x->next != nullptr; y=x, x=x->next, ++size);

        y->next = nullptr;
        x->next = head;
        head = x;

        return rotateRight(head, (--k)%size);
    }
};