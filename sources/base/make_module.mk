# MANUALLY GENERATED PART

LOCAL_SRC_DIR = base
MODULE_NAME = base

INCLUDES = libft.h

SRC_FILES = ft_atoi.c\
	    ft_bzero.c\
	    ft_charreplace.c\
	    ft_charsetreplace.c\
	    ft_countchar.c\
	    ft_count_if.c\
	    ft_endc.c\
	    ft_fabs.c\
	    ft_getnextvar.c\
	    ft_howmany.c\
	    ft_intsort.c\
	    ft_isalnum.c\
	    ft_isalpha.c\
	    ft_isascii.c\
	    ft_ischarin.c\
	    ft_isdigit.c\
	    ft_isprint.c\
	    ft_itoa.c\
	    ft_lstadd.c\
	    ft_lstclear.c\
	    ft_lstdel.c\
	    ft_lstdelone.c\
	    ft_lstiter.c\
	    ft_lstmap.c\
	    ft_lstnew.c\
	    ft_lstpush.c\
	    ft_match.c\
	    ft_match_parts.c\
	    ft_memalloc.c\
	    ft_memccpy.c\
	    ft_memchr.c\
	    ft_memcmp.c\
	    ft_memcpy.c\
	    ft_memdel.c\
	    ft_memmove.c\
	    ft_memset.c\
	    ft_pow.c\
	    ft_power_positif.c\
	    ft_putchar.c\
	    ft_putchar_fd.c\
	    ft_putendl.c\
	    ft_putendl_fd.c\
	    ft_putnbr_base.c\
	    ft_putnbr.c\
	    ft_putnbr_fd.c\
	    ft_putstr.c\
	    ft_putstrf.c\
	    ft_putstr_fd.c\
	    ft_putwchar.c\
	    ft_removechars.c\
	    ft_replace.c\
	    ft_scanstr.c\
	    ft_scanstr_parts.c\
	    ft_searchreplace.c\
	    ft_sqrt.c\
	    ft_startc.c\
	    ft_strcat.c\
	    ft_strchr.c\
	    ft_strcjoin.c\
	    ft_strclr.c\
	    ft_strcmp.c\
	    ft_strcpy.c\
	    ft_strdel.c\
	    ft_strdup.c\
	    ft_strequ.c\
	    ft_striter.c\
	    ft_striteri.c\
	    ft_strjoin.c\
	    ft_strlcat.c\
	    ft_strlen.c\
	    ft_strmap.c\
	    ft_strmapi.c\
	    ft_strncat.c\
	    ft_strncmp.c\
	    ft_strncpy.c\
	    ft_strnequ.c\
	    ft_strnew.c\
	    ft_strnstr.c\
	    ft_strrchr.c\
	    ft_strreplace.c\
	    ft_strsort.c\
	    ft_strsplit.c\
	    ft_strsplitcharset.c\
	    ft_strsplitescape.c\
	    ft_strstr.c\
	    ft_strsub.c\
	    ft_strtouper.c\
	    ft_strtrim.c\
	    ft_strunescape.c\
	    ft_strzero.c\
	    ft_tabfree.c\
	    ft_tabsize.c\
	    ft_tolower.c\
	    ft_toupper.c\
	    ft_unescape_args.c\
	    ft_wcharlen.c\
	    ft_wstrlen.c\
		ft_int_min.c\
	    ft_wstrlen_min.c

# AUTO GENERATED PART

include make_config.mk

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
INCLUDES := $(addprefix $(INC_DIR)/, $(INCLUDES))
INCLUDE_FLAGS = $(addprefix -I , $(INC_DIR))
GLOBAL_OBJ_FILES := $(GLOBAL_OBJ_FILES) $(OBJ_FILES)

LIBCPLUS_$(MODULE_NAME)_OBJECTS = $(OBJ_FILES)

LIBCPLUS_$(MODULE_NAME): $(OBJ_FILES)
	@echo "COMPILED MODULE $@"

$(OBJ_FILES): $(OBJ_DIR)/%.o : $(SRC_DIR)/$(LOCAL_SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "\tCREATING $@"
	@$(CC) $(FLAGS) $(INCLUDE_FLAGS) -c $< -o $@

.PHONY: LIBCPLUS_$(MODULE_NAME) LIBCPLUS_$(MODULE_NAME)_CLEAN
