#include<stdio.h>
#include<stdlib.h>
struct process
{
    int value;
    int k;
};
void FIFO(struct process a[],int n,int frame)
{
    
    int temp[frame],pagefault=0;
    for(int i=0;i<frame;i++)
    {
        temp[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        int hits=0;
        for(int j=0;j<3;j++)
        {
            if(a[i].value==temp[j])
            {
                hits++;
            }
        }
        if(hits==0)
        {
            pagefault++;
            if(pagefault<=frame)
            {
                temp[pagefault-1]=a[i].value;
            }
            else
            {
                temp[(pagefault-1)%frame]=a[i].value;
            }
        }
        printf("The frame are:");
        for(int i=0;i<frame;i++)
        {
            printf("%d\t",temp[i]);
        }
        printf("\n");
    }
    printf("\nTotal pagefaults are:%d",pagefault);
}
void LRU(struct process a[],int n,struct process framearr[])
{

    int hits=0,pagefault=0;
    for(int i=0;i<3;i++)
    {
        framearr[i].value=-1;
        framearr[i].k=-1;
    }
    for(int i=0;i<n;i++)
    {
        int pagefound=0;
        for(int j=0;j<3;j++)
        {
            if(a[i].value==framearr[j].value)
            {
                hits++;
                framearr[j].k=i;
                pagefound=1;
                break;
            }
        }
        if(pagefound==0)
        {
            pagefault++;
            int index=0;
            for(int j=0;j<3;j++)
            {
                if(framearr[j].k<framearr[index].k)
                {
                    index=j;
                }
            }
            framearr[index].value=a[i].value;
            framearr[index].k=i;
        }
    }
    printf("Total pagefaults are:%d",pagefault);
}
void optimal(struct process a[],int n,struct process framearr[])
{
    int pagefault=0,hits=0;

    for(int i=0;i<3;i++)
    {
        framearr[i].value=-1;
        framearr[i].k=-1;
    }
    for(int i=0;i<n;i++)
    {
        int pagefound=0;
        for(int j=0;j<3;j++)
        {
            if(a[i].value==framearr[j].value)
            {
                hits++;
                pagefound=1;
                break;
            }
        }
        if(pagefound==0)
        {
            pagefault++;
            int index=-1;
            int maxdist=-1;
            for(int j=0;j<3;j++)
            {
                int nextindex=-1;
                for(int m=i+1;m<n;m++)
                {
                    if(a[m].value==framearr[j].value)
                    {
                        nextindex=m;
                        break;
                    }
                }
                if(nextindex==-1)
                {
                    index=j;
                    break;
                }
                if(nextindex>maxdist)
                {
                    maxdist=nextindex;
                    index=j;
                }
            }
            framearr[index].value=a[i].value;
            framearr[index].k=i;
        }  
        printf("The frames are:");
        for(int i=0;i<3;i++)
        {
            printf("%d\t",framearr[i].value);
        }
        printf("\n");
    }
    printf("Total pagefault are:%d",pagefault);
}
int main()
{
    int n;
    int frame=3;
    struct process framearr[3];
    printf("Enter the size of InputStream:");
    scanf("%d",&n);
    struct process a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the numbers:");
        scanf("%d", &a[i].value);
        a[i].k=0;
    }
    printf("\n");
    int choice;
    printf("Enter the choice:\n1)FIFO\n2)LRU\n3)Optimal\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        FIFO(a,n,frame);
        break;
        case 2:
        LRU(a,n,framearr);
        break;
        case 3:
        optimal(a,n,framearr);
        break;

    }

}


