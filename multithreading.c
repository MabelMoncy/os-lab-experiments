#include <stdio.h>
#include <pthread.h>

int arr[100], n;
int sum = 0, min, max;

void* find_sum(void* arg) {
    for (int i = 0; i < n; i++)
        sum += arr[i];
}

void* find_min(void* arg) {
    min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
}

void* find_max(void* arg) {
    max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
}

int main() {
    pthread_t t1, t2, t3;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Create threads
    pthread_create(&t1, NULL, find_sum, NULL);
    pthread_create(&t2, NULL, find_min, NULL);
    pthread_create(&t3, NULL, find_max, NULL);

    // Join threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    float avg = (float)sum / n;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);
    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    return 0;
}