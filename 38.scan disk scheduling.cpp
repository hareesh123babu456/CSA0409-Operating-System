#include <stdio.h>
#include <math.h>
typedef struct req
{
	int data,status;
};
req r[100];
int main()
{
	int total,n,head,j,cylinders=0;
	printf("Enter the Total Number of Cylinders:");
	scanf("%d",&total);
	printf("Enter the total number of disk requests:");
	scanf("%d",&n);
	printf("Enter the Head:");
	scanf("%d",&head);
	printf("Enter the Disk requests:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&r[i]);
		r[i].status=0;
	}
	r[n].data=total-1;r[n].status=1;
	r[n+1].data=0;r[n+1].status=1;
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

	printf("\n");
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
	for(int i=n-1;i>0;i--)
	{
		if(r[i].status==0)
		{
			cylinders+=abs(head-r[i].data);
			printf("Disk Request-%d Satisfied\n",r[i].data);
			r[i].status=1;
			head=r[i].data;
		}
	}
	printf("No.Of Head Movements=%d",cylinders);
}
