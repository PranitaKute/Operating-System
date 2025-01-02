#include <iostream>
using namespace std;
int main() {
  int disk[100] = {0}; // Initialize a disk of 100 blocks (0 means free, 1 means occupied)
  int n, start, len;
  
  cout << "Enter the number of files: ";
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cout << "Enter starting block and length of file " << i + 1 << ": ";
    cin >> start >> len;
    
    // Check if the file can be allocated (i.e., blocks are free)
    bool allocated = true;
    
    for (int j = start; j < start + len; j++) {
      if (j >= 100 || disk[j] == 1) { // Ensure the blocks are within range and free
      allocated = false;
      break;
    }
  }
    
  // Allocate the file if all required blocks are free
  if (allocated) {
    for (int j = start; j < start + len; j++) {
      disk[j] = 1; // Mark blocks as occupied
    }
    cout << "File " << i + 1 << " allocated from block " << start << " to block " << start + len - 1 << endl;
    } else {
      cout << "File " << i + 1 << " could not be allocated. Blocks are already occupied or out of range.\n";
    }
    
    // Display the current status of the disk
    cout << "\nDisk status:\n";
    for (int i = 0; i < 100; i++) {
      cout << disk[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
