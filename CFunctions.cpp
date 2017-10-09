/*********************************************************
*
*  Multi Theft Auto: San Andreas
*
*  Shell module which can execute commands.
*
*  Developers:
*  x86 <sebasdevelopment@gmx.com>
*
*********************************************************/

#include <stdlib.h>
#include "CFunctions.h"
#include "extra/CLuaArguments.h"

#define MAX_STREAMED_OBJECTS 5000 

#define MAX_PLAYERS 30

int ObjectModel[MAX_STREAMED_OBJECTS];
float ObjectPos[MAX_STREAMED_OBJECTS][3];
float ObjectRotation[MAX_STREAMED_OBJECTS][3];
float ObjectDistance[MAX_STREAMED_OBJECTS];
int ObjectIDS[MAX_PLAYERS][MAX_STREAMED_OBJECTS];
int ObjectStreamed[MAX_PLAYERS][MAX_STREAMED_OBJECTS];
int ObjectID = -1;
int ObjectUsed[MAX_STREAMED_OBJECTS];

int CFunctions::System ( lua_State* luaVM )
{
    if ( luaVM )
    {
        if (lua_type(luaVM, 1) == LUA_TSTRING)
        {
            const char* m_bCommand = lua_tostring(luaVM, 1);

            /**********************************************
            *   System command (supports: Win32 & Linux).
            *   Win32 return value: 1 = fail.
            *   Linux return value: -1 = fail.
            **********************************************/
            int result = system(m_bCommand);
#ifdef WIN32
            if ( result != 1 )
#else
            if ( result != -1 )
#endif
            {
                lua_pushboolean(luaVM, true);
                return 1;
            }
        }
    }

    lua_pushboolean(luaVM, false);
    return 1;
}

void CFunctions::CreateDynamicObject(int ModelID, float X, float Y, float Z, float rX, float rY, float rZ, float Dist)
{
	ObjectID++; 
	ObjectModel[ObjectID] = ModelID; 
	ObjectPos[ObjectID][0] = X; 
	ObjectPos[ObjectID][1] = Y; 
	ObjectPos[ObjectID][2] = Z; 
	ObjectRotation[ObjectID][0] = rX; 
	ObjectRotation[ObjectID][1] = rY;
	ObjectRotation[ObjectID][2] = rZ; 
	ObjectDistance[ObjectID] = Dist; 
	ObjectUsed[ObjectID] = 1;
}

int CFunctions::createDynamicObject(lua_State* luaVM)
{
	if (luaVM)
	{
		CLuaArguments args;
		if (lua_type(luaVM, 1) == LUA_TNUMBER && lua_type(luaVM, 2) == LUA_TNUMBER && lua_type(luaVM, 3) == LUA_TNUMBER && lua_type(luaVM, 4) == LUA_TNUMBER && lua_type(luaVM, 5) == LUA_TNUMBER && lua_type(luaVM, 6) == LUA_TNUMBER && lua_type(luaVM, 7) == LUA_TNUMBER && lua_type(luaVM, 8) == LUA_TNUMBER )
		{
			CFunctions::CreateDynamicObject(lua_type(luaVM, 1), lua_type(luaVM, 2), lua_type(luaVM, 3), lua_type(luaVM, 4), lua_type(luaVM, 5), lua_type(luaVM, 6), lua_type(luaVM, 7), lua_type(luaVM, 8));
		}
		else
		{
			luaL_error(luaVM, "Bad argument @ 'Streamer Modules'");
			args.PushBoolean(false);
		}
		args.PushArguments(luaVM);
		return 1;
	}
	return 1;
}

void CFunctions::SetObjectStreamDistance(lua_State* luaVM, int ObjectID , float Dist)
{
	ObjectDistance[ObjectID] = Dist;
}