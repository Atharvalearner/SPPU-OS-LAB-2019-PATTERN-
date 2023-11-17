#include <stdio.h>
int main(){
	int i,j,k,x = 0,flag = 1,n = 5,m = 3;
	int alloc[5][3] = { { 0, 1, 0 },{ 2, 0, 0 }, { 3, 0, 2 }, { 2, 1, 1 }, { 0, 0, 2 } };
	int max[5][3] = { { 7, 5, 3 },{ 3, 2, 2 }, { 9, 0, 2 }, { 2, 2, 2 }, { 4, 3, 3 } };
	int avail[3] = {3,3,2};
	int need[n][m];
	int f[n],ans[n],ind = 0;
	for(k=0;k<n;k++){
		f[k] = 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(f[i] == 0){
				flag = 0;
				for(j=0;j<m;j++){
					if(need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}
				if(flag == 0){
					ans[ind++] = i;
					for(x=0;x<m;x++)
					avail[x] += alloc[i][x];
					f[i] = 1;
				}
			}
		}
	}
	flag = 1;
	for(i=0;i<n;i++){
		if(f[i] == 0){
			flag = 0;
			printf("sequence is not safe");
			break;
		}
	}
	if(flag == 1){
		printf("sequence is: ");
		for(i=0;i<n-1;i++)
		printf(" p%d ->",ans[i]);
		printf(" p%d\n ",ans[n-1]);
	}
	return 0;
}
