#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    char *str;

    // Create shared memory
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);

    // Attach
    str = (char*) shmat(shmid, NULL, 0);

    // Input
    char s1[50], s2[50];
    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    // Concatenate
    strcat(s1, s2);

    // Case flipping
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] >= 'a' && s1[i] <= 'z')
            s1[i] = s1[i] - 32;
        else if (s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i] = s1[i] + 32;
    }

    // Write to shared memory
    strcpy(str, s1);

    printf("Result in shared memory: %s\n", str);

    // Detach
    shmdt(str);

    return 0;
}