#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

struct node *push(struct node *h){
	int val;
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value: ");
	scanf("%d", &val);
	new_node->val = val;

	if (h == NULL){
		new_node->next = NULL;
		h = new_node;
	}
	else{
		new_node->next = h;
		h = new_node;
	}
	return h;
}

struct node *pop(struct node *h){
	struct node *p;
	p = h;
	if (h == NULL){
		printf("STACK UNDERFLOW");
	}
	else{
		printf("%d is popped off!!", p->val);
		h = p->next;
		free(p);
	}
	return h;
}

void peep(struct node *h){
	if(h == NULL){
		printf("STACK UNDERFLOW");
	}
	else{
		printf("%d", h->val);
	}
}

int main(){
	struct node *head = NULL;
	int opt = 0;
	printf("\t\t********** ARRAY STACK **********\n");
	printf("Options:\n1. Push\n2. Pop\n3. Peep\n4. Exit");

	while(opt != 4){
		printf("\nEnter the option: ");
		scanf("%d", &opt);
		switch(opt){
			case 1: head = push(head);
					break;

			case 2: head = pop(head);
					break;

			case 3: peep(head);
					break;

			case 4: printf("Program Terminated!!");
					break;

			default: printf("Enter the correct option!!");
					 break;	
		}
	}
	return 0;
}