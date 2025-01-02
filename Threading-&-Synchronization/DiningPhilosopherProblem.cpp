#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

const int N = 5; // Number of philosophers
mutex forks[N]; // Mutexes representing forks

void philosopher(int id) {
  while (true) {
  // Thinking
    cout << "Philosopher " << id << " is thinking.\n";
    this_thread::sleep_for(chrono::seconds(1));
    // Picking up left fork
    forks[id].lock();
    cout << "Philosopher " << id << " picked up left fork.\n";
    
    // Picking up right fork
    forks[(id + 1) % N].lock();
    cout << "Philosopher " << id << " picked up right fork.\n";
    cout << "Philosopher " << id << " is eating.\n";

    this_thread::sleep_for(chorno::seconds(2));
    forks[(id + 1) % N].unlock();
    cout << "Philosopher " << id << " put down right fork.\n";

    forks[id].unlock();
    cout << "Philosopher " << id << " put down left fork.\n";
  }
}
int main(){
  thread philosophers[N];
  
  for(int i = 0; i < N; i++){
    philosophers[i] = thread(philosopher, i);
  }

  for(int i = 0; i < N; i++){
    philosophers[i].join();
  }

  return 0;
}
