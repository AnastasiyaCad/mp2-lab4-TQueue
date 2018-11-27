#include"processor.h"
#include<ctime>


Task TCPU::TaskGeneration() 
{
	srand((unsigned int)time(NULL));
//	double num = rand();
	//double x = num / RAND_MAX;
	int num = rand() % 9 + 1;
	if (num < (IntensityQueue))
	{
		srand((unsigned int)time(NULL));
		Task Task;
		int core = rand() % 9 + 1;
		Task.Core = core;
		return Task;
	}
	else
	{
		Task Task;
		Task.Core = 0;
		return Task;
	}
}

void TCPU::Wait(int Tact, TQueue<Task> &q, Processor &pr)
{
	for (int i = 0; i < Tact; i++)
	{
		if (!q.IsFull()) {
			Task taskw;
			taskw = TaskGeneration();
			if (taskw.Core != 0)
				q.Push(taskw);
		}
		else qer++;
		if (q.IsEmpty())
			ProstoyQ++;
		else {
			for (int i = 0; i < q.Size(); i++)
			{
				Task taskq;
				taskq = q.Check();
				if (taskq.Core <= pr.Core) {
					pr.Core -= taskq.Core;
					pr.proc.push_back(taskq);
					q.Pop();
					TaskKol++;

				}
				else
					if (taskq.Core > pr.Core)
					{
						q.Pop();
						TaskKolProst++;
					}
					else break;
			}
		}

		if (pr.proc.size() != 0)
		{
			list<Task>::iterator it;
			for (it = pr.proc.begin(); it != pr.proc.end(); it++)
			{


				//it = ip.begin();
				(*it).Tact++;
				srand((unsigned int)time(NULL));
				int tmp = rand() % 9 + 1;

				if ((double)tmp / 10 < IntensityProc)
				{
					Task task2;
					task2 = (*it);
					if (task2.Tact == 1)
					{
						continue;
					}
					completed++;
					pr.proc.erase(it);
					pr.Core += task2.Core;
					NumberOfCycle += task2.Tact;
				}
			}
		}
		else ProstoyPr++;
	}
	Print(TaskKolProst, ProstoyQ, ProstoyPr, Time, completed, NumberOfCycle);
}



void TCPU::ProcWork(int _size, int _time, int _core, double _IntensityProc, double _IntensityQueue)
{
	Processor Proc;
	Proc.Core = _core;
	Size = _size;
	Time = _time;
	IntensityProc = _IntensityProc;
	IntensityQueue = _IntensityQueue;
	TQueue<Task> q2(Size);
	Wait(Time, q2, Proc);
}