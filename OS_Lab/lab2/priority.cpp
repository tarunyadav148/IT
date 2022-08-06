#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Process
{
public:
    int process_id;
    int burst_time;
    int priority;

    Process(int process_id, int burst_time, int priority)
    {
        this->process_id = process_id;
        this->burst_time = burst_time;
        this->priority = priority;
    }
};

void waitingTime(vector<Process> &process, int waitingtime[])
{
    int n = process.size();
    waitingtime[0] = 0;
    for (int i = 1; i < n; i++)
        waitingtime[i] = process[i - 1].burst_time + waitingtime[i - 1];
}

void turnAroundTime(vector<Process> &process, int waitingtime[], int tat[])
{
    int n = process.size();
    for (int i = 0; i < n; i++)
        tat[i] = process[i].burst_time + waitingtime[i];
}

void averageTime(vector<Process> &process)
{
    int n = process.size();

    int waitingtime[n], tat[n], total_waitingtime = 0, total_tat = 0;

    waitingTime(process, waitingtime);

    turnAroundTime(process, waitingtime, tat);

    cout << "\nProcesses "
         << " Burst time "
         << " Waiting time "
         << " Turn around time\n";

    for (int i = 0; i < n; i++)
    {
        int n = process.size();
        total_waitingtime = total_waitingtime + waitingtime[i];
        total_tat = total_tat + tat[i];
        cout << " " << process[i].process_id << "\t\t" << process[i].burst_time << "\t " << waitingtime[i] << "\t\t " << tat[i] << endl;
    }

    cout << "\nAverage waiting time = " << (float)total_waitingtime / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n << endl;
}
void scheduling(vector<Process> &process)
{
    int n = process.size();
    sort(process.begin(), process.end(), [](Process a, Process b)
         { return (a.priority > b.priority); });

    cout << "Order in which processes gets executed \n";

    for (int i = 0; i < n; i++)
        cout << process[i].process_id << " ";

    averageTime(process);
}

int main()
{
    vector<Process> process = {Process(1, 10, 2), Process(2, 5, 0), Process(3, 8, 1)};

    scheduling(process);

    return 0;
}