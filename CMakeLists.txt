cmake_minimum_required(VERSION 3.8)

project(khrechen.filler)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

include_directories(
        libftprintf/libft/inc
        libftprintf/inc
        inc
) # header directories

link_directories(
        libftprintf
) # library directories

link_libraries(
        ftprintf
)

set(HEADERS
        inc/filler.h
        ) # headers

set(SOURCE_FILES
        srcs/insert_piece.c
#        srcs/lists.c
        srcs/plateau_piece.c
        srcs/putsqr.c
        srcs/set_i_j.c
        srcs/wave.c

        srcs/main.c
        ) # sources

add_executable(khrechen.filler ${SOURCE_FILES} ${HEADERS}) # compilation
