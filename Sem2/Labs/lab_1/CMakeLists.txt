cmake_minimum_required(VERSION 3.24)

project(1_lab)

set(CMAKE_CXX_STANDARD 17)


add_definitions(-DSFML_STATIC)

include_directories("ext/SFML/include/")
include_directories("inc/")
link_directories("ext/SFML/lib/")

add_executable(1_lab main.cpp inc/animation.h src/animation.cpp)

target_link_libraries("1_lab"
        debug sfml-graphics-s-d
        debug sfml-window-s-d
        debug sfml-system-s-d
        debug sfml-audio-s-d)

target_link_libraries("1_lab"
        optimized sfml-graphics-s
        optimized sfml-window-s
        optimized sfml-system-s
        optimized sfml-audio-s)

target_link_libraries("1_lab" opengl32 freetype winmm gdi32 openal32 flac vorbisenc vorbisfile vorbis ogg)


FILE(COPY "ext/res/consola.ttf" DESTINATION "ext/res/")