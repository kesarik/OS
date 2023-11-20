/*Name-KesariKadam
RollNo-TIB30*/
#include<stdio.h>
#include<stdlib.h>

void SJF(int a[], int AT[], int BT[], int remainingtime[], int n)
{
    int currtime = 0;  // Keeps track of the current time during execution
    int completed = 0; // Checks the number of completed processes

    printf("\nprocesses\tArrivalTime\tBurstTime\tTurnaroundtime\tWaitingTime\n");

    while (completed < n)
    {
        int shortesttime = -1; // Represents that no process has been selected as the shortest time.

        // Find the process with the shortest remaining burst time among those that have arrived
        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= currtime && remainingtime[i] > 0)
            {
				//This condition checks whether the remaining burst time of the current process (remainingtime[i]) is less than
				// the remaining burst time of the previously selected shortest process (remainingtime[shortesttime])
                if (shortesttime == -1 || remainingtime[i] < remainingtime[shortesttime])
                {
                    shortesttime = i;
                }
            }
        }

        // If no process can be selected  increment the current time.
        if (shortesttime == -1)
        {
            currtime++;
        }
        else
        {
            // Execute the selected process for one time unit, decrement its remaining time, and increment the current time.
            remainingtime[shortesttime]--;
            currtime++;

            // If the process has completed its execution,update completion information.
            if (remainingtime[shortesttime] == 0)
            {
                completed++;

                //calulation
                int Turnaroundtime = currtime - AT[shortesttime];
				int WaitingTime=Turnaroundtime-BT[shortesttime];

                // Print process details
                printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a[shortesttime], AT[shortesttime], BT[shortesttime], Turnaroundtime,WaitingTime);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);

    int a[n], AT[n], BT[n], remainingtime[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the processes:");
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time:");
        scanf("%d", &AT[i]);
        printf("Enter the burst time:");
        scanf("%d", &BT[i]);
    }
    for (int i = 0; i < n; i++)
    {
        remainingtime[i] = BT[i];  //initally remainngtime is equal to burst time
    }

	//printing
    printf("The processes are::");
    printf("\nprocesses\tArrivalTime\tBurstTime\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        printf("\t\t");
        printf("%d", AT[i]);
        printf("\t\t");
        printf("%d", BT[i]);
        printf("\n\n");
    }
    printf("Shortest Job First (Preemptive) Scheduling:\n");
    SJF(a, AT, BT, remainingtime, n);

    return 0;
}

/*OUTPUT:
Enter the number of processes:5
Enter the processes:1
Enter the processes:2
Enter the processes:3
Enter the processes:4
Enter the processes:5
Enter the arrival time:3
Enter the burst time:1
Enter the arrival time:1
Enter the burst time:4
Enter the arrival time:4
Enter the burst time:2
Enter the arrival time:0
Enter the burst time:6
Enter the arrival time:2
Enter the burst time:3
The processes are::
processes       ArrivalTime     BurstTime
1               3               1

2               1               4

3               4               2

4               0               6

5               2               3

Shortest Job First (Preemptive) Scheduling:

processes       ArrivalTime     BurstTime       Turnaroundtime  WaitingTime
1               3               1               1               0
2               1               4               5               1
3               4               2               4               2
5               2               3               9               6
4               0               6               16              10

*/




