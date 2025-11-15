int	main(void)
{
	int a = 0;
	a = _Generic(a, 
			int: 1,
			float: 1,
			char: 1,
			default: 1
			);
	char b = _Generic(a,
			int: 'a'
			);
	//a switch thing
	//only takes types
	//can do function type select
	//can call funcs or return values
	//usually gets wrapped in macros for use
	//cannot do returns, can call any funcs otherwise
	return (a + b);
}
