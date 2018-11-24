set(parser_unit_tests_src
 run_all.cc
 parser_test.cc
 )
add_executable(parser_unit_tests ${parser_unit_tests_src})

target_link_libraries(parser_unit_tests 
					  parser
					  gtest
					  #gmock_main # for google mock
					  ${CMAKE_THREAD_LIBS_INIT}
					 )
add_test(
NAME parser_unit_tests
COMMAND parser_unit_tests
)
