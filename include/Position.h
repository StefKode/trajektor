#ifndef POSITION_H
#define POSITION_H
#include <Movement.h>

class Position {
	public:
		Position(void);
		double distance_to(&Position);
		void   advance(&Movement);
		
	private:

		//Mandatory properties
		double x;
		double y;

		//optional properties
}

#endif
