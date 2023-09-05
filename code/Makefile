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
_SUBFOLDERS	= . debug entities intersections parser renderer utils vec3 \
	menu/menu menu/ambient menu/camera menu/light menu/plane menu/sphere menu/cone menu/cylinder

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FLAGS                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

CFLAGS		= -Wall -Wextra -Werror -O3
CPPFLAGS	= -I mandatory/$(INC_FOLDER)
CPPFLAGS_BONUS	= -I bonus/$(INC_FOLDER)
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
# files. Because the BONUS_FILES only contains the name of the files we use and 
# not the absolute path of them, the vpath directive helps the make to find
# the file names on it.

vpath %.c $(foreach subfolder, $(_SUBFOLDERS), mandatory/$(SRC_FOLDER)/$(subfolder))
vpath %.c $(foreach subfolder, $(_SUBFOLDERS), bonus/$(SRC_FOLDER)/$(subfolder))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FILES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

MANDATORY_FILES += debug_1 debug_2
MANDATORY_FILES += world cylinder plane shape sphere lightsource
MANDATORY_FILES += intersections_1 intersections_2
MANDATORY_FILES += read_map parser parse_shapes parse_illumination parse_utils
MANDATORY_FILES += pixel render color light ray normal
MANDATORY_FILES += vec3_add vec3_dot vec3_scale vec3_normalize vec3_cross vec3_length vec3_new \
	vec3_sub vec3_cossine vec3_compare vec3_from_strings
MANDATORY_FILES += math message
MANDATORY_FILES += main

OBJS = $(patsubst %, $(OBJ_FOLDER)/%.o, $(MANDATORY_FILES))

BONUS_DEBUG	 += world_debug debug_1 debug_2
BONUS_ENTITIES += world cylinder plane shape sphere lightsource cone
BONUS_INTER	 += intersects pl_inter sp_inter cy_inter co_inter
BONUS_PARSER 	 += read_map parser parse_shapes parse_illumination parse_utils
BONUS_RENDER 	 += color light pixel ray normal render shadow threads texture	
BONUS_VEC 	 += vec3_add vec3_dot vec3_scale vec3_normalize vec3_cross vec3_length vec3_new \
	vec3_sub vec3_cossine vec3_compare vec3_from_strings vec3_rotate vec3_between
BONUS_UTILS	 += math message
BONUS_MENU	 += ambient camera search_objects menu_display menu_handler light_display light_handler \
	sphere_display sphere_handler cone_display cone_handler \
	cylinder_display cylinder_handler plane_display plane_handler

BONUS_FILES += $(BONUS_DEBUG) $(BONUS_ENTITIES) $(BONUS_INTER) $(BONUS_PARSER) $(BONUS_RENDER) \
	$(BONUS_VEC) $(BONUS_UTILS) $(BONUS_MENU) main

BONUS_OBJS = $(patsubst %, $(OBJ_FOLDER)_bonus/%_bonus.o, $(BONUS_FILES))
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
$(NAME): $(OBJ_FOLDER) $(OBJS)
	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(LIBNC)$(RESET)"
	$(MAKE) -C $(LIBNC)

	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(GNL)$(RESET)"
	$(MAKE) -C $(GNL)

	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(MLX)$(RESET)"
	$(MAKE) -C $(MLX)

	echo "[$(CYAN) Linking $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) 
	
	echo "$(GREEN)Done.$(RESET)"
	
$(OBJ_FOLDER)/%.o: %.c
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

re: fclean
	$(MAKE) all

bonus: .bonus

.bonus: $(OBJ_FOLDER)_bonus $(BONUS_OBJS)
	touch .bonus
	
	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(LIBNC)$(RESET)"
	$(MAKE) -C $(LIBNC)

	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(GNL)$(RESET)"
	$(MAKE) -C $(GNL)

	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(MLX)$(RESET)"
	$(MAKE) -C $(MLX)

	echo "[$(CYAN) Linking $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(CPPFLAGS_BONUS) $(BONUS_OBJS) -o $(NAME) $(LDFLAGS) 
	
	echo "$(GREEN)Done.$(RESET)"

$(OBJ_FOLDER)_bonus/%_bonus.o: %_bonus.c
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) $(CPPFLAGS_BONUS) -c $< -o $@

reb: fclean
	$(MAKE) bonus

clean:	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(OBJ_FOLDER)$(RESET)"
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(DEP_FOLDER)$(RESET)"
	$(RM) $(OBJ_FOLDER) $(OBJ_FOLDER)_bonus $(DEP_FOLDER)
	$(RM) .bonus

fclean: clean
	$(MAKE) fclean -C $(LIBNC)
	$(MAKE) fclean -C $(GNL)
	$(MAKE) clean -C $(MLX)

	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                        CUSTOM RULES                                       _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_


$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

$(OBJ_FOLDER)_bonus:
	mkdir -p $(OBJ_FOLDER)_bonus

fast:
	$(MAKE) re -j

bfast:
	$(MAKE) reb -j

run: fast
	clear
	./$(NAME) $(SCENE)

brun: bfast
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
