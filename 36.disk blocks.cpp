#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct block
{
	char d;
	block *next;
};
typedef struct file
{
	block *first,*last;
};
file f;
void init()
{
	f.first=(block *)malloc(sizeof(block));
	f.first->next=NULL;
	f.last=(block*)malloc(sizeof(block));
	f.last->next=NULL;
}
void alloc()
{
	char s[100];
	printf("Enter the Data:");
	scanf("%s",&s);
	block *c=f.first;
	for(int i=0;i<strlen(s);i++)
	{
		if(i!=strlen(s)-1)
		{
			c->d=s[i];
			c->next=(block*)malloc(sizeof(block));
			c=c->next;
		}
		else
		{
			f.last->d=s[i];
			c->next=f.last;
		}
	}
	printf("Data Allocated in Block By Block Format!!\n");
}
int main()
{
	init();
	alloc();
	block *c=f.first;
	while(c!=NULL)
	{
		printf("%c ",c->d);
		c=c->next;
	}
}
