// last: last abstract syntax tree
#include <stdio.h>
#include <stdlib.h>
#include <lastconfig.h>
 
int main (int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stdout,"%s Version %d.%d\n",
            argv[0],
            last_VERSION_MAJOR,
            last_VERSION_MINOR);
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
  }

  return 0;
}
