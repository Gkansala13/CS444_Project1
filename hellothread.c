#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* printNumbers(void* arg) {
    char* threadName = (char*) arg; // Cast the argument to char* type
    for (int i = 0; i < 5; i++) {
        printf("%s: %d\n", threadName, i);
    }
    return NULL;
}

int main() {
    printf("Launching threads\n");

    pthread_t thread1, thread2; // Declare thread handles
    char* threadName1 = "thread 1";
    char* threadName2 = "thread 2";

    // Create thread 1
    if (pthread_create(&thread1, NULL, printNumbers, (void*) threadName1) != 0) {
        printf("Error creating thread 1.\n");
        return 1;
    }

    // Create thread 2
    if (pthread_create(&thread2, NULL, printNumbers, (void*) threadName2) != 0) {
        printf("Error creating thread 2.\n");
        return 1;
    }

    // Wait for thread 1 to complete
    if (pthread_join(thread1, NULL) != 0) {
        printf("Error joining thread 1.\n");
        return 1;
    }

    // Wait for thread 2 to complete
    if (pthread_join(thread2, NULL) != 0) {
        printf("Error joining thread 2.\n");
        return 1;
    }

    printf("Threads complete!\n");

    return 0;
}
