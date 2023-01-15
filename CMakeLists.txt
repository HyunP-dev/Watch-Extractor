cmake_minimum_required(VERSION 3.24)
project(Watch_Extractor C)

set(CMAKE_C_STANDARD 23)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(LIBADWAITA REQUIRED libadwaita-1)

include_directories(${GTK4_INCLUDE_DIRS} ${LIBADWAITA_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS} ${LIBADWAITA_LIBRARY_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER} ${LIBADWAITA_CFLAGS_OTHER})

add_executable(Watch_Extractor main.c)
target_link_libraries(Watch_Extractor ${GTK4_LIBRARIES} ${LIBADWAITA_LIBRARIES})