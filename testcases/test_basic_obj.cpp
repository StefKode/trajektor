#include <SpaceObject.h>


int main()
{
	SpaceObject *m = new SpaceObject(	"testObj1",
						0.0, //x
						0.0, //y
						1.0, //speed
						90,  //direction
						0.0, //mass
						0.0  //radius
					);
	for (int i = 0; i < 100; i++) {
		m->advance(0.1);
		m->dbg_report();
	}

	delete m;
}
