#include "scheduling_algorithms.h"
#include <algorithm>

// Constructor
Process::Process(string pid, int at, int bt) {
    this->pid = pid;
    this->arrivalTime = at;
    this->burstTime = bt;
    this->completionTime = 0;
    this->turnaroundTime = 0;
    this->waitingTime = 0;
}

void SchedulerFCFS::addProcess(const Process &p) {
    processes.push_back(p);
}

void SchedulerFCFS::runFCFS() {
    // 1) Sort theo arrival time
    sort(processes.begin(), processes.end(), [](auto &a, auto &b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;

    for (auto &p : processes) {
        // Nếu CPU idle trước khi tiến trình đến
        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;
        }

        // 2) Tính Completion Time
        p.completionTime = currentTime + p.burstTime;

        // 3) Tính Turnaround Time = CT - AT
        p.turnaroundTime = p.completionTime - p.arrivalTime;

        // 4) Tính Waiting Time = TAT - BT
        p.waitingTime = p.turnaroundTime - p.burstTime;

        currentTime = p.completionTime;
    }
}

vector<Process> SchedulerFCFS::getResults() const {
    return processes;
}
