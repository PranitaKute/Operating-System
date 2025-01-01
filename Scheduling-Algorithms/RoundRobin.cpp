#include<iostream>
using namespace std;
int main() {
  int b[10], i, j = 1, n, temp, burst[10], wait[10], turn[10], p[10], a = 1, q, tat[10], t1 = 0;
  float t = 0, w = 0;
  
  cout << "Enter the number of processes and time quantum: ";
  cin >> n >> q;
  burst[0] = 0;
  b[0] = 0;
  tat[0] = 0;
  p[0] = 0;
  
  cout << "Enter burst time: ";
  for (i = 1; i <= n; i++) {
    cin >> burst[i];
  }
  
  // Copy burst times to b[] for processing
  for (i = 1; i <= n; i++) {
    b[i] = burst[i];
  }
  
  // Printing Gantt Chart
  cout << "\n\n\t\tGantt chart\n";
  for (i = 1; i <= n; i++) {
    if (b[i] > 0) {
    a = 1;
    cout << "P" << i << "\t|";
    
    if (b[i] >= q) {
      t1 = t1 + q;
      p[j] = t1;
      j++;
    } else if (b[i] < q) {
      t1 = t1 + b[i];
      p[j] = t1;
      j++;
    }
    b[i] = b[i] - q;
    if (b[i] <= 0) {
      tat[i] = t1;
    }
  } else {
    a++;
  }
    
  // If all processes are complete, break the loop
  if (a == n + 1)
    break;
    
  // Restart the loop to simulate round robin scheduling
  if (i == n)
    i = 0;
  }
  
  // Print the process completion times (Gantt chart)
  cout << "\n\n";
  for (i = 0; i < j; i++) {
    cout << p[i] << "\t";
  }
  
  // Calculate total turnaround time and waiting time
  for (i = 1; i <= n; i++) {
    t = t + tat[i]; // Total turnaround time
    w = w + tat[i] - burst[i]; // Total waiting time
  }
  
  // Calculate average waiting time and average turnaround time
  w = w / n;
  t = t / n;
  cout << "\nThe average waiting time is " << w << endl;
  cout << "The average turnaround time is " << t << endl;
  
  return 0;
}
