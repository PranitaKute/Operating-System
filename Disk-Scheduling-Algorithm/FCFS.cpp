#include <bits/stdc++.h>
using namespace std;
int request_size = 8;
void FCFS(int arr[], int head) {
  int seek_count = 0; // Total number of seek operations
  int distance, cur_track;
  
  // Process each request in the order they arrive
  for (int i = 0; i < request_size; i++) {
    cur_track = arr[i]; // Current track to be accessed
    distance = abs(cur_track - head); // Calculate absolute distance (seek time)
    seek_count += distance; // Add to total seek count
    head = cur_track; // Move the head to the current track
  }
  
  // Output the total number of seek operations
  cout << "Total number of seek operations = " << seek_count << endl;
  
  // Output the seek sequence
  cout << "Seek Sequence is:" << endl;
  for (int i = 0; i < request_size; i++) {
    cout << arr[i] << endl;
  }
}

int main() {
  // Request array
  int arr[request_size] = {176, 79, 34, 60, 92, 11, 41, 114};
  int head = 50; // Initial position of the disk head
  
  // Perform FCFS disk scheduling
  FCFS(arr, head);
  
  return 0;
}
