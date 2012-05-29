/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */
 
#ifndef ROCKETCORELUAROCKET_H
#define ROCKETCORELUAROCKET_H

#include <Rocket/Core/Lua/LuaType.h>
#include <Rocket/Core/Lua/lua.hpp>

namespace Rocket {
namespace Core {
namespace Lua {
#define ROCKETLUA_INPUTENUM(keyident,tbl) lua_pushinteger(L,Input::KI_##keyident); lua_setfield(L,(tbl),#keyident);

//just need a class to take up a type name, and a single object to be able to be pushed to Lua
class LuaRocket { int to_remove_warning; }; //instance of object defined in Interpreter.cpp

template<> void ExtraInit<LuaRocket>(lua_State* L, int metatable_index);
int LuaRocketCreateContext(lua_State* L, LuaRocket* obj);
int LuaRocketLoadFontFace(lua_State* L, LuaRocket* obj);
int LuaRocketRegisterTag(lua_State* L, LuaRocket* obj);

int LuaRocketGetAttrcontexts(lua_State* L);

void LuaRocketEnumkey_identifier(lua_State* L);

RegType<LuaRocket> LuaRocketMethods[];
luaL_reg LuaRocketGetters[];
luaL_reg LuaRocketSetters[];

LUATYPEDECLARE(LuaRocket)
}
}
}
#endif
