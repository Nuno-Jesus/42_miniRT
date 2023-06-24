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
BINARIES	= binaries
_SUBFOLDERS	= .

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                        DEPENDENCIES                                       _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

# The vpath directive is used to tell the Makefile where to look for the files, that
# are not in the current directory and match a pattern.
vpath %.c $(addprefix $(SOURCES)/, $(_SUBFOLDERS))
vpath %.h $(INCLUDES)

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FILES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

NAME	= miniRT
_FILES	= main hello
TARGET	= $(_FILES:%=%.o)
OBJS	= $(addprefix $(BINARIES)/, $(TARGET))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                       CONDITIONALS                                        _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

# Usually, we only define this macro in the command line when we want to compile in debug mode.
# If you want to activate debug mode, you can run the following command:
# 		make DEBUG=1
# This appends the flags below to the CFLAGS variable.
# Final CFLAGS: -Wall -Wextra -Werror -g -fsanitize=address
ifdef DEBUG
	CFLAGS += -g
endif

ifeq ($(SAN), A)
	CFLAGS += -fsanitize=address
else ifeq ($(SAN), L)
	CFLAGS += -fsanitize=leak
else ifeq ($(SAN), M)
	CFLAGS += -fsanitize=memory
else ifeq ($(SAN), U)
	CFLAGS += -fsanitize=undefined
endif
		
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           RULES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

all: $(NAME)

$(NAME): $(BINARIES) $(OBJS)
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INCLUDES)
	
	echo "$(GREEN)Done.$(RESET)"
	
$(BINARIES)/%.o : $(SOURCES)/%.c
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(BINARIES):
	mkdir -p $(BINARIES)

clean:	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(BINARIES)$(RESET)"
	$(RM) $(BINARIES)

fclean: clean
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --log-file=output.log ./$(NAME) $(SCENE)

norm:
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.h FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R CheckDefine $(shell find . -type f -name "*.h")
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.c FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R checkForbiddenSourceHeader $(shell find . -type f -name "*.c")

.SILENT:
