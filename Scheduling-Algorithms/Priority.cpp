#include<iostream>
using namespace std;
int main() {
  int i, j, pno[10], prior[10], bt[10], n, wt[10], tt[10], w1 = 0, t1 = 0, s;
  float aw, at;
  
  cout << "Enter the number of processes: ";
  cin >> n;
  
  for (i = 0; i < n; i++) {
    cout << "The process " << i + 1 << ":\n";
    cout << "Enter the burst time of process: ";
    cin >> bt[i];
    cout << "Enter the priority of process " << i + 1 << ": ";
    cin >> prior[i];
    pno[i] = i + 1;
  }
  
  // Sorting processes based on priority (lower number = higher priority)
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (prior[i] > prior[j]) {
        // Swap priority
        s = prior[i];
        prior[i] = prior[j];
        prior[j] = s;
        // Swap burst time
        s = bt[i];
        bt[i] = bt[j];
        bt[j] = s;
        // Swap process number
        s = pno[i];
        pno[i] = pno[j];
        pno[j] = s;
        }
      }
  }
  
  // Initialize waiting time and turnaround time for the first process
  wt[0] = 0;
  tt[0] = bt[0];
  
  // Calculate waiting time and turnaround time for each process
  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1]; // Waiting time
    tt[i] = wt[i] + bt[i]; // Turnaround time
    w1 += wt[i]; // Total waiting time
    t1 += tt[i]; // Total turnaround time
  }
  
  // Calculate averages
  aw = (float)w1 / n;
  at = (float)t1 / n;
  
  // Display the results
  cout << "\n Job \t Burst Time \t Waiting Time \t Turnaround Time \t Priority\n";
  for (i = 0; i < n; i++) {
    cout << pno[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tt[i] << "\t\t" << prior[i] <<
    endl;
  }
  
  // Display average waiting time and average turnaround time
  cout << "Average Waiting Time: " << aw << endl;
  cout << "Average Turnaround Time: " << at << endl;
  
  return 0;
}
