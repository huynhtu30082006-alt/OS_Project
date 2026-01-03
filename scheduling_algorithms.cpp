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
    this->completionTime = 0;
    this->turnaroundTime = 0;
    this->waitingTime = 0;
}

void SchedulerFCFS::addProcess(const Process &p) {
    processes.push_back(p);
}

void SchedulerFCFS::runFCFS() {
    // 1) Sắp xếp các tiến trình theo thời điểm đến (arrivalTime)
    sort(processes.begin(), processes.end(), compareByArrival);

    int currentTime = 0;

    for (auto &p : processes) {
        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;
        }

        // Tính các giá trị cơ bản
        p.completionTime = currentTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;

        currentTime = p.completionTime;
    }
}

vector<Process> SchedulerFCFS::getResults() const {
    return processes;
}
