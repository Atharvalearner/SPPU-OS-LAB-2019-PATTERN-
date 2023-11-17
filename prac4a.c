#include <stdio.h>
#include <stdlib.h>
int mutex = 1,full = 0,empty = 10,x = 0;
void producer(){
	--mutex;
	++full;
	--empty;
	x++;
	printf("\n producer produce item %d: ",x);
	++mutex;
}
void consumer(){
	--mutex;
	--full;
	++empty;
	printf("\n consumer consume item %d: ",x);
	x--;
	++mutex;
}
int main(){
	int n,i;
	printf("\n 1.producer \n 2.consumer \n 3.exit");
	for(i=1;i>0;i++){
		printf("\n enter your choice: ");
		scanf(" %d",&n);
		switch(n){
			case 1:
				if((mutex == 1) && (empty != 0))
					producer();
				else
					printf("\n buffer is full");
				break;
			case 2:
				if((mutex == 1) && (full != 0))
					consumer();
				else
					printf("\n buffer is empty");
				break;
			case 3:
				exit(0);
				break;
		}
	}
} 
