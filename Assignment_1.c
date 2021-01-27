// #define _CRT_SECURE_NO_WARNINGS // uncomment for Visual Studios

/* CE1107/CZ1107 Data Structures and Algorithm
Assignment 1 - Linked List Questions
Purpose: Implementing the required functions for Question 1
Coded by: Muqaffa
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode {
	int item;
	struct _listnode* next;
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist {
	int size;
	ListNode* head;
} LinkedList;			// You should not change the definition of LinkedList


///////////////////////// function prototypes ////////////////////////////////////

//You should not change the prototype of this function
int insertSortedLL(LinkedList* ll, int item);
void alternateMergeLinkedList(LinkedList* ll1, LinkedList* ll2);
void moveOddItemsToBack(LinkedList* ll);
void frontBackSplitLinkedList(LinkedList* ll, LinkedList* resultFrontList, LinkedList* resultBackList);

void printList(LinkedList* ll);
void removeAllItems(LinkedList* ll);
ListNode* findNode(LinkedList* ll, int index);
int insertNode(LinkedList* ll, int index, int value);
int removeNode(LinkedList* ll, int index);

void Q1();
void Q2();
void Q3();
void Q4();

int main()
{
  // Uncomment question to test
	//Q1();
	//Q2();
	//Q3();
	//Q4();

	return 0;
}

void Q1()
{
	LinkedList ll;
	int c, i, j;
	c = 1;

	//Initialize the linked list 1 as an empty linked list
	ll.head = NULL;
	ll.size = 0;

	printf("1: Insert an integer to the sorted linked list:\n");
	printf("2: Print the index of the most recent input value:\n");
	printf("3: Print sorted linked list:\n");
	printf("0: Quit:");

	while (c != 0)
	{
		printf("\nPlease input your choice(1/2/3/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			j = insertSortedLL(&ll, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			printf("The value %d was added at index %d\n", i, j);
			break;
		case 3:
			printf("The resulting sorted linked list is: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}
}

void Q2()
{
	LinkedList ll1, ll2;
	int c, i, j;
	c = 1;
	//Initialize the linked list 1 as an empty linked list
	ll1.head = NULL;
	ll1.size = 0;

	//Initialize the linked list 2 as an empty linked list
	ll2.head = NULL;
	ll2.size = 0;

	printf("1: Insert an integer to the linked list 1:\n");
	printf("2: Insert an integer to the linked list 2:\n");
	printf("3: Create the alternate merged linked list:\n");
	printf("0: Quit:\n");

	while (c != 0)
	{
		printf("Please input your choice(1/2/3/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list 1: ");
			scanf("%d", &i);
			j = insertNode(&ll1, ll1.size, i);
			printf("Linked list 1: ");
			printList(&ll1);
			break;
		case 2:
			printf("Input an integer that you want to add to the linked list 2: ");
			scanf("%d", &i);
			j = insertNode(&ll2, ll2.size, i);
			printf("Linked list 2: ");
			printList(&ll2);
			break;
		case 3:
			printf("The resulting linked lists after merging the given linked list are:\n");
			alternateMergeLinkedList(&ll1, &ll2); // You need to code this function
			printf("The resulting linked list 1: ");
			printList(&ll1);
			printf("The resulting linked list 2: ");
			printList(&ll2);
			removeAllItems(&ll1);
			removeAllItems(&ll2);
			break;
		case 0:
			removeAllItems(&ll1);
			removeAllItems(&ll2);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}
}

void Q3()
{
	LinkedList ll;
	int c, i, j;
	c = 1;
	//Initialize the linked list 1 as an empty linked list
	ll.head = NULL;
	ll.size = 0;


	printf("1: Insert an integer to the linked list:\n");
	printf("2: Move all odd integers to the back of the linked list:\n");
	printf("0: Quit:\n");

	while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			j = insertNode(&ll, ll.size, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			moveOddItemsToBack(&ll); // You need to code this function
			printf("The resulting linked list after moving odd integers to the back of the linked list is: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}
}

void Q4()
{
	int c, i;
	LinkedList ll;
	LinkedList resultFrontList, resultBackList;

	//Initialize the linked list as an empty linked list
	ll.head = NULL;
	ll.size = 0;

	//Initialize the front linked list as an empty linked list
	resultFrontList.head = NULL;
	resultFrontList.size = 0;

	// Initialize the back linked list as an empty linked list
	resultBackList.head = NULL;
	resultBackList.size = 0;

	printf("1: Insert an integer to the linked list:\n");
	printf("2: Print the linked list:\n");
	printf("3: Split the linked list into two linked lists, frontList and backList:\n");
	printf("0: Quit:\n");
	printf("Please input your choice(1/2/3/0): ");
	scanf("%d", &c);

	while (c != 0)
	{
		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			insertNode(&ll, ll.size, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 3:
			printf("The resulting linked lists after splitting the given linked list are:\n");
			frontBackSplitLinkedList(&ll, &resultFrontList, &resultBackList); // You need to code this function
			printf("Front linked list: ");
			printList(&resultFrontList);
			printf("Back linked list: ");
			printList(&resultBackList);
			printf("\n");
			removeAllItems(&ll);
			removeAllItems(&resultFrontList);
			removeAllItems(&resultBackList);
			break;
		case 0:
			removeAllItems(&ll);
			removeAllItems(&resultFrontList);
			removeAllItems(&resultBackList);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}

		printf("\nPlease input your choice(1/2/3/0): ");
		scanf("%d", &c);
	}

}
//////////////////////////////////////////////////////////////////////////////////

int insertSortedLL(LinkedList* ll, int item)
{
	int i = 0;
	ListNode* curr, * prev = NULL;

	for (curr = ll->head; curr != NULL; prev = curr, curr = curr->next, i++)
	{
		if (curr->item == item)
			return -1;
		if (curr->item > item) // found insertion slot
			break;
	}
	if (prev == NULL) // indicates that item is to be inserted at index 0
	{
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = item;
		ll->head->next = curr;
	}
	else
	{
		prev->next = malloc(sizeof(ListNode));
		prev->next->item = item;
		prev->next->next = curr;
	}
	return i;
}

///////////////////////////////////////////////////////////////////////////////////

void alternateMergeLinkedList(LinkedList* ll1, LinkedList* ll2)
{
	int i = 1;
	while (ll2->size > 0)
	{
		if (insertNode(ll1, i, ll2->head->item) != 0)
			break;
		removeNode(ll2, 0);
		i += 2;
	}
}

void moveOddItemsToBack(LinkedList* ll)
{
	int i;
	ListNode* tail, * curr = ll->head, * prev = NULL;

	if (ll->size < 2)
		return;
	for (tail = ll->head; tail->next != NULL; tail = tail->next); // get tail
	for (i = 0; i < ll->size && curr != NULL; i++) // && curr != NULL not needed if size is always correct
	{
		if (curr->item % 2 != 0) // found odd number
		{
			if (curr == tail) // if only final number is odd, no action needed
				break;
			if (prev == NULL)
				ll->head = curr->next;
			else
				prev->next = curr->next;
			tail->next = curr;
			tail = curr; // update tail
			tail->next = NULL;
			curr = prev ? prev->next : ll->head; // reassign curr pointer
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

void frontBackSplitLinkedList(LinkedList* ll, LinkedList* resultFrontList, LinkedList* resultBackList)
{
	int i = 0;
	ListNode* curr;

	for (curr = ll->head; curr != NULL; curr = curr->next, i++)
	{
		if (i < (ll->size + 1) / 2)
			insertNode(resultFrontList, resultFrontList->size, curr->item);
		else
			insertNode(resultBackList, resultBackList->size, curr->item);
	}
}

void printList(LinkedList* ll) {

	ListNode* cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}


void removeAllItems(LinkedList* ll)
{
	ListNode* cur = ll->head;
	ListNode* tmp;

	while (cur != NULL) {
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}


ListNode* findNode(LinkedList* ll, int index) {

	ListNode* temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0) {
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList* ll, int index, int value) {

	ListNode* pre, * cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0) {
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL) {
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList* ll, int index) {

	ListNode* pre, * cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0) {
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL) {

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}
