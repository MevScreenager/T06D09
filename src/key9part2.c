#include <stdio.h>

#define LEN 100

void sum(int *buff1, int *buff2, int *len1, int *len2);
void sub(int *buff1, int *buff2, int *len1, int *len2);
int input(int *a, int *b, int *len1, int *len2);
void output(int *a);
int max(int l1, int l2);
void move(int *a, int m);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/

int main() {
    int data_1[LEN], data_2[LEN], len1 = 0, len2 = 0;
    if (input(data_1, data_2, &len1, &len2)) {
      sum(data_1, data_2, &len1, &len2);
      sub(data_1, data_2, &len1, &len2);
    } else {
        printf("n/a");
    }
    return 0;
}

int max(int l1, int l2) {
  if (l1 > l2)
    return l1;
  return l2;
}

int input(int *a, int *b, int *len1, int *len2) {
    for (int *p = a; p - a < LEN; p++) {
        if (!scanf("%d", p)) return 0;
        if ((int *) p  != p) return 0;
        if (*p < -9 || *p > 9) return 0;
        (*len1)++;
        if (getchar() == 10) break;
    }
    for (int *p = &a[*len1]; p - a < LEN; p++) *p = 0;
    for (int *p = b; p - b < LEN; p++) {
        if (!scanf("%d", p)) return 0;
        if ((int *) p  != p) return 0;
        if (*p > 9|| *p < 0) return 0;
        (*len2)++;
        if (getchar() == 10) break;
    }
    for (int *p = &b[*len2]; p - b < LEN; p++) *p = 0;
    if (getchar() != 10) return 0;
    return 1;
}

void sum(int *buff1, int *buff2, int *len1, int *len2) {
  int result[LEN], number = 0;
  move(buff1, -(LEN - *len1 - 1));
  move(buff2, -(LEN - *len2 - 1));

  for (int *m = &result[LEN - 1]; m - result + 1>= 0; m--)
    for (int *p = &buff1[LEN - (&result[LEN - 1] - m + 1)]; p - buff1 >= 0; p--) {
      for (int *l = &buff2[LEN - (&result[LEN - 1] - m + 1)]; l - buff2 >= 0; l--) {
        *m = (*p + *l) % 10 + number;
        printf("*m: %d\t*p: %d\t*l: %d\t*p + *l: %d\t*number: %d\n", *m, *l, *p, *p + *l, number);
        if (*p + *l > 9) number = 1;
        else
        number = 0;
        break;
      }
      break;
    }
  if (number) result[0] = number;
  output(result);
  printf("\n");
}


void move(int *a, int m) {
    int arry[LEN];
    for (int *p = &a[LEN + m + 1]; p - a < LEN; p++)
        arry[p - &a[LEN + m + 1]] = *p;
    for (int *p = a; p - a < LEN + m; p++)
        arry[(-1 * m) + (p - a)] = *p;
    for (int *p = &a[0]; p - a < LEN; p++)
        *p = arry[p - &a[0]];
}

void sub(int *buff1, int *buff2, int *len1, int *len2) {
  int result[LEN], number = 0, count = 0;
  if (len1 < len2) {
    printf("n/a");
    return;
  }
  for (int *m = &result[LEN - 1]; m - result >= 0; m--)
    for (int *p = &buff1[LEN - (&result[LEN - 1] - m)]; p - buff1 >= 0; p--) {
      for (int *l = &buff2[LEN - (&result[LEN - 1] - m)]; l - buff2 >= 0; l--) {
        *m = *p - *l + number;
        if (*p - *l < 0) number = -1;
        else
        number = 0;
        count++;
        break;
      }
      break;
    }
  output(result);
}

void output(int *a) {
  int t = 0;
    for (int *p = a; p - a < LEN; p++) {
        if (p - a == LEN - 1) {
            printf("%d", *p);
            return;
        }
        if (a[p - a] != 0) t = 1;
        if (a[p - a] < 0) {
          printf("n/a");
          return;
        }
        if (t) printf("%d ", *p);
    }
}
