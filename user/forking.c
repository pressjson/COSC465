/* #include "forking.h" */
#include "kernel/types.h"
#include "user/user.h"

int main(void) {
  printf("Hello, xv6!\n");
  sleep(20);
  int pid = fork();
  printf("How are you? %d\n", pid);
  int pid2 = fork();
  printf("Fine. %d\n", pid2);
  return 0;
}

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
