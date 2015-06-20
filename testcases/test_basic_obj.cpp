#include <SpaceObject.h>
#include <SpaceSystem.h>
#include <stdio.h>

int main()
{
	SpaceSystem sys;
//                         s      m      h    d
	double lim_sec  = (60.0 * 60.0 * 24 * 690);
	double step_sec = 300;
	double dur_sec  = 0.0;
	double capture_sec      = 0.0;
	double capture_step_sec = lim_sec / 2000.0;

	//_________________________name_________________pos(m)_____________move(m/s)_________m(kg)_______r(m)_____
	sys.add(new SpaceObject(  "Sun",         0,       0, 0,        0,       0, 0,    1.985e30,  696342e3));

	sys.add(new SpaceObject("Earth",         0,  149.6e9,                0,     29.78e3,        0, 0,    5.972e24,   6.371e6));
	sys.add(new SpaceObject("probe",         0, (149.6e9+6.371e6+200e3) ,0,    (29.78e3+11.8e3), 0, 0,           1,         1));

	sys.add(new SpaceObject( "Mars",  -227.9e9,       0, 0,        0, 24.07e3, 0,  0.64174e24,  3.3962e6));

	sys.listObjects();

	while (dur_sec < lim_sec) {
		sys.advance_all(step_sec);
		if (capture_sec <= dur_sec) {
			sys.posLog();
			capture_sec = dur_sec + capture_step_sec;
			//printf("-------dur=%f capt=%f step=%f\n", dur_sec, capture_sec, capture_step_sec);
		}
		dur_sec += step_sec;
	}
}
