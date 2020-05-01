#include "../rtv1.h"

int 	disk_intersection(t_rt *rt, t_object *plane, double *dist)						//************************************************//
{
	t_vect	vect;


	double	a;
	double	b;

	vect = soustraction(rt->cam.cam_ray.o, plane->position);
	a = -dot(vect, plane->direction);
	b = dot(rt->cam.cam_ray.d, plane->direction);
	*dist = a / b;

	vect = addition(rt->cam.cam_ray.o, multiplication(rt->cam.cam_ray.d, *dist));
	if(module(soustraction(vect, plane->position))  >=	plane->r)
		return (0);
	if (*dist >= 1e-4)
		return (1);
	return (0);
}		