#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "SwordFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */




void Sword_Take(CommandContext context, GameState* gameState, WorldData* worldData) {
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	
	printf("You pick up the sword\n");
}


void Sword_Use(CommandContext context, GameState* gameState, WorldData* worldData) {
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* Sword;

	if ((gameState == NULL) || (worldData == NULL))
	{
		return;
	}


	if (context != CommandContext_Item_Inventory)
	{
		printf("You must have the Sword before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 0)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the sword here.\n");
		return;
	}

	if (GameFlags_IsInList(gameState->gameFlags, "enemiesKilled"))
	{

		printf("You already used the sword here.\n");
		return;
	}
	else {
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; 
		}
		Sword = ItemList_FindItem(gameState->inventory, "Sword");

		printf("You swing the sword wildly and manage to hit all the bat like creatures, killing them");
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "enemiesKilled");



	}




}





Item* Sword_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("Sword", "A medieval sword. You wonder how it could've gotten here.", true, Sword_Use, Sword_Take, NULL);
}