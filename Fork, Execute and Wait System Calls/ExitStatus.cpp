#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
using namespace std;
void show_return_status() {
  pid_t childpid;
  int status;
  // Wait for the child process to finish
  childpid = wait(&status);
  // Check if the wait call failed
  if (childpid == -1) {
  perror("Failed to wait for child");
  }
  // Check if the child process terminated normally
  else if (WIFEXITED(status)) {
  cout << "Child " << (long)childpid << " terminated with return status " <<
  WEXITSTATUS(status) << endl;
  }
}

int main() {
  pid_t pid = fork();
  if (pid == -1) {
    // Fork failed
    perror("Failed to fork");
    return 1;
  }
  else if (pid == 0) {
    // Child process
    cout << "Child process executing..." << endl;
    exit(5); // Exit with status 5
  }
  else {
    // Parent process
    show_return_status(); // Show the exit status of the child
  }
  
  return 0;
}
