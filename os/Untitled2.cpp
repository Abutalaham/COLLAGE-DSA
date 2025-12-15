#include<stdio.h>
int main(){
	int pid[15];
	int bt[15];
	int wt[15];
	int n;
	printf("ENTER NUMBER OF PROCESSES: ");
	scanf("%d",&n);
	printf("ENTER ALL PROCESSESS PID : ");
	for(int i=0;i<n;i++){
		scanf("%d",&pid[i]);
	}
	printf("ENTER THE BURST TIME FOR ALL PROCESSESS:");
	for(int i = 0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	int i,j;
	int temp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(bt[i]>bt[j]){
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				temp=pid[i];
				pid[i]=pid[j];
				pid[j]=temp;
			}
		}
	}
	wt[0]=0;
	for(int i = 1;i<n;i++){
		wt[i]=bt[i-1]+wt[i-1];
	}
	int TWT=0,TAT=0;
	int ta[15];
	printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTARNAROUND TIME\n");
	for(int i = 0;i<n;i++){
		ta[i]=bt[i]+wt[i];
	}
	for(int i=0;i<n;i++){
		printf("%d\t\t%d\t\t%d\t\t%d\n",pid[i],bt[i],wt[i],ta[i]);
		TWT = TWT+wt[i];
		TAT = TAT+ta[i];
	}
	printf("average waiting time = %.2f",(float)TWT/n);
	printf("average turnaround time = %.2f",(float)TAT/n);
	return 0;
}
