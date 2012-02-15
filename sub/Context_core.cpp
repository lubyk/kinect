#include "kinect/Context.h"

#include "lua_cpp_helper.h"





using namespace kinect;


/* ============================ Constructors     ====================== */

/** kinect::Context::Context()
 * include/kinect/Context.h:50
 */
static int Context_Context(lua_State *L) {
  try {
    Context * retval__ = new Context();
    return retval__->luaInit(L, retval__, "kinect.Context");
  } catch (std::exception &e) {
    lua_pushfstring(L, "Context: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "Context: Unknown exception");
  }
  return lua_error(L);
}



/* ============================ Destructor       ====================== */

static int Context_destructor(lua_State *L) {
  Context **userdata = (Context**)dubL_checksdata_n(L, 1, "kinect.Context");

  
  // custom destructor
  Context *self = *userdata;
  if (self) self->luaDestroy();
  
  *userdata = NULL;
  return 0;
}



// test if class is deleted
static int Context_deleted(lua_State *L) {
  Context **userdata = (Context**)dubL_checksdata_n(L, 1, "kinect.Context");
  lua_pushboolean(L, *userdata == NULL);
  return 1;
}

/* ============================ tostring         ====================== */

static int Context__tostring(lua_State *L) {
  Context **userdata = (Context**)dubL_checksdata_n(L, 1, "kinect.Context");
  
  if (!*userdata) {
    lua_pushstring(L, "<kinect.Context: NULL>");
    return 1;
  }
  
  
  lua_pushfstring(L, "<kinect.Context: %p>", *userdata);
  
  return 1;
}

/* ============================ Member Methods   ====================== */




/* ============================ Lua Registration ====================== */

static const struct luaL_Reg Context_member_methods[] = {
  {"__tostring"        , Context__tostring},
  {"__gc"              , Context_destructor},
  {"deleted"           , Context_deleted},
  {NULL, NULL},
};

static const struct luaL_Reg Context_namespace_methods[] = {
  {"Context"           , Context_Context},
  {NULL, NULL},
};



#ifdef DUB_LUA_NO_OPEN
int luaload_kinect_Context_core(lua_State *L) {
#else
extern "C" int luaopen_kinect_Context_core(lua_State *L) {
#endif
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "kinect.Context");

  // metatable.__index = metatable (find methods in the table itself)
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");

  // register member methods
  luaL_register(L, NULL, Context_member_methods);
  // save meta-table in kinect.Context_
  register_mt(L, "kinect", "Context");

  // register class methods in a global namespace table
  luaL_register(L, "kinect", Context_namespace_methods);


	return 1;
}
