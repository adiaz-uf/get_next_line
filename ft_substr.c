#include "get_next_line.h"

/**
 * If the string is longer than the length of the substring, 
 * return the substring, otherwise return the string.
 * 
 * @param s The string to be split.
 * @param start the index of the first character to include in the substring.
 * @param len the length of the substring
 * 
 * @return A pointer to a new string.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*sub;

	i = ft_strlen(s);
	if (i - start < len)
		len = i - start;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub || !s)
		return (0);
	j = 0;
	if (start < i)
	{
		while (j < len && s[j + start] != '\0')
		{
			sub[j] = s[j + start];
			j++;
		}
	}
	sub[j] = '\0';
	return (sub);
}