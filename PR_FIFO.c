#include<stdio.h>
#include<stdlib.h>

int main()
{
    int pages,pagefault=0,hits;
    int frames=3;

    printf("Enter the size of pages(inputstream):");
	scanf("%d",&pages);

    int inputpages[pages];
	for(int i=0;i<pages;i++)
	{
		printf("Enter the pages:");
		scanf("%d",&inputpages[i]);
	}
	printf("\n");
	
	//Printing input stream
	printf("input Stream is:");
	for(int i=0;i<pages;i++)
	{
		printf("%d",inputpages[i]);
		printf("\t");
	}
    printf("\n");
    
    int temp[frames];
    for(int i=0;i<frames;i++)
    {
        temp[i]=-1;    //initially set -1 to indicate empty frames
    }

    for(int i=0;i<pages;i++)
    {
        hits=0;
        for(int j=0;j<frames;j++)
        {
            if(inputpages[i]==temp[j])  //checking if input stream is already present in frames or not
            hits++;  //if present then hint++ and pagefault--
        }
      
        if (hits == 0)   //it checks if the page is not already in memory.
        {
            pagefault++; // Increment page fault if the page is not found in any frame

            if (pagefault <= frames)  // If this condition is true, it means that there are still empty frames in memory
            {
                temp[pagefault - 1] = inputpages[i];  //places the current page into the next available empty frame
                //The index pagefault - 1 is used to access the correct frame since arrays are zero-indexed
            } 
            else 
            {
                temp[(pagefault - 1) % frames] = inputpages[i]; //handle the FIFO situation
            }
        }
        printf("\n");
        printf("The frames are:\n");
        for(int i=0;i<frames;i++)
        {
            printf("%d\t",temp[i]);
        }
        printf("\n"); 
    }
    printf("Total number of page faults are:%d\t",pagefault);
    return 0;
}
/*Output:
Enter the size of InputStream:15
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
Enter the pages:1
Enter the pages:2
Enter the pages:0
The Input Stream is:    7       0       1       2       0       3       0       4       2       3       0       3       10
The frames are:
7       -1      -1

7       0       -1

7       0       1

2       0       1

2       0       1

2       3       1

2       3       0

4       3       0

4       2       0

4       2       3

0       2       3

0       2       3

0       1       3

0       1       2

0       1       2
Total PageFault are:12
*/