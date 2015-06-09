#include <SpaceSystem.h>
#include<stdio.h>
#include<math.h>

void check(const char *text, double is, double must, double tolerance, int *err, int *pass)
{
	printf("%-20s : ", text);
	if (fabs(is - must) <= tolerance) {
		printf("OK");
		(*pass)++;
	} else {
		printf("FAIL (is=%E, must=%E, tolerance=%E)", is, must, tolerance);
		(*err)++;
	}
	printf("\n");
}

void t_body(int *err, int *pass)
{
	//-----------------------------------------------------------------
	printf("****** Test Body ********\n");
	double bm, br;
	bm = 1.234e3;
	br = 4.552e8;
	Body *b = new Body(bm, br);
	check("get_mass",   b->get_mass(),   bm, 0, err, pass);
	check("get_radius", b->get_radius(), br, 0, err, pass);
	delete b;
}

void t_movement(int *err, int *pass)
{
	//-----------------------------------------------------------------
	printf("****** Test Movement ********\n");
	double ms, md;
	ms =  1.0;
	md = 90.0;
	Movement *m = new Movement(ms, md);
	check("get_speed",     m->get_speed(),            1.0, 0.0, err, pass);
	check("get_direction", m->get_direction(),       90.0, 0.0, err, pass);
	check("get_dir_Rad",   m->get_direction_rad(), M_PI/2, 0.0, err, pass);
	delete m;
}

void t_position(int *err, int *pass)
{
	//-----------------------------------------------------------------
	printf("****** Test Position ********\n");
	double px, py;
	px =  23.1;
	py = 456.4;
	Position *p = new Position(px, py);
	check("get_x", p->get_x(), px, 0.0, err, pass);
	check("get_y", p->get_y(), py, 0.0, err, pass);
	Position *r = new Position(0,1);
	Position *o = new Position(2,1);
	Position *q = new Position(2,2);
	Position *s = new Position(1,2);
	printf("bla %E\n", atan2(2,0));
	check("distance_to", r->distance_to(o),     2.0, 0.001, err, pass);
	check("distance_to", r->distance_to(q), sqrt(5), 0.001, err, pass);
	check("get_bearing", r->get_bearing(o),     0.0, 0.001, err, pass);
	check("get_bearing", r->get_bearing(s),  M_PI/4, 0.001, err, pass);
	delete p;
	delete r;
	delete o;
}

int main()
{
	int err  = 0;
	int pass = 0;
	
	t_body(&err,     &pass);
	t_movement(&err, &pass);
	t_position(&err, &pass);

	printf("\n-----------------------------\n");
	printf("PASS = %d\n", pass);
	printf("FAIL = %d\n", err);
}
