#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
 int i;

 i = 0;
 while (s1[i] || s2[i])
 {
  if (s1[i] < s2[i])
   return (-1);
  if (s1[i] > s2[i])
   return (1);
  i++;
 }
 return (0);
}

int main()
{
    char str1[] = "izzzz";
    char str2[] = "Hzzzz";

    printf("%d", ft_strcmp(str1, str2));
    return 0;
}
