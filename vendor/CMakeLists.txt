
    # ----------------------------------------------------------------------------------
    #  vendor/[plat]/ ===> LUBYK_LIB/kinect/vendor
    # ----------------------------------------------------------------------------------
if(EXISTS ${MODULE}/vendor/${PLAT})
  add_custom_target("${MODULE_NAME}_vendor" ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${LUBYK_LIB}/kinect/vendor
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${MODULE}/vendor/${PLAT} ${LUBYK_LIB}/kinect/vendor
  )

  add_dependencies(${MODULE_NAME} "${MODULE_NAME}_vendor")

endif(EXISTS ${MODULE}/vendor/${PLAT})

