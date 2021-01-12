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
int search(struct Node* head, int ctr, int x) 
{ 
    struct Node* current = head;
    int temp = 0;
    while(current != NULL) 
    { 
        if(temp == ctr-x)
        {
            return current->value;
        } 
        current = current->next; 
        temp++;
    } 
    return 0;
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
	int n, temp, ctr = 0;
	printf("Jumlah Data : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("Data ke-%d : ", i+1);
		scanf("%d", &temp);
		pushHead(temp);
		ctr++;
	}
	int loc;
	printf("Lokasi Data yang dicari : ");
	scanf("%d", &loc);
	puts("");
	printlinkedlist();
	printf("\nValue ke %d adalah %d", loc, search(head, ctr, loc));
	return 0;
}

