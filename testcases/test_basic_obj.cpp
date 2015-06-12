#include <SpaceObject.h>
#include <SpaceSystem.h>

int main()
{
	SpaceSystem sys;

	//-----------------------name----------x--------y----speed------dir-----mass----------radius
	sys.add(new SpaceObject("earth", 0,       0, 0, 0, 0, 0, 5.97219e24, 0.0));
	sys.add(new SpaceObject("sat",   0, 200.0e3, 0, 7.8e3, 0, 0,        1.0, 0.0));

	for (int i = 0; i < 1000; i++) {
		sys.advance_all(1);
		sys.dbg_report("sat");
	}
}
