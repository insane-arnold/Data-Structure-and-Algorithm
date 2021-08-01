#include<stdio.h>
#define MAX 10
int top = -1;

void push(int a[]){
	int val;
	if (top == (MAX - 1)){
		printf("STACK OVERFLOW");
	}
	else{
		printf("Enter the value: ");
		scanf("%d", &val);
		top = top + 1;
		a[top] = val;
	}
}

void pop(int a[]){
	if (top == -1){
		printf("STACK UNDERFLOW");
	}
	else{
		printf("%d is popped off!!", a[top]);
		top = top-1;
	}
}

void peep(int a[]){
	if(top == -1){
		printf("STACK UNDERFLOW");
	}
	else{
		printf("Top element : %d", a[top]);
	}
}

int main(){
	int A[MAX];
	int opt = 0;
	printf("\t\t********** ARRAY STACK **********\n");
	printf("Options:\n1. Push\n2. Pop\n3. Peep\n4. Exit");

	while(opt != 4){
		printf("\nEnter the option: ");
		scanf("%d", &opt);
		switch(opt){
			case 1: push(A);
					break;

			case 2: pop(A);
					break;

			case 3: peep(A);
					break;

			case 4: printf("Program Terminated!!");
					break;

			default: printf("Enter the correct option!!");
					 break;	
		}
	}
	return 0;
}