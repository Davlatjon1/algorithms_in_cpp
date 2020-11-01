// linear search
#include<stdio.h>
using namespace std;
int main(){
	bool ResultOK = false;
	int index = -1, position=0;
	int n;
	scanf("%d", &n);
	int a[n];
	int key=7;
	for (int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	while(position<n && index==-1){
		if (a[position]==key){
			index = position;
			ResultOK = true;
		}
		position=position+1;
	}
	if (ResultOK) printf("Raspolojenie=%d; Pocisiya=%d", position, index);
}
