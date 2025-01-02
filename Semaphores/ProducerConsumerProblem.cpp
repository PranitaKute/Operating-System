#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <cstdlib>
#define BUFFER_SIZE 5 // Buffer size
int buffer[BUFFER_SIZE]; // Shared buffer
int in = 0, out = 0; // Indexes for producer and consumer
sem_t empty, full, mutex; // Semaphores for synchronization

// Producer function
void* producer(void* arg) {
  int item;
  while (true) {
    item = rand() % 100; // Produce a random item
    sem_wait(&empty); // Wait for an empty slot
    sem_wait(&mutex); // Lock the buffer (enter critical section)
    
    // Add the produced item to the buffer
    buffer[in] = item;
    std::cout << "Producer produced: " << item << std::endl;
    in = (in + 1) % BUFFER_SIZE; // Move to the next position
    sem_post(&mutex); // Unlock the buffer (leave critical section)
    sem_post(&full); // Signal that a full slot is available
    sleep(1); // Simulate time taken to produce
  }
  return nullptr;
}
// Consumer function
void* consumer(void* arg) {
  int item;
  while (true) {
    sem_wait(&full); // Wait for a full slot
    sem_wait(&mutex); // Lock the buffer (enter critical section)
    
    // Consume the item from the buffer
    item = buffer[out];
    std::cout << "Consumer consumed: " << item << std::endl;
    out = (out + 1) % BUFFER_SIZE; // Move to the next position
    sem_post(&mutex); // Unlock the buffer (leave critical section)
    sem_post(&empty); // Signal that an empty slot is available
    sleep(1); // Simulate time taken to consume
  }
  return nullptr;
}
int main() {
  pthread_t prod, cons; // Threads for producer and consumer
  
  // Initialize semaphores
  sem_init(&empty, 0, BUFFER_SIZE); // Buffer slots initially empty
  sem_init(&full, 0, 0); // Initially, no buffer slots are full
  sem_init(&mutex, 0, 1); // Mutex to protect shared buffer
  
  // Create producer and consumer threads
  pthread_create(&prod, nullptr, producer, nullptr);
  pthread_create(&cons, nullptr, consumer, nullptr);
  
  // Wait for threads to finish (in this case, the loop runs infinitely)
  pthread_join(prod, nullptr);
  pthread_join(cons, nullptr);
  
  // Destroy semaphores (this won't be reached in the infinite loop scenario)
  sem_destroy(&empty);
  sem_destroy(&full);
  sem_destroy(&mutex);
    
  return 0;
}
