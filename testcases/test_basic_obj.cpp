#include <SpaceObject.h>


int main()
{
	SpaceObject *m = new SpaceObject(	0.0, //x
						0.0, //y
						0.0, //speed
						0.0, //direction
						0.0, //mass
						0.0  //radius
					);

	delete m;
}
