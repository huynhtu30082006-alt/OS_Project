#ifndef SCHEDULING_ALGORITHMS_H
#define SCHEDULING_ALGORITHMS_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Process {
    string id;
    int arrivalTime;
    int burstTime;
    int startTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    bool isCompleted = false;
};

struct SchedulingResult {
    vector<Process> processes;
    double avgWaitingTime;
    double avgTurnaroundTime;
};

SchedulingResult runSJF(vector<Process> processes);

#endif