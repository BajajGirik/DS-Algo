/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	ListNode *hasCycle(ListNode *head)
	{
		if (head == NULL)
			return NULL;

		ListNode *slow = head;
		ListNode *fast = head;
		while (fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;

			if (fast == NULL)
				break;

			if (slow->next == fast->next)
				break;
		}

		return fast;
	}

	ListNode *detectCycle(ListNode *head)
	{
		ListNode *ptr = hasCycle(head);

		if (ptr == NULL)
			return NULL;
		if (ptr->next == NULL)
			return NULL;

		ListNode *temp = head;
		while (temp->next != ptr->next)
		{
			temp = temp->next;
			ptr = ptr->next;
		}

		if (temp == ptr)
			return ptr;

		return temp->next;
	}
};