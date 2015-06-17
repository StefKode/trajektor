#include <SpaceObject.h>
#include <SpaceSystem.h>

int main()
{
	SpaceSystem sys;

	//                        name                pos           move           m        r
	sys.add(new SpaceObject("earth",          0, 0, 0,       0, 0, 0,   5.972e24, 6.371e6));
	sys.add(new SpaceObject("sat",    0, 206.371e6, 0,   7.8e3, 0, 0,          1,       1));

	for (int i = 0; i < 1000000; i++) {
		sys.advance_all(1);
		sys.report("sat");
	}
}
