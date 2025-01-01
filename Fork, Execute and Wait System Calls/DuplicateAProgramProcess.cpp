#include <iostream>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int main() {
  pid_t child_pid;
  
  // Print the process ID of the main program
  cout << "The main program process ID is: " << getpid() << endl;
  
  // Create a child process using fork
  child_pid = fork();
  if (child_pid != 0) {
    // This is the parent process
    cout << "This is the parent process, with ID: " << getpid() << endl;
    cout << "The child's process ID is: " << child_pid << endl;
  } else {
    // This is the child process
    cout << "This is the child process, with ID: " << getpid() << endl;
  }
  
  return 0;
}
