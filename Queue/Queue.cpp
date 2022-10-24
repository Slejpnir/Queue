// Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

const int QMAX = 100;

struct Queue
{
    int que[QMAX];
	int front;
	int rear;
};

void init(Queue	*q)
{
	q->front = 1;
	q->rear = 0;
}

void insert(Queue* q, int x)
{
	if (q->rear == QMAX - 1)
	{
		cout << "Queue is full" << endl;
		return;
	}
	q->rear++;
	q->que[q->rear] = x;
}

bool isEmpty(Queue* q)
{
	return q->front > q->rear;
}

int remove(Queue* q)
{
	int x;
	if (isEmpty(q))
	{
		cout << "Queue is empty" << endl;
		return -1;
	}
	x = q->que[q->front];
	for (int i = q->front; i < q->rear; i++)
	{
		q->que[i] = q->que[i + 1];
	}
	q->rear--;
	return x;
}

void print(Queue* q)
{
	int i;
	if (isEmpty(q))
	{
		cout << "Queue is empty" << endl;
		return;
	}
	for (i = q->front; i <= q->rear; i++)
	{
		cout << q->que[i] << " ";
	}
	cout << endl;
}

int main()
{
	Queue* q = new Queue;
	init(q);
	print(q);
	for (int i = 0; i < 10; i++)
	{
		insert(q, i);
	}
	cout << endl;
	print(q);
	for (int i = 0; i < 10; i++)
	{
		cout <<"Deleting element " << remove(q) << " "<<endl;
		print(q);
	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
