#include "selfprot.h"
#include <math.h>

/*
 * Function: CalculateSystemState
 * --------------------------------------------
 * calculate the system state based on environment data and
 * stores the calculated state in the caught data structure
 *
 * env: contains environment data and calculated state will be stored in it
 */
void CalculateSystemState(EnvironmentData *env) {
	int x = env->acc_x;
	int y = env->acc_y;
	int z = env->acc_z;
	int temp = env->temp;
	int temp_high = 0;
	int acc_high = 0;
	int squaree = x*x+z*z+y*y;
	if (x >= 20 || x <= -20 || y >= 20 || y <= -20 || z >= 20 || z <= -20 || squaree >= 900)
		{
			acc_high = 1;
		}
	if (temp > 34)
		{
			temp_high = 1;
		}

	if (temp_high == 1 && acc_high == 1)
	{
		env->state = HIGH_ACCELERATION_AND_TEMP;
	}
	else if ( temp_high == 1 && acc_high == 0)
	{
		env->state = HIGH_TEMP;
	}
	else if ( temp_high == 0 && acc_high == 1)
	{
		env->state = HIGH_ACCELERATION;
	}
	else
	{
		env->state = OK;
	}
}
