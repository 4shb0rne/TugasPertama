#include <stdio.h>
#include <stdlib.h>
/*
Individual Assignment
1. Given two sorted linked lists L1 and L2 of size M and N respectively, merge them into one sorted linked list.
2. Find the range (difference between maximum and minimum value) of a linked list.
3. Find the middle element of a linked list.
4. Given a sorted linked list, remove all the duplicates.
5. Find the Nth node from the end of the linked list. 
6. Given a sorted (ascending) linked list, manipulate it to become a sorted (descending) linked list.
*/
struct Node
{
    int value;
    Node *next; 
} *head, *tail, *curr;

Node *createNode(int value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}
void push(struct Node** head, int value) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    node->value = value; 
    node->next = *head; 
    *head = node; 
} 
void swap(struct Node *a, struct Node *b) 
{ 
    int temp = a->value; 
    a->value = b->value; 
    b->value = temp; 
} 
void bubbleSort(struct Node *head) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
    if (head == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        ptr1 = head; 
        while (ptr1->next != lptr) 
        { 
            if (ptr1->value > ptr1->next->value) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
Node* merge(Node* h1, Node* h2) 
{ 
    if (!h1) 
    {
    	return h2; 
	}
    if (!h2) 
    {
    	return h1;
	}
    if (h1->value < h2->value) 
	{ 
        h1->next = merge(h1->next, h2); 
        return h1; 
    } 
    else 
	{ 
        h2->next = merge(h1, h2->next); 
        return h2; 
    } 
} 
void printList(struct Node* head, int ctr)
{
    struct Node* ptr = head;
    int temp = 0;
    while (ptr)
    {
    	if(temp == ctr-1)
    	{
    		printf("%d", ptr->value);
        	ptr = ptr->next;
		} else
		{
			printf("%d -> ", ptr->value);
       		ptr = ptr->next;
		}
		temp++;
    }
}
int main()
{
	int n, m, temp;
	struct Node* head1 = NULL, *head2 = NULL;
	
	printf("Jumlah Data LL pertama : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("Data LL pertama ke-%d : ", i+1);
		scanf("%d", &temp);
		push(&head1, temp);
	}
	bubbleSort(head1);
	printf("Jumlah Data LL kedua : ");
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		printf("Data LL kedua ke-%d   : ", i+1);
		scanf("%d", &temp);
		push(&head2, temp);
	}
	bubbleSort(head2);
	Node* final = merge(head1, head2);
	printList(final, n+m);
	return 0;
}

