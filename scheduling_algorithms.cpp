#include "scheduling_algorithms.h"
#include <algorithm>

// Hàm so sánh dùng cho sort
bool compareByArrival(const Process &a, const Process &b)
{
    return a.arrivalTime < b.arrivalTime;
}

// Constructor
Process::Process(string pid, int at, int bt) {
    this->pid = pid;
    this->arrivalTime = at;
    this->burstTime = bt;
    this->startTime = 0;
    this->completionTime = 0;
    this->turnaroundTime = 0;
    this->waitingTime = 0;
    this->responseTime = 0;
}

void SchedulerFCFS::addProcess(const Process &p) {
    processes.push_back(p);
}

void SchedulerFCFS::runFCFS() {
    // 1) Sắp xếp theo arrivalTime
    sort(processes.begin(), processes.end(), compareByArrival);

    int currentTime = 0;
    for (auto &p : processes) {
        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;
        }

        // Start Time
        p.startTime = currentTime;

        // Completion Time
        p.completionTime = currentTime + p.burstTime;

        // Turnaround Time
        p.turnaroundTime = p.completionTime - p.arrivalTime;

        // Waiting Time
        p.waitingTime = p.startTime - p.arrivalTime;

        // Response Time = Waiting Time
        p.responseTime = p.waitingTime;

        currentTime = p.completionTime;
    }
}

vector<Process> SchedulerFCFS::getResults() const {
    return processes;
}
