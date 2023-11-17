#include <stdio.h>

int main(){
	int arrival_time[30],burst_time[30],temp[30];
	int i,j,n,smallest,count = 0;
	double waiting_time,turnaround_time,end;
	float avg_wait_time,avg_turn_time;
	printf("enter the no. of processes: ");
	scanf("%d",&n);
	printf("\nenter details of %d processes: ",n);
	for(i=0;i<n;i++){
		printf("\nenter arrival time: ");
		scanf("%d",&arrival_time[i]);
		printf("enter burst time: ");
		scanf("%d",&burst_time[i]);
		temp[i] = burst_time[i];
	}
	burst_time[9] = 9999;
	for(j = 0;count != n;j++){
		smallest = 9;
		for(i=0;i<n;i++){
			if(arrival_time[i] <= j && burst_time[i] < burst_time[smallest] && burst_time[i] > 0){
				smallest = i;
			}
		}
		burst_time[smallest]--;
		if(burst_time[smallest] == 0){
			count++;
			end = j + 1;
			waiting_time = waiting_time + end - arrival_time[smallest] - temp[smallest];
			turnaround_time = turnaround_time + end - arrival_time[smallest];
		}
	}
	avg_wait_time = waiting_time / n;
	avg_turn_time = turnaround_time / n;
	printf("\naverage waiting time is: %lf",avg_wait_time);
	printf("\naverage turnaround time is: %lf",avg_turn_time);
	return 0;
}
