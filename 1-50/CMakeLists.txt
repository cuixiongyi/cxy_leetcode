cmake_minimum_required (VERSION 2.8.11)


add_executable (1_main 1.cpp)


install(TARGETS 1_main
		RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib)



