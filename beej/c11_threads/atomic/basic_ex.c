atomic_int a = 0;
int b = 0;
thread1()
{
	a += 3;		// atomic
	a = a + 3;	// NOT atomic, has many read and write of atomic in one line. not gud
}

thread2()
{
	// all atomic:
	a += b;
	a *= b;//any math
	a |= b;//any bitwise
	a++;
	++a;
	a >>= b;//any shift
}
