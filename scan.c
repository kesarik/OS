#include<stdio.h>
#include<stdlib.h>
struct process
{
    int values;
    int flag;
};
void sort(struct process a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++) 
        {
            if (a[j].values > a[j + 1].values) 
            {
                int temp = a[j].values;
                a[j].values = a[j + 1].values;
                a[j + 1].values = temp;
            }
        }
    }
}
void logic(struct process a[],int n,int head,int direction)
{
    int seektime = 0;
    int position = head;
    printf("Seek Sequence is: %d", position);
    int shortest_distance=99999;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        int dist=abs(position-a[i].values);
        if((dist<shortest_distance) && (a[i].flag==0))
        {
            shortest_distance=dist;
            index=i;
        }
    }
    while(index!=-1)
    {
        a[index].flag = 1;
        seektime = seektime + shortest_distance;
        position = a[index].values;
        printf("-> %d", position);
        shortest_distance = 99999;
        index = -1;
       
        for(int i=0;i<n;i++)
        {
            int dist=abs(position-a[i].values);
            if(a[i].flag==0)
            {
                if((dist<shortest_distance)&& (a[i].values>=position)&&(direction==1))
                {
                    shortest_distance=dist;
                    index=i;
                }
                else if((dist<shortest_distance)&& (a[i].values<=position)&&(direction==-1))
                {
                    shortest_distance=dist;
                    index=i;
                }
            }
        }
        if(index==-1)
        {
            direction=-direction;
            for(int i=0;i<n;i++)
            {
                int dist=abs(position-a[i].values);
                if((dist<shortest_distance) && (a[i].flag==0))
                {
                    shortest_distance=dist;
                    index=i;
                }
            }

        }
    }
    printf("\n Total Seek time is:%d",seektime);

}

int main()
{
    int n,head;
    printf("Enter the input size:");
    scanf("%d",&n);

    struct process a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the values:");
        scanf("%d",&a[i].values);
        a[i].flag=0;
    }
    printf("Enter the head value:");
    scanf("%d",&head);
    printf("\n");
    
    int direction;
    printf("Enter the Direction:\n1)Forward direction\n 2)backword Direction\n");
    scanf("%d",&direction);
      
    printf("After Sorting:\n");
    sort(a,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i].values);
    }
    printf("\n");

    printf("Printing input:\n");
    printf("Values\t Flag\n");
    for(int i=0;i<n;i++)
    {
            printf("%d\t%d\n",a[i].values,a[i].flag);
    }
    printf("\n"); 
    logic(a,n,head,direction);
    return 0;

}
/*Output:
Enter the Size of Queue:7
Enter the numbers:82
Enter the numbers:170
Enter the numbers:43
Enter the numbers:140
Enter the numbers:24
Enter the numbers:16
Enter the numbers:190

Enter the head Position:50

Value   Flag
82      0
170     0
43      0
140     0
24      0
16      0
190     0
After sorting:
Value   Flag
16      0
24      0
43      0
82      0
140     0
170     0
190     0
Enter the Direction:
1)Forward Direction
2)Backword Direction
1
The seek Sequence is:50->43->82->140->170->190->24->16
Total Seektime is:328
//BACKWORD
Enter the Size of Queue:7
Enter the numbers:82
Enter the numbers:170
Enter the numbers:43
Enter the numbers:140
Enter the numbers:24
Enter the numbers:16
Enter the numbers:190

Enter the head Position:50

Value   Flag
82      0
170     0
43      0
140     0
24      0
16      0
190     0
After sorting:
Value   Flag
16      0
24      0
43      0
82      0
140     0
170     0
190     0
Enter the Direction:
1)Forward Direction
2)Backword Direction
2
The seek Sequence is:50->43->24->16->82->140->170->190
Total Seektime is:208*/





