#include <SpaceSystem.h>
#include<stdio.h>
#include<math.h>
#include<Eigen/Dense>

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

void t_eigen(int *err, int *pass)
{
	//-----------------------------------------------------------------
	printf("****** Test Eigen ********\n");
	Vector3d v;
	v << 1.1, 2.2, 3.3;
	printf("x = %e  y = %e  z = %e\n", v(0), v(1), v(2));
	check("Eigen x", v(0), 1.1, 0.0, err, pass);
	check("Eigen y", v(1), 2.2, 0.0, err, pass);
	check("Eigen z", v(2), 3.3, 0.0, err, pass);
}

void t_position(int *err, int *pass)
{
	//-----------------------------------------------------------------
	printf("****** Test Position ********\n");
	Vector3d v;
	v << 1.1, 2.2, 3.3;
	printf("x = %e  y = %e  z = %e\n", v(0), v(1), v(2));
	Position p(v);
	p.dbg_report();
	printf("\n");
	check("New Eigen x", (p.get_vect())(0), 1.1, 0.0, err, pass);
	check("New Eigen y", (p.get_vect())(1), 2.2, 0.0, err, pass);
	check("New Eigen z", (p.get_vect())(2), 3.3, 0.0, err, pass);

	Vector3d base;
	Vector3d other;
	base  << 0, 0, 0;
	other << 2, 1, 0;
	Position p0(base);
	Position p1(other);
	check("distance_to", p1.distance_to(&p0), sqrt(5), 0.001, err, pass);
	
}

int main()
{
	int err  = 0;
	int pass = 0;
	
	t_eigen(&err, &pass);
	t_position(&err, &pass);

	printf("\n-----------------------------\n");
	printf("PASS = %d\n", pass);
	printf("FAIL = %d\n", err);
}
