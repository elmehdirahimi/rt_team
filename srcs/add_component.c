#include "../rtv1.h"

void duplicate(t_object *obj)
{
	obj->compos = (struct s_object *)malloc(sizeof(struct s_object));
	obj->compos->type = obj->type;
	obj->compos->color = obj->color;
	obj->compos->position = obj->position;
	obj->compos->direction = obj->direction;
	if(obj->type != PLANE)
		obj->compos->r = obj->r;
	obj->compos->repere = obj->repere;
	obj->compos->limit = obj->limit;
	obj->compos->txt = obj->txt;
    obj->compos->tc = obj->tc;
	obj->compos->t2 = obj->t2;
	obj->compos->coupe = obj->coupe;
	if(obj->tc == TEXTURE)
	{
		obj->compos->txt = obj->txt;
		obj->compos->txt->coup = obj->txt->coup;
		obj->compos->txt->hi = obj->txt->hi;
	}
	if(obj->type == PLANE)
	{
		obj->compos->limitx = obj->limitx;
		obj->compos->limitz = obj->limitz;
	}
}

void dup_compos(t_object *obj, t_object *compos, double x , double r)
{
	compos->type = DISK;
	compos->color = obj->color;
	compos->position = addition(obj->position, multiplication(obj->direction, x * obj->limit));
	compos->direction = obj->direction;
	compos->repere = obj->repere;
	compos->r = r;
    compos->tc = obj->tc;
	compos->t2 = obj->t2;
}
void	add_plane_compos(t_object *obj)
{
	obj->compos = (struct s_object *)malloc(sizeof(struct s_object));
	duplicate(obj);
	obj->compos->next = NULL;
}

void	add_cylinder_compos(t_object *obj)
{
	obj->compos = (struct s_object *)malloc(sizeof(struct s_object));
	duplicate(obj);
	if(obj->coupe == 0)
		obj->compos->next = NULL;
	else{
	obj->compos->next = (struct s_object *)malloc(sizeof(struct s_object));
	dup_compos(obj,obj->compos->next, 1.0, obj->r);
	obj->compos->next->next = (struct s_object *)malloc(sizeof(struct s_object));
	dup_compos(obj,obj->compos->next->next, -1.0, obj->r);
	obj->compos->next->next->next = NULL;
	}
}

void	add_cone_compos(t_object *obj)
{	
	obj->compos = (struct s_object *)malloc(sizeof(struct s_object));
	duplicate(obj);
	if(obj->coupe == 0)
		obj->compos->next = NULL;
	else{
	obj->compos->next = (struct s_object *)malloc(sizeof(struct s_object));
	dup_compos(obj,obj->compos->next, 1.0, tan((obj->r)) * obj->limit);
	obj->compos->next->next = (struct s_object *)malloc(sizeof(struct s_object));
	dup_compos(obj,obj->compos->next->next, -1.0, tan((obj->r)) * obj->limit);
	obj->compos->next->next->next = NULL;
	}
}

void	add_sphere_compos(t_object *obj)
{
	obj->limit = 0.0;
	obj->compos = (struct s_object *)malloc(sizeof(struct s_object));
	duplicate(obj);
	if(obj->coupe == 0)
		obj->compos->next = NULL;
	else{
	obj->compos->next = (struct s_object *)malloc(sizeof(struct s_object));
	dup_compos(obj,obj->compos->next, 1.0, obj->r);
	obj->compos->next->next = NULL;
	} 
}

void	add_compos(t_object *obj)
{
    if (obj->type == PLANE)
			add_plane_compos(obj);
		if (obj->type == CYLINDER)
			add_cylinder_compos(obj);
		else if (obj->type == CONE)
			add_cone_compos(obj);
		else if (obj->type == SPHERE)
			add_sphere_compos(obj);
}