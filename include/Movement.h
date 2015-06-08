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

class Movement {
	public:
		Movement(double speed, double direction);
		void   add_moveVector(double add_speed, double add_direction);
		double get_speed();
		double get_direction();
		double get_direction_rad();

	private:
		//Mandatory properties
		double m_speed;     //m/s
		double m_direction; //angle/degrees

		//optional properties
};

#endif
