set(argparse_lib 
	argparse.cc
   )	
add_library(argparse ${LIB_TYPE} ${argparse_lib})

target_include_directories(argparse PUBLIC ${ARGPARSE_INCLUDE_DIR})
 
target_link_libraries(
					   argparse 
					   ${CMAKE_THREAD_LIBS_INIT}
					  )

if(BuildShared)
  #install  libargparse.so to <cmake output dir>/${CMAKE_CURRENT_DIR}/
  install(TARGETS argparse LIBRARY DESTINATION lib DESTINATION lib)
else()
  # install  libargparse.a to <cmake output dir>/${CMAKE_CURRENT_DIR}/
  install(TARGETS argparse LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
endif()

#to do
install(DIRECTORY ../include/argparse DESTINATION include)
