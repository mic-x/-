#include <stdio.h>

#define LEN 10

int main(){
	int a[LEN] = {2,5,6,5,9,3,5,6,8,4};
	int j,key,i;
	for(j=1;j<LEN;j++){
		key = a[j];
		i = j;
		while(i > 0 && key < a[i - 1]){
			a[i] = a[i - 1];
			--i;
		}
		a[i] = key;
	}
}

