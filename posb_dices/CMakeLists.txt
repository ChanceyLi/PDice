cmake_minimum_required(VERSION 3.10)
# set the project name
project(PDice VERSION 1.1)

option (USE_DICE "Use dice provided structrue implementation" OFF)

configure_file(PDiceConfig.h.in PDiceConfig.h)

# if(USE_DICE)
#     add_subdirectory(Dice)
#     list(APPEND EXTRA_LIBS Dice)
#     list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/Dice")
# endif()
# add the executable
add_executable(PDice main.cpp dice.cpp)

target_link_libraries(PDice PUBLIC ${EXTRA_LIBS})
target_include_directories(PDice PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            ${EXTRA_INCLUDES}
                            )