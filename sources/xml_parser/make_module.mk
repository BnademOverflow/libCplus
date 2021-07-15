# MANUALLY GENERATED PART

LOCAL_SRC_DIR = xml_parser
MODULE_NAME = xml_parser

INCLUDES = xml_parser.h

SRC_FILES = main.c\
	    parser_types.c\
	    tools.c\
	    manipulations.c

# AUTO GENERATED PART

include make_config.mk

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
INCLUDES := $(addprefix $(INC_DIR)/, $(INCLUDES))
INCLUDE_FLAGS = $(addprefix -I , $(INC_DIR))
GLOBAL_OBJ_FILES := $(GLOBAL_OBJ_FILES) $(OBJ_FILES)

LIBCPLUS_$(MODULE_NAME): $(OBJ_FILES)
	@echo "COMPILED MODULE $@"

$(OBJ_FILES): $(OBJ_DIR)/%.o : $(SRC_DIR)/$(LOCAL_SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "\tCREATING $@"
	@$(CC) $(FLAGS) $(INCLUDE_FLAGS) -c $< -o $@

.PHONY: LIBCPLUS_$(MODULE_NAME) LIBCPLUS_$(MODULE_NAME)_CLEAN
