#include "get_next_line.h"

/**
 * It returns a pointer to the first occurrence 
 * of the character c in the string s
 * 
 * @param s The string to be searched.
 * @param c The character to be located.
 * 
 * @return A pointer to the first occurrence of 
 * the character c in the string s.
 */
int	ft_find_pos(const char *s, int c)
{
	char	aux;
	char	*str;
	int		i;

	aux = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == aux)
			return (i);
		else
			i++;
	}
	if (aux == '\0')
		return (i);
	else
		return (0);
}