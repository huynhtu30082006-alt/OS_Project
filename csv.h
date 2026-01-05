#pragma once
#ifndef CSV_H
#define CSV_H

#include <string>
#include <vector>

struct Process {
    std::string process; 
    int arrival;         
    int burst;           
};

std::vector<Process> readCSV(const std::string& filename);
bool validateCSV(const std::vector<Process>& list);

#endif
