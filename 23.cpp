#include <iostream>
using namespace std;
/*
23 - Merge k Sorted Lists - HARD [Acceptance Rate : 59.9%]  
* You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
* Merge all the linked-lists into one sorted linked-list and return it.
*
*/

struct ListNode
{
    ListNode* next;
    int val;
};

class Solution {
public:

    void insert_node(ListNode* &global_list, ListNode* node)
    {
        if (global_list == nullptr || node->val < global_list->val)
        {
            node->next = global_list;
            global_list = node;
            return;
        }
        for (ListNode* ptr = global_list; ptr != nullptr; ptr = ptr->next)
        {
            if (ptr->next == nullptr) // Edge case
            {
                ptr->next = node;
                node->next = nullptr;
                break;
            }
            if (ptr->next->val >= node->val)
            {
                ListNode* toAttach = ptr->next;
                ptr->next = node;
                node->next = toAttach;
                break;
            }
        }
    }

    void process_list(ListNode* &global_list, ListNode* list)
    {
        if (list == nullptr)
            return;
        ListNode* next_node = list->next; 
        insert_node(global_list, list);
        process_list(global_list, next_node);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* global_list = nullptr;

        for (auto& current_list : lists)
        {
            process_list(global_list, current_list);
        }
        return global_list;
    }
};