void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	argc = 0;
	while (argv[argc][i])
	{
		ft_putchar(argv[argc][i]);
		i++;
	}
	ft_putchar('\n');
	return 0;
}
