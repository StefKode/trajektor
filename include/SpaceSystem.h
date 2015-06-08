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

#ifndef SPACESYSTEM_H
#define SPACESYSTEM_H
#include<SpaceObject.h>
#include<vector>

class SpaceSystem {
	public:
		 SpaceSystem();
		~SpaceSystem(void);
		void add(SpaceObject *obj);
		void advance_all(double deltaT);
		void dbg_report();
		void dbg_report(const char *name);
		
	private:
		std::vector<SpaceObject*> m_system;
};

#endif
