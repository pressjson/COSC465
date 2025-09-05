/* #include "pingpong.h" */
#include "kernel/types.h"
#include "user/user.h"

int main(void) {
  int fds[2];
  pipe(fds);
  if (pipe < 0) {
    printf("pingpong: pipe failed");
    exit(1);
  }
  int pid = fork();

  if (pid == 0) {
    // child
    /* sleep(10); */
    char received[1];
    int cc = read(fds[0], received, 1);
    if(cc != 1) {
      printf("child: read error %d!\n", cc);
    }
    if (received[0]) {
      /* printf("%d: received ping %c\n", getpid(), received[0]); */
      printf("%d: received ping\n", getpid());
    }

    char send[1] = {'a'};
    write(fds[1], send, 1);
    close(fds[1]);
    exit(0);

  } else {
    // parent
    char send[1] = {'c'};
    int cc = write(fds[1], send, 1);
    if(cc != 1) {
      printf("parent: write error! %d\n", cc);
    }
    wait(&pid);

    char received[1];
    read(fds[0], received, 1);
    if (received[0]) {
      /* printf("%d: received pong %c\n", getpid(), received[0]); */
      printf("%d: received pong\n", getpid());
    }
    /* close(fds[0]); */
    exit(0);
  }
}
