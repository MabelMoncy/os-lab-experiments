#include <stdio.h>

struct Process {
    int pid, at, bt, priority;
    int ct, tat, wt, completed;
};

int main() {
    int n;
    float totalWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nEnter Arrival Time of P%d: ", p[i].pid);
        scanf("%d", &p[i].at);

        printf("Enter Burst Time of P%d: ", p[i].pid);
        scanf("%d", &p[i].bt);

        printf("Enter Priority of P%d: ", p[i].pid);
        scanf("%d", &p[i].priority);

        p[i].completed = 0;
    }

    int time = 0, completed = 0;

    while (completed != n) {
        int idx = -1;
        int bestPriority = -1;

        // Select highest priority process
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= time) {
                if (p[i].priority > bestPriority) {
                    bestPriority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        // Execute process
        time += p[idx].bt;

        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        totalWT += p[idx].wt;

        p[idx].completed = 1;
        completed++;
    }

    // Output
    printf("\nPriority Scheduling Result:\n");
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].priority,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);

    return 0;
}