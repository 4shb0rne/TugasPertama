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
int findmid(struct Node* head, int x) 
{ 
    struct Node* current = head;
    int temp = 0;
    while(current != NULL) 
    { 
        if(temp == x)
        {
            return current->value;
        } 
        current = current->next; 
        temp++;
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
	int n, temp;
	printf("Jumlah Data : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("Data ke-%d : ", i+1);
		scanf("%d", &temp);
		pushTail(temp);
	}
	// 1 2 3 4 5 6
	// 1 2 3 4 5
	printList(head, n);
	if(n % 2 != 0)
	{
		printf("\nMiddle value : %d", findmid(head, (n/2)));
	} else
	{
		printf("\nMiddle value : %d atau %d", findmid(head, (n/2)-1), findmid(head, (n/2)));
	}
	return 0;
}

