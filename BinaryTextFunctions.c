#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "BinaryTextFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore, GameState_EndGame */
#include "GameFlags.h" /* GameFlags_IsInList, GameFlags_Add */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;



Item* BinaryText_Build()
{
	/* Create a "binary" item */
	return Item_Create("binary", "You can barely make out the digits. 0010\n", false, NULL, NULL, NULL);

}