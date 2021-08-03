# include<stdio.h>
# include<stdlib.h>

struct node{
	struct node *prev;
	int val;
	struct node *next;
};

struct node *enqueue(struct node *h, struct node **t){
	int val;
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("Enter the value: ");
	scanf("%d", &val);
	new_node->val = val;
	if (h == NULL){
		new_node->next = NULL;
		h = new_node;
		*t = new_node;
		new_node->prev = NULL;
	}
	else{
		new_node->next = h;
		new_node->prev = NULL;
		h->prev = new_node;
		h = new_node;
	}
	return h;
}

struct node *dequeue(struct node **h, struct node *t){
	struct node *ptr, *prevptr;
	ptr = *h;
	if (*h == NULL){
		printf("UNDERFLOW");
		return t;
	}
	if ((*h)->next == NULL){
		printf("%d is deleted!!", (*h)->val);
		*h = NULL;
		t = NULL;
		free(ptr);
		return t;
	}
	
	prevptr = t->prev;
	prevptr->next = NULL;
	printf("%d is deleted!!", t->val);
	free(t);
	t = prevptr;
	return t;
}

void print(struct node *h){
	struct node *ptr;
	ptr = h;
	if (ptr == NULL){
		printf("UNDERFLOW");
		return;
	}
	else{
		while(ptr != NULL){
			printf("%d ", ptr->val);
			ptr = ptr->next;
		}
	}
}

int main(){
	int opt=0;
	struct node *head = NULL, *tail = NULL;

	printf("********** LINKED LIST QUEUE **********\nOptions:");
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");

	while(opt!=11){

		printf("\nEnter the option: ");
		scanf("%d", &opt);

		switch(opt){
			case 1: head = enqueue(head, &tail);
					break;

			case 2: tail = dequeue(&head, tail);
					break;

			case 3: print(head);
					break;

			case 4: printf("Program Terminated!!");
					break;

			default: printf("Enter valid option!!\n");
					 break;
		}
	}
	return 0;
}