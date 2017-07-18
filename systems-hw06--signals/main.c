// Calvin Vuong and William Xiang
// MKS65 pd10
// Work6
// 11-09-2016

#include "main.h"

static void sighandler(int signo) {

  switch(signo) {

  case SIGUSR1:
    printf("Parent PID: %d\n", getppid());
    break;

  case SIGINT: {

    int fd = open("error.log", O_WRONLY | O_APPEND | O_CREAT, 0644);

    // generate string to write to file
    char *id_str = (char *) malloc( sizeof(pid_t) + 8 );
    snprintf(id_str, sizeof(pid_t)+8, "{PID: %d} ", getpid()); // terminating null purposely not copied

    char *buf = (char *) malloc( sizeof(pid_t)+8 + 30);
    snprintf(buf, sizeof(pid_t)+8 + 30, "%s Program exited due to SIGINT\n", id_str);    

    write( fd, buf, sizeof(pid_t) + 8 + 30 - 1);
    close(fd);

    free(id_str);
    free(buf);
    exit(0);
    break;
  }

  default:
    break;
  }

}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);    

  while (1) {
    printf( "PID: %d\n", getpid() );
    sleep(1);
  }

  return 0;
}
