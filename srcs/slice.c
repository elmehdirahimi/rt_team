#include "../rtv1.h"

int slice_plan(t_object *obj, t_vect p)
{
    if(fabs(p.x) > obj->limitx || fabs(p.z) > obj->limitz)
        return (0);
    return(1);
}

int slice_cylinder(t_object *obj, t_vect p)
{
    if (fabs(p.y) > obj->limit)
	 	return (0);
    return(1);
}

int slice_sphere(t_object *obj, t_vect p)
{
     if (p.y < 0)
	 	return (0);
    return(1);
}

int slice(t_object *obj, t_vect p)
{   
        if (obj->type == PLANE)
			return slice_plan(obj, p);
		if (obj->type == CYLINDER || obj->type == CONE)
			return slice_cylinder(obj, p);
		if (obj->type == SPHERE)
			return slice_sphere(obj, p);
        return (1);
}