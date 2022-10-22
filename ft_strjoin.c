#include "get_next_line.h"

/**
 * It takes two strings and returns a new string 
 * that is the concatenation of the two strings
 * 
 * @param s1 The first string to be joined.
 * @param s2 The string to be appended to the end of s1.
 * 
 * @return A pointer to a new string that is the result 
 * of the concatenation of s1 and s2.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	size_t	size;
	size_t	i;
	size_t	j;

	size = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	c = malloc(sizeof(char) * size + 1);
	if (!c)
		return (0);
	i = 0;
	while (i < ft_strlen((char *)s1))
	{
		c[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen((char *)s2))
	{
		c[i] = s2[j];
		i++;
		j++;
	}
	c[i] = '\0';
	return (c);
}