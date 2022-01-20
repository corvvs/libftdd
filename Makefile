CC				:=	gcc
LIBFT_DIR		:=	libft
LIBFT_A			:=	libft.a
EXEC_DIR_LIBC	:=	execs_c
EXEC_DIR_LIBFT	:=	execs_ft
MAIN_DIR		:=	mains
OUT_DIR_LIBC	:=	out_c
OUT_DIR_LIBFT	:=	out_ft
DIRS			:=	execs_c execs_ft out_c out_ft

FUNCS_PART1		:=	memset memcmp memcpy\
					strlen \
					isalpha isdigit isalnum isprint isascii \
					atoi

$(LIBFT_DIR)/$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)


$(LIBFT_A)		:	$(LIBFT_DIR)/$(LIBFT_A)
	cp $(LIBFT_DIR)/$(LIBFT_A) .


$(DIRS)			:
	mkdir -p $@

$(FUNCS_PART1)	: $(LIBFT_A) $(EXEC_DIR_LIBC) $(EXEC_DIR_LIBFT) $(OUT_DIR_LIBC) $(OUT_DIR_LIBFT)
	@echo [building $@]
	$(CC) -o $(EXEC_DIR_LIBC)/$@ $(LIBFT_A) $(MAIN_DIR)/$@.c
	$(CC) -D USE_LIBFT=1 -o $(EXEC_DIR_LIBFT)/$@ $(LIBFT_A) $(MAIN_DIR)/$@.c
	@echo [testing $@]
	$(EXEC_DIR_LIBC)/$@ 1> $(OUT_DIR_LIBC)/$@.out 2> $(OUT_DIR_LIBC)/$@.err
	@echo "[exit status: $${?}]" >> $(OUT_DIR_LIBC)/$@.out
	$(EXEC_DIR_LIBFT)/$@ 1> $(OUT_DIR_LIBFT)/$@.out 2> $(OUT_DIR_LIBFT)/$@.err
	@echo "[exit status: $${?}]" >> $(OUT_DIR_LIBFT)/$@.out
	diff -u $(OUT_DIR_LIBC)/$@.out $(OUT_DIR_LIBFT)/$@.out
	@echo [$@: ok]

clean			:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean			:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(LIBFT_A)

run				: $(FUNCS_PART1)
