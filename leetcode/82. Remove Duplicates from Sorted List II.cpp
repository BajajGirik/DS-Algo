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
		if (head == NULL or head->next == NULL)
			return head;

		ListNode *sentinel = new ListNode(0, head);
		ListNode *result = sentinel;
		result->next = NULL;

		while (head)
		{
			int val = head->val;
			if (head->next and val == head->next->val)
				while (head and val == head->val)
					head = head->next;
			else
			{
				result->next = head;
				head = head->next;
				result = result->next;
				result->next = NULL;
			}
		}

		return sentinel->next;
	}
};