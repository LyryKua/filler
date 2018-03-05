cmake_minimum_required(VERSION 3.8)

project(magic)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

include_directories(
        libftprintf/libft/inc
        libftprintf/inc
) # header directories

link_directories(
        libftprintf
) # library directories

link_libraries(
        ftprintf
        mlx
)

set(HEADERS
        visualization/visualization.h
        visualization/color.h
        ) # headers

set(SOURCE_FILES
        visualization/graphics.c
        visualization/plateau_piece.c

        visualization/main.c) # sources

add_executable(magic ${SOURCE_FILES} ${HEADERS}) # compilation

target_link_libraries(magic "-framework OpenGL" "-framework AppKit")
