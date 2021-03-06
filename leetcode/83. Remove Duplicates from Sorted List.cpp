/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if (head == NULL)
			return NULL;

		ListNode *prev = head;
		ListNode *root = head;
		root = root->next;

		while (root)
		{
			if (prev->val != root->val)
			{
				prev->next = root;
				prev = root;
			}

			else
				prev->next = NULL;

			root = root->next;
		}

		return head;
	}
};