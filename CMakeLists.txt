cmake_minimum_required (VERSION 2.6)
project (Chat)


set(SOURCES 
	Src/main.cpp
	Src/user.cpp
	Src/server.cpp
	)
	
set(HEADERS
	Headers/user.h
	Headers/server.h
	)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/Headers
		
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        C:/Users/Michael/Documents/boost_1_67_0/boost_1_67_0/ 
)
target_link_libraries(${PROJECT_NAME} C:/Users/Michael/Documents/boost_1_67_0/boost_1_67_0/stage_x86/lib/libboost_system-vc141-mt-gd-x32-1_67.lib)				 
target_link_libraries(${PROJECT_NAME} C:/Users/Michael/Documents/boost_1_67_0/boost_1_67_0/stage_x86/lib/libboost_date_time-vc141-mt-gd-x32-1_67.lib)		
target_link_libraries(${PROJECT_NAME} C:/Users/Michael/Documents/boost_1_67_0/boost_1_67_0/stage_x86/lib/libboost_regex-vc141-mt-gd-x32-1_67.lib)	
target_link_libraries(${PROJECT_NAME} C:/Users/Michael/Documents/boost_1_67_0/boost_1_67_0/stage_x86/lib/libboost_thread-vc141-mt-gd-x32-1_67.lib)	
target_link_libraries(${PROJECT_NAME} C:/Users/Michael/Documents/boost_1_67_0/boost_1_67_0/stage_x86/lib/libboost_chrono-vc141-mt-gd-x32-1_67.lib)	

				   
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/Debug")