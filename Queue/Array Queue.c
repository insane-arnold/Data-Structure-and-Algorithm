#include<stdio.h>
#define MAX 10
int front = -1;
int end = -1;

void enquque(int a[]){
	int val;
	if (end == MAX - 1){
		printf("OVERFLOW");
	}
	else{
		printf("Enter the value: ");
		scanf("%d", &val);
		if (front == -1){
			front = 0;
		}
		end = end + 1;
		a[end] = val;
	}
}

void dequeue(int a[]){
	if (front == -1){
		printf("UNDERFLOW");
	}
	else if (front > end){
		printf("UNDERFLOW");
		front = -1;
		end = -1;
	}
	else{
		printf("%d is deleted!!", a[front]);
		front = front + 1;
	}
}

int main(){
	int A[MAX];
	int opt = 0;
	printf("\t\t********** ARRAY QUEUE **********\n");
	printf("Options:\n1. Enqueue\n2. Dequeue\n3. Exit");

	while(opt != 4){
		printf("\nEnter the option: ");
		scanf("%d", &opt);
		switch(opt){
			case 1: enquque(A);
					break;

			case 2: dequeue(A);
					break;

			case 3: printf("Program Terminated!!");
					break;

			default: printf("Enter the correct option!!");
					 break;	
		}
	}
	return 0;
}