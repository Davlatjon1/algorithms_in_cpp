#include<iostream>
const int m=3, n=5;
void inparr(int a[m][n]){
	int i,j;
	for (i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
}

void outarr(int a[m][n]){
	int i,j;
	printf("Matrica:\n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

int processarr(int a[m][n]){
	int i,j,s,max;
	for(i=0;i<m;i++){
		s=0;
		for(j=0;j<n;j++){
			s+=a[i][j];
		}
		if (i==0) max=s;
		else if (max<s) max=s;
	}
	return max;
}

int main(){
	int b[m][n];
	inparr(b);
	outarr(b);
	printf("Maximalnaya summa stroki = %d", processarr(b));
}
