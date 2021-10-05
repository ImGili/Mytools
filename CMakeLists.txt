cmake_minimum_required(VERSION 3.0)
project(Mytools)



if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    if(APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wno-parentheses  -std=c++11")
        message("Apple")
    elseif(WIN32)
        message("WIN32")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Werror -fexec-charset=GBK  -std=c++11")
    elseif(UNIX AND NOT APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wpedantic  -std=c++11")
        message("Linux")        
    endif()
    
        
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()


include_directories(                tools/include/
                                    tools/vendor/glm
                                    )

file(GLOB PROJECT_HEADERS           tools/include/*.hpp
                                    tools/include/*.h)
file(GLOB PROJECT_SOURCES           tools/src/*.cpp
                                    tools/test/*.cpp
                                    )

add_definitions()
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                               )

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

add_custom_command(
TARGET ${PROJECT_NAME} POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/tools/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>
DEPENDS ${PROJECT_SHADERS})

