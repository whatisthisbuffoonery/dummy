typedef _Atomic double atomic_double;//works fine, can take other keywords on this line
typedef _Atomic(double) atomic_double;//other form, no mixing other keywords here
typedef _Atomic(struct s_something) atomic_something;//use case for second form
unsigned atomic_double;//invalid after typedef
