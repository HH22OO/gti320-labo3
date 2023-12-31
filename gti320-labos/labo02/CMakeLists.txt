cmake_minimum_required(VERSION 3.15)

project(labo02)

# Setup language requirements
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)

#--------------------------------------------------
# Sous MAC, OpenGL est Deprecated, mais toujours
# fonctionnel, on veut éviter tous les warnings
# durant la compilation.
#--------------------------------------------------
if (APPLE)
  add_definitions( -DGL_SILENCE_DEPRECATION )
endif()

add_definitions(${NANOGUI_EXTRA_DEFS})
include_directories(${nanogui_SRC_DIR}/include)
include_directories(${NANOGUI_EXTRA_INCS})
include_directories(${PROJECT_SOURCE_DIR}/../labo01/src ${COMMON_INCLUDES})

find_package(OpenGL REQUIRED)

# Add .cpp and .h files
set(HEADERS ParticleSimGLCanvas.h ParticleSimApplication.h ParticleSystem.h Vector2d.h Solvers.h GraphColoring.h)
set(SOURCE main.cpp ParticleSimApplication.cpp ParticleSimGLCanvas.cpp ParticleSystem.cpp GraphColoring.cpp)
add_executable(labo02 ${SOURCE} ${HEADERS})
target_link_libraries(labo02 nanogui ${NANOGUI_EXTRA_LIBS} OpenMP::OpenMP_CXX)

if(MSVC) 
	set_property(TARGET labo02 PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/labo02)
endif()
