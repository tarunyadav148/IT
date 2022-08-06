//FCFS
#include<iostream>
using namespace std;

void find_waiting_time(int processes[], int n,
						int burst_time[], int waiting_time[])
{
	waiting_time[0] = 0;

	for (int i = 1; i < n ; i++ )
		waiting_time[i] = burst_time[i-1] + waiting_time[i-1] ;
}

void find_turn_around( int processes[], int n,
				int burst_time[], int waiting_time[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = burst_time[i] + waiting_time[i];
}

void find_avg_time( int processes[], int n, int burst_time[])
{
	int waiting_time[n], tat[n], total_waiting_time = 0, total_tat = 0;

	find_waiting_time(processes, n, burst_time, waiting_time);

	find_turn_around(processes, n, burst_time, waiting_time, tat);

	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";

	for (int i=0; i<n; i++)
	{
		total_waiting_time = total_waiting_time + waiting_time[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << burst_time[i] <<"\t "
			<< waiting_time[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_waiting_time / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

int main()
{
	int processes[] = { 1, 2, 3};
	int n = sizeof(processes) / sizeof(processes[0]);

	int burst_time[] = {9, 6, 11};

	find_avg_time(processes, n, burst_time);
	return 0;
}
