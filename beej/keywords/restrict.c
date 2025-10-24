int main(void)
{
	int a = 1;
	int *restrict b = &a;//only for optimisations,
						 // no modifications to 'a' using a different pointer while scope lasts
						 // also no 'a = 2'
	(void) a;
	(void) b;
}
