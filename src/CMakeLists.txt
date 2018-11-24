set(parser_lib 
	parser.cc
   )	
add_library(parser ${LIB_TYPE} ${parser_lib})

target_include_directories(parser PUBLIC ${PARSER_INCLUDE_DIR})
 
target_link_libraries(
					   parser 
					   ${CMAKE_THREAD_LIBS_INIT}
					  )

if(BuildShared)
  #install  libparser.so to <cmake output dir>/${CMAKE_CURRENT_DIR}/
  install(TARGETS parser LIBRARY DESTINATION lib DESTINATION lib)
else()
  # install  libparser.a to <cmake output dir>/${CMAKE_CURRENT_DIR}/
  install(TARGETS parser LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
endif()

#to do
install(DIRECTORY ../include/parser DESTINATION include)
