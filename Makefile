FLAGS = -Wall -Werror -Wextra -g
CC = cc

NAME = push_swap
BONUS_NAME = checker

PATH_LIBFT = libft
LIBFT = libft.a

PATH_GNL = libft/get_next_line
GNL = get_next_line.a

PATH_PRINTF = ft_printf
FT_PRINTF = libftprintf.a

YELLOW = "\e[93m"
BRIGHT_GREEN = "\e[1;92m" 	#bold
RED = "\e[1;31m" 			#bold
RESET = "\e[0m"

FILES_LIST = check_efficiency/check_efficiency_no_save \
				check_efficiency/check_efficiency \
				check_efficiency/check_efficiency_utils \
				check_efficiency/moves_counter_no_save \
				operations/op_rev_rotate \
				lib_dll/ft_create_list \
				lib_dll/ft_create_node \
				lib_dll/ft_free_list \
				lib_dll/ft_list_size \
				lib_dll/ft_list_last \
				lib_dll/ft_list_addback \
				lib_dll/ft_list_addfront \
				lib_dll/ft_list_find_node \
				operations/op_rotate \
				operations/op_swap_and_push \
				sorting_fts/ft_two_and_four_numbers \
				sorting_fts/ft_three_numbers \
				sorting_fts/ft_five_numbers \
				sorting_fts/push_b_to_a \
				sorting_fts/push_a_to_b \
				sorting_fts/sorting \
				check_input \
				find_functions \
				index_stack \
				initialize_stack \
				push_swap_utils \
				main \

FUNCTIONS = $(patsubst %, %.c, $(FILES_LIST))

FUNCTIONS_OBJ = $(FUNCTIONS:.c=.o)

BONUS_FILES = bonus_checker/checker \
				index_stack \
				initialize_stack \
				push_swap_utils \
				check_input \
				operations/op_rev_rotate \
				operations/op_rotate \
				operations/op_swap_and_push \
				lib_dll/ft_create_list \
				lib_dll/ft_create_node \
				lib_dll/ft_free_list \
				lib_dll/ft_list_size \
				lib_dll/ft_list_last \
				lib_dll/ft_list_addback \
				lib_dll/ft_list_addfront \
				lib_dll/ft_list_find_node \
			
BONUS = $(patsubst %, %.c, $(BONUS_FILES))

BONUS_OBJ = $(BONUS_FILE:.c=.o)

all:
	@echo $(YELLOW) "Compiling..." $(RESET)
	@{ \
	    $(MAKE) --no-print-directory build > build.log 2>&1 & \
	    PID=$$!; \
	    chars="/-\\|"; \
	    while kill -0 $$PID 2>/dev/null; do \
	        echo $(YELLOW) "Compiling..." $(RESET); \
			sleep 0.8; \
	    done; \
	    wait $$PID; \
	    STATUS=$$?; \
	    if [ $$STATUS -eq 0 ]; then \
	        echo $(BRIGHT_GREEN) "Push Swap compiled successfully!" $(RESET); \
	        rm -f build.log; \
	    else \
	        echo $(RED) "Failed!" $(RESET); \
	        cat build.log; \
	        rm -f build.log; \
	        exit 1; \
	    fi \
	}

build: $(NAME)

%.o: %.c
	$(CC) -g $(FLAGS) -c $< -o $@
	
$(NAME): $(FUNCTIONS_OBJ)
	@$(MAKE) -C $(PATH_LIBFT)
	@$(MAKE) -C $(PATH_GNL)
	@$(MAKE) -C $(PATH_PRINTF)
	@$(CC) $(FLAGS) $(FUNCTIONS_OBJ) $(PATH_LIBFT)/$(LIBFT) $(PATH_GNL)/$(GNL) $(PATH_PRINTF)/$(FT_PRINTF) -o $(NAME)
	
$(BONUS_NAME): all

bonus: $(BONUS_NAME)
	@$(MAKE) -C $(PATH_LIBFT)
	@$(MAKE) -C $(PATH_GNL)
	@$(MAKE) -C $(PATH_PRINTF)
	@$(CC) $(FLAGS) -g $(BONUS) $(PATH_LIBFT)/$(LIBFT) $(PATH_GNL)/$(GNL) ./bonus_checker/push_swap_bonus.h -o $(BONUS_NAME)

clean:
	@$(MAKE) clean -C $(PATH_LIBFT)
	@$(MAKE) clean -C $(PATH_GNL)
	@$(MAKE) clean -C $(PATH_PRINTF)
	@rm -f $(FUNCTIONS_OBJ) $(BONUS_OBJ)

fclean: clean
	@$(MAKE) fclean -C $(PATH_LIBFT)
	@$(MAKE) fclean -C $(PATH_GNL)
	@$(MAKE) fclean -C $(PATH_PRINTF)
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: