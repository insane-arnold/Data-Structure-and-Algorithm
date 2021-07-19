#include<stdio.h>

void print(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}

void insert(int a[], int *p){
	int in, ele, i;
	printf("Enter the index: ");
	scanf("%d", &in);
	printf("Enter the element: ");
	scanf("%d", &ele);
	for(i = *p;i>=in;i--){
		a[i] = a[i-1];
	}
	a[in] = ele;
	*p = *p+1;
}

void search(int a[], int n){
	int num, i,flag = 0;
	printf("Enter the number for searching: ");
	scanf("%d", &num);
	for(i=0;i<n;i++){
		if (a[i] == num){
			flag = 1;
			break;
		}
	}
	if (flag == 1){
		printf("Found!! at index %d!!", i);
	}
	else{
		printf("Not Found!!");
	}
}

void delete(int a[], int *p){
	int in, i;
	printf("Enter the index to delete: ");
	scanf("%d", &in);
	for(i=in;i<*p-1;i++){
		a[i] = a[i+1];
	}
	*p = *p-1;
}

void update(int a[]){
	int in, num;
	printf("Enter the index to be updated: ");
	scanf("%d", &in);
	printf("Enter the value to be updated: ");
	scanf("%d", &num);
	a[in] = num;
}

int main(){
	int i, A[100],n,opt=0;

	printf("\t\t**********ARRAY**********\nOptions: ");
	printf("\n1.Print\n2.Insert\n3.Delete\n4.Search\n5.Update\n6.Exit");

	printf("\nEnter the size of array: ");
	scanf("%d", &n);
	printf("Enter the elements: ");

	for(i=0;i<n;i++){
		scanf("%d", &A[i]);
	}

	while(opt != 6){
		printf("\nEnter the option: ");
		scanf("%d", &opt);

		switch(opt)
		{
			case 1: print(A, n);
					break;

			case 2: insert(A, &n);
					break;

			case 3: search(A, n);
					break;

			case 4: delete(A, &n);
					break;

			case 5: update(A);
					break;

			case 6: printf("Program Terminated !!");
					break;

			default: printf("Enter the correct option!!");
					 break;

		}
	}

}