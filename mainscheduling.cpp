#include <iostream>
#include <vector>
#include <string>
#include "scheduling_algorithms.h"

using namespace std;

int main()
{
    // Tạo scheduler FCFS
    SchedulerFCFS scheduler;

    // Dữ liệu kiểm chứng từ textbook
    scheduler.addProcess(Process("P1", 0, 4));
    scheduler.addProcess(Process("P2", 1, 3));
    scheduler.addProcess(Process("P3", 2, 2));
    scheduler.addProcess(Process("P4", 3, 1));

    // Chạy thuật toán FCFS
    scheduler.runFCFS();

    // Lấy kết quả
    vector<Process> results = scheduler.getResults();

    // In bảng kết quả ra console
    cout << "PID\tAT\tBT\tCT\tTAT\tWT" << endl;
    for (auto &p : results) {
        cout << p.pid << "\t"
             << p.arrivalTime << "\t"
             << p.burstTime << "\t"
             << p.completionTime << "\t"
             << p.turnaroundTime << "\t"
             << p.waitingTime << endl;
    }

    return 0;
}
