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

    for (int *p = a; p - a < *n; p++) {
        if (!scanf("%d", p)) return 0;
        if ((int *) p  != p) return 0;
    }
    if (!scanf("%d", m)) return 0;
    if ((int *) m  != m) return 0;
    if (getchar() == 10) return 0;
    return 1;
}

void move(int *a, int *n, int *m) {
    int arry[NMAX];
    for (int *p = m; p - a < *n; p++)
        arry[p - m] = *p;
    for (int *p = a; p - a < *m; p++)
        arry[n - m + (p - a)] = *p;
    for (int *p = a; p - a < *n; p++)
        *p = arry[p - a];
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
