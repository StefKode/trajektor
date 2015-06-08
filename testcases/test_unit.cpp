#include <SpaceSystem.h>
#include<stdio.h>

int main()
{
	int err  = 0;
	int pass = 0;
	
	//-----------------------------------------------------------------
	printf("****** Test Body ********\n");
	double bm, br;
	bm = 1.234e3;
	br = 4.552e8;
	Body *b = new Body(bm, br);
	if (b->get_mass() != bm) {
		printf("get mass failed\n");
		err++;
	} else {
		printf("get mass ok\n");
		pass++;
	}
	if (b->get_radius() != br) {
		printf("get radius failed\n");
		err++;
	} else {
		printf("get radius ok\n");
		pass++;
	}
	delete b;

	//#####################################################################
	printf("\n-----------------------------\n");
	printf("PASS = %d\n", pass);
	printf("FAIL = %d\n", err);
}
