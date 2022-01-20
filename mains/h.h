#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../libft/libft.h"
#ifdef USE_LIBFT
# define dd_memset ft_memset
# define dd_memcmp ft_memcmp
# define dd_strlen ft_strlen
# define dd_isalpha ft_isalpha
# define dd_isdigit ft_isdigit
# define dd_isalnum ft_isalnum
# define dd_isascii ft_isascii
# define dd_isprint ft_isprint
#else
# define dd_memset memset
# define dd_memcmp memcmp
# define dd_strlen strlen
# define dd_isalpha isalpha
# define dd_isdigit isdigit
# define dd_isalnum isalnum
# define dd_isascii isascii
# define dd_isprint isprint
#endif

