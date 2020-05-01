#include "../rtv1.h"

static void	rotate_x(double *y, double *z, double alpha)
{
	double previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}


static void	rotate_y(double *x, double *z, double beta)
{
	double previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}


static void	rotate_z(double *x, double *y, double gamma)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void project(t_vect *p, t_vect rot)
{
    rotate_x(&(*p).y, &(*p).z, rot.x);
	rotate_y(&(*p).x, &(*p).z, rot.y);
	rotate_z(&(*p).x, &(*p).y, rot.z);
}