int main(void)
{
	int a = 1;
	int const *const p = &a;
	int const *const *const b = &p;

	(void) b;
	(void) a;
	(void) p;
}
