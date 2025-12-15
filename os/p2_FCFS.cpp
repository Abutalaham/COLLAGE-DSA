#include<stdio.h>
int main(){
	int n;
	int pid[15];
	int bt[15];
	printf("ENTER THE NUMBER OF PROCESSORS: ");
	scanf("%d",&n);
	printf("\nENTER THE PROCESS ID FOR ALL PROCESSES:");
	for(int i=0;i<n;i++){
		scanf("%d",&pid[i]);
	}
	printf("\nENTER THE BURST TIME OF ALL PROCESSERS:");
	for(int i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	int wt[15];
	wt[0]=0;
	for (int i=1;i<n;i++){
		wt[i]=bt[i-1]+wt[i-1];
	}
	printf("\nprocess id\tburst time\twaiting time\tTurnaround time\n");
	int twt=0,tat=0;
	int ta[15];
	for (int i=0;i<n;i++){
		ta[i]=bt[i]+wt[i];
		printf("%d\t\t%d\t\t%d\t\t%d\n",pid[i],bt[i],wt[i],ta[i]);
		twt = twt+wt[i];
        tat = tat+ta[i];
	}
	printf("\nAverage Waiting Time = %.2f",(float)twt / n);
    printf("\nAverage Turnaround Time = %.2f\n",(float)tat / n);
    return 0;
}
