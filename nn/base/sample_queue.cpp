#include <iostream>
#include <string>
#include "processor.h"

using namespace std;

int main()
{
	int Qsize, time, cores;
	double processorInt, queueInt;
	cout << "Enter Qsize" << endl;
	cin >> Qsize;
	cout << "Enter cores" << endl;
	cin >> cores;
	cout << "Enter Intensivnost processora" << endl;
	cin >> processorInt;
	cout << "Enter Intensivnost queue " << endl;
	cin >> queueInt;
	cout << "Enter JobTime" << endl;
	cin >> time;
	TCPU proc1;
	proc1.ProcWork(Qsize, time, cores, processorInt, queueInt);
	return 0;
}
