//*************************************************************************
//*************************************************************************
/**
 * \file		
 *
 * \brief		
 *
 * \copyright	
 *
 * \author		Julien Wang
*/
//*************************************************************************
//*************************************************************************
#ifndef _LOCATEPOINT_H_   					// Re-include guard
#define _LOCATEPOINT_H_	    				// Re-include guard


//-------------------------------------------------------------------------
/**
 * \struct	Point_3
 * \brief	原点和另外两个直角点的距离,未知点到三点的距离
 */
//-------------------------------------------------------------------------
typedef struct {
	double x;
	double y;
	double r0, r1, r2;
} Point_3;

//-------------------------------------------------------------------------
/**
 * \struct	Point_4
 * \brief	已知点的位置和未知点的距离
 */
//-------------------------------------------------------------------------
typedef struct {
	double x;
	double y;
	double z;
	double r;
} Point_4;

//-------------------------------------------------------------------------
/**
 * \struct	unknownPoint
 * \brief	未知点
 */
//-------------------------------------------------------------------------
typedef struct {
	double x;
	double y;
	double z;
} unknownPoint;



//-------------------------------------------------------------------------
/**
 * \fn int locatePoint_4(Point points[], double location[3]);
 *
 * \brief This function takes an array of points and a location and returns the index of the point that is closest to the location.
 *
 * \param points is an array of points
 *
 * \return location is the location to compare against.	
*/
//-------------------------------------------------------------------------
unknownPoint locatePoint_3(Point_3 *points);

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
int locatePoint_4(Point_4 points[], double location[3]);

void test(void);

#endif                                      // re-include guard
