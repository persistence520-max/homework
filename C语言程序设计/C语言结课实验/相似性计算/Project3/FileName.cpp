#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
double CosCoef(double* pVectorA, double* pVectorB, int nVectorLen) {
	double sumAB = 0, sumA = 0, sumB = 0;
	double result;
	for (int i = 0; i < nVectorLen; i++) {
		sumAB += pVectorA[i] * pVectorB[i];
		sumA += pVectorA[i] * pVectorA[i];
		sumB += pVectorB[i] * pVectorB[i];
	}
	if (sumA * sumB == 0)return 0.0;
	result = sumAB / (sqrt(sumA * sumB));
	return result;
}

double EuclideanDistance(double* pVectorA, double* pVectorB, int nVectorLen) {
	double EuclideanDistance = 0, sum = 0;
	for (int i = 0; i < nVectorLen; i++) {
		sum += pow(pVectorA[i] - pVectorB[i], 2);
	}
	EuclideanDistance = sqrt(sum);
	return EuclideanDistance;
}

int main()
{
	int n, t;
	double a[1000], b[1000];
	printf("输入数据组数：");
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%lf", &b[i]);
		}
		printf("EuclideanDistance = %.4lf\n", EuclideanDistance(a, b, n));
		printf("CosCoef(A, B) = %.4lf\n", CosCoef(a, b, n));
	}

	return 0;
}