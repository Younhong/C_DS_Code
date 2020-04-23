#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
int n = 7;
int graph[MAX_VERTICES][MAX_VERTICES] = { { 0, 1, 1, 0, 0, 1 }, { 0, 0, 1, 1 }, { 0 }, { 1, 0, 1 }, { 0, 0, 1, 0, 0, 0, 1 }, { 1, 0, 1 }, { 0, 0, 0, 1, 1 } };
int visited[MAX_VERTICES];

void reset(int flag[], int size);
void dfs(int v);

int main()
{
	int i = 0;
	for (i = 0; i < n; i++) {
		reset(visited, n);
		printf("dfs(%d): ", i);
		dfs(i);
		printf("\n");
	}
	system("PAUSE");

	return 0;
}

void reset(int flag[], int size) {
	for (int i = 0; i < size; i++)
		flag[i] = 0;

	return;
}

void dfs(int v) {
	if (visited[v])
		return;
	visited[v] = 1;
	printf(" %5d", v);
	for (int i = 0; i < 7; i++) {
		if (graph[v][i] == 1)
			dfs(i);
	}

	return;
}