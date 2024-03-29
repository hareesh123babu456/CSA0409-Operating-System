#include <stdio.h>
int main()
{
	int p[10],bt[10],n,wt[10],tat[10],twt=0,ttat=0;
	printf("Enter the Number of Processes:");
	scanf("%d",&n);
	printf("Enter the Process Details:\n");
	for(int i=0;i<n;i++)
	{
		p[i]=i+1;
		printf("Enter the Burst_Time of Process %d:",i+1);
		scanf("%d",&bt[i]);
	}
	for(int i=0;i<n;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(bt[j]<bt[min]) min=j;
		}
		int t=bt[i];
		bt[i]=bt[min];
		bt[min]=t;
		t=p[min];
		p[min]=p[i];
		p[i]=t;
	}
	wt[0]=0;
	tat[0]=bt[0];
	ttat+=tat[0];
	for(int i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		twt+=wt[i];
		tat[i]=wt[i]+bt[i];
		ttat+=tat[i];
	}
		printf("Process_Id  Burst_Time  Waiting_Time  Turn_Around_Time\n");
	for(int i=0;i<n;i++)
	{
		printf("%d            %d            %d            %d\n",p[i],bt[i],wt[i],tat[i]);
	}
	float awt=(float)twt/n;
	float atat=(float)ttat/n;
	printf("Average Waiting Time:%.3f",awt);
	printf("\nAverage Turn Around Time:%.2f",atat);
	
}
