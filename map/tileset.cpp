//       _________ __                 __
//      /   _____//  |_____________ _/  |______     ____  __ __  ______
//      \_____  \\   __\_  __ \__  \\   __\__  \   / ___\|  |  \/  ___/
//      /        \|  |  |  | \// __ \|  |  / __ \_/ /_/  >  |  /\___ |
//     /_______  /|__|  |__|  (____  /__| (____  /\___  /|____//____  >
//             \/                  \/          \//_____/            \/
//  ______________________                           ______________________
//                        T H E   W A R   B E G I N S
//         Stratagus - A free fantasy real time strategy game engine
//
/**@name tileset.c - The tileset. */
//
//      (c) Copyright 1998-2005 by Lutz Sammer and Jimmy Salmon
//
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; only version 2 of the License.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
//      02111-1307, USA.
//
//      $Id$

//@{

/*----------------------------------------------------------------------------
--  Includes
----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "script.h"
#include "stratagus.h"
#include "tileset.h"
#include "map.h"
#include "iolib.h"
#include "video.h"

/*----------------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------------*/

/**
** Size of a tile in X
*/
int TileSizeX = 32;

/**
** Size of a tile in Y
*/
int TileSizeY = 32;

/*----------------------------------------------------------------------------
-- Functions
----------------------------------------------------------------------------*/

/**
** Load tileset and setup ::TheMap for this tileset.
**
** @see TheMap @see TheMap.Tileset.
*/
void LoadTileset(void)
{
	//  Load and prepare the tileset
	TileSizeX = TheMap.Tileset.TileSizeX;
	TileSizeY = TheMap.Tileset.TileSizeY;

	ShowLoadProgress("Tileset `%s'", TheMap.Tileset.ImageFile);
	//TheMap.TileGraphic = NewGraphic(TheMap.Tileset.ImageFile, 0, 0);
	TheMap.TileGraphic = NewGraphic(TheMap.Tileset.ImageFile, TileSizeX, TileSizeY);
	LoadGraphic(TheMap.TileGraphic);
}


/**
** Cleanup the tileset module.
**
** @note this didn't frees the configuration memory.
*/
void CleanTilesets(void)
{
	// Free the tileset data
	free(TheMap.Tileset.Name);
	free(TheMap.Tileset.ImageFile);
	free(TheMap.Tileset.Table);
	free(TheMap.Tileset.FlagsTable);
	free(TheMap.Tileset.Tiles);
	free(TheMap.Tileset.MixedLookupTable);
	free(TheMap.Tileset.TileTypeTable);
	if (TheMap.Tileset.SolidTerrainTypes)
		free(TheMap.Tileset.SolidTerrainTypes[0].TerrainName);
	free(TheMap.Tileset.SolidTerrainTypes);
	memset(&TheMap.Tileset, 0, sizeof(Tileset));

	//
	// Should this be done by the map?
	//
	FreeGraphic(TheMap.TileGraphic);
	TheMap.TileGraphic = NULL;
}

//@}
