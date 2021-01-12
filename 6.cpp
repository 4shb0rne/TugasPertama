#include <stdio.h>
#include <stdlib.h>
struct Node{
    int value;
    Node *next; 

} *head, *tail, *curr;

Node *createNode(int value){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}
void pushTail(int value) {
  Node *temp = createNode(value);
  if(!head) 
  { 
    head = tail = temp;
  } else 
  { 
    tail->next = temp; 
    tail = temp; 
  }
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
            if (ptr1->value < ptr1->next->value) 
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
void printlinkedlist()
{
    if(!head)
    {
        return;
    } else
    {
        curr = head;
        while(curr)
        {
            printf("%d ", curr->value);
            curr = curr->next;
        }
    }   
}
int main()
{
	int n, temp;
	printf("Jumlah Data : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("Data ke-%d : ", i+1);
		scanf("%d", &temp);
		pushTail(temp);
	}
	printf("Before: \n");
	printlinkedlist();
	bubbleSort(head);
	printf("After :\n");
	printlinkedlist();
	
	return 0;
}

