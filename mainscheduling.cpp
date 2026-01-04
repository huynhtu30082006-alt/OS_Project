#include <iostream>
#include <vector>
#include <string>
#include "scheduling_algorithms.h"

using namespace std;

int main()
{
    int numOfProcesses;
    cout << "Enter number of processes: ";
    cin >> numOfProcesses;

    SchedulerFCFS scheduler;

    for (int i = 0; i < numOfProcesses; i++) {
        string name;
        int at, bt;
        cout << "\nEnter name of process " << i + 1 << ": ";
        cin >> name;
        cout << "Enter Arrival Time: ";
        cin >> at;
        cout << "Enter Burst Time: ";
        cin >> bt;

        scheduler.addProcess(Process(name, at, bt));
    }

    // Chạy thuật toán FCFS
    scheduler.runFCFS();

    // In kết quả
    vector<Process> results = scheduler.getResults();

    cout << "\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n";
    for (auto &p : results) {
        cout << p.pid << "\t"
             << p.arrivalTime << "\t"
             << p.burstTime << "\t"
             << p.startTime << "\t"
             << p.completionTime << "\t"
             << p.turnaroundTime << "\t"
             << p.waitingTime << "\t"
             << p.responseTime << endl;
    }

    return 0;
}
