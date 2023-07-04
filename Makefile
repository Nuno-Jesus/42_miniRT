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

CFLAGS		= -Wall -Wextra -Werror
MAKEFLAGS	= --no-print-directory

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                          FOLDERS                                          _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

INCLUDES	= includes 
SOURCES		= sources
OBJECTS		= objects
LIBNC		= libnc
GNL			= gnl
_SUBFOLDERS	= . destroy parser entities utils vector

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                        DEPENDENCIES                                       _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

# The vpath directive tells the Makefile to look in these folders for missing
# files. Because the _FILES only contains the name of the files we use and 
# not the absolute path of them, the vpath directive helps the make to find
# the file names on it.

vpath %.c $(foreach subfolder, $(_SUBFOLDERS), $(SOURCES)/$(subfolder))
vpath %.h $(INCLUDES)

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FILES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

NAME	= miniRT
_VECTOR	= vector_add vector_dot vector_mult vector_norm vector_cross vector_mod vector_new \
	vector_sub vector_debug
_DESTROY = destroy
_PARSER = read_map parser parse_shapes parse_illumination 
_ENTITIES = cylinder plane sphere source ambient camera
_UTILS = atof message parse_utils
_FILES	= main $(_VECTOR) $(_DESTROY) $(_PARSER) $(_ENTITIES) $(_UTILS)
TARGET	= $(patsubst %, %.o, $(_FILES))
OBJS	= $(foreach target, $(TARGET), $(OBJECTS)/$(target))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                       CONDITIONALS                                        _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

# To make use of these flags, you must define them in the command line, when
# running the make command. For instance, if you want the debug flag:
#	make D=1
# The value of 1 is a dummy value, as the make command needs an assignment
# to recognize D as a variable, otherwise it would be considered a target
# If you need both debug and sanitizer:
# 	make D=1 SAN=A

ifdef D
	CFLAGS += -g
endif

ifeq ($(SAN), A)
	CFLAGS += -fsanitize=address
else ifeq ($(SAN), L)
	CFLAGS += -fsanitize=leak
else ifeq ($(SAN), M)
	CFLAGS += -fsanitize=memory
else ifeq ($(SAN), T)
	CFLAGS += -fsanitize=thread
# else ifeq ($(SAN), U)
# 	CFLAGS += -fsanitize=undefined
endif
		
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           RULES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJS)
	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(LIBNC)$(RESET)"
	$(MAKE) -C $(LIBNC)/

	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(GNL)$(RESET)"
	$(MAKE) -C $(GNL)/

	echo "[$(CYAN) Linking $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INCLUDES) -lnc -lm -L $(LIBNC) -lnc -L $(GNL) -lgnl
	
	echo "$(GREEN)Done.$(RESET)"
	
$(OBJECTS)/%.o: %.c
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(OBJECTS):
	mkdir -p $(OBJECTS)



clean:	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(OBJECTS)$(RESET)"
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C $(LIBNC)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

run: re
	./$(NAME) $(SCENE)

fast:
	$(MAKE) re -j

leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --log-file=output.log ./$(NAME) $(SCENE)

norm:
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.h FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R CheckDefine $(shell find . -type f -name "*.h")
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.c FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R checkForbiddenSourceHeader $(shell find . -type f -name "*.c")

.SILENT:
