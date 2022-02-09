#include<stdio.h>
#define NMAX 10

int input(int *a, int *n, int *m);
void output(int *a, int *n);
void move(int *a, int *n, int *m);

int main() {
    int n, data[NMAX], m;
    if (input(data, &n, &m)) {
        move(data, &n, &m);
        output(data, &n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n, int *m) {
    if (!scanf("%d", n)) return 0;
    if ((int *) n  != n) return 0;
    if (*n < 0) return 0;

    for (int *p = a; p - a < *n; p++) {
        if (!scanf("%d", p)) return 0;
        if ((int *) p  != p) return 0;
        if (p - a < *n - 1 && getchar() == 10) return 0;
    }
    if (!scanf("%d", m)) return 0;
    if ((int *) m  != m) return 0;
    if (getchar() != 10) return 0;
    return 1;
}

void move(int *a, int *n, int *m) {
    int arry[NMAX];
    if (*m > 0) {
        for (int *p = &a[*m]; p - a < *n; p++)
            arry[p - &a[*m]] = *p;
        for (int *p = a; p - a < *m; p++)
            arry[(*n - *m) + (p - a)] = *p;
        for (int *p = a; p - a < *n; p++)
            *p = arry[p - a];
    } if (*m < 0) {
        for (int *p = &a[*n - (-1 * *m)]; p - a < *n; p++)
            arry[p - &a[*n - (-1 * *m)]] = *p;
        for (int *p = a; p - a < *n - (-1 * *m); p++)
            arry[(-1 * *m) + (p - a)] = *p;
        for (int *p = a; p - a < *n; p++)
            *p = arry[p - a];
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
