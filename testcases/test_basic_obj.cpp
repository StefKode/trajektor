#include <SpaceObject.h>
#include <SpaceSystem.h>

int main()
{
	SpaceSystem system;

	//---------------------------------name----------x--------y----speed------dir-----mass----------radius
	SpaceObject *m1 = new SpaceObject("earth",     0.0,     0.0,     0.0,     0.0,     5.97219e24,     0.0);
	SpaceObject *m2 = new SpaceObject("sat",       0.0, 200.0e3,   7.8e3,     0.0,            1.0,     0.0); //7.8km/s

	system.addObject(m1);
	system.addObject(m2);

	for (int i = 0; i < 10; i++) {
		system.advance_all(0.1);
		system.dbg_report();
	}

	delete m1;
	delete m2;
}
