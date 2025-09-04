/* #include "forking.h" */
#include "kernel/types.h"
#include "user/user.h"

/* int main(void) { */
/*   printf("Hello, xv6!\n"); */
/*   sleep(20); */
/*   int pid = fork(); */
/*   printf("How are you? %d\n", pid); */
/*   int pid2 = fork(); */
/*   printf("Fine. %d\n", pid2); */
/*   return 0; */
/* } */

int main(void) {
  char *x[10];
  x[0] = "ls";
  /* x[1] = "sh"; */
  x[2] = 0;
  printf("%d\n", getpid());
  char input[1];
  printf("q to quit: ");
  // read 1 character from STDIN to "input"
  read(0, input, 1);
  while (input[0] != 'q') {
    int pid = fork();
    if (pid > 0) {
      // parent process
      wait(&pid);
      printf("p: %d\n", getpid());
      printf("q to quit: ");
      read(0, input, 1);
    } else {
      // child process
      printf("c: %d\n", getpid());
      exec(x[0], x);
      // anything after the exec is effectively removed
    }
  }
}

/* if (pid == 0) -> child process
 * if (pid != 0) -> parent process or error
 * if (pid > 0) -> parent process, no error
 * if (pid < 0) -> error
 */

/*
** PARENT
** ---
** getpid() = A
** pid = B
**    |
**    |
**    |  fork()
**    |
**    V
** CHILD
** ---
** getpid() = B
** pid = 0    // 0 == child; else parent
**
** For A3, read the CMake file and the part about the sleep command
*/
