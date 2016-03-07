char *ft_strupcase(char *str)
{
    int index = 0;

    while (str[index])
    {
        if (str[index] >= 'a' && str[index] <= 'z')
            {
                str[index] = ('A' + str[index] - 'a');
                index++;
            }
        index++;
    }
   return str;
}
