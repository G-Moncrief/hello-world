#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<class T>
void reverseQueue (queue<T> &q)
{
	stack<T> S;
	while (!q.empty()){
		S.push(q.front());
		cout << q.front() << endl;
		q.pop();
	}
	
	cout << "REVERSING QUEUE USING TEMP STACK" << endl;
	
	while (!S.empty()){
		q.push(S.top());
		S.pop();
	}
	
}

int main ()
{
	queue <int> testqueue;
	testqueue.push(1);
	testqueue.push(2);
	testqueue.push(3);
	testqueue.push(4);
	testqueue.push(5);
	
	reverseQueue(testqueue);
	
	while (!testqueue.empty()){
		cout << testqueue.front() << endl;
		testqueue.pop();
	}
	
}
