#include<stdio.h>
#include<stdlib.h>
struct LRU
{
	int value;
	int k;
};
int main()
{
	int n;
	int pagefault=0,hit=0;
	struct LRU frame[3];
	
	
	printf("Enter the size of input:");
	scanf("%d",&n);
	
	struct LRU a[n];
	
	for(int i=0;i<n;i++)
	{
		printf("Enter the input Stream:");
		scanf("%d",&a[i].value);
		a[i].k=0;
	}
	for(int j=0;j<3;j++)
	{
		frame[j].value=-1;
		frame[j].k=-1;	
	}
	//Inserting frame
	for(int i=0;i<n;i++)
	{
		int pagefound=0;
		for(int j=0;j<3;j++)
		{
			if(a[i].value==frame[j].value)
			{
				hit++;
				frame[j].k=i;
				pagefound=1;
				break;
			}
		}
		if(pagefound==0)
		{
			pagefault++;
			int index=0;
			for(int j=1;j<3;j++)
			{
				if(frame[j].k<frame[index].k)
				{
					index=j;
				}
			}
			frame[index].value=a[i].value;
			frame[index].k=i; 
		}	
	}
	 //printing
    printf("The InputStream is:\n");
    printf("Value\tK\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i].value);
        printf("\t");
        printf("%d",a[i].k);
        printf("\n");
    }
    printf("\n");
    printf("Value\tK\n");
    for(int i=0;i<3;i++)
	{		
		printf("%d\t",frame[i].value);
		printf("%d\n",frame[i].k);	
	}
	printf("\n");
	printf("Total pagefaults are:%d",pagefault);
	return 0;
	
}
/*Output:
Enter the Size of InputStream:20
Enter the pages:7
Enter the pages:0
Enter the pages:1
Enter the pages:2
Enter the pages:0
Enter the pages:3
Enter the pages:0
Enter the pages:4
Enter the pages:2
Enter the pages:3
Enter the pages:0
Enter the pages:3
Enter the pages:2
Enter the pages:1
Enter the pages:2
Enter the pages:0
Enter the pages:1
Enter the pages:7
Enter the pages:0
Enter the pages:1

The pages are:
Value   K
7       0
0       0
1       0
2       0
0       0
3       0
0       0
4       0
2       0
3       0
0       0
3       0
2       0
1       0
2       0
0       0
1       0
7       0
0       0
1       0


Value   K
1       19
0       18
7       17

Total pagefaults are:12
*/