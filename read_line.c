#include "push_swap.h"

#define SH_LINE_BUFFSIZE 10

static char	*stradd(char *s1, char const *s2)
{
	char	*ret;
	size_t	size_s1;
	size_t	size_s2;

	size_s1 = 0;
	if (s1 != NULL)
		size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	ret = malloc((sizeof(char) * (size_s1 + size_s2) + 1));
	if (ret == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		ft_memcpy(ret, s1, size_s1);
		ft_memcpy(&ret[size_s1], s2, size_s2 + 1);
		free(s1);
	}
	else
		ft_memcpy(ret, s2, size_s2 + 1);
	return (ret);
}

char	*sh_read_line(void)
{
	char	buff[SH_LINE_BUFFSIZE + 1];
	char	*str;
	size_t	ret;

	str = NULL;
	while (1)
	{
		ret = read(1, buff, SH_LINE_BUFFSIZE);
		buff[ret] = 0;
		str = stradd(str, buff);
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	return (str);
}