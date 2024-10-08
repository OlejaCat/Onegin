CFLAGS = -Wall -Wextra -Og
ifeq ($(CC), clang)
CFLAGS += -Wconversion -Wdangling -Wdeprecated -Wdocumentation -Wformat -Wfortify-source -Wgcc-compat -Wgnu -Wignored-attributes -Wignored-pragmas -Wimplicit -Wmost -Wshadow-all -Wthread-safety -Wuninitialized -Wunused -Wformat
CFLAGS += -Wargument-outside-range -Wassign-enum -Wbitwise-instead-of-logical -Wc23-extensions -Wc11-extensions -Wcast-align -Wcast-function-type -Wcast-qual -Wcomma -Wcomment -Wcompound-token-split -Wconditional-uninitialized -Wduplicate-decl-specifier -Wduplicate-enum -Wduplicate-method-arg -Wduplicate-method-match -Wempty-body -Wempty-init-stmt -Wenum-compare -Wenum-constexpr-conversion -Wextra-tokens -Wfixed-enum-extension -Wfloat-equal -Wloop-analysis -Wframe-address -Wheader-guard -Winfinite-recursion -Wno-gnu-binary-literal -Wint-conversion -Wint-in-bool-context -Wmain -Wmisleading-indentation -Wmissing-braces -Wmissing-prototypes -Wover-aligned -Wundef -Wvla
endif
ifeq ($(CC), cc)
CFLAGS += -Waggressive-loop-optimizations -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wopenmp-simd -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wswitch-default -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-varargs -Wstack-usage=8192 -Wstack-protector
endif
ifeq ($(CC), gcc)
CFLAGS += -Waggressive-loop-optimizations -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wopenmp-simd -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wswitch-default -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-varargs -Wstack-usage=8192 -Wstack-protector
endif

INCLUDE = -I MyMiniLib/include -I include

LIBRARY = -lm

ASAN_FLAGS = -fsanitize=address,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

FLAGS = -fstack-protector-strong -fcheck-new -fstrict-overflow $(CFLAGS)
O_LEVEL = -O2
MARCH = -march=znver1

RELEASE_FLAGS = $(FLAGS) $(O_LEVEL) $(MARCH) -DNDEBUG -fomit-frame-pointer -g3 -flto
LINK_FLAGS_RELEASE = $(LIBRARY) -DNDEBUG -g3 -flto

CFLAGS += $(INCLUDE) $(ASAN_FLAGS) -DDEBUG -D_FORTIFY_SOURCES=3 -ggdb -g3

all: base

base: main.o onegin_logic.o sorting_algorithms.o string_functions.o work_with_files.o helpful_functions.o user_interaction.o logger.o my_asserts.o work_with_doubles.o
	@$(CC) $(LINK_FLAGS_RELEASE) $(RELEASE_FLAGS) main.o onegin_logic.o sorting_algorithms.o string_functions.o work_with_files.o helpful_functions.o user_interaction.o logger.o my_asserts.o work_with_doubles.o -o onegin

main.o: source/main.cpp
	@$(CC) $(RELEASE_FLAGS) -c source/main.cpp

onegin_logic.o: source/onegin_logic.cpp
	@$(CC) $(RELEASE_FLAGS) -c source/onegin_logic.cpp

sorting_algorithms.o: source/sorting_algorithms.cpp
	@$(CC) $(RELEASE_FLAGS) -c source/sorting_algorithms.cpp

string_functions.o: source/string_functions.cpp
	@$(CC) $(RELEASE_FLAGS) -c source/string_functions.cpp

work_with_files.o: source/work_with_files.cpp
	@$(CC) $(RELEASE_FLAGS) -c source/work_with_files.cpp

user_interaction.o: source/user_interaction.cpp
	@$(CC) $(RELEASE_FLAGS) -c source/user_interaction.cpp

helpful_functions.o: MyMiniLib/source/helpful_functions.cpp
	@$(CC) $(RELEASE_FLAGS) -c MyMiniLib/source/helpful_functions.cpp

logger.o: MyMiniLib/source/logger.cpp
	@$(CC) $(RELEASE_FLAGS) -c MyMiniLib/source/logger.cpp

my_asserts.o: MyMiniLib/source/my_asserts.cpp
	@$(CC) $(RELEASE_FLAGS) -c MyMiniLib/source/my_asserts.cpp

work_with_doubles.o: MyMiniLib/source/work_with_doubles.cpp
	@$(CC) $(RELEASE_FLAGS) -c MyMiniLib/source/work_with_doubles.cpp

clean:
	@rm -rf *.o onegin
