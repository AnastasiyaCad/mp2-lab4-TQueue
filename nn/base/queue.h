#ifndef __QUEUE_H__
#define __QUEUE_H__

const int MaxQueueSize = 100;

template <class T>
class TQueue
{
	T *pMem;
	int MemSize;
	int begin;
	int end;
	int DataCount;
public:
	TQueue()
	{
		MemSize = MaxQueueSize; 
		DataCount = 0;
		begin = 0;
		end = 0;
		pMem = new T[MemSize];
	}
	TQueue(int _MemSize)
	{
		if ((_MemSize > 1) && (_MemSize <= MaxQueueSize))
		{
			MemSize = _MemSize;
				DataCount = 0;
				begin = 0;
				end = 0;
				pMem = new T[MemSize];
		}
		else throw "size";
	}

	//TQueue<T>::TQueue(const TQueue<T> &_TQueue) //Конструктор копирования.
	//{
	//	MemSize = _TStack.MemSize;
	//	DataCount = _TStack.DataCount;
	//	begin = _TStack.begin;
	//	end = _TStack.end;
	//	pMem = new T[MemSize];
	//}

	/*TQueue<T>& TQueue<T>::operator=(const TQueue<T> &_TQueue)//оператор присваивания
	{
		if (this == &_TQueue)
			return*this;
		if (size != _TQueue.size)
		{
			size = _TStack.size;
			delete[]pMem;
			pMem = new T[size];
		}
		top = _TStack;
		for (int i = 0; i < size; i++)
			pMem[i] = _TStack.pMem[i];
		return *this;
	}*/

	~TQueue()
	{
		delete[] pMem;
	}

	bool IsEmpty() { 
		return DataCount == 0;
	}

	bool IsFull() { //заполнена ли память
		return DataCount == MemSize;
	}


	T Pop() { //берет элемент
		if (!IsEmpty()) {
			//T res = pMem[begin++];
			T res = pMem[begin];
			begin++;
			DataCount--;
			if (begin > MemSize-1)
				begin = 0;
			return res;
			//end -= MemSize + 1;
		}
		else throw "error";
	}
	void Push(T v) {//положить элемент
		if (!IsFull()) {
			pMem[end++] = v;
			DataCount++;
			if (end > MemSize-1)
				end = 0; //end -= MemSize + 1;
		}
		else throw "ERROR! The queue is full ";
	}

	

	int GetNextIndex(int index)
	{
		return (++index%MemSize);
	}

	T Check() {
		if (!IsEmpty()) return pMem[begin];
		else throw "error";
	}

	int Size() { return DataCount;}

};

#endif