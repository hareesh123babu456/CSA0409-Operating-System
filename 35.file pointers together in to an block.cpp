#include <stdio.h>
#include <string.h>
typedef struct block
{
	char d;
};
typedef struct indexblock
{
	block blocks[100];
	int numblock;
};
indexblock b;
void simulate()
{
	for(int i=0;i<b.numblock;i++)
	{
		printf("Block-%d : %c\n",i+1,b.blocks[i].d);
	}
}
int main()
{
	char t[100];
	for(int i=0;i<100;i++)
	{
		b.blocks[i].d=-1;
	}
	printf("Enter the Number of Blocks:");
	scanf("%d",&b.numblock);
	printf("Enter the Data into the file:");
	scanf("%s",&t);
	for(int i=0;i<strlen(t);i++)
	{
		b.blocks[i].d=t[i];
	}
	simulate();
}
