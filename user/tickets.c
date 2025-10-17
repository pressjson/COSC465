#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char* argv[]) {
  if (argc < 1) {
    fprintf(2, "tickets: need to provide an argument.");
    return -1;
  }
  int pid = atoi(argv[1]);
  int ticket = tickets(pid);
  /* printf("tickets for process %d: %d\n", pid, ticket); */
  printf("%d\n", ticket);
  return 0;
}
