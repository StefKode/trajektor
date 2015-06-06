#ifndef BODY_H
#define BODY_H
#include <Position.h>
#include <Movement.h>
#include <Body.h>

class SpaceObject {
	public:
		SpaceObject(void);
		
	private:

		//Mandatory properties
		Position *m_pos;
		Movement *m_move;
		Body     *m_body;

		//optional properties
}

#endif
