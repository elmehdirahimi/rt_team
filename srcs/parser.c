/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 23:07:20 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/23 20:57:45 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		parser(t_rt *rt)
{
	//camera
	rt->f = 0; // pour le filtre
	rt->cam.cam_ray.o = constrector(0.0, 0.0, 20.0);
	rt->cam.look_at = constrector(0.0, 0.0, 0.0);

	//light
	t_light *t;
	t = (t_light *)malloc(sizeof(t_light));
	t->color = constrector(255.0, 255.0,255.0);
	t->position = constrector(0.0, 0.0, 20.0);
	t->translation = constrector(0.0, 0.0, 0.0);
	t->position = addition(t->position,t->translation);
	t->next = NULL;
	rt->light = t;

	//sphere avec color
	t_object *sphere = (t_object*)malloc(sizeof (t_object));
	sphere->type = SPHERE;
	sphere->color = constrector(123.0,44,55.0);
	sphere->position = constrector(0.0, -1.0, 0.0);
	sphere->position = addition(sphere->position,sphere->translation);
	sphere->translation = constrector(0.0, 0.0, 0.0);
	sphere->r = 1.0;
	sphere->tc = COLOR; /// color , texture ou noise 
	sphere->coupe = 0; /// sans coupe
	add_compos(sphere);
	sphere->next = NULL;
	///// sphere avec coupe et color
	t_object *sphere2 = (t_object*)malloc(sizeof (t_object));
	sphere2->type = SPHERE;
	sphere2->color = constrector(123.0,44,155.0);
	sphere2->position = constrector(1.5, 4.0, 0.0);
	sphere2->translation = constrector(0.0, 0.0, 0.0);
	sphere2->position = addition(sphere2->position,sphere2->translation);
	sphere2->r = 1.0;
	sphere2->tc = COLOR; /// color , texture ou noise 
	sphere2->coupe = 1; /// avec coupe----------------------------[
	sphere2->direction = constrector(0.0, 0.0, 1.0);
	sphere2->rotation = constrector(DEG_TO_RAD(0.0), DEG_TO_RAD(60.0), DEG_TO_RAD(0.0));
	sphere2->repere = set_repere(sphere2->direction);
	sphere2->repere = set_repere(sphere2->direction);
	project(&(sphere2->repere.i), sphere2->rotation);
	project(&(sphere2->repere.j), sphere2->rotation);
	project(&(sphere2->repere.k), sphere2->rotation);
	project(&(sphere2->direction),sphere2->rotation);/////---------]
	add_compos(sphere2);
	sphere2->next = sphere;

	/////////// sphere texture
	t_object *sphere3 = (t_object*)malloc(sizeof (t_object));
	sphere3->type = SPHERE;
	sphere3->position = constrector(-2.5, 1.5, 0.0);
	sphere3->translation = constrector(0.0, 0.0, 0.0);
	sphere3->position = addition(sphere3->position,sphere3->translation);
	sphere3->r = 2.0;
	sphere3->tc = 1; ///    texture ----[
	sphere3->txt = (t_texture *)malloc (sizeof(t_texture));
	char *path = ft_strdup("xpm/4.xpm");
	if (!load_texture(rt,sphere3, path))
		ft_putendl("error : failed to load texture");//////-----]
	sphere3->coupe = 0; /// sans coupe----------------------------[
	sphere3->direction = constrector(0.0, 0.0, 1.0);
	sphere3->rotation = constrector(DEG_TO_RAD(0.0), DEG_TO_RAD(60.0), DEG_TO_RAD(0.0));
	sphere3->repere = set_repere(sphere3->direction);
	sphere3->repere = set_repere(sphere3->direction);
	project(&(sphere3->repere.i), sphere3->rotation);
	project(&(sphere3->repere.j), sphere3->rotation);
	project(&(sphere3->repere.k), sphere3->rotation);
	project(&(sphere3->direction),sphere3->rotation);
	/////---------]
	add_compos(sphere3);
	sphere3->next = sphere2;
	





	/////////// cylinder texture
	t_object *cylinder = (t_object*)malloc(sizeof (t_object));
	cylinder->type = CYLINDER;
	cylinder->position = constrector(-4.5, 0, 0.0);
	cylinder->translation = constrector(0.0, 0.0, 0.0);
	cylinder->position = addition(cylinder->position,cylinder->translation);
	cylinder->r = 1.5;
	cylinder->tc = 1; ///    texture ----[
	cylinder->txt = (t_texture *)malloc (sizeof(t_texture));
	cylinder->txt->coup = 0;
	cylinder->txt->hi = 4.0; // par defaul
	char *path2 = ft_strdup("xpm/4.xpm");
	if (!load_texture(rt,cylinder, path2))
		ft_putendl("error : failed to load texture");//////-----]
	cylinder->coupe = 0; /// sans coupe----------------------------[
	cylinder->direction = constrector(0.0, 1.0, 0.0);
	cylinder->rotation = constrector(DEG_TO_RAD(0.0), DEG_TO_RAD(60.0), DEG_TO_RAD(0.0));
	cylinder->repere = set_repere(cylinder->direction);
	cylinder->repere = set_repere(cylinder->direction);
	project(&(cylinder->repere.i), cylinder->rotation);
	project(&(cylinder->repere.j), cylinder->rotation);
	project(&(cylinder->repere.k), cylinder->rotation);
	project(&(cylinder->direction),cylinder->rotation);
	/////---------]
	add_compos(cylinder);
	cylinder->next = sphere3;
	

	///// cylinder2 avec coupe et color
	t_object *cylinder2 = (t_object*)malloc(sizeof (t_object));
	cylinder2->type = CYLINDER;
	cylinder2->color = constrector(13.0,144,155.0);
	cylinder2->position = constrector(1.5, -2.0, 0.0);
	cylinder2->translation = constrector(0.0, 0.0, 0.0);
	cylinder2->position = addition(cylinder2->position,cylinder2->translation);
	cylinder2->r = 1.0;
	cylinder2->tc = COLOR; /// color , texture ou noise 
	cylinder2->coupe = 1; /// avec coupe----------------------------[
	cylinder2->limit = 2.5;
	cylinder2->direction = constrector(0.0, 0.0, 1.0);
	cylinder2->rotation = constrector(DEG_TO_RAD(30.0), DEG_TO_RAD(0.0), DEG_TO_RAD(0.0));
	cylinder2->repere = set_repere(cylinder2->direction);
	cylinder2->repere = set_repere(cylinder2->direction);
	project(&(cylinder2->repere.i), cylinder2->rotation);
	project(&(cylinder2->repere.j), cylinder2->rotation);
	project(&(cylinder2->repere.k), cylinder2->rotation);
	project(&(cylinder2->direction),cylinder2->rotation);/////---------]
	add_compos(cylinder2);

	cylinder2->next = cylinder;


	
///// plane avec coupe et color
	t_object *plane = (t_object*)malloc(sizeof (t_object));
	plane->type = PLANE;
	plane->color = constrector(13.0,144,155.0);
	plane->position = constrector(4, -4.0, 0.0);
	plane->translation = constrector(0.0, 0.0, 0.0);
	plane->position = addition(plane->position,plane->translation);
	plane->tc = COLOR; /// color , texture ou noise 
	plane->coupe = 1; /// avec coupe----------------------------[
	plane->limitx = 2.5;
	plane->limitz = 2.5;
	plane->direction = constrector(0.0, 0.0, 1.0);
	plane->rotation = constrector(DEG_TO_RAD(30.0), DEG_TO_RAD(0.0), DEG_TO_RAD(0.0));
	plane->repere = set_repere(plane->direction);
	plane->repere = set_repere(plane->direction);
	project(&(plane->repere.i), plane->rotation);
	project(&(plane->repere.j), plane->rotation);
	project(&(plane->repere.k), plane->rotation);
	project(&(plane->direction),plane->rotation);/////---------]
	add_compos(plane);

	plane->next = cylinder2;




	rt->object = plane;

	
	return (1);
}
