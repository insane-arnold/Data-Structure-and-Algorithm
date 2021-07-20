# include<stdio.h>
# include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

struct node *create(struct node *h){
	int val;
	struct node *new_node;
	printf("Enter -1 to finish!!\n");
	printf("Enter the value: ");
	scanf("%d", &val);
	while(val!=-1){
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->val = val;
		if (h == NULL){
			new_node->next = NULL;
			h = new_node;
		}
		else{
			new_node->next = h;
			h = new_node;
		}
		printf("Enter the value: ");
		scanf("%d", &val);
	}
	return h;
}

void print(struct node *h){
	struct node *ptr;
	ptr = h;
	if (ptr == NULL){
		printf("Link List is Empty!!");
		return;
	}
	else{
		while(ptr != NULL){
			printf("%d ", ptr->val);
			ptr = ptr->next;
		}
	}
}

struct node *insert_begin(struct node *h){
	int val;
	struct node *new_node;
	if (h == NULL){
		printf("Link List is Empty!!");
		return h;
	}
	else{
		printf("Enter the value: ");
		scanf("%d", &val);
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->val = val;
		new_node->next = h;
		h = new_node;
	}
	return h;
}

void insert_end(struct node *h){
	int val;
	struct node *ptr, *new_node;
	ptr = h;
	if (h == NULL){
		printf("Link List is Empty!!");
		return;
	}
	else{
		printf("Enter the value: ");
		scanf("%d", &val);
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->val = val;
		new_node->next = NULL;
		ptr->next = new_node;
	}
}

void insert_before(struct node *h){
	int val, data;
	struct node *new_node, *ptr, *prevptr;
	ptr = h;
	if(h == NULL){
		printf("Link List is Empty!!");
		return;
	}
	else{
		printf("Enter the given data: ");
		scanf("%d", &data);
		while(ptr->val != data){
			if (ptr->next == NULL){
				printf("Data Not Found!!");
				return;
			}
			prevptr = ptr;
			ptr = ptr->next;
		}
		new_node = (struct node*)malloc(sizeof(struct node));
		printf("Enter the value: ");
		scanf("%d", &val);
		new_node->val = val;
		new_node->next = ptr;
		prevptr->next = new_node;
	}
}

void insert_after(struct node *h){
	int val, data;
	struct node *new_node, *ptr;
	ptr = h;
	if(h == NULL){
		printf("Link List is Empty!!");
		return;
	}
	else{
		printf("Enter the given data: ");
		scanf("%d", &data);
		while(ptr->val != data){
			if (ptr->next == NULL){
				printf("Data Not Found!!");
				return;
			}
			ptr = ptr->next;
		}
		new_node = (struct node*)malloc(sizeof(struct node));
		printf("Enter the value: ");
		scanf("%d", &val);
		new_node->val = val;
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
}

void search(struct node *h){
	int data;
	struct node *ptr;
	ptr = h;
	printf("Enter the search number: ");
	scanf("%d", &data);
	while(ptr != NULL){
		if (ptr->val == data){
			printf("Found!!");
			return;
		}
		ptr = ptr->next;
	}
	printf("Not Found");
}

struct node *delete_beg(struct node *h){
	struct node *ptr;
	ptr = h;
	if (h == NULL){
		printf("Link List is Empty");
		return h;
	}
	h = ptr->next;
	free(ptr);
	printf("First Node Deleted!!");
	return h;
}

struct node *delete_end(struct node *h){
	struct node *ptr, *prevptr;
	int count = 0;
	ptr = h;
	if (h == NULL){
		printf("Link List is Empty");
		return h;
	}
	while(ptr->next != NULL){
		count = 1;
		prevptr = ptr;
		ptr = ptr->next;
	};
	if (count == 0){
		printf("Last Node is Deleted!!");
		free(ptr);
		h = NULL;
		return h;
	}
	prevptr->next = NULL;
	printf("Last Node is Deleted!!");
	free(ptr);
	return h;
}

struct node *delete_data(struct node *h){
	int data, count=0;
	struct node *ptr,*prevptr;
	ptr = h;
	if(h == NULL){
		printf("Link List is Empty!!");
		return h;
	}
	printf("Enter the deleting data: ");
	scanf("%d", &data);
	while(ptr->val != data){
		count = 1;
		if (ptr->next == NULL){
				printf("Data Not Found!!");
				return h;
			}
			prevptr = ptr;
			ptr = ptr->next;
	}
	if (count == 0){
		printf("Data is Deleted!!");
		free(ptr);
		h = NULL;
		return h;
	}
	prevptr->next = ptr->next;
	free(ptr);
	printf("Data is Deleted");
	return h;
}

int main(){
	int opt=0;
	struct node *head = NULL;

	printf("**********SINGLE LINKED LIST**********\nOptions:");
	printf("\n1.Create\n2.Print\n3.Insert at Begining\n4.Insert at End\n5.Insert before\n6.Insert After\n7.Search\n\
8.Delete Begining\n9.Delete End\n10.Delete Middle\n11.Exit\n");

	while(opt!=11){

		printf("\nEnter the option: ");
		scanf("%d", &opt);

		switch(opt){
			case 1: head = create(head);
					break;

			case 2: print(head);
					break; 

			case 3: head = insert_begin(head);
					break;

			case 4: insert_end(head);
					break;

			case 5: insert_before(head);
					break;

			case 6: insert_after(head);
					break;

			case 7: search(head);
					break;

			case 8: head = delete_beg(head);
					break;

			case 9: head = delete_end(head);
					break;

			case 10: head = delete_data(head);
					 break;

			case 11: printf("Program Terminated!!");
					break;

			default: printf("Enter valid option!!\n");
					 break;
		}
	}
	return 0;
}