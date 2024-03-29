#include <stdio.h>
typedef struct frame
{
	int page,o,op;
};
frame frames[10];
void init(int n)
{
	for(int i=0;i<n;i++)
	{
		frames[i].o=0;
		frames[i].op=0;
		frames[i].page=-1;
	}
}
int main()
{
	int l,n,a[100],j,pg=0;
	printf("Enter the Number of Frames:");
	scanf("%d",&l);
	init(l);
	printf("Enter the Number of Page References:");
	scanf("%d",&n);
	printf("Enter the Page References:");
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		int f=0,c=0;
		for(j=0;j<l;j++)
		{
			if(frames[j].page==a[i])
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
			for(j=0;j<l;j++)
			{
				if(frames[j].page!=-1)
				{
					frames[j].o+=1;
				}
			}
		}
		else
		{
			pg++;
			int emp=0,in=0;
			for(j=0;j<l;j++)
			{
				if(frames[j].page==-1)
				{
					emp=1;
					break;
				}
			}
			if(emp==1)
			{
				frames[j].o=0;
				frames[j].page=a[i];
				for(j=0;j<l;j++)
				{
					frames[j].o+=1;
				}
			}
			else
			{
				for(j=0;j<l;j++)
				{
					c=0,f=0;
					for(int k=i;k<n;k++)
					{   c++;
						if(frames[j].page==a[k])
						{
							f=1;
							break;
						}
					}
					if(f==1)
					{
						frames[j].op+=c;
					}
				}
				f=0;
				for(j=0;j<l;j++)
				{
					if(frames[j].op==0)
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					int max=0,in=0;
					for(j=0;j<l;j++)
					{
						if(frames[j].op>max)
						{
							max=frames[j].op;
							in=j;
						}
					}
					frames[in].page=a[i];
					frames[in].o=0;
				}
				else
				{
					int max=0,in=0;
					for(j=0;j<l;j++)
					{
						if(frames[j].o>max && frames[j].op==0)
						{
							max=frames[j].o;
							in=j;
						}
					}
					frames[in].page=a[i];
					frames[in].o=0;
				}
				for(j=0;j<l;j++)
				{
					frames[j].o+=1;
					frames[j].op=0;
				}
			}
		}
		printf("Frames after Reference-%d",i);
		for(j=0;j<l;j++)
		{
			printf("%d ",frames[j].page);
		}
		printf("\n");
	}
	printf("Page_Faults:%d",pg);
}
