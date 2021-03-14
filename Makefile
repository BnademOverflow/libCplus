# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <abiri@1337.MA>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 14:42:53 by abiri             #+#    #+#              #
#    Updated: 2019/05/03 22:42:32 by abiri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NO NEED TO CHANGE THIS MAKEFILE FOR NORMAL USE

include make_config.mk

all: $(NAME)

GLOBAL_OBJ_FILES =

MODULES := $(addsuffix /make_module.mk, $(addprefix $(SRC_DIR)/, $(MODULES)))
include $(MODULES)

MODULE_RULES = $(addprefix LIB9WADA_, $(MODULES))

$(OBJ_DIR):
	@-mkdir $(OBJ_DIR)
$(NAME): $(MODULE_RULES) | $(OBJ_DIR)
	@echo "LINKING OBJECT FILES"
	@$(LINKER) $(LINKER_FLAGS) $(NAME) $(GLOBAL_OBJ_FILES)
	@echo "INDEXING LIBRARY"
	@$(RANLIB) $(RANLIB_FLAGS) $(NAME)
	@echo "CREATED $(NAME)"
clean:
	@$(DELETE_COMMAND) $(DELETE_COMMAND_FLAGS) $(OBJ_DIR)
	@echo "CLEANED OBJECT FILES"
fclean: clean
	@$(DELETE_COMMAND) $(DELETE_COMMAND_FLAGS) $(NAME)
	@echo "DELETED $(NAME)"
	@$(DELETE_COMMAND) $(DELETE_COMMAND_FLAGS) $(OBJ_DIR)
	@echo "DELETED $(OBJ_DIR)"
re: fclean all
.PHONY: all clean fclean re
