/******************************************
Name: Sim McQueen
Date: 3/5/21
Desc: Adds functions to the key item
******************************************/


#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "KeyFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */




void Key_Take(CommandContext context, GameState* gameState, WorldData* worldData) {
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	printf("Hoping that it will be useful, you put the key in your pocket.\n");
}

void Key_Use(CommandContext context, GameState* gameState, WorldData* worldData){

	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* Key; /* The key in the player's inventory */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	if (context != CommandContext_Item_Inventory)
	{
		
		printf("Find the key and pick it up first.\n");
		return;
	}
	if (gameState->currentRoomIndex != 0)
	{
		printf("You cannot use the brick here.\n");
		return;
	}
	if (GameFlags_IsInList(gameState->gameFlags, "keyDoorUnlocked"))
	{

		printf("You already unlocked the door.\n");
		return;
	}
	else {
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; 
		}

		Key = ItemList_FindItem(gameState->inventory, "Key");
		gameState->inventory = ItemList_Remove(gameState->inventory, Key);
		printf("You walk up to the door and unlock it, allowing you to pass into the next room.\n");
		//Room_SetDescription(room, "This is room 0.  You are in a display room.  There is a broken cage here.\n");
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "keyDoorUnlocked");
	}
}




Item* KeyBuild() {
	return Item_Create("Key", "A small key, covered in dust", true, Key_Use, Key_Take, NULL);
}