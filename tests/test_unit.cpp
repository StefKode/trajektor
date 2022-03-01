#include <gtest/gtest.h>

#include <SpaceSystem.h>
#include<stdio.h>
#include<math.h>
#include<Eigen/Dense>


testing::AssertionResult float_match(double is, double must, double tolerance)
{
	if (fabs(is - must) <= tolerance) {
		return testing::AssertionSuccess();
	}
	return testing::AssertionFailure() << is << " does not match " << must;
}

/* EIGEN TESTS ***********************************************************************/
/* Fixture */
class t_eigen_f : public ::testing::Test {
protected:
	virtual void SetUp() {
		v << 1.1, 2.2, 3.3;
	}
	virtual void TearDown() {
	}
	Vector3d v;
};

/* Test cases */
TEST_F(t_eigen_f, x)
{
	EXPECT_TRUE(float_match(v(0), 1.1, 0.0));
}

TEST_F(t_eigen_f, y)
{
	EXPECT_TRUE(float_match(v(1), 2.2, 0.0));
}

TEST_F(t_eigen_f, z)
{
	EXPECT_TRUE(float_match(v(2), 3.3, 0.0));
}

/* POSITION TESTS ***********************************************************************/
/* Fixture */
class t_position_f : public ::testing::Test {
protected:
	virtual void SetUp() {
		v << 1.1, 2.2, 3.3;
	}
	virtual void TearDown() {
		if (p  != NULL) delete(p);
		if (p0 != NULL) delete(p0);
		if (p1 != NULL) delete(p1);
		if (move != NULL) delete(move);
	}
	void t00_makepos() {
		p = new Position(v);
	}
	void t01_makedistance() {
		base  << 0, 0, 0;
		other << 2, 1, 0;
		p0 = new Position(base);
		p1 = new Position(other);
	}
	void t02_move1() {
		move_vect << 1, 1, 0;
		move = new Movement(move_vect);
		p0->advance(move, 1);
	}
	void t03_move2() {
		Vector3d new_move;
		new_move << -1, -1, 0;
		move->add_moveVector(new_move); //stop
		move->add_moveVector(new_move); //backward
		p0->advance(move, 1);
	}
	Vector3d v;
	Vector3d base;
	Vector3d other;
	Vector3d move_vect;
	Position *p = NULL;
	Position *p0 = NULL;
	Position *p1 = NULL;
	Movement *move;
};

/* Test cases */
TEST_F(t_position_f, makepos)
{
	t00_makepos();
	EXPECT_TRUE(float_match((p->get_vect())(0), 1.1, 0.0)) << "New Eigen x" << std::endl;
	EXPECT_TRUE(float_match((p->get_vect())(1), 2.2, 0.0)) << "New Eigen y" << std::endl;
	EXPECT_TRUE(float_match((p->get_vect())(2), 3.3, 0.0)) << "New Eigen z" << std::endl;
}

TEST_F(t_position_f, distance)
{
	t00_makepos();
	t01_makedistance();
	EXPECT_TRUE(float_match(p1->distance_to(p0), sqrt(5), 0.001)) << "distance_to" << std::endl;
}

TEST_F(t_position_f, move)
{
	t00_makepos();
	t01_makedistance();
	t02_move1();
	EXPECT_TRUE(float_match((p0->get_vect())(0), 1.0, 0.0)) << "move to pos x" << std::endl;
	EXPECT_TRUE(float_match((p0->get_vect())(1), 1.0, 0.0)) << "move to pos y" << std::endl;
	EXPECT_TRUE(float_match((p0->get_vect())(2), 0.0, 0.0)) << "move to pos z" << std::endl;
}
#if 0
	//check
	check("move2 pos x", (p0.get_vect())(0), 0.0, 0.0, err, pass);
	check("move2 pos y", (p0.get_vect())(1), 0.0, 0.0, err, pass);
	check("move2 pos z", (p0.get_vect())(2), 0.0, 0.0, err, pass);
	p0.advance(&move, 1);
	//check
	check("move3 pos x", (p0.get_vect())(0), -1.0, 0.0, err, pass);
	check("move3 pos y", (p0.get_vect())(1), -1.0, 0.0, err, pass);
	check("move3 pos z", (p0.get_vect())(2), 0.0, 0.0, err, pass);
#endif

#if 0
void t_force(int *err, int *pass)
{
	//-----------------------------------------------------------------
	printf("****** Test Force *******\n");
	Vector3d v, addf;
	v << 1.0, 2.0, 0.0;
	Force f;
	check("force_init x", (f.get_vect())(0), 0.0, 0.0, err, pass);
	check("force_init y", (f.get_vect())(1), 0.0, 0.0, err, pass);
	check("force_init z", (f.get_vect())(2), 0.0, 0.0, err, pass);
	f.add_forceVector(v);
	check("force0     x", (f.get_vect())(0), 1.0, 0.0, err, pass);
	check("force0     y", (f.get_vect())(1), 2.0, 0.0, err, pass);
	check("force0     z", (f.get_vect())(2), 0.0, 0.0, err, pass);
	addf << 0.0, -1.0, 0;
	f.add_forceVector(addf);
	check("force1     x", (f.get_vect())(0), 1.0, 0.0, err, pass);
	check("force1     y", (f.get_vect())(1), 1.0, 0.0, err, pass);
	check("force1     z", (f.get_vect())(2), 0.0, 0.0, err, pass);
	printf("gravity static not checked\n");
}

void t_spaceobject(int *err, int *pass)
{
	//-----------------------------------------------------------------
	printf("****** Test SpaceObject *******\n");
	//                                 name                     pos       move           m        r
	SpaceObject *so0 = new SpaceObject("test-earth",        1, 2, 3,   0, 0, 0,   5.972e24, 6.371e6); //earth
	check("so1 pos check x", so0->get_pos(0), 1.0, 0, err, pass);
	check("so1 pos check y", so0->get_pos(1), 2.0, 0, err, pass);
	check("so1 pos check z", so0->get_pos(2), 3.0, 0, err, pass);

	printf("**--drop test y --**\n");
	//                                     name                    pos           move          m        r
	SpaceObject *earth1 = new SpaceObject("earth",              0, 0, 0,      0, 0, 0,   5.972e24, 6.371e6); //earth
	SpaceObject *stone1 = new SpaceObject("testbody_1",   0, 6.371e6, 0,      0, 0, 0,          1,       1); //1kg, 1m, sealevel
	//earth1->report();
	stone1->report();
	for (int i=0; i < 100; i++) {
		//printf("%3.1fs stone delta=%5.2f\n", 0.01*(float)i, stone1->get_pos(1) - 6.371e6);
		stone1->clearForce();
		stone1->add_forceInteraction(earth1);
		stone1->advance(0.01);
	}
	stone1->report();
	check("drop path after 1s", stone1->get_pos(1) - 6.371e6, -4.9, 0.1, err, pass);

	printf("**--drop test y --**\n");
	//                                     name                    pos           move          m        r
	SpaceObject *earth2 = new SpaceObject("earth",              0, 0, 0,      0, 0, 0,   5.972e24, 6.371e6); //earth
	SpaceObject *stone2 = new SpaceObject("testbody_1",   6.371e6, 0, 0,      0, 0, 0,          1,       1); //1kg, 1m, sealevel
	//earth2->report();
	stone2->report();
	for (int i=0; i < 100; i++) {
		//printf("%3.1fs stone delta=%5.2f\n", 0.01*(float)i, stone2->get_pos(0) - 6.371e6);
		stone2->clearForce();
		stone2->add_forceInteraction(earth2);
		stone2->advance(0.01);
	}
	stone2->report();
	check("drop path after 1s", stone2->get_pos(0) - 6.371e6, -4.9, 0.1, err, pass);
}
#endif


int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#if 0
	int err  = 0;
	int pass = 0;
	
	t_eigen(&err, &pass);
	t_position_move(&err, &pass);
	t_force(&err, &pass);
	t_spaceobject(&err, &pass);

	printf("\n-----------------------------\n");
	printf("PASS = %d\n", pass);
	printf("FAIL = %d\n", err);
#endif
}
