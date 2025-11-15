	.text
	.file	"basic.c"
	.globl	thread1                         # -- Begin function thread1
	.p2align	4, 0x90
	.type	thread1,@function
thread1:                                # @thread1
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	$1, y(%rip)
	movl	$2, %eax
	xchgl	%eax, x(%rip)
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	thread1, .Lfunc_end0-thread1
	.cfi_endproc
                                        # -- End function
	.globl	ft_putnbr                       # -- Begin function ft_putnbr
	.p2align	4, 0x90
	.type	ft_putnbr,@function
ft_putnbr:                              # @ft_putnbr
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	$1, -8(%rbp)
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	movl	-4(%rbp), %eax
	cltd
	idivl	-8(%rbp)
	cmpl	$9, %eax
	jle	.LBB1_3
# %bb.2:                                #   in Loop: Header=BB1_1 Depth=1
	imull	$10, -8(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.LBB1_1
.LBB1_3:
	jmp	.LBB1_4
.LBB1_4:                                # =>This Inner Loop Header: Depth=1
	cmpl	$0, -8(%rbp)
	je	.LBB1_6
# %bb.5:                                #   in Loop: Header=BB1_4 Depth=1
	movl	-4(%rbp), %eax
	cltd
	idivl	-8(%rbp)
	movl	$10, %ecx
	cltd
	idivl	%ecx
	addl	$48, %edx
	movb	%dl, %al
	movb	%al, -9(%rbp)
	movl	$1, %edi
	leaq	-9(%rbp), %rsi
	movl	$1, %edx
	callq	write@PLT
	movl	-8(%rbp), %eax
	movl	$10, %ecx
	cltd
	idivl	%ecx
	movl	%eax, -8(%rbp)
	jmp	.LBB1_4
.LBB1_6:
	movl	$1, %edi
	leaq	.L.str(%rip), %rsi
	movl	$1, %edx
	callq	write@PLT
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	ft_putnbr, .Lfunc_end1-ft_putnbr
	.cfi_endproc
                                        # -- End function
	.globl	thread2                         # -- Begin function thread2
	.p2align	4, 0x90
	.type	thread2,@function
thread2:                                # @thread2
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
.LBB2_1:                                # =>This Inner Loop Header: Depth=1
	cmpl	$2, x(%rip)
	je	.LBB2_3
# %bb.2:                                #   in Loop: Header=BB2_1 Depth=1
	jmp	.LBB2_1
.LBB2_3:
	movl	y(%rip), %edi
	callq	ft_putnbr
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end2:
	.size	thread2, .Lfunc_end2-thread2
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	xorl	%eax, %eax
	xchgl	%eax, x(%rip)
	leaq	-8(%rbp), %rdi
	leaq	thread1(%rip), %rsi
	xorl	%eax, %eax
	movl	%eax, %edx
	callq	thrd_create@PLT
	leaq	-16(%rbp), %rdi
	leaq	thread2(%rip), %rsi
	xorl	%eax, %eax
	movl	%eax, %edx
	callq	thrd_create@PLT
	movq	-8(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	callq	thrd_join@PLT
	movq	-16(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	callq	thrd_join@PLT
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end3:
	.size	main, .Lfunc_end3-main
	.cfi_endproc
                                        # -- End function
	.type	y,@object                       # @y
	.bss
	.globl	y
	.p2align	2, 0x0
y:
	.long	0                               # 0x0
	.size	y, 4

	.type	x,@object                       # @x
	.globl	x
	.p2align	2, 0x0
x:
	.long	0                               # 0x0
	.size	x, 4

	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"\n"
	.size	.L.str, 2

	.ident	"Ubuntu clang version 18.1.3 (1ubuntu1)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym thread1
	.addrsig_sym ft_putnbr
	.addrsig_sym write
	.addrsig_sym thread2
	.addrsig_sym thrd_create
	.addrsig_sym thrd_join
	.addrsig_sym y
	.addrsig_sym x
