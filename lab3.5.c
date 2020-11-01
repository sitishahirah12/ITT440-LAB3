#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

int check_prime(int);

int main(void) {
    void sigint_handler(int sig);
    int n, result;

    printf("Enter a number:\n");
    scanf("%d", &n);

    result = n;

    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if(pid > 0)  {
      close(0);
      close(fd[1]);
      dup(fd[0]);
    }
    else if(pid == 0)  {
      close(1);
      close(fd[0]);
      dup(fd[1]);
    }

int check_prime(int a)
{
  int c;

  for(c = 2; c <= a-1; c++)
 {
   if(a % c == 0)
   return 0;
       }
   return 1;
    }
    
    if(n == 1) {
      printf("1 is neither prime nor composite.\n");
    }
    else {
    if(n == 2) {
      printf("%d is a prime number.\n", n); }
    else {
      printf("%d is not a prime number.\n", n); }
    }

return EXIT_SUCCESS;
}

void sigint_handler(int sig)
{
  printf("EXIT");
}
