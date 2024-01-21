#include "stdio.h"

void main()
{
	int K[100][100], i, j, maxk, maxt, maxi, maxj, mink, mint, mini, minj, k, t, t0, m, n, Sw, Sb;
	int f;
	k = 0;
	t = 0;
	printf("Enter the size of the crossword: ");
	scanf_s("%i%i", &m, &n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			printf("Enter the color of the square: ");
			scanf_s("%i", &K[i][j]);
		}
	Sw = 0;
	Sb = m * n;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			if (K[i][j] == 0) {
				k = 0;
				t = 0;
				t0 = n - j - 1;
				f = 1;
				while (f == 1) {
					if ((K[i + k][j + t + 1] == 0) && (t < t0)) t++;
					else if ((K[i + k + 1][j] == 0) && (k < m - i - 1)) {
						t0 = t;
						t = 0;
						k++;
					}
					else f = 0;
				}
				if ((k + 1)*(t + 1) > Sw) {
					maxk = k + 1;
					maxt = t + 1;
					maxi = i;
					maxj = j;
					Sw = maxk * maxt;
				}
			}
			else if ((K[i][j] == 1) && (((i == 0) && (j == 0)) || ((i != 0) && (j == 0) && (K[i - 1][j] != 1)) || ((i == 0) && (j != 0) && (K[i][j - 1] != 1)) || ((i != 0) && (j != 0) && (K[i][j - 1] != 1) && (K[i - 1][j] != 1)))) {
				k = 0;
				t = 0;
				t0 = n - j - 1;
				f = 1;
				while (f == 1) {
					if ((K[i + k][j + t + 1] == 1) && (t < t0)) t++;
					else if ((K[i + k + 1][j] == 1) && (k < m - i - 1)) {
						t0 = t;
						t = 0;
						k++;
					}
					else f = 0;
				}
				if ((k + 1)*(t + 1) < Sb) {
					mink = k + 1;
					mint = t + 1;
					mini = i;
					minj = j;
					Sb = mink * mint;
				}
			}
		}
	printf("The beginning of the biggest white rectangle is in (%i, %i), its size is %i x %i\n", maxi, maxj, maxk, maxt);
	printf("The beginning of the smallest black rectangle is in (%i, %i), its size is %i x %i", mini, minj, mink, mint);
}