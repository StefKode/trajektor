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

#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <Eigen/Dense>

using namespace Eigen;

class Movement {
	public:
		Movement(Vector3d init);
		void   add_moveVector(Vector3d add);
		Vector3d get_vect();
		void report();

	private:
		//Mandatory properties
		Vector3d *m_vect;

		//optional properties
};

#endif
