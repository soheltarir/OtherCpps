/*This program creates a square checkered board with side N (N is taken as an user input), where each grid element is of size 1*1.
The program fills the grids with either black or white (0 or 1) randomly, the prints the possibility of reaching from top to bottom.*/


#include <iostream>
#include <time.h>
#include <stdio.h>
#define MAX 1000000000
using namespace std;

class WeightedQuickUnionUF {
private:
        int * id,* sz;
	int count;
public:
	int * fill;	
	WeightedQuickUnionUF(int N) {
		id = (int *) malloc (MAX*sizeof(int));
		sz = (int *) malloc (MAX*sizeof(int));
		fill = (int *) malloc (MAX*sizeof(int));
		if(id == NULL) exit (1);
		if(sz == NULL) exit (1);
		if(fill == NULL) exit(1);		
		count = N;
		srand(time(NULL));
		for (long i = 0; i < N; i++) {
			id[i] = i;
			sz[i] = 1;
			fill[i] = rand()%2;
			}
	}
	~WeightedQuickUnionUF(){
		free (id);
		free (sz);
		free (fill);
	}
	int Count() {
		return count;
	}
	int find(int p) {
		while (p != id[p])
			p = id[p];
		return p;
	}
	bool connected(int p, int q) {
		return find(p) == find(q);
	}
	void Union(int p, int q) {
		int i = find(p);
		int j = find(q);
		if (i == j) return;
		
		if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
		else 			   { id[j] = i; sz[i] += sz[j]; }
		count --;
		}
};

int main() {
	long N;
	cout << "Enter the Dimension of the Square Grid:";
	cin >> N;
	WeightedQuickUnionUF uf(N*N);
	for (long i = 0; i < N*N; i++) {
		/*if (i % N == 0) cout << endl;
		if (uf.fill[i] == 1) cout << "*";
		else		      cout << "o";
		*/
		if ((i > 0)&&(i%N != 0))		
			if (uf.fill[i] == uf.fill[i-1]) 
				uf.Union(i, i-1);
		if ((i < N*N - 1)&&(i%N != N-1))		
			if (uf.fill[i] == uf.fill[i+1]) 
				uf.Union(i, i+1);
		if (i > N-1)
			if (uf.fill[i] == uf.fill[i-N]) 
				uf.Union(i, i-N);
		if (i < N*(N-1))		
			if (uf.fill[i] == uf.fill[i+N]) 
				uf.Union(i, i+N);
	}
	bool bFlag = false;
	for (long i = N*(N-1); i < N*N; i++) {
		
		if ((uf.find(i) < N)&&(uf.fill[i] == 1)){
			bFlag = true;
			break;
		}
	}
	if (bFlag == true)
		cout << endl << "Top and bottom are connected!" << endl;
	else
		cout << endl << "Top and bottom are not connected!" << endl;

	return 0;
}
