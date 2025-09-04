/* #include "pingpong.h" */
#include "kernel/types.h"
#include "user/user.h"

int main(void) {
  int x[2];
  pipe(x);
  int SLEEP_TICKS = 0;
  int pid = fork();


  if (pid == 0) {
    // child
    sleep(SLEEP_TICKS);
    char received[1];
    read(x[0], received, 2);
    if (received[0]) {
      /* printf("%d: received ping %c\n", getpid(), received[0]); */
      printf("%d: received ping\n", getpid());
    }

    char send[1];
    send[0] = 'a';
    write(x[1], send, 1);
    exit(0);

  } else {
    // parent
    char send[1];
    send[0] = 'd';
    write(x[1], send, 1);
    wait(&pid);

    char received[1];
    read(getpid(), received, 1);
    if (received[0]) {
      /* printf("%d: received pong %c\n", getpid(), received[0]); */
      printf("%d: received pong\n", getpid());
    }
    exit(0);
  }
}
