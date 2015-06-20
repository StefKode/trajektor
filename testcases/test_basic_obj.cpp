#include <SpaceObject.h>
#include <SpaceSystem.h>
#include <stdio.h>

int main()
{
	SpaceSystem sys;
	double earth_r = 6.371e6;
	double earth_m = 5.972e24;
	double step    = 0.5;
	int i = 0;

	//                           name                        pos            move             m         r
	sys.add(new SpaceObject(  "earth",  0,               0, 0,        0, 0,   0,       earth_m,  earth_r));
	sys.add(new SpaceObject("bigrock",  0, earth_r + 900e4, 0,     1000, 0,   0,   earth_m/100,  earth_r));
	sys.add(new SpaceObject(    "sat",  0, earth_r + 200e3, 0,    7.8e3, 9,   5,             1,        1));
	sys.listObjects();

	while (1) {
		sys.advance_all(step);
		//printf("%dmin | ", (int)(step * (double)i/60.0));
		//sys.report("sat");
		//printf("\033[1A");
		//printf("%s %f, %f, %f\n", sat.get_name(), sat.get_pos(0), sat.get_pos(1), sat.get_pos(2));
		sys.posLog();
		i++;
		if ((int)(step * (double)i/60.0) > 300) {
			break;
		}
	}
}
