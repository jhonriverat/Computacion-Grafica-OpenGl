cmake_minimum_required(VERSION 3.28.5)

project(OPENGL1 VERSION 0.1.0)

cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED) 
find_package(GLUT REQUIRED)
find_package(X11 REQUIRED)

include_directories(cwc/include freeglut/include glew/include)

set(SOURCES
    main.cpp
    myWindow.cpp
    myApplication.cpp 
    cwc/source/glApplication.cpp
    cwc/source/glWindow.cpp
    cwc/source/glsl.cpp
    cwc/source/glutwindow.cpp
    glew/source/glew.c
    freeglut/source/freeglut_callbacks.c
    freeglut/source/freeglut_cursor.c
    freeglut/source/freeglut_display.c
    freeglut/source/freeglut_ext.c
    freeglut/source/freeglut_font.c
    freeglut/source/freeglut_font_data.c
    freeglut/source/freeglut_gamemode.c
    freeglut/source/freeglut_geometry.c
    freeglut/source/freeglut_glutfont_definitions.c
    freeglut/source/freeglut_init.c
    freeglut/source/freeglut_joystick.c
    freeglut/source/freeglut_main.c
    freeglut/source/freeglut_menu.c
    freeglut/source/freeglut_misc.c
    freeglut/source/freeglut_overlay.c
    freeglut/source/freeglut_state.c
    freeglut/source/freeglut_stroke_mono_roman.c
    freeglut/source/freeglut_stroke_roman.c
    freeglut/source/freeglut_structure.c
    freeglut/source/freeglut_teapot.c
    freeglut/source/freeglut_videoresize.c
    freeglut/source/freeglut_window.c
)

add_executable(OPENGL1 ${SOURCES})

target_link_libraries(OPENGL1 OpenGL::GL OpenGL::GLU GLEW::GLEW GLUT::GLUT X11)
