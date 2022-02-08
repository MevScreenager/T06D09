#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int *length, int *sum);
int sum_numbers(int *buffer, int *length);
void find_numbers(int* buffer, int *length_in, int number, int *numbers, int *length_out);

int main() {
    int n_in, data_1[NMAX], sum, data_2[NMAX], n_out = 0;
    if (input(data_1, &n_in)) {
        sum = sum_numbers(data_1, &n_in);
        find_numbers(data_1, &n_in, sum, data_2, &n_out);
        output(data_2, &n_out, &sum);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    if (!scanf("%d", n)) return 0;
    if ((int *) n  != n) return 0;

    for (int *p = a; p - a < *n; p++) {
        scanf("%d", p);
        if (!scanf("%d", p)) return 0;
        if ((int *) p  != p) return 0;
        if (getchar() != 10) return 0;
    }
    if (getchar() != 10) return 0;
    return 1;
}

int sum_numbers(int *buffer, int *length) {
    int sum = 0;
    for (int i = 0; i < *length; i++)
        if (buffer[i] % 2 == 0)
            sum = sum + buffer[i];
    return sum;
}

void find_numbers(int* buffer, int *length_in, int number, int *numbers, int *length_out) {
    for (int i = 0; i < *length_in; i++)
        if (number % buffer[i] == 0) {
            numbers[*length_out] = buffer[i];
            (*length_out)++;
        }
}

void output(int *a, int *n, int *sum) {
    printf("%d\n", *sum);
    if (*n == 0) {printf("%d", 0); return;}
    for (int *p = a; p - a < *n; p++) {
        if (p - a == *n - 1) {
            printf("%d", *p);
            return;
        }
        printf("%d ", *p);
    }
}
