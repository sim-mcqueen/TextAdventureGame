/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "BrickFunctions.h" /* Brick_Build */
#include "GoldPieceFunctions.h" /* GoldPiece_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */
#include "SwordFunctions.h"



/******************************************************************************
	Build room TEMPLATE
    Use this example function to build additional rooms
******************************************************************************/
Room* RoomN_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	   include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	   add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

	/* Items
	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}


/* TODO REQUIRED: Build room 0 */
Room* Room0_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("You're in a dimly lit cavern, the only source of light is from through the small hole which you fell through. It's too high to climb back out. You see small writing carved into the floor next to you.\n");
	
	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	Room_AddRoomExit(room, "north", 1);

	/* TODO BASIC: Add room exit shortcut for "n" */
	Room_AddRoomExitShortcut(room, "n", 1);

	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	ItemList_AddItem(Room_GetItemList(room), Sword_Build());

	/* return the new room */
	return room;
}



/* TODO REQUIRED: Build room 1 */
Room* Room1_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create */
	room = Room_Create("Room 1\n");

	Room_AddRoomExit(room, "north", 2);
	Room_AddRoomExitShortcut(room, "n", 2);

	Room_AddRoomExit(room, "west", 4);
	Room_AddRoomExitShortcut(room, "w", 4);

	Room_AddRoomExit(room, "south", 0);
	Room_AddRoomExitShortcut(room, "s", 0);

	return room;
}



/* TODO REQUIRED: Build room 2 */
Room* Room2_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	room = Room_Create("Room 2\n");

	Room_AddRoomExit(room, "west", 3);
	Room_AddRoomExitShortcut(room, "w", 3);

	Room_AddRoomExit(room, "south", 1);
	Room_AddRoomExitShortcut(room, "s", 1);

	return room;
}


Room* Room3_Build()
{
	Room* room = NULL;
	room = Room_Create("Room 3\n");

	Room_AddRoomExit(room, "east", 2);
	Room_AddRoomExitShortcut(room, "e", 2);

	return room;
}

Room* Room4_Build()
{
	Room* room = NULL;
	room = Room_Create("Room 4\n");

	Room_AddRoomExit(room, "east", 1);
	Room_AddRoomExitShortcut(room, "e", 1);

	Room_AddRoomExit(room, "south", 5);
	Room_AddRoomExitShortcut(room, "s", 5);

	Room_AddRoomExit(room, "west", 6);
	Room_AddRoomExitShortcut(room, "w", 6);

	return room;
}

Room* Room5_Build()
{
	Room* room = NULL;
	room = Room_Create("Room 5\n");

	Room_AddRoomExit(room, "north", 4);
	Room_AddRoomExitShortcut(room, "n", 4);

	return room;
}

Room* Room6_Build()
{
	Room* room = NULL;
	room = Room_Create("Room 6\n");

	Room_AddRoomExit(room, "east", 4);
	Room_AddRoomExitShortcut(room, "e", 4);

	Room_AddRoomExit(room, "north", 7);
	Room_AddRoomExitShortcut(room, "n", 7);

	return room;
}

Room* Room7_Build()
{
	Room* room = NULL;
	room = Room_Create("Room 7\n");

	Room_AddRoomExit(room, "south", 6);
	Room_AddRoomExitShortcut(room, "s", 6);

	return room;
}


/* ------------------------------------------------------- */
/* Create the world data for a new game */
/* ------------------------------------------------------- */
WorldData* CreateInitialWorldData()
{
	/* The new world data */
	WorldData* worldData;

	/* TODO REQUIRED: update room count to match the number of rooms you have created and added to the world
	   if this number doesn't match then your game will either crash or you will end up stuck in a broken room with no exits */
	int roomCount = 8;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("GAM100!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room0_Build());
	WorldData_SetRoom(worldData, 1, Room1_Build());
	WorldData_SetRoom(worldData, 2, Room2_Build());
	WorldData_SetRoom(worldData, 3, Room3_Build());
	WorldData_SetRoom(worldData, 4, Room4_Build());
	WorldData_SetRoom(worldData, 5, Room5_Build());
	WorldData_SetRoom(worldData, 6, Room6_Build());
	WorldData_SetRoom(worldData, 7, Room7_Build());

	/* TODO ADVANCED: add additional advanced rooms */

	/* return the new object */
	return worldData;
}