#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
 
struct ListNode* detectCycle(struct ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (1) {
		fast = fast->next;
		if (fast == NULL) {
			return NULL;
		}
		fast = fast->next;
		if (fast == NULL) {
			return NULL;
		}
		slow = slow->next;
		if (slow == fast) {
			break;
		}
	}
	slow = head;
	while (1) {
		if (slow == fast) {
			return slow;
		}
		fast = fast->next;
		slow = slow->next;
	}
}