#include <stdio.h>
#include <limits.h>

struct Process {
    int pid, at, bt, rt, ct, tat, wt;
};

int main() {
    int n, completed = 0, time = 0;
    float totalWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter Arrival Time of P%d: ", p[i].pid);
        scanf("%d", &p[i].at);

        printf("Enter Burst Time of P%d: ", p[i].pid);
        scanf("%d", &p[i].bt);

        p[i].rt = p[i].bt; // Remaining time initially = burst time
    }

    // SRTF Logic
    while (completed != n) {
        int shortest = -1;
        int minRT = INT_MAX;

        // Find process with minimum remaining time
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].rt < minRT) {
                minRT = p[i].rt;
                shortest = i;
            }
        }

        // If no process available → CPU idle
        if (shortest == -1) {
            time++;
            continue;
        }

        // Execute for 1 unit time
        p[shortest].rt--;

        // If process finishes
        if (p[shortest].rt == 0) {
            completed++;
            p[shortest].ct = time + 1;

            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;

            totalWT += p[shortest].wt;
        }

        time++;
    }

    // Output
    printf("\nSRTF Scheduling Result:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);

    return 0;
}