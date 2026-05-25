#include <stdio.h>

// Define structure for a process
struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival Time
    int burst;      // Burst Time
    int completion; // Completion Time
    int turnaround; // Turnaround Time
    int waiting;    // Waiting Time
};

int main() {
    int n;

    // Ask user for number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Create array of processes
    struct Process p[n];

    // ---------------- INPUT SECTION ----------------
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;  // Assign PID starting from 1

        printf("\nEnter Arrival Time of P%d: ", p[i].pid);
        scanf("%d", &p[i].arrival);

        printf("Enter Burst Time of P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);
    }

    // ---------------- SORTING (FCFS RULE) ----------------
    // Sort processes by arrival time using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            // Compare arrival times of adjacent processes
            if (p[j].arrival > p[j + 1].arrival) {

                // Swap entire process structures
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // ---------------- CPU EXECUTION ----------------
    int currentTime = 0;     // Tracks current CPU time
    float totalWaiting = 0;  // For calculating average waiting time

    for (int i = 0; i < n; i++) {

        // If CPU is idle (no process has arrived yet)
        if (currentTime < p[i].arrival) {
            currentTime = p[i].arrival;
        }

        // Execute process (non-preemptive)
        currentTime += p[i].burst;

        // Calculate Completion Time
        p[i].completion = currentTime;

        // Calculate Turnaround Time = CT - AT
        p[i].turnaround = p[i].completion - p[i].arrival;

        // Calculate Waiting Time = TAT - BT
        p[i].waiting = p[i].turnaround - p[i].burst;

        // Add waiting time to total
        totalWaiting += p[i].waiting;
    }

    // ---------------- OUTPUT SECTION ----------------
    printf("\n\nFCFS Scheduling Result:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].completion,
               p[i].turnaround,
               p[i].waiting);
    }

    // Calculate and display average waiting time
    printf("\nAverage Waiting Time = %.2f\n", totalWaiting / n);

    return 0;
}