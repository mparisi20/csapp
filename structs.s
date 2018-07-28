	.file	"structs.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "midpoint: (%d,%d)\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	addl	$-128, %esp
	call	___main
	leal	32(%esp), %eax ; This address is used to hold the struct that makepoint builds
	movl	$5, 20(%esp)
	movl	$4, 16(%esp)
	movl	$3, 12(%esp)
	movl	$2, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	_makepoint
	movl	32(%esp), %eax ; Then, the created struct is transferred to screen.pt1 and screen.pt2
	movl	%eax, 88(%esp) ; screen.pt1 begins at offset 88(%esp)
	movl	36(%esp), %eax
	movl	%eax, 92(%esp)
	movl	40(%esp), %eax
	movl	%eax, 96(%esp)
	movl	44(%esp), %eax
	movl	%eax, 100(%esp)
	movl	48(%esp), %eax
	movl	%eax, 104(%esp)
	leal	32(%esp), %eax
	movl	$6, 20(%esp)
	movl	$5, 16(%esp)
	movl	$4, 12(%esp)
	movl	$150, 8(%esp)
	movl	$200, 4(%esp)
	movl	%eax, (%esp)
	call	_makepoint
	movl	32(%esp), %eax
	movl	%eax, 108(%esp) ; screen.pt2 begins at offset 108(%esp)
	movl	36(%esp), %eax
	movl	%eax, 112(%esp)
	movl	40(%esp), %eax
	movl	%eax, 116(%esp)
	movl	44(%esp), %eax
	movl	%eax, 120(%esp)
	movl	48(%esp), %eax
	movl	%eax, 124(%esp)
	movl	92(%esp), %edx
	movl	112(%esp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, %ecx
	movl	88(%esp), %edx
	movl	108(%esp), %eax
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, %edx
	leal	68(%esp), %eax
	movl	$0, 20(%esp)
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_makepoint
	movl	72(%esp), %edx
	movl	68(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.globl	_makepoint
	.def	_makepoint;	.scl	2;	.type	32;	.endef
_makepoint:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$32, %esp
	movl	12(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	24(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	28(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	8(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, (%eax)
	movl	-16(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	-8(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	-4(%ebp), %edx
	movl	%edx, 16(%eax)
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
