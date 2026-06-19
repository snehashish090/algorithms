#include <iostream>
using namespace std;
/*
* 430 - Flatten a Multilevel Double Linked List MEDIUM
* https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
*
* You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, 
* and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, 
* also containing these special nodes. These child lists may have one or more children of their own, and so on, 
* to produce a multilevel data structure as shown in the example below.
*
* Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, 
* doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr 
* and before curr.next in the flattened list.
*
* Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.
*/

// Underlying Data Structue
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    // Helper function

    Node** return_tree(Node* head)
    {
        Node** pointers = new Node*[2]; // [head ,tail]
        pointers[0] = head;
        for (Node* ptr=head; ptr!=nullptr; ptr=ptr->next)
        {
            if (ptr->child){

                Node** ptrs = return_tree(ptr->child);
                if (ptr->next)
                {
                    Node* temp = ptr->next;
                    ptr->next = ptrs[0];
                    ptrs[0]->prev = ptr;
                    temp->prev = ptrs[1];
                    ptrs[1]->next = temp;
                }
                else{
                    ptr->next = ptrs[0];
                    ptrs[0]->prev = ptr;
                }
                ptr->child = nullptr;
            }

            if (ptr->next == nullptr){pointers[1] = ptr;} // Mark the tail
        }
        return pointers;
    }

    Node* flatten(Node* head) {
        // Simple recursion problem
        
        Node** output = return_tree(head);
        return output[0];
    }
};








