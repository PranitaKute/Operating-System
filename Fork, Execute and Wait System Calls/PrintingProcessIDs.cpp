//Printing the Process IDs
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int main(){
  cout<<"The process id is : \n" << int(getpid());
  cout<<"\nThe parent process ID is \n" << int(getppid());
  
  return 0;
}
