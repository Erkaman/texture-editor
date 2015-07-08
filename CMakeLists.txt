
# how to build on windows
# http://stackoverflow.com/a/8532797
# https://forums.wxwidgets.org/viewtopic.php?t=40491

######################################
#### PROJECT SETTINGS.
######################################

CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
PROJECT(app)

SET(CMAKE_BUILD_TYPE "Debug")

# COMPILER SETTINGS.
if(MSVC)
ADD_DEFINITIONS(/GR- /MTd /W4)

else()
ADD_DEFINITIONS( -pedantic -Wno-deprecated -fno-exceptions -Waddress
-Warray-bounds
-Wc++11-compat
-Wchar-subscripts
-Wcomment
-Wformat
-Wnonnull
-Wparentheses
-Wpointer-sign
-Wreorder
-Wreturn-type
-Wsequence-point
-Wsign-compare
-Wstrict-aliasing
-Wstrict-overflow=1
-Wswitch
-Wtrigraphs
-Wuninitialized
-Wunused-function
-Wunused-label
-Wunused-value
-Wunused-variable
-Wvolatile-register-var)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")
endif()

######################################
#### SET SOURCE FILES.
######################################

#SET(SRC main.cpp)
file(GLOB ENGINE_SRC src/*.cpp)

######################################
############ ADD  LIBRARIES
######################################

set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})


#FIND_PACKAGE(OpenGL)
#LIST(APPEND game_libs ${GLUT_LIBRARY} ${OPENGL_LIBRARY})

#LIST(APPEND game_libs glfw3)


file(GLOB APP_SRC src/*.cpp)

include_directories("src")

ADD_EXECUTABLE(app ${APP_SRC} )
TARGET_LINK_LIBRARIES(app ${wxWidgets_LIBRARIES})
