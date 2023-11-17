#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
void asort(int arr[30],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("\n Ascending order: ");
	for(i=0;i<n;i++){
		printf("\t%d",arr[i]);
	}
	printf("\n");
}
void dsort(int arr[30],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(arr[j] < arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("\n Descending order: ");
	for(i=0;i<n;i++){
		printf("\t %d",arr[i]);
	}
	printf("\n");
}
void forkeg(){
	int i,j,n,arr[30];
	printf("\n enter no. of values in array: ");
	scanf("%d",&n);
	printf("\n enter array elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int pid = fork();
	if(pid == 0){
		printf("\n child process: \n child process id = %d\n",getppid());
		dsort(arr,n);
		printf("\n element sort using quick sort: ");
		for(i=0;i<n;i++){
			printf("\t%d",arr[i]);
		}
		printf("\b\n parent process id=%d\n",getpid());
		system("ps -x");
	}
	else{
		printf("\n parent process: \n parent process id=%d\n",getppid());
		asort(arr,n);
		printf("\n element sort using bubble sort: ");
		for(i=0;i<n;i++){
			printf("\t%d",arr[i]);
		}
		printf("\n");
	}
}
int main(){
	forkeg();
	return 0;
}
