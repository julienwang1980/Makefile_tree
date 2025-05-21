//*************************************************************************
//*************************************************************************
/**
 * \file		
 *
 * \brief		计算空间某个点的定位
 *
 * \copyright	
 *
 * \author		Julien Wang
*/
//*************************************************************************
//*************************************************************************
#include "locatePoint.h"
#include <stdio.h>
#include <math.h>


//-------------------------------------------------------------------------
/**
 * \fn unknownPoint locatePoint_3(Point_3 *points);
 *
 * \brief This function takes an array of points and a location and returns the index of the point that is closest to the location.
 *
 * \param points is an array of points
 *
 * \return location is the location to compare against.
 */
//-------------------------------------------------------------------------
unknownPoint locatePoint_3(Point_3 *points)
{
	unknownPoint point;
	point.x = (pow(points->r0, 2) - pow(points->r1, 2) + pow(points->x, 2)) / (2 * points->x);	//x = (R0²- R1² + X²) / (2*X)
	point.y = (pow(points->r0, 2) - pow(points->r2, 2) + pow(points->y, 2)) / (2 * points->y);	//x = (R0²- R2² + Y²) / (2*Y)
	point.z = sqrt(pow(points->r0, 2) - pow(point.x, 2) - pow(point.y, 2));
	return point;
}


//-------------------------------------------------------------------------
/**
 * \fn int locatePoint_4(Point points[], double location[3]);
 *
 * \brief This function takes an array of points and a location and returns the index of the point that is closest to the location.
 *
 * \param points is an array of points
 * \param location is the location to compare against
 *
 * \return The index of the point that is closest to the location, or -1 if there are no points in the array.
 */
//-------------------------------------------------------------------------
int locatePoint_4(Point_4 points[], double location[3])
{
    // 系数矩阵
    double A[3][3];
    // 常数项
    double b[3];

    // 构建系数矩阵和常数项
    for (int i = 0; i < 3; i++) {
        A[i][0] = 2 * (points[i + 1].x - points[0].x);
        A[i][1] = 2 * (points[i + 1].y - points[0].y);
        A[i][2] = 2 * (points[i + 1].z - points[0].z);
        b[i] = pow(points[i + 1].r, 2) - pow(points[0].r, 2) - pow(points[i + 1].x, 2) + pow(points[0].x, 2) - pow(points[i + 1].y, 2) + pow(points[0].y, 2) - pow(points[i + 1].z, 2) + pow(points[0].z, 2);
    }

    // 高斯消元法求解线性方程组
    for (int i = 0; i < 3; i++) {
        // 寻找主元
        double max = fabs(A[i][i]);
        int row = i;
        for (int k = i + 1; k < 3; k++) {
            if (fabs(A[k][i]) > max) {
                max = fabs(A[k][i]);
                row = k;
            }
        }

        // 交换行
        if (row != i) {
            for (int k = i; k < 3; k++) {
                double temp = A[i][k];
                A[i][k] = A[row][k];
                A[row][k] = temp;
            }
            double temp = b[i];
            b[i] = b[row];
            b[row] = temp;
        }

        // 检查主元是否为0，若为0则无解或无唯一解
        if (fabs(A[i][i]) < 1e-6) {
            return -1;
        }

        // 消元
        for (int k = i + 1; k < 3; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < 3; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    // 回代求解
    for (int i = 2; i >= 0; i--) {
        for (int j = i + 1; j < 3; j++) {
            b[i] -= A[i][j] * location[j];
        }
        location[i] = -b[i] / A[i][i];
    }

    return 0;
}



void test(void)
{
	// 初始化已知的四个点和它们到未知点的距离
    Point_4 knownPoints[4] = {
        {0, 0, 0, 17.32},
        {10, 0, 0, 14.14},
        {0, 10, 0, 14.14},
        {0, 0, 10, 14.14}
    };

    // 用于存储未知点的坐标
    double unknownLocation[3];

    // 调用函数进行定位
    if (locatePoint_4(knownPoints, unknownLocation) == 0) {
        // 输出结果
        printf("未知点的坐标是: (%f, %f, %f)\n", unknownLocation[0], unknownLocation[1], unknownLocation[2]);
    } else {
        printf("无法定位未知点。\n");
    }

	// 初始化已知的距离
	Point_3 point3 = {
		.x = 1.450,
		.y = 0.690,
		.r0 = 11.209,
		.r1 = 11.170,
		.r2 = 11.222,
	};
	// 用于存储未知点的坐标
    unknownPoint point;
 	point = locatePoint_3(&point3);

    printf("未知点的坐标是3: (%f, %f, %f)\n", point.x, point.y, point.z);
}