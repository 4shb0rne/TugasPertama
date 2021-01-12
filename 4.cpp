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
void pushHead(int value){
    Node *temp = createNode(value);
    if(!head) 
    {
        head = tail = temp;
    } else
    {
        temp->next = head;
        head = temp;
    }
}
void removeDuplicates(struct Node* head) 
{ 
    struct Node* current = head; 
    struct Node* next_next;  

    if (current == NULL)  
    {
        return; 
    } 
    while (current->next != NULL)  
    { 
       if (current->value == current->next->value)  
       {              
           next_next = current->next->next; 
           free(current->next); 
           current->next = next_next;   
       } 
       else 
       { 
          current = current->next;  
       } 
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
		pushHead(temp);
	}
	bubbleSort(head);
	printf("\nBefore :\n");
	printlinkedlist();
	printf("\nAfter:\n");
	removeDuplicates(head);
	printlinkedlist();
	return 0;
}

