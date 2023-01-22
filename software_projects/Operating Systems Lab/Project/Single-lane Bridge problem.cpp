#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<time.h>


// Semaphores to represent the northbound and southbound directions on the bridge
pthread_mutex_t northboundLock;
pthread_mutex_t southboundLock;

// Mutex to ensure that only one farmer is on the bridge at a time
pthread_mutex_t mutex;

// Function to simulate a northbound farmer crossing the bridge
void* northboundFarmer(void* arg) {
  pthread_mutex_lock(&northboundLock);
  pthread_mutex_lock(&mutex);
  printf("northbound farmer is on the bridge\n");
  // Sleep for a random period of time to simulate crossing the bridge
  sleep(rand() % 5 + 1);
  printf("northbound farmer has crossed the bridge\n");
  pthread_mutex_unlock(&mutex);
  pthread_mutex_unlock(&northboundLock);
  return NULL;
}

// Function to simulate a southbound farmer crossing the bridge
void* southboundFarmer(void* arg) {
  pthread_mutex_lock(&southboundLock);
  pthread_mutex_lock(&mutex);
  printf("southbound farmer is on the bridge\n");
  // Sleep for a random period of time to simulate crossing the bridge
  sleep(rand() % 5 + 1);
  printf("southbound farmer has crossed the bridge\n");
  pthread_mutex_unlock(&mutex);
  pthread_mutex_unlock(&southboundLock);
  return NULL;
}

int main(int argc, char* argv[]) {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the Semaphores and Mutex
  pthread_mutex_init(&northboundLock, NULL);
  pthread_mutex_init(&southboundLock, NULL);
  pthread_mutex_init(&mutex, NULL);

// Create several northbound and southbound farmer threads
for (int i = 0; i < 1; i++) {
pthread_t t1, t2;
pthread_create(&t1, NULL, northboundFarmer, NULL);
pthread_create(&t2, NULL, southboundFarmer, NULL);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
}

// Destroy the Semaphores and Mutex
pthread_mutex_destroy(&northboundLock);
pthread_mutex_destroy(&southboundLock);
pthread_mutex_destroy(&mutex);

return 0;
}