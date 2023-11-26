/*
* File: sjf.cpp
* Author: Raphael Light
* 
* Shortest-Job-First (SJF) CPU Scheduling Algorithm.
*/

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void SJFNonPreempt(int);
void SJFPreempt(int);

int main()
{
    int numOfProcesses = 5;
    SJFPreempt(numOfProcesses);
    return 0;
}

void SJFNonPreempt(int numOfProcesses)
{
    int pid[numOfProcesses];
    int unsortedBurstTime[numOfProcesses], sortedBurstTime[numOfProcesses];
    int waitTime[numOfProcesses];

    // Initialize Process Burst Times.
    for(int i = 0; i < numOfProcesses; i++)
    {
        cout << "Enter the Burst Time of Process P" << i + 1 << ": ";
        cin >> sortedBurstTime[i];
        unsortedBurstTime[i] = sortedBurstTime[i];
    }
    cout << endl;

    // Sort Burst Times in Ascending Order.
    sort(sortedBurstTime, sortedBurstTime + numOfProcesses);

    // Sort and Initialize Process IDs.
    for(int i = 0; i < numOfProcesses; i++)
    {
        for(int j = 0; j < numOfProcesses; j++)
        {
            if(sortedBurstTime[i] == unsortedBurstTime[j])
                pid[i] = j + 1;
        }
    }

    // Compute Waiting Times.
    int wait_time = 0;
    waitTime[0] = wait_time;
    for(int i = 0; i < numOfProcesses - 1; i++)
    {
        wait_time += sortedBurstTime[i];
        waitTime[i + 1] = wait_time;
    }

    // Sort Waiting Times According to Process IDs.
    int waitTime_[numOfProcesses];
    for(int i = 0; i < numOfProcesses; i++)
    {
        waitTime_[i] = waitTime[i];
    }
    for(int i = 0; i < numOfProcesses; i++)
    {
        waitTime[pid[i] - 1] = waitTime_[i];
    }

    // Display Results.
    cout << "Process ID" << "  |  " << "Burst Time (ms)" << "  |  " << "Waiting Time (ms)" << endl;
    for(int i = 0; i < numOfProcesses; i++)
    {
        cout << setw(6) << "P" << i + 1 << setw(14) << unsortedBurstTime[i] << setw(15) << waitTime[i] << endl;
    }
    cout << endl;

    float totalWaitTime = 0;
    for(int i = 0; i < numOfProcesses; i++)
        totalWaitTime += waitTime[i];
    double averageWaitTime = totalWaitTime / static_cast<float>(numOfProcesses);
    cout << "Average Waiting Time: " << setprecision(2) << averageWaitTime << " ms" << endl << endl;
}

void SJFPreempt(int numOfProcesses)
{
    int burstTime[numOfProcesses], arrivalTime[numOfProcesses], burst_time[numOfProcesses];
    int totalWaitingTime[numOfProcesses], waitTime[numOfProcesses], numOfMillisecs[numOfProcesses];
    int turnaroundTime[numOfProcesses], completionTime[numOfProcesses];

    // Initialize Process Burst Time and Arrival Time.
    for(int i = 0; i < numOfProcesses; i++)
    {
        cout << "Enter the Burst Time of Process P" << i + 1 << ": ";
        cin >> burstTime[i];
        burst_time[i] = burstTime[i];
    }
    cout << endl;
    for (int i = 0; i < numOfProcesses; i++)
    {
        cout << "Enter the Arrival Time of Process P" << i + 1 << ": ";
        cin >> arrivalTime[i];
    }
    cout << endl;

    // PROCESS EXECUTION
    // Initialize Max Burst Time and Max Arrival Time.
    int totalBurstTime = 0, maxArrivalTime, maxBurstTime;
    for(int i = 0; i < numOfProcesses; i++)
    {
        totalBurstTime += burstTime[i];
        maxArrivalTime = arrivalTime[i] + 1;
        if(arrivalTime[i] < arrivalTime[(i + 1) % numOfProcesses])
            maxArrivalTime = arrivalTime[(i + 1) % numOfProcesses] + 1;
    }
    maxBurstTime = totalBurstTime;

    // Initialize Total Waiting Time and the Number of Millisecs a process has executed to 0.
    for(int j = 0; j < numOfProcesses; j++)
    {
        totalWaitingTime[j] = 0;
        numOfMillisecs[j] = 0;
    }

    int process_id;
    int arrival_id;
    int i = 0; // Arrival Time Counter
    totalBurstTime = 1;
    while(totalBurstTime <= maxBurstTime)
    {
        i = i % maxArrivalTime;

        // Find the Arrival ID of a process that arrives at time i.
        for(int j = 0; j < numOfProcesses; j++) 
        {
            if(i == arrivalTime[j])
                arrival_id = j;
        }

        // A special case to execute a process that arrives at time 0 at the beginning of thread processing.
        if(totalBurstTime == 1) 
        {
            int arrival_time[numOfProcesses];
            for (int j = 0; j < numOfProcesses; j++) // Copy Arrival Times.
            {
                arrival_time[j] = arrivalTime[j];
            }
            sort(arrival_time, arrival_time + numOfProcesses); // Sort Copied Arrival Times.
            
            // Execute the first process to arrive until the arrival of the second process.
            process_id = arrival_id;
            burstTime[process_id] -= arrival_time[1];
            i += arrival_time[1];
            totalBurstTime += arrival_time[1];

            // Record Process Completion Time.
            if(burstTime[process_id] == 0)
                completionTime[process_id] = totalBurstTime;

            // Record Process Waiting Time.
            for(int k = 0; k < numOfProcesses; k++)
            {
                if(burstTime[k] > 0)
                    totalWaitingTime[k] += arrival_time[1];
            }
        }

        // Arrival Preemption 
        if(burstTime[process_id] > burstTime[arrival_id] && burstTime[arrival_id] > 0) 
        {
            numOfMillisecs[process_id] = burstTime[process_id];
            process_id = arrival_id;
        }

        // Preemption when a process is finished (or is a zombie) or when Process ID is the same as Arrival ID.    
        if(burstTime[process_id] <= 0 || process_id == arrival_id)
        {
            int temp = process_id;
            for(int k = 0; k < numOfProcesses; k++)
                if(burstTime[process_id] <= 0 || (burstTime[process_id] > burstTime[k] && burstTime[k] > 0))
                {
                    process_id = k;
                    burstTime[process_id];
                }
            if(burstTime[temp] > 0 && temp != process_id)
                numOfMillisecs[temp] = burstTime[temp];
        }
        
        burstTime[process_id] -= 1; // Decrement Process Burst Time.

        // Record Process Completion Time.
        if(burstTime[process_id] == 0)
            completionTime[process_id] = totalBurstTime;

        // Record Process Waiting Time.
        for(int k = 0; k < numOfProcesses; k++)
        {
            if(k != process_id && burstTime[k] > 0)
                totalWaitingTime[k] += 1;
        }

        i++;
        totalBurstTime++;
    }

    // Compute Waiting Time and Turnaround Time.
    for(int j = 0; j < numOfProcesses; j++)
        if(numOfMillisecs[j] != 0)
            numOfMillisecs[j] = burst_time[j] - numOfMillisecs[j];
    for(int j = 0; j < numOfProcesses; j++)
    {
        waitTime[j] = totalWaitingTime[j] - numOfMillisecs[j] - arrivalTime[j];
        turnaroundTime[j] = completionTime[j] - arrivalTime[j];
    }

    // Display Results.
    cout << "Process ID" << "  |  " << "Burst Time (ms)" << "  |  " << "Arrival Time (ms)" << "  |  " << "Waiting Time (ms)" << "  |  " << "Turnaround Time (ms)" << endl;
    for(int j = 0; j < numOfProcesses; j++)
        cout << setw(5) << "P" << j + 1 << setw(17) << burst_time[j] << setw(20) << arrivalTime[j] << setw(22) << waitTime[j] << setw(24) << turnaroundTime[j] << endl;
    cout << endl;

    float totalWaitTime = 0;
    for(int j = 0; j < numOfProcesses; j++)
        totalWaitTime += waitTime[j];
    float averageWaitTime = totalWaitTime / static_cast<float>(numOfProcesses);
    cout << "Average Waiting Time: " << setprecision(2) << averageWaitTime << " ms" << endl << endl;
}