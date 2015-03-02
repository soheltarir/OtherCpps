#include <iostream>
#include <ctime>
using namespace std;

const int nLimit = 10000;

class QuickUnion
{
	public: int id[nLimit];
	public: int fill[nLimit];
	
	public: QuickUnion(int N)
	{
		for (int i = 0; i < N; i++)
		{
			id[i] = i;
						
			fill[i] = rand() % 2;
		}
	}
	
	private: int root(int i)
	{
		while (i != id[i]) i = id[i];
		return i;
	}

	public: bool connected(int p, int q)
	{
		return id[p] == id[q];
	}

	public: void Union(int p, int q)
	{
		int i = root(p);
		int j = root(q);
		id[i] = j;
	}
};

int main()
{
	int N;
	cout << "Enter Side of Square" << endl;
	cin >> N;
	QuickUnion obj(N*N);
	for (int i = 0; i < N*N; i++)
	{
		if ((obj.fill[i] == obj.fill[i+1])&&(obj.id[i] != obj.id[i+1])&&(i < N*N))
			obj.Union(i, i+1);
		else if ((obj.fill[i] == obj.fill[i+N])&&(obj.id[i] != obj.id[i+N])&&(i < N*N))
			obj.Union(i, i+N);
	}
	for (int i = 0; i < N*N; i++)
	{
		if (i%N == 0)
			cout << endl;
		if (obj.fill[i] == 0)
			cout << "X";
		else if (obj.fill[i] == 1)
			cout << "O";
	}
	cout << endl;
	int Flag = 1;
	for (int i = (N-1)*N; i < N*N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (obj.connected(i, j) && obj.fill[i])
			{
				Flag = 0;
				break;
			}
		}
		if (Flag == 0)
			break;
	}
	if (Flag == 0)
		cout << "Top and Bottom are connected" << endl;
	else
		cout << "Top and Bottom are not connected" << endl;
	
	return 0;
}
