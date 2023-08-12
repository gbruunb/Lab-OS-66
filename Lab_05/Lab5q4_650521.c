#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char userChoice = 'z';
	while (userChoice != 'q')
	{
		// print menu
		printf("\na: ls\n");
		printf("b: ps\n");
		printf("c: who\n");
		printf("q for quit\n");
		scanf(" %c", &userChoice);

		pid_t pid = fork();
		if (pid == 0)
		{
			switch (userChoice)
			{
			case 'a':
				printf("\n===== Perform ls =====\n");
				execlp("ls", "ls", NULL);
				break;
			case 'b':
				printf("\n===== Perform ps =====\n");
				execlp("ps", "ps", NULL);
				break;
			case 'c':
				printf("\n===== Perform whoami =====\n");
				execlp("whoami", "whoami", NULL);
				break;
			default:
				exit(0);
				break;
			}
		}
		wait(NULL);
	}
	printf("parent terminated\n");
}
