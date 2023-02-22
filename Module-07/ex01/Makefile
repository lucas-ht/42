# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#                                                                Config                                                                               #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

NAME			:=	iter

CC 				:=	c++
CFLAGS			:=	-Wall -Wextra -Werror -std=c++98
CDEBUG_FLAGS	:=	-Wall -g
CFLAGS_EXEC		:=

CINCLUDES		:=	./

CLIBRARY		:=	0	# 0 | 1 : Compiles to a static library
CBONUS			:=	0	# 0 | 1 : Compiles only the bonus files
CBONUS_NAME		:=	$(NAME)

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#                                                                Sources                                                                              #
# ━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ #

SOURCES			:=	main.cpp


BONUS			:=


# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#                                                                Default                                                                              #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

all:			$(NAME)
	@:;

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#                                                                 Hooks                                                                               #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

_hook_name:

_hook_clean:

_hook_fclean:

_hook_header:

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#                                                                 Rules                                                                               #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

$(NAME):		_title _progress_header _compile_smart

header:			_clean _title _set_header _set_debug _hook_header _compile
	@$(MAKE) -s _clean

bonus:			_title_bonus _set_bonus $(NAME)

clean:			_title
	@$(MAKE) -s _clean
	@$(call print_clean)
	@$(MAKE) -s _hook_clean

fclean:			_title
	@$(MAKE) -s _fclean
	@$(call print_clean)
	@$(MAKE) -s _hook_fclean

re: 			fclean _compile_smart

rebonus:		_title_bonus fclean _set_bonus _compile_smart
reb:			rebonus

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#                                                                 Logic                                                                               #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

SOURCES_DIR		:=	./
BUILD_DIR		:=	./build/

rwildcard		 =	$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

EXTENSION		 =	$(lastword $(subst ., , $(SOURCES)))
OBJECTS			 =	$(SOURCES:%.$(EXTENSION)=$(BUILD_DIR)%.o)
HEADERS			:=	$(call rwildcard,$(firstword $(CINCLUDES)),*.h *.hpp)

$(BUILD_DIR)%.o: $(SOURCES_DIR)%.$(EXTENSION)
	@mkdir -p $(@D);
	@$(CC) -c $(CFLAGS) $(addprefix -I , $(CINCLUDES)) $< -o $@;
	@$(call progress,$(subst $(subst ./,,$(SOURCES_DIR)),,$<), 1)

_compile:
ifeq ($(strip $(CLIBRARY)), 1)
	@$(MAKE) -s _compile_lib NAME='$(strip $(NAME))' SOURCES='$(strip $(SOURCES))' CFLAGS='$(strip $(CFLAGS))'										\
	                         SOURCES_DIR='$(strip $(SOURCES_DIR))' UI_COMPILE='$(strip $(UI_COMPILE))'
else
	@$(MAKE) -s _compile_exec NAME='$(strip $(NAME))' SOURCES='$(strip $(SOURCES))' CFLAGS='$(strip $(CFLAGS))'										\
	                          SOURCES_DIR='$(strip $(SOURCES_DIR))' UI_COMPILE='$(strip $(UI_COMPILE))'
endif
	@$(call print_done)

_compile_smart:	_progress_file _set_debug _hook_name
	@$(if $(shell [[ (-e $(NAME)) && ($(FILE_TOTAL) == 0) ]] && echo 1),																			\
		$(call print_nothing),																														\
		$(MAKE) -s _compile NAME='$(strip $(NAME))' CFLAGS='$(strip $(CFLAGS))' SOURCES='$(strip $(SOURCES))'										\
		                    SOURCES_DIR='$(strip $(SOURCES_DIR))';																					\
	)

_compile_exec: _progress_file _progress_header _progress_info $(OBJECTS)
ifneq ($(strip $(SOURCES_DIR)), )
	@$(call print_exec,$(NAME))
	@$(CC) $(CFLAGS) $(addprefix -I , $(CINCLUDES)) $(OBJECTS) $(CFLAGS_EXEC) -o $(NAME);
endif

_compile_lib: _progress_file _progress_header _progress_info $(OBJECTS)
ifneq ($(strip $(SOURCES_DIR)), )
	@$(call print_linking,$(NAME))
	@ar -rcs $(NAME) $(OBJECTS);
endif

_clean:
	@rm -rf $(BUILD_DIR);

_fclean:
	@$(MAKE) -s _clean
	@rm -f $(NAME);
	@rm -f $(CBONUS_NAME);

_set_header:
	@$(eval UI_COMPILE := $(shell printf '1'))
	@$(eval SOURCES := $(shell printf '$(strip $(HEADERS))'))
	@$(eval SOURCES_DIR := $(shell printf ''))

_set_bonus:
ifeq ($(strip $(CBONUS)), 1)
	@$(eval SOURCES := $(shell printf '$(strip $(BONUS))'))
else
	@$(eval SOURCES := $(shell printf '$(strip $(SOURCES) $(BONUS))'))
endif
	@$(eval OBJECTS := $(SOURCES:%.$(EXTENSION)=$(BUILD_DIR)%.o))
	@$(eval NAME := $(shell printf '$(strip $(CBONUS_NAME))'))
	@$(eval CFLAGS := $(shell printf '\$(CFLAGS) \-D BONUS'))
	@$(eval CDEBUG_FLAGS := $(shell printf '\$(CDEBUG_FLAGS) \-D BONUS'))

_set_debug:
ifeq ($(strip $(debug)), 1)
	@$(eval CFLAGS := $(shell printf '\$(CDEBUG_FLAGS) \-D DEBUG'))
endif
ifeq ($(strip $(leaks)), 1)
	@$(eval CFLAGS := $(shell printf '\$(CFLAGS) \-D DEBUG_LEAKS'))
endif

.PHONY:				all								$(NAME)							$(CBONUS_NAME)													\
																																					\
					header							bonus							clean							fclean							\
					re								rebonus							reb																\
					_clean							_fclean																							\
																																					\
					_hook_name						_hook_clean						_hook_fclean					_hook_header					\
																																					\
					_compile						_compile_smart 					_compile_lib					_compile_exec					\
																																					\
					_set_header						_set_bonus						_set_debug														\
																																					\
					_title							_title_bonus																					\
					_progress_header				_progress_file					_progress_info

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#                                                               UI Config                                                                             #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

UI_TITLE		:=	1	# 0 | 1 : Draws the title
UI_PROGRESS		:=	1	# 0 | 1 : Draws the progress bar
UI_COMPILE		:=	0	# 0 | 1 : Draws the compiling messages
UI_MESSAGE		:=	1	# 0 | 1 : Draws the other messages
UI_NOTHING		:=	1	# 0 | 1 : Draws a message if the target if done
UI_INFO			:=	1	# 0 | 1 : Draws the compiler's info

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#                                                                 Colors                                                                              #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

COLOR_ESC		:=	\033[
COLOR_END		:=	m
COLOR_FOR		:=	$(addprefix $(COLOR_ESC), 38;5;)
COLOR_BAC		:=	$(addprefix $(COLOR_ESC), 48;5;)

COLOR_RESET		:=	$(addsuffix $(COLOR_END), $(addprefix $(COLOR_ESC), 0))
COLOR_BOLD		:=	$(addsuffix $(COLOR_END), $(addprefix $(COLOR_ESC), 1))

COLOR_SUCCESS	:=	$(addsuffix $(COLOR_END), $(addprefix $(COLOR_FOR), 190))
COLOR_WARNING	:=	$(addsuffix $(COLOR_END), $(addprefix $(COLOR_FOR), 220))
COLOR_DANGER	:=	$(addsuffix $(COLOR_END), $(addprefix $(COLOR_FOR), 196))
COLOR_ACCENT	:=	$(addsuffix $(COLOR_END), $(addprefix $(COLOR_FOR), 105))
COLOR_INFO		:=	$(addsuffix $(COLOR_END), $(addprefix $(COLOR_FOR), 215))
COLOR_PROGRESS	:=	$(addsuffix $(COLOR_END), $(addprefix $(COLOR_FOR), 117))

COLOR_LGREY		:=	$(addsuffix $(COLOR_END), $(addprefix $(COLOR_FOR), 250))
COLOR_DGREY		:=	$(addsuffix $(COLOR_END), $(addprefix $(COLOR_FOR), 240))

# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #
#                                                                 Style                                                                               #
# ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ #

PRINT_WIDTH		:=	$(shell tput cols)

PRINT_NAME		 =	$(firstword $(subst ., , $(shell printf $(NAME) | tr '[:lower:]' '[:upper:]')))
PRINT_PREFIX	 =	$(COLOR_BOLD)$(COLOR_DGREY)[$(COLOR_RESET)$(COLOR_LGREY)$(PRINT_NAME)$(COLOR_BOLD)$(COLOR_DGREY)] $(COLOR_ACCENT)~$(COLOR_RESET)
PRINT_TITLE 	:=	1
PRINT_PROGRESS	:=	━

FILE_CURRENT	:=	1
FILE_TOTAL		:=	0
FILE_PERCENT	 =	$(shell printf $$(( $(FILE_CURRENT) * 100 / $(FILE_TOTAL) )))

# Title
_title:
	@$(call title,$(PRINT_NAME))

_title_bonus:
	@$(call title,$(PRINT_NAME)_BONUS)

define title
	@if [[ ($(UI_TITLE) == 1) && $(strip $(PRINT_TITLE)) == 1 ]]; then																				\
		$(eval LEN := $(shell printf $(1) | wc -m)):;																								\
		printf '$(COLOR_DGREY)';																													\
		printf '━%.0s' $$(seq $$(( $(PRINT_WIDTH) / 2 - $(LEN) / 2 - 2 )));																			\
		printf '$(COLOR_RESET) $(subst _, ,$(1)) $(COLOR_DGREY)';																					\
		printf '━%.0s' $$(seq $$(( $(PRINT_WIDTH) - ($(PRINT_WIDTH) / 2 - $(LEN) / 2) - $(LEN) )));													\
		printf '$(COLOR_RESET)\n\n';																												\
		$(eval PRINT_TITLE := $(shell printf 0)):;																									\
	fi;
endef

# Print functions
define print_exec
	@if [ $(UI_MESSAGE) == 1 ]; then																												\
		printf "$(PRINT_PREFIX)$(COLOR_PROGRESS) Compiling $(1)$(COLOR_RESET)\n";																	\
	fi;
endef

define print_linking
	@if [ $(UI_MESSAGE) == 1 ]; then																												\
		printf "$(PRINT_PREFIX)$(COLOR_PROGRESS) Linking $(1)$(COLOR_RESET)\n";																		\
	fi;
endef

define print_clean
	@if [ $(UI_MESSAGE) == 1 ]; then																												\
		printf "$(PRINT_PREFIX)$(COLOR_WARNING) Cleaning $(COLOR_RESET)\n\n";																		\
	fi;
endef

define print_nothing
	@if [[ $(UI_NOTHING) == 1 && $(UI_NOTHING) == 1 ]]; then																						\
		printf "$(PRINT_PREFIX)$(COLOR_WARNING) $(NAME) is already compiled !$(COLOR_RESET)\n\n";													\
	fi;
endef

define print_done
	@if [ $(UI_MESSAGE) == 1 ]; then																												\
		printf "$(PRINT_PREFIX)$(COLOR_SUCCESS) Done !$(COLOR_RESET)\n\n";																			\
	fi;
endef

# Check if a header file has changed
_progress_header:
	$(if $(shell [ "$(strip $(HEADERS))" ] && echo 1),																								\
		$(eval HEADER_NEWEST := $(shell printf $(firstword $(HEADERS))))																			\
	)
	@$(foreach HEADER, $(HEADERS),																													\
		$(if $(shell [[ "$(strip $(CINCLUDES))" && ($(HEADER) -nt $(HEADER_NEWEST)) ]] && echo 1),													\
			$(eval HEADER_NEWEST := $(shell printf $(HEADER)))																						\
		)																																			\
	)
	@$(foreach OBJECT, $(OBJECTS),																													\
		$(if $(shell [[ "$(strip $(CINCLUDES))" && (-e $(OBJECT)) && ($(HEADER_NEWEST) -nt $(OBJECT)) ]] && echo 1),								\
			$(MAKE) -s _fclean																														\
		)																																			\
	)

# Count the number of file to compile
_progress_file:
	@$(eval FILE_TOTAL := $(shell printf 0))
	@$(foreach SOURCE, $(SOURCES),																													\
		$(if $(shell [ $(SOURCE:%.$(EXTENSION)=$(BUILD_DIR)%.o) -ot $(addprefix $(SOURCES_DIR), $(SOURCE)) ] && echo 1),							\
			$(eval FILE_TOTAL := $(shell printf $$(( $(FILE_TOTAL) + 1 ))))																			\
		)																																			\
	)

# Display the info
_progress_info:
	@if [ $(UI_INFO) == 1 ]; then \
		printf "$(PRINT_PREFIX) CC      : $(COLOR_PROGRESS)$(strip $(CC))$(COLOR_RESET)\n"; \
		printf "$(PRINT_PREFIX) Flags   : $(COLOR_PROGRESS)$(strip $(CFLAGS))$(COLOR_RESET)\n"; \
	fi;
	@if [[ ($(UI_COMPILE) == 0) && ($(UI_MESSAGE) == 1) && ($(FILE_TOTAL) != 0) ]]; then \
		printf "$(PRINT_PREFIX) Compiling ...\n"; \
	fi;

# Draw for each file
define progress
	@if [[ ($(UI_PROGRESS) == 1) && ($(FILE_CURRENT) != 1) ]]; then \
		tput el;\
	fi;
	@if [ $(UI_COMPILE) == 1 ]; then																												\
		$(eval LEN := $(shell printf '[$(PRINT_NAME)] ~ Compiling $(1)' | wc -m)):;																	\
		printf "$(PRINT_PREFIX) Compiling $(COLOR_INFO)$(1)$(COLOR_RESET)";																			\
		printf ' %.0s' $$(seq $$(( $(PRINT_WIDTH) - $(LEN) - 3 )));																					\
		printf '$(COLOR_BOLD)$(COLOR_DGREY)[$(COLOR_RESET)$(COLOR_SUCCESS)✓$(COLOR_BOLD)$(COLOR_DGREY)]$(COLOR_RESET)\n';							\
	fi;
	@if [ $(UI_PROGRESS) == 1 ]; then																												\
		printf '$(COLOR_SUCCESS)';																													\
		$(eval LEN := $(shell printf $$(( ($(PRINT_WIDTH) - 5) * $(FILE_PERCENT) / 100 )) )):;														\
		if [ $(LEN) != 0 ]; then																													\
			printf '$(PRINT_PROGRESS)%.0s' $$(seq $(LEN));																											\
		fi;																																			\
		if [ $(FILE_TOTAL) != $(FILE_CURRENT) ]; then																								\
			printf '$(COLOR_RESET)$(COLOR_DGREY)';																									\
			printf '$(PRINT_PROGRESS)%.0s' $$(seq $$(( ($(PRINT_WIDTH) - 5) - $(LEN) )));																			\
			printf ' ';																																\
		fi;																																			\
		printf '$(COLOR_RESET) $(FILE_PERCENT)%%$(COLOR_RESET)\n\eM';																					\
		if [ $(FILE_TOTAL) == $(FILE_CURRENT) ]; then																								\
			printf '\eD\n';																															\
		fi;																																			\
		$(eval FILE_CURRENT := $(shell printf $$(( $(FILE_CURRENT) + 1 )))):;																		\
	fi;
endef
