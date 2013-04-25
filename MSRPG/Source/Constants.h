#ifndef	CONSTANTS_H_
#define CONSTANTS_H_

#define SCREEN_LINE_NUMBER 19
#define SCREEN_COLUMN_NUMBER 21

enum imageIDs
{
	//menus
	IMAGE_SPLASH1 = 0,
	IMAGE_BUTTON1,
	IMAGE_BACKGROUND_OPTIONS,
	IMAGE_BACKGROUND_CREDITOS,
	IMAGE_CHARACTER1,
	IMAGE_FONT_CENTURY_GOTHIC,
	//ingame
	IMAGE_TILESET,
	IMAGE_TILESET2
};

enum stringIDs
{
	STRING_PLAY_GAME = 0
};

enum fontIDs
{
	FONT_CENTURY_GOTHIC
};

enum layerIDs
{
	LAYER_GROUND1 = 0,
	LAYER_FIXED1,
	LAYER_MOVABLE_PICKABLE1,
	LAYER_CHARACTER1
};

//codigo global de todas anima��es
//definida aqui. consta no XML e � passada na hora de criar um novo generic object.
enum animationIDs
{
	//menus
	ANIMATION_SPLASH1 = 0,
	ANIMATION_BUTTON1,
	ANIMATION_BACKGROUND_OPTIONS,
	ANIMATION_BACKGROUND_CREDITOS,
	ANIMATION_CHAR1,
	//ingame
	ANIMATION_GROUND_SAND1,
	ANIMATION_GROUND_BRICK1,
	ANIMATION_GROUND_GRASS1,
	ANIMATION_GROUND_BRICK2,
	ANIMATION_GROUND_TREE1
};

enum objectIDs
{
	OBJECT_GROUND_SAND = 0,
	OBJECT_GROUND_BRICK1,
	OBJECT_GROUND_GRASS,
	OBJECT_GROUND_BRICK2,
	OBJECT_FIXED_TREE,
	OBJECT_MAIN_CHARACTER
};

#endif