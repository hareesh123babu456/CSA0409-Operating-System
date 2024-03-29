#include <stdio.h>
#include <math.h>
int main()
{
	int dr[20],head,cylinders=0,n;
	printf("Enter the Number of Disk Requests:");
	scanf("%d",&n);
	printf("Enter the Disk Requests:");
	for(int i=0;i<n;i++) scanf("%d",&dr[i]);
	printf("Enter the Current Head Position:");
	scanf("%d",&head);
	for(int i=0;i<n;i++)
	{
		cylinders+=abs(head-dr[i]);
		head=dr[i];
	}
	printf("Number of Head Movements :%d cylinders",cylinders);
}
