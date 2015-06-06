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

#ifndef FORCE_H
#define FORCE_H

class Force {
	public:
		Force();
		void   add_forceVector(double force, double direction);
		double get_forceResult();
		double get_directionResult();
		static double get_gravity(double r, double m1, double m2);
		
	private:

		//Mandatory properties
		double m_force;   //N
		double m_direction; //m

		//optional properties
};

#endif
