#ifndef SCHEDULING_ALGORITHMS_H
#define SCHEDULING_ALGORITHMS_H

#include <string>
#include <vector>
using namespace std;

class Process {
public:
    string pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;

    Process(string pid = "", int at = 0, int bt = 0);
};

class SchedulerFCFS {
private:
    vector<Process> processes;

public:
    void addProcess(const Process &p);
    void runFCFS();                     // chỗ chạy thuật toán FCFS
    vector<Process> getResults() const; // lấy kết quả sau khi chạy
};

#endif // SCHEDULING_ALGORITHMS_H
