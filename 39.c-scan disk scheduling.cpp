#include <stdio.h>
#include <math.h>
typedef struct req
{
	int data,status;
};
req r[100];
int main()
{
	int cylinders=0,n,head,j,total;
	printf("Enter the Number of Cylinders:");
	scanf("%d",&total);
	printf("Enter the Number of Disk Requests:");
	scanf("%d",&n);
	printf("Enter the disk requests:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&r[i].data);
		r[i].status=0;
	}
	printf("Enter Head Position:");
	scanf("%d",&head);
	r[n].data=0;r[n].status=1;
	r[n+1].data=total-1;r[n+1].status=1;
	r[n+2].data=head;r[n+2].status=1;
	n+=3;
	for(int i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(r[i].data>r[j].data)
			{
				req s=r[i];
				r[i]=r[j];
				r[j]=s;
			}
		}
	}
	for(j=0;j<n;j++)
	{
		if(r[j].data==head)
		{
			break;
		}
	}
	for(int i=j+1;i<n;i++)
	{
		cylinders+=abs(head-r[i].data);
		if(r[i].status==0)
		{
			printf("Disk Request-%d Accessed\n",r[i].data);
			r[i].status=1;
		}
		head=r[i].data;
	}
	cylinders+=r[n-1].data;
	head=r[0].data;
	for(int i=0;i<j;i++)
	{
		if(r[i].status==0)
		{
			cylinders+=abs(head-r[i].data);
			printf("Disk Request-%d Accessed\n",r[i].data);
			r[i].status=1;
			head=r[i].data;
		}
	}
	printf("Total Number of Head Movements:%d",cylinders);
}
