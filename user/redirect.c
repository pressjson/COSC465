/* #include "redirect.h" */
#include "kernel/fcntl.h"
#include "kernel/types.h"
#include "user/user.h"

int main(void) {
  close(1);
  open("out.txt", O_WRONLY | O_CREATE | O_TRUNC); // in kernel/types.h
  printf("Hello world!\n");

  return 0;
}
