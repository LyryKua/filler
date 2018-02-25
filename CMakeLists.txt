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
		srcs/plateau_piece.c

		srcs/main.c
		srcs/lists.c) # sources

add_executable(khrechen.filler ${SOURCE_FILES} ${HEADERS}) # compilation
