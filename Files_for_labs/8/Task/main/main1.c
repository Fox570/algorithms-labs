#include <stdio.h>
#include <stdlib.h>

int in_arr(int el, int N, int arr[]);

int main() {
	int i, sum = 0;
	char flag = 0;
	int arr[] = {3, 0, 5, -1, -2, 5, 8, 6};
	const int N = sizeof(arr) / sizeof(arr[0]);

	// 1
	int min = abs(arr[0]);
	for (i=1; i<N; i++) {
		if (abs(arr[i]) < min)
			min = abs(arr[i]);
	}
	printf("min = %d\n", min); // 0
	
	// 2
	for (i=0; i<N; i++) {
		if (flag == 1)
			sum += abs(arr[i]);
		else if (arr[i] == 0)
			flag = 1;
	}
	printf("sum = %d\n", sum); // 22
	
	// 3
	short cnt;
	int sort_arr[N];
	for (i=0, cnt=0; i<N; i++) {
		if (i%2==0)
			sort_arr[cnt] = arr[i];
		else {
			sort_arr[N-1-cnt] = arr[i];
			cnt++;
		}
	}
	
	for (i=0; i<N; i++) {
		printf("%d ", sort_arr[i]);	
	}
	printf("\n"); // 3 5 -2 6 0 -1 8 

	// 4
	int set[N];
	for (i=0, cnt=0; i<N; i++) {
		if (!in_arr(arr[i], N, set))
			set[cnt++] = arr[i];
	}
	
	for (i=0; i<cnt; i++) {
		printf("%d ", set[i]);	
	}
	printf("\n");

	return 0;
}

int in_arr(int el, int N, int arr[]) {
	for (int i=0; i<N; i++) {
		if (arr[i] == el)
			 return 1;
	}
	return 0;
}
