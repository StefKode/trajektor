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

#include<SpaceObject.h>
#include<stdio.h>

SpaceObject::SpaceObject(	const char *name,
				double x,	double y,
				double speed,	double direction,
				double mass,	double radius)
{
	m_pos  = new Position(x,y);
	m_move = new Movement(speed, direction);
	m_body = new Body(mass, radius);
	mref_name = name;
}

SpaceObject::~SpaceObject()
{
	delete(m_pos);
	delete(m_move);
	delete(m_body);
}

void SpaceObject::advance(double deltaT)
{
	m_pos->advance(m_move, deltaT);
}

void SpaceObject::dbg_report()
{
	printf("[ %-10s ] ", mref_name);
	m_pos->dbg_report();
	printf("\n");
}
