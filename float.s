	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	call	___main // x87 instructions
	flds	LC0    // load floating point value at LC0 (a)
	fstps	12(%esp) // take a and store it in 12(%esp)
	flds	12(%esp) // load a back onto the stack
	fadd	%st(0), %st // equivalent to multiplying by 2
	fstps	8(%esp) // store at 8(%esp)... which is b
	movl	$0, %eax // return 0
	leave
	ret
LFE0:
	.section .rdata,"dr"
	.align 4
LC0:
	.long	1085276160