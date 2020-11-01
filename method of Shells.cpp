#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void ShellSort (int array[], int size)              
{
	int step, i, j, tmp;
	for (step = size / 2; step > 0; step /= 2)
		for (i = step; i < size; i++) 
			for (j = i - step; j >= 0 && array[j] > array[j + step]; j -= step)
			{
				tmp = array[j];
				array[j] = array[j + step];
				array[j + step] = tmp;
			}
}
int main(){
	int n;
	printf("N: ");
	scanf("%d",&n);
	srand(time(0));
	int a[n];
	for(int i=0; i<n; i++){
		a[i] = rand()%100 + 1;
		printf("%d ", a[i]);
	}
	printf("\n");
	float start = clock();
	ShellSort(a, n);
	float end = clock();
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n========================");
	printf("\nTime spent - %f", start-end);
}
