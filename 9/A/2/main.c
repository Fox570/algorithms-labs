#include <stdio.h>
#include <stdlib.h>

int contains(int *arr, int N, int el);
int *set(int arr[], int N, int *out_size);

int main() {
	int a[] = {3, 1, 5, -1, -2, 5, 8, 6};
	int N = sizeof(a) / sizeof(a[0]);

	int unique_size = 0;
	int *s = set(a, N, &unique_size);
	printf("unique_size = %d\n", unique_size);

	for (int i=0; i<unique_size; i++) {
		printf("%d ", s[i]);
	}

	free(s);
	return 0;
}

int contains(int arr[], int N, int el) {
	for (int i=0; i<N; i++) {
		if (arr[i] == el)
			return 1;
	}
	return 0;
}

int *set(int arr[], int N, int *out_size) {
	int *unique = NULL;
	int unique_cnt = 0;

	for (int i=0; i<N; i++) {
		if (!contains(unique, unique_cnt, arr[i])) {
			int *tmp = realloc(unique, (unique_cnt+1) * sizeof(int));
			if (tmp == NULL) {
				free(unique);
				fprintf(stderr, "Memory allocation error\n");
				return NULL;
			}
			unique = tmp;
			unique[unique_cnt++] = arr[i];
		}
	}

	*out_size = unique_cnt;
	return unique;
}