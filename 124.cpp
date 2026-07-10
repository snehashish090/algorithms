/**
* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;

 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 * };
 *
 */

class FrontierNode {
    TreeNode* node;
    TreeNode* next;

    FrontierNode(TreeNode* node)
    {
        this->node = node;
        this->next = nullptr;
    }
    FrontierNode(TreeNode* node, TreeNode* next)
    {
        this->node = node;
        this->next = next;
    }
};

class QueueFrontier
{
    Node* head;
    Node* tail;

    QueueFrontier(Node* head, Node* tail)
    {
        this->head = head;
        this->tail = tail;
    }
};

class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        TreeNode* current = root;
        QueueFrontier* frontier =  &QueueFrontier(
            FrontierNode(root),
            FrontierNode(root)
        );
        while (current != nullptr)
        {
            // Defualt Behaviour
            TreeNode* bigger = current->left;
            if (current->left->val > current->right->val)
                bigger = left;
            else
                bigger = right;
        }
        return 0;
    }
};