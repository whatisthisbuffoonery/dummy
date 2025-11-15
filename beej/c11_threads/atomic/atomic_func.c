// Store a value into an atomic object
void atomic_store_explicit(volatile A *object, C desired, memory_order order);

// Load a value from an atomic object
C atomic_load_explicit(const volatile A *object, memory_order order);

// Atomically exchange a value and return the old value
C atomic_exchange_explicit(volatile A *object, C desired, memory_order order);

// Atomic compare and exchange (strong)
_Bool atomic_compare_exchange_strong_explicit(
    volatile A *object, 
    C *expected, 
    C desired, 
    memory_order success, 
    memory_order failure
);

// Atomic compare and exchange (weak)
_Bool atomic_compare_exchange_weak_explicit(
    volatile A *object, 
    C *expected, 
    C desired, 
    memory_order success, 
    memory_order failure
);

// Atomic fetch and add
C atomic_fetch_add_explicit(volatile A *object, C operand, memory_order order);

// Atomic fetch and subtract
C atomic_fetch_sub_explicit(volatile A *object, C operand, memory_order order);

// Atomic flag test and set
_Bool atomic_flag_test_and_set_explicit(volatile atomic_flag *object, memory_order order);

// Atomic flag clear
void atomic_flag_clear_explicit(volatile atomic_flag *object, memory_order order);

//A means whatever atomic type
//C means the corresponding non atomic type of A


//atomic_store_explicit							memory_order_release, relaxed, seq_cst
//atomic_load_explicit							memory_order_acquire, relaxed, seq_cst
//atomic_exchange_explicit						memory_order_acq_rel, relaxed, seq_cst
//atomic_compare_exchange_* (weak/strong)		memory_order_acq_rel, acquire, release, relaxed, seq_cst
//atomic_fetch_add/sub/etc.						memory_order_acq_rel, relaxed, seq_cst
//atomic_flag_test_and_set_explicit				memory_order_acquire, rel, seq_cst
//atomic_flag_clear_explicit					memory_order_release, seq_cst
