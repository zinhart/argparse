set(token_parser_lib 
	token_parser.cc
   )	
add_library(token_parser ${LIB_TYPE} ${token_parser_lib})

target_include_directories(token_parser PUBLIC ${TOKEN_PARSER_INCLUDE_DIR})
 
target_link_libraries(
					   token_parser 
					   ${CMAKE_THREAD_LIBS_INIT}
					  )

if(BuildShared)
  #install  libtoken_parser.so to <cmake output dir>/${CMAKE_CURRENT_DIR}/
  install(TARGETS token_parser LIBRARY DESTINATION lib DESTINATION lib)
else()
  # install  libtoken_parser.a to <cmake output dir>/${CMAKE_CURRENT_DIR}/
  install(TARGETS token_parser LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
endif()

#to do
install(DIRECTORY ../include/token_parser DESTINATION include)
