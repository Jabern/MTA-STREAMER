/*********************************************************
*
*  Multi Theft Auto: San Andreas
*
*  Streamer module which can Stream Objects <3.
*
*  Developers:
*  Jaber
*
*********************************************************/

class CFunctions;

#ifndef __CFUNCTIONS_H
#define __CFUNCTIONS_H

#include <stdio.h>

#include "include/ILuaModuleManager.h"
extern ILuaModuleManager10 *pModuleManager;

class CFunctions
{
public:
        static int      System          ( lua_State* luaVM );
		static void		CreateDynamicObject		(int ModelID, float X, float Y, float Z, float rX, float rY, float rZ, float Dist = 100.0);
		static int createDynamicObject(lua_State * luaVM);
		static void		SetObjectStreamDistance		(lua_State* luaVM, int ObjectID, float Dist);

};
#endif
