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
	Position *t = new Position(-1,0);
	check("1 distance_to", r->distance_to(o),       2.0, 0.001, err, pass);
	check("2 distance_to", r->distance_to(q),   sqrt(5), 0.001, err, pass);
	check("1 get_bearing", r->get_bearing(o),       0.0, 0.001, err, pass);
	check("2 get_bearing", r->get_bearing(s),    M_PI/4, 0.001, err, pass);
	check("3 get_bearing", r->get_bearing(t), 1.25*M_PI, 0.001, err, pass);
	
	Position *base   = new Position(0,0);
	Position *walker = new Position(0,0);
	Movement *m_r1 = new Movement(1.0,     0);
	Movement *m_l1 = new Movement(1.0, 180.0);
	Movement *m_u1 = new Movement(1.0,  90.0);
	Movement *m_d1 = new Movement(1.0, 270.0);
	
	//---
	printf("check walk right\n");
	check("pre check  x..", walker->get_x(), 0.0, 0.001, err, pass);
	check("pre check  y..", walker->get_y(), 0.0, 0.001, err, pass);
	walker->advance(m_r1, 1.0); //right 1m
	check("advance r1 x..", walker->get_x(), 1.0, 0.001, err, pass);
	check("advance r1 y..", walker->get_y(), 0.0, 0.001, err, pass);
	check("advance bear..", base->get_bearing(walker), 0.0, 0.001, err, pass);
	//--walker is now at 1,0
	
	//---
	printf("check walk down\n");
	walker->advance(m_d1, 1.0); //down 1m
	check("advance d1 x..", walker->get_x(),  1.0, 0.001, err, pass);
	check("advance d1 y..", walker->get_y(), -1.0, 0.001, err, pass);
	check("advance bear..", base->get_bearing(walker), 1.75*M_PI, 0.001, err, pass);
	//--walker is now at 1,-1

	//---
	printf("check walk 2 left and two up\n");
	walker->advance(m_l1, 2.0); //left 2m
	walker->advance(m_u1, 2.0); //up 2m
	check("advance d1 x..", walker->get_x(), -1.0, 0.001, err, pass);
	check("advance d1 y..", walker->get_y(),  1.0, 0.001, err, pass);
	check("advance bear..", base->get_bearing(walker), 0.75*M_PI, 0.001, err, pass);
	//--walker is now at -1,1
}

void t_force(int *err, int *pass)
{
	//-----------------------------------------------------------------
	printf("****** Test Force ********\n");
	Force *f1 = new Force();
	check("get_currentForce    ", f1->get_currentForce(),     0.0, 0.0, err, pass);
	check("get_currentDirection", f1->get_currentDirection(), 0.0, 0.0, err, pass);
	
	//--
	//f1.add_forceVector(1.0, 0);
}
	
int main()
{
	int err  = 0;
	int pass = 0;
	
	t_body(&err,     &pass);
	t_movement(&err, &pass);
	t_position(&err, &pass);
	t_force(&err, &pass);

	printf("\n-----------------------------\n");
	printf("PASS = %d\n", pass);
	printf("FAIL = %d\n", err);
}
