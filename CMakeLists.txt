cmake_minimum_required (VERSION 2.6)
project (Chat)


set(SOURCES 
	Src/main.cpp
	)
	
set(HEADERS

	)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/Headers
)


				 
					   
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_BINARY_DIR}/Debug")