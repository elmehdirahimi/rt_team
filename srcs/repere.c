#include "../rtv1.h"


t_repere set_repere(t_vect dir)
{
    t_repere rep;
    t_vect up;

    up = constrector(0.0, 1.0, 0.0);
    rep.j = dir;
	if (equal(up, rep.j) == 1)
	{
		rep.i = constrector(1.0, 0.0, 0.0);
		rep.k = constrector(0.0, 0.0, 1.0);
	}
	else
	{
		if (equal(up, rep.j) == 2)
		{
			rep.i = constrector(-1.0, 0.0, 0.0);
			rep.k = constrector(0.0, 0.0, 1.0);
		}
		else
		{
			rep.i = cross(up, rep.j);
			rep.k = cross(rep.i, rep.j);
		}
	}
    return (rep);
}
