#include<stdio.h>
#include<stdlib.h>

struct process
{
    int value;
    int flag;
};
void sort(struct process a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j].value>a[j+1].value)
            {
                int temp=a[j].value;
                a[j].value=a[j+1].value;
                a[j+1].value=temp;

            }
        }
    }
}
void logic(struct process a[],int n,int head)
{
    int seektime=0;
    int position=head;
    printf("Seek Sequence is:%d",position);
    for(int i=0;i<n;i++)   //iterates through the entire request queue
    {
        int min_seek_time=9999;
        int index=-1;   //This variable is used to store the index of the request that has the minimum seek time
        for(int j=0;j<n;j++)
        {
            if(a[j].flag==0)  //checking if Process is already executed 
            {
                int seek=abs(position-a[j].value);
                if(seek<min_seek_time)
                {
                    min_seek_time=seek;
                    index=j;   //It updates Index with the index j,
                }
            }
        }
        if(index!=-1) //t means that a request with the shortest seek time has been found
        {
            a[index].flag=1;
            position=a[index].value;
            seektime=seektime+min_seek_time;
            printf("->%d",position);

        }
    }
    printf("\nTotal Seek Time is::%d",seektime);
}
int main()
{
    int n;
    printf("Enter the size of the queue:");
    scanf("%d",&n);

    struct process a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the Numbers:");
        scanf("%d",&a[i].value);
        a[i].flag=0;
    }

    int head;
    printf("Enter the head position:");
   scanf("%d",&head);
    //printing
    printf("The numbers are:\n");
    printf("Value\tFlag\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i].value);
        printf("\t");
        printf("%d",a[i].flag);
        printf("\n");
    }
    
    printf("After Sorting:\n");
    sort(a,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i].value);
    }
    printf("\n");

    logic(a,n,head);
    return 0;
}

/*Output:
Enter the Size of Queue:7
Enter the Numbers:82
Enter the Numbers:170
Enter the Numbers:43
Enter the Numbers:140
Enter the Numbers:24
Enter the Numbers:16
Enter the Numbers:190

Enter the head position:50
Value   Flag
82      0
170     0
43      0
140     0
24      0
16      0
190     0

After Sorting:
Value   Flag
16      0
24      0
43      0
82      0
140     0
170     0
190     0

The Seek Sequence is:50->43->24->16->82->140->170->190
Total Seektime is:208*/
