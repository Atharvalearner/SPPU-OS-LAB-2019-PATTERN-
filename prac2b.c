#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char *argv[]){
	int val[10],ele;
	int n,i,j;
	char *cval[10];
	pid_t pid;
	char *newe[]={NULL};
	printf("Enter size of array: ");
	scanf("%d",&n);
	printf("\nEnter Array elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&val[i]);
	}
	printf("\nEntered Array is: ");
	for(i=0;i<n;i++){
		printf("\t%d",val[i]);
	}
	for(i=1;i<n;i++){
		for(j=0;j<n-1;j++){
			if(val[j]>val[j+1]){
				int temp =val[j];
				val[j]=val[j+1];
				val[j+1]=temp;
			}
		}
	}
	printf("\nSorted Array is: ");
	for(i=0;i<n;i++){
		printf("\t%d",val[i]);
	}
	printf("\nEnter element of search: ");
	scanf("%d",&ele);
	int found = 0;
	for(i=0;i<n;i++){
		if(val[i] == ele){
			found = 1;
			break;
		}
	}
	if(found){
		printf("\nelement %d found in sorted array.\n ",ele);
	}else{
		printf("\nelement %d is not found in sorted array.\n",ele);
	}
	return 0;
}
