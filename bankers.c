#include<stdio.h>
#include<stdlib.h>

struct process
{
    int allocation[3];
    int max[3];
    int available[3];
    int need[3];
    int flag;
    int id;

};
int main()
{
    int n;
    printf("Enter the number of Processes:");
    scanf("%d",&n);

    struct process a[n];
    for(int i=0;i<n;i++)
    {
        printf("For Process %d:",i+1);
        printf("\n");
        for(int j=0;j<3;j++)
        {
            printf("Allocation for%d:",j+1);
            scanf("%d",&a[i].allocation[j]);

            printf("Max for %d:",j+1);
            scanf("%d",&a[i].max[j]);

            a[i].available[j]=0;
            a[i].need[j]=0;
            a[i].flag = 0;
            a[i].id = i + 1;
        }
    }
    // Printing
    printf("Printing values:\n");
    printf("Process\t\tAllocation\t\tMax\t\tAvailable\t\tNeed\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\t", i + 1);
        for (int j = 0; j < 3; j++) 
        {
            printf("%d\t", a[i].allocation[j]);
        }
        for (int j = 0; j < 3; j++) 
        {
            printf("%d\t", a[i].max[j]);
        }
        for (int j = 0; j < 3; j++) 
        {
            printf("%d\t", a[i].available[j]);
        }
        for (int j = 0; j < 3; j++) 
        {
            printf("%d\t", a[i].need[j]);
        }
        printf("\n");
    }

    printf("Enter the value for resorcses:");
    int A,B,C;
    printf("\n");
    printf("Enter the value for A:");
    scanf("%d",&A);
    printf("Enter the value for B:");
    scanf("%d",&B);
    printf("Enter the value for C:");
    scanf("%d",&C);

    int a_sum = 0, b_sum = 0, c_sum = 0;
    for (int i = 0; i < n; i++)
    {
        a_sum += a[i].allocation[0];
        b_sum += a[i].allocation[1];
        c_sum += a[i].allocation[2];
    }

    int A1, B1, C1;
    A1 = A - a_sum;
    B1 = B - b_sum;
    C1 = C - c_sum;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < 3; j++)
         {
            a[i].need[j] = a[i].max[j] - a[i].allocation[j];
        }
    }

    printf("Total Availbale resourses are:");
    printf("%d\t%d\t%d\n", A1, B1, C1);

    int path[n];
    int k=0;   //used to keep track of the position in the Path array where processes are added.
    int pathsafe=0;  //used to check if a safe execution path exists or not

    while(k<n)
    {
        int canexecute=0;
        for(int i=0;i<n;i++)
        {
            if(a[i].flag==0)  // If process is not already inserted in the path
            {
                int resource=1;  //assuming initially that the process can be executed safely
                for(int j=0;j<3;j++)
                {
                    if(a[i].need[j]> (j==0?A1 :(j==1?B1 :C1)))  
                    //selects A1 when j is 0, B1 when j is 1, and C1 when j is 2 for comaring with need value
                    {
                        resource=0;
                        break;
                    }
                }
                if(resource==1)
                {
                    path[k]=a[i].id;
                    k=k+1;
                    a[i].flag=1;
                    A1+=a[i].allocation[0];
                    B1+=a[i].allocation[1];
                    C1+=a[i].allocation[2];
                    a[i].available[0]=A1;
                    a[i].available[1]=B1;
                    a[i].available[2]=C1;
                    canexecute=1;

                }
            }
        }
        if(canexecute==0)
        {
            pathsafe=1;  //if no process can be executed safely
            break;
        }
    }
    if(pathsafe==0)
    {
        printf("The safe Path is:\n");
        for (int i = 0; i < n; i++) 
        {
            printf("%d ", path[i]); 
        }
        printf("\n");

    }
    else
    {
        printf("The path is unsafe\n");
    }
        
    // Printing
    printf("Printing values:\n");
    printf("Process\t\tAllocation\t\tMax\t\tAvailable\t\tNeed\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\t", i + 1);
        for (int j = 0; j < 3; j++) 
        {
            printf("%d\t", a[i].allocation[j]);
        }
        for (int j = 0; j < 3; j++) 
        {
            printf("%d\t", a[i].max[j]);
        }
        for (int j = 0; j < 3; j++) 
        {
            printf("%d\t", a[i].available[j]);
        }
        for (int j = 0; j < 3; j++) 
        {
            printf("%d\t", a[i].need[j]);
        }
        printf("\n");
    }
    printf("The safe Path is:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", path[i]); 
    }
    printf("\n");
    return 0;
}

/*OUTPUT:
Enter the number of Processes:5
For Process 1:
Allocation for1:0
Max for 1:7
Allocation for2:1
Max for 2:5
Allocation for3:0
Max for 3:3
For Process 2:
Allocation for1:2
Max for 1:3
Allocation for2:0
Max for 2:2
Allocation for3:0
Max for 3:2
For Process 3:
Allocation for1:3
Max for 1:9
Allocation for2:0
Max for 2:0
Allocation for3:2
Max for 3:2
For Process 4:
Allocation for1:2
Max for 1:4
Allocation for2:1
Max for 2:2
Allocation for3:1
Max for 3:2
For Process 5:
Allocation for1:0
Max for 1:5
Allocation for2:0
Max for 2:3
Allocation for3:2
Max for 3:3
Printing values:
Process         Allocation              Max             Available               Need
1       0       1       0       7       5       3       0       0       0       0       0       0
2       2       0       0       3       2       2       0       0       0       0       0       0
3       3       0       2       9       0       2       0       0       0       0       0       0
4       2       1       1       4       2       2       0       0       0       0       0       0
5       0       0       2       5       3       3       0       0       0       0       0       0
Enter the value for resorcses:
Enter the value for A:10
Enter the value for B:5
Enter the value for C:7
Total Availbale resourses are:3 3       2
The safe Path is:
2 4 5 1 3
Printing values:
Process         Allocation              Max             Available               Need
1       0       1       0       7       5       3       7       5       5       7       4       3
2       2       0       0       3       2       2       5       3       2       1       2       2
3       3       0       2       9       0       2       10      5       7       6       0       0
4       2       1       1       4       2       2       7       4       3       2       1       1
5       0       0       2       5       3       3       7       4       5       5       3       1
The safe Path is:
2 4 5 1 3
*/