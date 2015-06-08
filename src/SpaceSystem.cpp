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

#include<SpaceSystem.h>

SpaceSystem::SpaceSystem()
{
}

SpaceSystem::~SpaceSystem()
{
}

void SpaceSystem::addObject(SpaceObject *obj)
{
	m_system.push_back(obj);
}

void SpaceSystem::advance_all(double deltaT)
{
	unsigned int A,B,i;

	/*#########################################
	  for A in all objects
		for B in all objects
			A.addForce(B)

	  for A in all objects
		A.advance(deltaT);
	###########################################*/

	for(A=0; A < m_system.size(); A++){
		for(B=0; B < m_system.size(); B++){
			m_system[A]->add_forceInteraction(m_system[B]);
		}
	}

	//FIXME combine loops?
	for(i=0; i < m_system.size(); i++){
		m_system[i]->advance(deltaT);
	}
}

void SpaceSystem::dbg_report()
{
	for(unsigned int i=0; i < m_system.size(); i++){
		m_system[i]->dbg_report();
	}
}
