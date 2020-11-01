#include<stdio.h>
#include<time.h>
#include<cstdlib>
#include<fstream>
using namespace std;
fstream in_file; 

void Output(int i, bool found){
	if (found){
		printf("������� ������, ������ ��������: %d\n",i); in_file<<"������� ������, ������ ��������: "<<i<<"\n";
	}else{
		printf("������� �� ������!\n"); in_file<<"������� �� ������!\n";
	}
}
void _sort(int a[], int size){
	int temp;
	for(int i=0; i < size-1; i++){
		for(int j=0; j < size-i-1; j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
void Fast_Posledovatelniy(int n, int Key, int A[],bool found=false){
	clock_t time;
	time = clock();
	int i=0;
	while(A[i]!=Key) i++;
	printf("\n�����: ������� ���������������� �����\n"); in_file<<"\n�����: ������� ���������������� �����\n";
	if(i<n) found=true;
	Output(i,found);
	time = clock() - time;
	printf("%f\n\n", (double)time/CLOCKS_PER_SEC); in_file<<(double)time/CLOCKS_PER_SEC<<"\n\n";
}
void Posledovatelniy(int n, int Key, int A[], bool found=false){
	clock_t time;
	time = clock();
	int i=0;
	while(A[i]!=Key && i<n) i++;
	printf("\n�����: ���������������� �����\n"); in_file<<"\n�����: ���������������� �����\n";
	if(A[i]==Key) found=true;
	Output(i,found);
	time = clock() - time;
	printf("%f\n\n", (double)time/CLOCKS_PER_SEC); in_file<<(double)time/CLOCKS_PER_SEC<<"\n\n";
}
void Fast_Binary(int n, int Key, int A[], bool found=false){
	clock_t time;
	time = clock();
	int l=0,mid,r=n-1, i=0;
	_sort(A,n);
	printf("\n�����: �������� �����\n"); in_file<<"\n�����: �������� �����\n";
	while(l<=r){
		mid=(l+r)/2;
		if(A[mid]==Key){
			i=mid;
			found=true;
			break;
		}
		if(A[mid]>Key) r=mid-1;
		else l=mid+1;
	}
	Output(i,found);
	time = clock() - time;
	printf("%f\n\n", (double)time/CLOCKS_PER_SEC); in_file<<(double)time/CLOCKS_PER_SEC<<"\n\n";
}
void Start(){
	in_file.open("lab_r2.txt", ios::out);
	int n,key;
	srand(time(0));
	scanf("%d",&n); in_file<<"���������� ���������: "<<n<<"\n��������: ";
	int a[n];
	for(int i=0;i<n;i++){
		a[i]=rand()%n+1;
		printf("%d ",a[i]); in_file<<a[i]<<" ";
	}printf("\n");
	scanf("%d",&key);   in_file<<"\n����: "<<key;
	
	Posledovatelniy(n,key,a,in_file);
	Fast_Posledovatelniy(n,key,a,in_file);
	Fast_Binary(n,key,a,in_file);
}
int main(){
	setlocale(LC_ALL,"Russian");
	Start();
}
