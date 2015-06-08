/*#######################################################################################
 #
 # Copyright by Stefan Koch <StefanKoch@gmx.org>, 2015
 #
 # This file is part of spacepath
 #
 #    spacepath is free software: you can redistribute it and/or modify
 #    it under the terms of the GNU General Public License as published by
 #    the Free Software Foundation, either version 3 of the License, or
 #    (at your option) any later version.
 #
 #    spacepath is distributed in the hope that it will be useful,
 #    but WITHOUT ANY WARRANTY; without even the implied warranty of
 #    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 #    GNU General Public License for more details.
 #
 #    You should have received a copy of the GNU General Public License
 #    along with spacepath.  If not, see <http://www.gnu.org/licenses/>.
 #
 ######################################################################################*/

#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H
#include<Body.h>
#include<Force.h>
#include<Movement.h>
#include<Position.h>

class SpaceObject {
	public:
		 SpaceObject(	const char *name,
				double x, 	double y, 
				double speed, 	double direction, 
				double mass,	double radius);
		~SpaceObject(void);

		Position *get_posRef();
		void      add_forceInteraction(SpaceObject *other);
		void      advance(double deltaT);
		double    get_x();
		double    get_y();
		double    get_mass();
		void      dbg_report();
		
	private:

		//Mandatory properties
		Position *m_pos;
		Movement *m_move;
		Body     *m_body;
		Force    *m_force;
		const char *mref_name;

		//optional properties
};

#endif
