#pragma once
enum class MAP_TYPE
{
	WALL,
	ROAD,
	PLACE,
	HOUSE
};
enum class ENTITY_TYPE
{
	ALLY,
	ENEMY,
	TRAP
};

enum class ROAD_TYPE
{
	FIRST,
	SECOND,
	NONE
};

enum class ALLY_TYPE
{
	ARCHER = 1,
	CROSSBOW = 2,
	BALLISTA,
	GUNSLINGER,
	FIRE_WIZARD,
	ICE_WIZARD,
	LIGHTNING_WIZARD,
	NECROMANCER,
	SWORD,
	SPEAR,
	SLAYER,
	GREATSWORD
};

enum class ENEMY_TYPE
{
	GOBLIN = 1,
	GOLDGOBLIN,
	OGRE,
	GOLEM,
	DRAGON,
	END
};

enum class TRAP_TYPE
{
	DEFAULT
};

enum class INGAMESCENE_STATE
{
	IDLE,
	SELECT,
	PLACE,
	BATTLE,
	REMOVE,
	ASK,
	NONE
};