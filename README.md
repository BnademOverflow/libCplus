# LibC+
Wonderful library with lots of useful functions, algorithms and data structures in C, link it with -lC+
Better than C, not as much as c++

# Usage
Compile the library with
```
make
```
To link it with your project use flag `-lC+` with GCC
```
gcc main.c -lC+
```
Include files depending on functions and modules you will use
all header files are available in `includes` directory

# Library Structure And How To Contribute
the root of the repo contains
```
Makefile
make_config.mk
sources 
includes
author
LICENSE
README.md
```
# Makefile
This makefile does not have rules for every source file, in fact it is static and includes other makefiles.
the `make_config.mk` makefile contains config variables, like what compiler to use, and what _**modules**_ to compile (we'll get to that later)
the sources directory contains multiple subdirectories
```
base
get_next_line
ttslist
ft_printf
```
Each subdirectory of `sources` is called a `module`
Every module contains source files and a `make_module.mk` file
Here's a preview of a `make_module.mk` file
```makefile
# MANUALLY GENERATED PART

LOCAL_SRC_DIR = ttslist
MODULE_NAME = ttslist

INCLUDES = ttslist.h

SRC_FILES = ttslist_constructors.c\
	    ttslist_delete.c\
	    ttslist_iterator.c\
	    ttslist_operations.c\
	    ttslist_purge.c\
	    ttslist_tools.c

# AUTO GENERATED PART

include make_config.mk

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
INCLUDES := $(addprefix $(INC_DIR)/, $(INCLUDES))
...
...
...
```
We will just pay attention to the _MANUALLY GENERATED PART_
in it you specify a **unique** module name, and the module directory name, header files to include, and source files
the makefile takes care of the rest
After adding a new module, we need to load it, so the makefile will compile it and link it to the library.
We do that in the `make_config.mk`
```makefile
# makefile config specifying locations, compiler and compilation flags

NAME = libC+.a
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
```
This `make_config.mk` also contains other config variables, so you can change the compiler you use or the library name.
# The documentations
Every module should contain a README.md file, containing the documentation and explaining what each function does, with its prototype and usage.
finally, the author file contains names or logins of people who contributed to this library.
