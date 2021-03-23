# makefile config specifying locations, compiler and compilation flags

LIB_NAME = 9wada
NAME = lib$(LIB_NAME).a
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
	  get_next_line\
	  xml_parser\
	  cvector
