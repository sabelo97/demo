#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char ref;
	int index;
	int find;
	
	index = 0;
	find = 0;
	while (find <= index && str[index] != '\0')
	{
		if (str[index] == to_find[find] && str[index] != '\0')
		{
			ref = to_find[find];
			write (1, &ref, 1);
			index++;
			find++;
		}
		else
		{
			while (str[index] != to_find[find])
			{
				index++;
			}
		}
	{
	return 0;
}

int main()
{
	char str1[] = "12962344234";
	char str2[] = "96";
	
	ft_strstr(str1, str2);
	return 0;
}
