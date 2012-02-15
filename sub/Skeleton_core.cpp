#include "kinect/Skeleton.h"

#include "lua_cpp_helper.h"





using namespace kinect;


/* ============================ Constructors     ====================== */

/** kinect::Skeleton::Skeleton()
 * include/kinect/Skeleton.h:45
 */
static int Skeleton_Skeleton(lua_State *L) {
  try {
    Skeleton * retval__ = new Skeleton();
    return retval__->luaInit(L, retval__, "kinect.Skeleton");
  } catch (std::exception &e) {
    lua_pushfstring(L, "Skeleton: %s", e.what());
  } catch (...) {
    lua_pushfstring(L, "Skeleton: Unknown exception");
  }
  return lua_error(L);
}



/* ============================ Destructor       ====================== */

static int Skeleton_destructor(lua_State *L) {
  Skeleton **userdata = (Skeleton**)dubL_checksdata_n(L, 1, "kinect.Skeleton");

  
  // custom destructor
  Skeleton *self = *userdata;
  if (self) self->luaDestroy();
  
  *userdata = NULL;
  return 0;
}



// test if class is deleted
static int Skeleton_deleted(lua_State *L) {
  Skeleton **userdata = (Skeleton**)dubL_checksdata_n(L, 1, "kinect.Skeleton");
  lua_pushboolean(L, *userdata == NULL);
  return 1;
}

/* ============================ tostring         ====================== */

static int Skeleton__tostring(lua_State *L) {
  Skeleton **userdata = (Skeleton**)dubL_checksdata_n(L, 1, "kinect.Skeleton");
  
  if (!*userdata) {
    lua_pushstring(L, "<kinect.Skeleton: NULL>");
    return 1;
  }
  
  
  lua_pushfstring(L, "<kinect.Skeleton: %p>", *userdata);
  
  return 1;
}

/* ============================ Member Methods   ====================== */




/* ============================ Lua Registration ====================== */

static const struct luaL_Reg Skeleton_member_methods[] = {
  {"__tostring"        , Skeleton__tostring},
  {"__gc"              , Skeleton_destructor},
  {"deleted"           , Skeleton_deleted},
  {NULL, NULL},
};

static const struct luaL_Reg Skeleton_namespace_methods[] = {
  {"Skeleton"          , Skeleton_Skeleton},
  {NULL, NULL},
};



#ifdef DUB_LUA_NO_OPEN
int luaload_kinect_Skeleton_core(lua_State *L) {
#else
extern "C" int luaopen_kinect_Skeleton_core(lua_State *L) {
#endif
  // Create the metatable which will contain all the member methods
  luaL_newmetatable(L, "kinect.Skeleton");

  // metatable.__index = metatable (find methods in the table itself)
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");

  // register member methods
  luaL_register(L, NULL, Skeleton_member_methods);
  // save meta-table in kinect.Skeleton_
  register_mt(L, "kinect", "Skeleton");

  // register class methods in a global namespace table
  luaL_register(L, "kinect", Skeleton_namespace_methods);


	return 1;
}
