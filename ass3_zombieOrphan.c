//Zombie Process
/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    pid_t C_id = fork(); //C_Id of type pid_t so using fork function we create child id of the type of pid
    if(C_id==0)
    {
        printf("Child Process is Existing!!\n");
        printf("Child Process id is:");
        printf("%d",getpid());
        printf("\n");
    }
    else if(C_id>0)
    {
       printf("\nParent Process Existing!!\n");
		printf("Parent Process Id: ");
		printf("%d",getppid());
		printf("\n");
		printf("Parent Process Going to Sleep!\n");
		sleep(30);
		printf("\n");
		printf("Parent Process Waking Up..!!\n");

    }
    else{
        printf("Error Occured!!");
    }
    return 0;
}*/

//Orphan Process
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    pid_t c_id=fork();
    if(c_id==0)
    {
        sleep(10);
		printf("\nI am Child Process Having Parent id: ");
		printf("%d",getppid());
		printf("\nI am Child Process Having Child id: ");
		printf("%d",getpid());
		printf("\n");

    }
    else
    {
        printf("\nI am Parent Process Having Parent id: ");
		printf("%d",getppid());
		printf("\nI am Parent Process Having Child id: ");
		printf("%d",getpid());
		printf("\n");
    }
    return 0;
}