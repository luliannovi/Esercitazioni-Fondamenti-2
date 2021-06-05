#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

bool InTempo(const job* jobs, int index, int* time) {
    if (jobs[index].duration + time[0] > jobs[index].deadline)
        return false;
    else
        return true;
}

void ScheduleJobsRec(const job* jobs, size_t j_size, double* appet, bool* fatti, int* tot, int* ordine,int  * time, int* profit) {

    int max = 0;
    int pos = -1;
    for (int i = 0; i < j_size; i++) {
        if (appet[i] > max && fatti[i]==false && InTempo(jobs, i,time)) {
            max = appet[i];
            pos = i;
        }
    }
    if (pos == -1)
        return;
    fatti[pos] = true;
    *time = *time + jobs[pos].duration;
    ordine = realloc(ordine, (*tot + 1) * sizeof(int));
    ordine[*tot] = pos;
    *tot = *tot +1;
    *profit += jobs[pos].profit;
    ScheduleJobsRec(jobs, j_size, appet, fatti, tot, ordine, time,profit);
    return;
}


int ScheduleJobs(const job* jobs, size_t j_size) {
    if (jobs == NULL)
        return 0;
    double* appet = malloc(j_size * sizeof(double));
    for (int i = 0; i < j_size; i++) {
        appet[i] = jobs[i].profit / jobs[i].duration;
    }
    bool* fatti = malloc(j_size * sizeof(bool));
    for (int i = 0; i < j_size; i++) {
        fatti[i] = false;
    }
    int tot = 0;
    int* ordine = malloc(j_size * sizeof(int));
    int time = 0;
    int profit = 0;
    ScheduleJobsRec(jobs, j_size, appet, fatti, &tot, ordine, &time, &profit);

    for (int i = 0; i < tot; i++)
        printf("%d ", ordine[i]);
    free(ordine);
    free(appet);
    free(fatti);
    return profit;
}
/*
int main(void) {
    job* jobs = malloc(3 * sizeof(job));
    job a = { 80,2,4 };
    job b = { 100,5,6 };
    job c = { 30,1,3 };
    jobs[0] = a;
    jobs[1] = b;
    jobs[2] = c;
    ScheduleJobs(jobs, 3);

}*/