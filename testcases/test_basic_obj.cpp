#include <SpaceObject.h>


int main()
{
	SpaceObject *m = new SpaceObject(	"testObj1",
						0.0, //x
						0.0, //y
						0.0, //speed
						0.0, //direction
						0.0, //mass
						0.0  //radius
					);
	for (int i = 0; i < 100; i++) {
		m->advance(0.0);
		m->dbg_report();
	}

	delete m;
}
