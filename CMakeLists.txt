set(MODULE_NAME kinect)

set(MODULE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}")

include_directories(${MODULE}/include)
include_directories(${MODULE}/vendor/Include)

if(EXISTS ${MODULE}/src)
  file (GLOB MODULE_SOURCES ${MODULE}/src/*.cpp ${MODULE}/src/${PLAT}/*.cpp ${MODULE}/src/*.c ${MODULE}/src/${PLAT}/*.c ${MODULE}/src/*.mm ${MODULE}/src/${PLAT}/*.mm)
  build_module(${MODULE_NAME} ${MODULE_SOURCES})
else(EXISTS ${MODULE}/src)
  add_custom_target(${MODULE_NAME} true) # noop
  add_dependencies(modules "${MODULE_NAME}")
endif(EXISTS ${MODULE}/src)


file(GLOB KINECT_LIBS ${MODULE}/vendor/${PLAT}/*.dylib)
if(EXISTS ${MODULE}/sub)
  # Build a shared object for each file in sub.
  include(${LUBYK_SOURCE_DIR}/modules/CMakeSub.txt)
endif(EXISTS ${MODULE}/sub)
target_link_libraries(${MODULE_NAME}_Context_core ${KINECT_LIBS})
target_link_libraries(${MODULE_NAME}_Skeleton_core ${KINECT_LIBS})

# ----------------------------------------------------------------------------------
#  module_vendor
# ----------------------------------------------------------------------------------
if(EXISTS ${MODULE}/vendor/CMakeLists.txt)
  add_subdirectory(${MODULE}/vendor)
  add_dependencies(${MODULE_NAME} "${MODULE_NAME}_vendor")
endif(EXISTS ${MODULE}/vendor/CMakeLists.txt)

# ----------------------------------------------------------------------------------
#  module_bind
# ----------------------------------------------------------------------------------
file(GLOB MODULE_HEADERS ${MODULE}/include/${MODULE}/*.h)
add_custom_target("${MODULE_NAME}_bind"
  COMMAND ruby ${LUBYK_SOURCE_DIR}/modules/bind.rb ${MODULE_NAME}
  DEPENDS ${MODULE_HEADERS})


# ----------------------------------------------------------------------------------
#  module_lib
# ----------------------------------------------------------------------------------
if(EXISTS ${MODULE}/lib)
  add_custom_target("${MODULE_NAME}_lib" ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${MODULE}/lib ${LUBYK_LIB})

  add_dependencies(${MODULE_NAME} "${MODULE_NAME}_lib")

endif(EXISTS ${MODULE}/lib)

