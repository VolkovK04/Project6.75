#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
	if (left == right) {
		return head;
	}
	if (left + 1 == right) {
		struct ListNode* buff = head;
		head = head->next;
		head->next = buff;
		return head;
	}
	struct ListNode* ptr = head;
	int index = 0;
	while (index < left-2) {
		ptr = ptr->next;
		index++;
	}
	struct ListNode* start = ptr;
	ptr = ptr->next;
	struct ListNode* end = ptr;

	struct ListNode* buff1 = ptr;
	ptr = ptr->next;
	while (index++ != right-2) {
		struct ListNode* buff2 = ptr->next;
		ptr->next = buff1;
		buff1 = ptr;
		ptr = buff2;
	}
	if (left == 1) {

	}
	else {
		start->next = buff1;
	}
	end->next = ptr;
	if (left == 1) {
		return buff1;
	}
	return head;
}