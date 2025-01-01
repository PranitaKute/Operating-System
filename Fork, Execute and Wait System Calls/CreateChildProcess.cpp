#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) {
  pid_t childpid;
  // Fork a new process
  childpid = fork();
  
  if (childpid == -1) {
    // Error handling for fork failure
    perror("Failed to fork");
    return 1;
  }
  
  if (childpid == 0) {
    // This is the child process
    // Execute the "ls -l" command using execl
    execl("/bin/ls", "ls", "-l", NULL);
    // If execl fails, handle the error
    perror("Child failed to exec ls");
    return 1;
  }
  
  // Parent process waits for the child to terminate
  if (childpid != wait(NULL)) {
    // Error handling if wait fails
    perror("Parent failed to wait due to signal or error");
    return 1;
  }
  
  return 0;
}
