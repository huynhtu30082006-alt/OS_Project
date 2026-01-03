#include "scheduling_algorithms.h"

using namespace std;

SchedulingResult runSJF(vector<Process> processes) {
    int n = processes.size();
    int completed = 0;
    int currentTime = 0;
    int totalWT = 0;
    int totalTAT = 0;
    vector<Process> result;

    while (completed != n) {
        int idx = -1;
        int minBurst = 1e9;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].isCompleted) {
                if (processes[i].burstTime < minBurst) {
                    minBurst = processes[i].burstTime;
                    idx = i;
                } else if (processes[i].burstTime == minBurst) {
                    if (processes[i].arrivalTime < processes[idx].arrivalTime) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            processes[idx].startTime = currentTime;
            processes[idx].completionTime = processes[idx].startTime + processes[idx].burstTime;
            processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
            processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;

            totalWT += processes[idx].waitingTime;
            totalTAT += processes[idx].turnaroundTime;
            
            currentTime = processes[idx].completionTime;
            processes[idx].isCompleted = true;
            result.push_back(processes[idx]);
            completed++;
        } else {
            int nextArrival = 1e9;
            for(int i = 0; i < n; i++) {
                if(!processes[i].isCompleted) 
                    nextArrival = min(nextArrival, processes[i].arrivalTime);
            }
            currentTime = nextArrival;
        }
    }

    return {result, (double)totalWT / n, (double)totalTAT / n};
}