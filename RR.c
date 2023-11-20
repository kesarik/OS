#include<stdio.h>
#include<stdlib.h>

void RR(int a[], int AT[], int BT[], int remainingtime[], int n, int QT)
{
    int currtime = 0; //track the curr time during execution(means Gantt chart time(CT))
    int completed = 0;  //menas no process has been select,track number of completed processes

    printf("\nprocesses\tArrivalTime\tBurstTime\tTurnaroundtime\tWaitingTime\n");
    
    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= currtime && remainingtime[i] > 0)
            {
                //remaining time means QT madhun minus krun jo time rahil to
                if (remainingtime[i] <= QT)  // Compare remaining time to quantum
                {
                    currtime += remainingtime[i]; //add all remaining time to currtime
                    remainingtime[i] = 0;  //indicate that the process has completed.
                    completed++;

                    int TurnaroundTime = currtime - AT[i];
                    int WaitingTime = TurnaroundTime - BT[i];

                    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a[i], AT[i], BT[i], TurnaroundTime, WaitingTime);
                }
                else
                {
                    //if remaining is greater than QT then add QT to currime
                    currtime += QT;
                    remainingtime[i] -= QT; //decrement the remainingtime
                }
            }
        }
    }
}
int main()
{
    int n, QT;
    printf("Enter the number of processes:");
    scanf("%d", &n);

    int a[n], BT[n], AT[n], remainingtime[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Process ID:");
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time:");
        scanf("%d", &AT[i]);
        printf("Enter the burst time:");
        scanf("%d", &BT[i]);
    }
    printf("Enter the quantum time:");
    scanf("%d", &QT);

    for (int i = 0; i < n; i++)
    {
        remainingtime[i] = BT[i];   // //initally remainngtime is equal to burst time
    }

    // Printing process details
    printf("The processes are::\n");
    printf("Process\tArrivalTime\tBurstTime\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\n", a[i], AT[i], BT[i]);
    }

    printf("Round Robin (Preemptive) Scheduling:\n");
    RR(a, AT, BT, remainingtime, n, QT);
    return 0;
}
/*Output:
Enter the number of processes:4
Enter the Process ID:10

Enter the Process ID:2
Enter the Process ID:3
Enter the Process ID:4
Enter the arrival time:0
Enter the burst time:5
Enter the arrival time:1
Enter the burst time:4
Enter the arrival time:2
Enter the burst time:2
Enter the arrival time:4
Enter the burst time:1
Enter the quantum time:2
The processes are::
Process ArrivalTime     BurstTime
1       0               5
2       1               4
3       2               2
4       4               1
Round Robin (Preemptive) Scheduling:

processes       ArrivalTime     BurstTime       Turnaroundtime  WaitingTime
3               2               2               4               2
4               4               1               3               2
2               1               4               10              6
1               0               5               12              7
*/

