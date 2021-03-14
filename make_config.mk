# makefile config specifying locations, compiler and compilation flags

NAME = lib9wada.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_DIR = sources
INC_DIR = includes
OBJ_DIR = objects
DELETE_COMMAND = rm
DELETE_COMMAND_FLAGS = -rf
LINKER = ar
LINKER_FLAGS = rc
RANLIB = ranlib
RANLIB_FLAGS =

# IN HERE ADD OR REMOVE MODULES

MODULES = base\
	  ttslist\
	  get_next_line
