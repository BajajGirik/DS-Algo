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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		int carry = 0;
		ListNode *head = new ListNode(0);
		ListNode *ptr = head;
		while (l1 and l2)
		{
			ListNode *node = new ListNode((l1->val + l2->val + carry) % 10);
			carry = (l1->val + l2->val + carry) / 10;
			ptr->next = node;
			ptr = node;

			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1)
		{
			ListNode *node = new ListNode((l1->val + carry) % 10);
			carry = (l1->val + carry) / 10;
			ptr->next = node;
			ptr = node;

			l1 = l1->next;
		}

		while (l2)
		{
			ListNode *node = new ListNode((l2->val + carry) % 10);
			carry = (l2->val + carry) / 10;
			ptr->next = node;
			ptr = node;

			l2 = l2->next;
		}

		if (carry != 0)
		{
			ListNode *node = new ListNode(carry % 10);
			ptr->next = node;
			ptr = node;
		}

		return head->next;
	}
};