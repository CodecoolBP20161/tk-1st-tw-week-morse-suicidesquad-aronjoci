#include "selfprot.h"

/*
 * Function: CreateEnvironmentData
 * --------------------------------------------
 * converts input data into structured form
 *
 * acc_x: acceleration in the X direction
 * acc_y: acceleration in the Y direction
 * acc_z: acceleration in the Z direction
 * temp: magnitude of the temperature
 */
EnvironmentData CreateEnvironmentData(float acc_x, float acc_y, float acc_z, signed int temp) {
	int acc_x_int = (int)(acc_x*10);
	int acc_y_int = (int)(acc_y*10);
	int acc_z_int = (int)(acc_z*10);

	EnvironmentData env = {acc_x_int, acc_y_int, acc_z_int, temp};
	return env;
}
