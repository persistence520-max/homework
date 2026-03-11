#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
double EuclideanDistance(double* pVectorA, double* pVectorB, int nVectorLen);
int main()
{
	FILE *fp;
	fp = fopen("iris_change.data.txt", "r");
	if (fp == NULL) {
		printf("open error!\n");
		exit(0);
	}
	//打开文件

	typedef struct Iris {
		double data[4];
		int belong;
		char name[30];
	} IRIS;
	//利用结构体来储存文件

	IRIS a[200];
	int i;
	double max[4];
	double min[4];
	int initial = 0;
	for (i = 0; (fscanf(fp, "%lf,%lf,%lf,%lf,%s", &a[i].data[0], &a[i].data[1], &a[i].data[2], &a[i].data[3], a[i].name)) == 5; i++) {
		if (!initial) {
			for (int j = 0; j < 4; j++) {
				max[j] = min[j] = a[i].data[j];
			}
			initial = 1;
		}
		else {
			for (int j = 0; j < 4; j++) {
				if (max[j] <= a[i].data[j]) {
					max[j] = a[i].data[j];
				}
				if (min[j] >= a[i].data[j]) {
					min[j] = a[i].data[j];
				}
			}
		}
	
	}
	//读入数据，并且选出最大最小值

	for (int m = 0; m < i; m++) {
		for (int j = 0; j < 4; j++) {
			a[m].data[j] = (a[m].data[j] - min[j]) / (max[j] - min[j]);
		}
	}
	//标准化初值

	printf("请输入分为几类：");
	int k;
	scanf("%d", &k);
	//输入簇数

	double** cluster_point;
	if ((cluster_point = (double**)malloc(k * sizeof(double*))) == NULL) {
		printf("Not able to allocate memory.\n");
		exit(1);
	}
	for (int j = 0; j < k; j++) {
		if ((cluster_point[j] = (double*)malloc(4 * sizeof(double))) == NULL) {
			printf("Not able to allocate memory.\n");
			exit(1);
		}
	}
	//开辟一个数组来储存簇点

	srand(time(NULL));
	for (int j = 0; j < k; j++) {
		
		int random = rand() % i;
		for (int m = 0; m < 4; m++) {
			cluster_point[j][m] = a[random].data[m];
		}
	}
	//随机选取k个点作为簇心

	double error_range = 1;
	while (error_range > 0.0000001) {
		for (int j = 0; j < i; j++) {
			double min_distance = EuclideanDistance(a[j].data, cluster_point[0], 4);
			a[j].belong = 0;
			for (int m = 1; m < k; m++) {
				if (min_distance >= EuclideanDistance(a[j].data, cluster_point[m], 4)) {
					min_distance = EuclideanDistance(a[j].data, cluster_point[m], 4);
					a[j].belong = m;
				}
			}
		}
		//根据到簇点的距离，对数据进行分类

		double* sum;
		error_range = 0;
		if ((sum = (double*)malloc(4 * sizeof(double))) == NULL) {
			printf("Not able to allocate the sum memory.\n");
			exit(1);
		}

		for (int j = 0; j < k; j++) {
			
			for (int n = 0; n < 4; n++) {
				sum[n] = 0;
			}

			double count = 0;
			for (int m = 0; m < i; m++) {
				if (a[m].belong == j) {
					count++;
					for (int n = 0; n < 4; n++) {
						sum[n] += a[m].data[n];
					}
				}
			}

			for (int m = 0; m < 4; m++) {

				error_range += fabs(cluster_point[j][m] - sum[m] / count);
				cluster_point[j][m] = sum[m] / count;
				
			}

		}
		//重置簇点
	
		free(sum);
	}

	for (int j = 0; j < k; j++) {
		printf("类别%d:\n", j + 1);
		for (int m = 0; m < i; m++) {
			if (a[m].belong == j) {
				printf("%.1lf, %.1lf, %.1lf, %.1lf, ", a[m].data[0], a[m].data[1], a[m].data[2], a[m].data[3]);
				printf("%s\n", a[m].name);
			}
		}
	}


	for (int j = 0; j < k; j++) {
		free(cluster_point[j]);
	}
	free(cluster_point);
	fclose(fp);

	return 0;
}

double EuclideanDistance(double* pVectorA, double* pVectorB, int nVectorLen) {
	double EuclideanDistance = 0, sum = 0;
	for (int i = 0; i < nVectorLen; i++) {
		sum += pow(pVectorA[i] - pVectorB[i], 2);
	}
	EuclideanDistance = sqrt(sum);
	return EuclideanDistance;
}

/*
	int format_control = 0;
		for (int j = 0; j < i; j++) {

			printf("%d\t", a[j].belong);
			if (format_control++ == 9) {
				printf("\n");
				format_control = 0;
			}

		}
*/