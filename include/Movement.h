#ifndef MOVEMENT_H
#define MOVEMENT_H

class Movement {
	public:
		Movement(void);
		double get_speed();
		double get_direction();

	private:
		//Mandatory properties
		double speed;     //m/s
		double direction; //angle/rad

		//optional properties
}

#endif
