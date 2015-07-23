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
#include<Propulsion.h>
#include<Eigen/Dense>

using namespace Eigen;

class SpaceObject {
	public:
		 SpaceObject(	const char *name,
				double px, double py, double pz,
				double vx, double vy, double vz,
				double mass,	double radius);
		~SpaceObject(void);

		Position *get_posRef();
		double    get_pos(unsigned int idx);
		void      add_forceInteraction(SpaceObject *other);
		void      set_propulsion(Propulsion *prop);
		void      advance(double deltaT);
		void	  clearForce();
		double    get_mass();
		void      report();
		void      posLog();
		void      vLog(double simtime, double step);
		bool      nameMatch(const char *);
		const char * getName();
		
	private:

		//Mandatory properties
		Position *m_pos;
		Movement *m_move;
		Body     *m_body;
		Force    *m_force;
		const char *mref_name;
		double    m_sumTime;

		//optional properties
};

#endif
