/******************************************
Name: Sim McQueen
Date: 3/5/21
Desc: Adds functions to the key item
******************************************/


#include "GameState.h"
#include "GameFlags.h"
#include "Item.h"
#include "stdafx.h"
#include "KeyFunctions.h"

void KeyTake(CommandContext context, GameState* gameState, WorldData* worldData) {
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	

}


Item* KeyBuild() {

}