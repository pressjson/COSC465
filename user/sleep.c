#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  // get args
  if (argc < 2) {
    fprintf(2, "Usage: sleep [INT]...\n");
    exit(1);
  }
  /* fprintf(1, "argv[1] == %s\n", argv[1]); */
  int n;
  n = atoi(argv[1]);
  /* fprintf(1, "n == %d\n", n); */
  /* if (n < 0) { */
  /*   fprintf(2, "Error: int can not be negative"); */
  /*   exit(1); */
  /* } */
  sleep(n);
  /* fprintf(1, "Slept for %d ticks\n", n); */


  exit(0);
}
