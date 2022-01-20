#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "../libft/libft.h"
#ifdef USE_LIBFT
# define dd_memset ft_memset
# define dd_memcmp ft_memcmp
# define dd_memcpy ft_memcpy
# define dd_memchr ft_memchr
# define dd_strlen ft_strlen
# define dd_isalpha ft_isalpha
# define dd_isdigit ft_isdigit
# define dd_isalnum ft_isalnum
# define dd_isascii ft_isascii
# define dd_isprint ft_isprint
# define dd_toupper ft_toupper
# define dd_tolower ft_tolower
# define dd_atoi ft_atoi
#else
# define dd_memset memset
# define dd_memcmp memcmp
# define dd_memcpy memcpy
# define dd_memchr memchr
# define dd_strlen strlen
# define dd_isalpha isalpha
# define dd_isdigit isdigit
# define dd_isalnum isalnum
# define dd_isascii isascii
# define dd_isprint isprint
# define dd_toupper toupper
# define dd_tolower tolower
# define dd_atoi atoi
#endif
