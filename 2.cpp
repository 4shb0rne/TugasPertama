#include <stdio.h>
#include <stdlib.h>
struct Node{
    int value;
    Node *next; // pointer for next node

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
int max(struct Node* head) 
{ 
    int max = 0; 
    while(head != NULL) 
	{ 
        if (max < head->value) 
        {
        	max = head->value;
		}
        head = head->next; 
    } 
    return max; 
} 
int min(struct Node* head) 
{ 
    int min = 1000000;  
    while(head != NULL) 
	{
        if(min > head->value) 
        {
        	min = head->value;
		}
        head = head->next; 
    } 
    return min; 
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
	printf("Difference : %d-%d = %d", max(head), min(head), max(head)-min(head));
	return 0;
}

