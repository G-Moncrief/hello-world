#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<class T>
void reverseStack (stack<T> &q)
{
	queue<T> S;
	while (!q.empty()){
		S.push(q.top());
		cout << q.top() << endl;
		q.pop();
	}
	
	cout << "REVERSING STACK USING TEMP QUEUE" << endl;
	
	while (!S.empty()){
		q.push(S.front());
		S.pop();
	}
}
	
int main ()
{
	stack <int> teststack;
	teststack.push(1);
	teststack.push(2);
	teststack.push(3);
	teststack.push(4);
	teststack.push(5);
	
	reverseStack(teststack);
	
	while (!teststack.empty()){
		cout << teststack.top() << endl;
		teststack.pop();
	}
}
