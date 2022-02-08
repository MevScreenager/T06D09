#include<stdio.h>

int input(int *a, int *n);
void output(int *a, int *n);
void quick_sort(int *a, int first, int last);
void heapSort(int *a, int n);
void heapify(int *a, int n, int i);
void equat(int *a, int *b, int *n);

int main() {
    int NMAX = 10, data_1[NMAX], data_2[NMAX];
    if (input(data_1, &NMAX)) {
        equat(data_1, data_2, &NMAX);
        quick_sort(data_1, 0, NMAX - 1);
        output(data_1, &NMAX);
        printf("\n");
        heapSort(data_2, NMAX);
        output(data_2, &NMAX);

    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        if (!scanf("%d", p)) return 0;
        if ((int *) p  != p) return 0;
    }
    if (getchar() != 10) return 0;
    return 1;
}

void equat(int *a, int *b, int *n) {
    for (int i = 0; i < *n; i++)
        b[i] = a[i];
}

void quick_sort(int *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2];
        do {
            while (a[left] < middle)
                left++;
            while (a[right] > middle)
                right--;
            if (left <= right) {
                int time = a[left]; a[left] = a[right]; a[right] = time;
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(a, first, right);
        quick_sort(a, left, last);
    }
}

void heapSort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int time = a[0]; a[0] = a[i]; a[i] = time;
        heapify(a, i, 0);
    }
}

void heapify(int *a, int n, int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        int time = a[i]; a[i] = a[largest]; a[largest] = time;
        heapify(a, n, largest);
    }
}

void output(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        if (p - a == *n - 1) {
            printf("%d", *p);
            return;
        }
        printf("%d ", *p);
    }
}
