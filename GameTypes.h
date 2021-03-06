/*
 * GameTypes.h
 *
 *  Created on: 12.05.2014
 *      Author: dmitry
 */

#ifndef GAMETYPES_H_
#define GAMETYPES_H_

enum eItemMainClassification {
	TEST_ITEM ,
	TEST_WEAPON ,
	TEST_ROBE,
	TEST_AMMO
};
enum eItemClassification {
	TEST_ITEM_UNKNOWN ,
	TEST_ITEM2,
	TEST_ITEM3,
	TEST_ITEM_VLADISLAU_HAND
};
enum eWeaponClassification {
	TEST_WEAPON_NONE,
	TEST_WEAPON_GUN,
	TEST_WEAPON_PISTOL,
	TEST_WEAPON_ROCKET,
};
enum eRobeClassification {
	TEST_ROBE_NONE,
	TEST_ROBE_1 ,
	TEST_ROBE_2
};
enum eAmmoClassification {
	TEST_AMMO_1,
	TEST_AMMO_2,
	TEST_AMMO_BULLETS
};
enum eMoveTypes{
	MOVE_NONE,
	MOVE_RIGHT,
	MOVE_LEFT,
	MOVE_DOWN,
	MOVE_UP,
	MOVE_SIT,
	MOVE_JUMP
};
enum eAnimsTypes{
	ANIM_UNKNOWN = MOVE_NONE,
	ANIM_MOVE_RIGHT = MOVE_RIGHT,
	ANIM_MOVE_LEFT = MOVE_LEFT,
	ANIM_MOVE_DOWN = MOVE_DOWN,
	ANIM_MOVE_UP = MOVE_UP,
	ANIM_MOVE_SIT = MOVE_SIT,
	ANIM_MOVE_JUMP = MOVE_JUMP,
	ANIM_HOLDING,
	ANIM_SHOOT_RIGHT,
	ANIM_SHOOT_LEFT,
	ANIM_SHOOT_DOWN,
	ANIM_SHOOT_UP,
	ANIM_WORKING_RIGHT,
	ANIM_WORKING_LEFT,
	ANIM_WORKING_DOWN,
	ANIM_WORKING_UP
};
enum eAxis{
	AXIS_UNKNOWN,
	AXIS_X,
	AXIS_Y,
	AXIS_Z
};

struct sAnim
{
	animation *mpAnim;
	unsigned int miSpeed;

	float mfScaledMultiplier;
	float mfRotateDegrees;
};
struct sStaticTexture
{
	cTexture	*mpTexture;

	float mfScaledMultiplier;
	float mfRotateDegrees;

	float GetRealWidth();
	float GetRealHeigth();
};


#endif /* GAMETYPES_H_ */
