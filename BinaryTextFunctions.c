#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "BinaryTextFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore, GameState_EndGame */
#include "GameFlags.h" /* GameFlags_IsInList, GameFlags_Add */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;



Item* BinaryText_Build()
{
	/* Create a "egg" item, using the functions defined in this file */
	return Item_Create("carvings", "You can barely make out the digits. \n", false, NULL, NULL, NULL);
}