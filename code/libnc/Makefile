#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           COLORS                                          _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                          COMMANDS                                         _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

CC = cc
RM = rm -rf
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FLAGS                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address
MK		= --no-print-directory

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                          FOLDERS                                          _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

DEPS			= includes 
SRCS			= .
_SUBFOLDERS		= binary_search_tree conversions dictionary is linked_list \
					matrix memory pair print str utils vector
VPATH			= srcs $(addprefix $(SRCS)/nc_, $(_SUBFOLDERS))
OBJ_DIR			= bin

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FILES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_


NAME	= libnc.a

_FILES += isalnum isalpha isascii isdigit isprint isnum

_FILES += replace replace_all split strchr strdup striteri strjoin strlcat \
			strlcpy strlen strclen strmapi strncmp strnstr strrchr strtrim \
			substr strcmp

_FILES += putchar_fd putendl_fd putnbr_fd putstr_fd

_FILES += bzero calloc memchr memcmp memcpy memmove memset

_FILES += atoi atod itoa tochar tolower tonum toupper

_FILES += pair_new pair_print pair_copy pair_swap pair_delete pair_tostring \
			pair_clear

_FILES += matrix_new matrix_delete matrix_size matrix_copy matrix_append \
			matrix_print matrix_merge matrix_add matrix_join
					
_FILES += vector_new vector_push vector_pop vector_clear vector_delete \
			vector_copy vector_at vector_find vector_merge vector_print \
			vector_first vector_last 

_FILES += dict_new dict_insert dict_copy dict_get dict_exists dict_remove \
			dict_values_setup dict_clear dict_delete dict_to_list dict_keys \
			dict_values dict_print

_FILES += list_add_back list_add_front list_at list_clear list_delone list_find \
			list_iter list_last list_map list_new list_reverse list_size

_FILES += bstree_new bstree_insert bstree_traverse bstree_delete bstree_clear \
			bstree_print bstree_copy bstree_deepcopy bstree_find bstree_count \
			bstree_height bstree_to_list

_FILES += numlen count free clamp

OBJS			= $(_FILES:%=nc_%.o)
TARGET			= $(addprefix $(OBJ_DIR)/, $(OBJS))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           RULES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_


all: $(NAME)

$(NAME): $(OBJ_DIR) $(TARGET)
	$(AR) $(NAME) $(TARGET)
	
$(OBJ_DIR)/%.o : $(SRCS)/%.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean:	
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

norm:
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.h FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R CheckDefine $(shell find . -type f -name "*.h")
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.c FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R checkForbiddenSourceHeader $(shell find . -type f -name "*.c")

.SILENT:
