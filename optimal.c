#include<stdio.h>
#include<stdlib.h>

struct optimal
{
    int value;
    int k;
    //value (the page number) and a k (the index of its occurrence in the input stream).
};
int main()
{
    int pagefault=0,hit=0;
    struct optimal frame[3];
    for(int i=0;i<3;i++)
    {
        frame[i].value=-1;
        frame[i].k=-1;
    }
    int n;
    printf("Enter the size of the input Stream:");
    scanf("%d",&n);

    struct optimal a[n];
    for(int i =0;i<n;i++)
    {
        printf("Enter the input stream:");
        scanf("%d",&a[i].value);
        a[i].k=i;// This line assigns the value of i(the current loop index) to the k member of the i-th element of the A array
       
    }
    for(int i=0;i<n;i++)
    {
        int pagefound=0;
        for(int j=0;j<3;j++)
        {
             if(frame[j].value==a[i].value)
            {
                hit++;
                pagefound=1;
                break;
            }
        }
        if(pagefound==0)  //This condition checks whether a page fault occurred
        {
            pagefault++;
            //These variables are used to keep track of which frame should be replaced and which frame has the maximum distance to its next occurrence in the input stream
            int index=-1;
            int maxdist=-1;
            for(int j=0;j<3;j++)
            {
                int nextIndex=-1;  //basically nextpage
                for(int m=i+1;m<n;m++)//for iterating inputStream 
                {
                    if(frame[j].value==a[m].value)//the condition to check next occurance of number in Input stream from Frame
                    {
                        nextIndex=m; //storing the value of next occuring index of number 
                        break;
                    }
                }
                if(nextIndex==-1)//if particulat element is not repeating in input array 
                {
                    index=j; //copying index of that number and breaking outer loop
                    break;
                }
                if(nextIndex>maxdist)
                {
                    maxdist=nextIndex;
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
    printf("Total PageFaults: %d\n", pagefault);
    printf("Total Hits: %d\n", hit);

}
/*Output:
Enter the size of InputStream:20
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


The pages are:
Value   K
7       17
0       10
1       13

Total pagefault are:9
*/


