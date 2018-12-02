#ifndef __TJOBSTREAM_H__
#define __TJOBSTREAM_H__

#include<list>
#include<iostream>
#include<cstdlib>
#include<iterator>

#include "queue.h"

using namespace std;

struct Task
{
	int Core = 0;
	int Tact = 0;
};

struct Processor
{
	list <Task> proc;
	int Core = 0;
};

class TCPU
{
	int Time; 
	double IntensityProc; //введенная пользователем интенсивность процессора
	double IntensityQueue;//введенная пользователем интенсивность очереди 
	int ProstoyPr; // простой в процессоре
	int ProstoyQ; // простой в очереди
	int Size;
	int qer = 0; 
	int TaskKol = 0;
	int TaskKolProst = 0;
	int NumberOfCycle = 0;
	int completed = 0;

public:
	Task TaskGeneration();
	void Wait(int Tact, TQueue<Task> &q, Processor &pr);
	void ProcWork(int _size, int _time, int _core, double _IntensityProc, double _IntensityQueue);
	void Print(int TaskKolProst, int ProstoyQ, int ProstoyPr, int Time, int completed, int NumberOfCycle)
	{
		cout << "Statistics:" << endl;
		cout << "Number of tasks received in the computer system: " << TaskKolProst << endl;
		if (TaskKolProst != 0)
			cout << "Number of failures in sevice job: " << (ProstoyQ * 100 / TaskKolProst) << "%" << endl;
		else
			cout << "Number of failures in sevice job: " << 0 << endl;
		cout << "Idle clock cycles: " << (ProstoyPr * 100 / Time) << "%" << endl;
		if (completed != 0)
			cout << "Average time of task execution: " << (double(Time - ProstoyPr) / double(completed)) << endl;
		else
			cout << "Average time of task execution: " << 0 << endl;
		cout << "Task comleted: " << completed << endl;
		cout << "Total cycles: " << NumberOfCycle << endl;
	}
};

#endif