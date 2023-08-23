OS = $(shell uname)

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
#_                                          FOLDERS                                          _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

INC_FOLDER	= includes 
SRC_FOLDER	= sources
OBJ_FOLDER	= objects
DEP_FOLDER	= dependencies
LIBNC		= libnc
GNL			= gnl
MLX			= mlx_linux
_SUBFOLDERS	= . debug entities intersections parser renderer utils vec3 menu

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FLAGS                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

CFLAGS		= -Wall -Wextra -Werror -Ofast
CPPFLAGS	= -I $(INC_FOLDER) -MMD
MAKEFLAGS	= --no-print-directory
MLXFLAGS	= -L ./$(MLX) -lmlx -lXext -lX11 -lm 
LIBNCFLAGS	= -L ./$(LIBNC) -lnc
GNLFLAGS	= -L ./$(GNL) -lgnl
LDFLAGS		= $(LIBNCFLAGS) $(GNLFLAGS) $(MLXFLAGS) -lm -lpthread

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                        DEPENDENCIES                                       _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

# The vpath directive tells the Makefile to look in these folders for missing
# files. Because the _FILES only contains the name of the files we use and 
# not the absolute path of them, the vpath directive helps the make to find
# the file names on it.

vpath %.c $(foreach subfolder, $(_SUBFOLDERS), $(SRC_FOLDER)/$(subfolder))
vpath %.h $(INC_FOLDER)

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FILES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

_FILES += debug_1 debug_2
_FILES += world cylinder plane shape sphere lightsource cone
_FILES += intersects pl_inter sp_inter cy_inter co_inter
_FILES += read_map parser parse_shapes parse_illumination parse_utils
_FILES += color light pixel ray normal render shadow threads	
_FILES += vec3_add vec3_dot vec3_scale vec3_normalize vec3_cross vec3_length vec3_new \
	vec3_sub vec3_cossine vec3_compare vec3_from_strings
_FILES += math message
_FILES += menu parse_objects shapes camera ambient lights lights_info \
	spheres spheres_info spheres_info2 cones cones_info cones_info2 \
	cylinders cylinders_info cylinders_info2 planes planes_info planes_info2
_FILES += main

DEPFILES = $(patsubst %, $(DEP_FOLDER)/%.d, $(_FILES))
OBJS	 = $(patsubst %, $(OBJ_FOLDER)/%.o, $(_FILES))
NAME     = miniRT

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
else ifeq ($(SAN), U)
	CFLAGS += -fsanitize=undefined
endif

ifeq ($(OS), Darwin)
	MLX = mlx_macos
	MLXFLAGS = -L ./$(MLX) -lmlx -framework OpenGL -framework AppKit -lm
endif

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           RULES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

all: $(NAME)

#! Remove the echos and replace everything with a loading bar
$(NAME): $(OBJ_FOLDER) $(DEP_FOLDER) $(OBJS)
	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(LIBNC)$(RESET)"
	$(MAKE) -C $(LIBNC)

	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(GNL)$(RESET)"
	$(MAKE) -C $(GNL)

	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(MLX)$(RESET)"
	$(MAKE) -C $(MLX)

	echo "[$(CYAN) Linking $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) 
	
	mv $(OBJS:.o=.d) $(DEP_FOLDER)
	echo "$(GREEN)Done.$(RESET)"
	
$(OBJ_FOLDER)/%.o: %.c
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPFILES)

$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(DEP_FOLDER):
	mkdir -p $(DEP_FOLDER)

clean:	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(OBJ_FOLDER)$(RESET)"
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(DEP_FOLDER)$(RESET)"
	$(RM) $(OBJ_FOLDER) $(DEP_FOLDER)

fclean: clean
	$(MAKE) fclean -C $(LIBNC)
	$(MAKE) fclean -C $(GNL)
	$(MAKE) clean -C $(MLX)

	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                        CUSTOM RULES                                       _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

fast:
	$(MAKE) re -j

run: fast
	clear
	./$(NAME) $(SCENE)

leaks: fast
	valgrind --leak-check=full --show-leak-kinds=all --log-file=output.log ./$(NAME) $(SCENE)

norm:
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.h FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R CheckDefine $(shell find . -type f -name "*.h")
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.c FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R checkForbiddenSourceHeader $(shell find . -type f -name "*.c")

.SILENT:
