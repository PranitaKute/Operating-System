#include <iostream>
using namespace std;
int main() {
  int bt[20], p, wt = 0, tat, i, twt = 0, ttat = 0;
  // Input the number of processes
  cout << "Enter the number of processes: ";
  cin >> p;
  // Input the burst time for each process
  cout << "Enter the burst time for each process: ";
  for (i = 0; i < p; i++) {
    cin >> bt[i];
  }
  cout << "Burst time \t\t Waiting time \t\t Turn-around time" << endl;
  // Calculate waiting time, turn-around time for each process
  for (i = 0; i < p; i++) {
    twt += wt; // Total waiting time
    tat = bt[i] + wt; // Turn-around time = Burst time + Waiting time
    ttat += tat; // Total turn-around time
    // Display burst time, waiting time, and turn-around time for each process
    cout << bt[i] << "\t\t\t " << wt << "\t\t\t " << tat << endl;
    wt += bt[i]; // Update waiting time for the next process
  }
  // Calculate and display the average waiting time and average turn-around time
  cout << "\n\nAverage waiting time: " << (float)twt / p << endl;
  cout << "Average turn-around time: " << (float)ttat / p << endl;
  
  return 0;
}
