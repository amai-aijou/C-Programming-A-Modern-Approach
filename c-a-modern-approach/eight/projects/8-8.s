	.file	"8-8.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Enter grades for student #%d: "
.LC1:
	.string	"Student:\t "
.LC2:
	.string	"#%-6d"
	.align 8
.LC3:
	.string	"---------------------------------------------------"
.LC4:
	.string	"Total:\t    "
.LC5:
	.string	"%6d%%"
.LC6:
	.string	"Average:    "
.LC7:
	.string	"Quiz:\t\t "
.LC8:
	.string	"High Score: "
.LC9:
	.string	"Low Score:  "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	leaq	-128(%rbp), %rdx
	movl	$0, %eax
	movl	$12, %ecx
	movq	%rdx, %rdi
	rep stosq
	movq	%rdi, %rdx
	movl	%eax, (%rdx)
	addq	$4, %rdx
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, -16(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L5:
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -8(%rbp)
	jmp	.L3
.L4:
	addl	$1, -8(%rbp)
.L3:
	cmpl	$4, -8(%rbp)
	jle	.L4
	addl	$1, -4(%rbp)
.L2:
	cmpl	$4, -4(%rbp)
	jle	.L5
	movl	$10, %edi
	call	putchar
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L6
.L7:
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L6:
	cmpl	$4, -4(%rbp)
	jle	.L7
	movl	$10, %edi
	call	putchar
	movl	$.LC3, %edi
	call	puts
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L8
.L11:
	movl	$0, -8(%rbp)
	jmp	.L9
.L10:
	movl	-8(%rbp), %eax
	movslq	%eax, %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-128(%rbp,%rax,4), %eax
	addl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	addl	%eax, -12(%rbp)
	addl	$1, -8(%rbp)
.L9:
	cmpl	$4, -8(%rbp)
	jle	.L10
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -16(%rbp)
	addl	$1, -4(%rbp)
.L8:
	cmpl	$4, -4(%rbp)
	jle	.L11
	movl	$10, %edi
	call	putchar
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L12
.L15:
	movl	$0, -8(%rbp)
	jmp	.L13
.L14:
	movl	-8(%rbp), %eax
	movslq	%eax, %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-128(%rbp,%rax,4), %eax
	addl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	addl	%eax, -12(%rbp)
	addl	$1, -8(%rbp)
.L13:
	cmpl	$4, -8(%rbp)
	jle	.L14
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	%edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -16(%rbp)
	movl	$0, -12(%rbp)
	addl	$1, -4(%rbp)
.L12:
	cmpl	$4, -4(%rbp)
	jle	.L15
	movl	$10, %edi
	call	putchar
	movl	$10, %edi
	call	putchar
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L16
.L17:
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L16:
	cmpl	$4, -4(%rbp)
	jle	.L17
	movl	$10, %edi
	call	putchar
	movl	$.LC3, %edi
	call	puts
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L18
.L21:
	movl	$0, -8(%rbp)
	jmp	.L19
.L20:
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-128(%rbp,%rax,4), %eax
	addl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	addl	%eax, -12(%rbp)
	addl	$1, -8(%rbp)
.L19:
	cmpl	$4, -8(%rbp)
	jle	.L20
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	%edx
	sarl	$31, %eax
	movl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -20(%rbp)
	movl	$0, -12(%rbp)
	addl	$1, -4(%rbp)
.L18:
	cmpl	$4, -4(%rbp)
	jle	.L21
	movl	$10, %edi
	call	putchar
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L22
.L26:
	movl	$0, -8(%rbp)
	jmp	.L23
.L25:
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-128(%rbp,%rax,4), %eax
	cmpl	%eax, -24(%rbp)
	jge	.L24
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-128(%rbp,%rax,4), %eax
	movl	%eax, -24(%rbp)
.L24:
	addl	$1, -8(%rbp)
.L23:
	cmpl	$4, -8(%rbp)
	jle	.L25
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -24(%rbp)
	addl	$1, -4(%rbp)
.L22:
	cmpl	$4, -4(%rbp)
	jle	.L26
	movl	$10, %edi
	call	putchar
	movl	$.LC9, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L27
.L31:
	movl	$0, -8(%rbp)
	jmp	.L28
.L30:
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-128(%rbp,%rax,4), %eax
	cmpl	%eax, -28(%rbp)
	jle	.L29
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-128(%rbp,%rax,4), %eax
	movl	%eax, -28(%rbp)
.L29:
	addl	$1, -8(%rbp)
.L28:
	cmpl	$4, -8(%rbp)
	jle	.L30
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -28(%rbp)
	addl	$1, -4(%rbp)
.L27:
	cmpl	$4, -4(%rbp)
	jle	.L31
	movl	$10, %edi
	call	putchar
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.5.0 20240719 (Red Hat 11.5.0-5)"
	.section	.note.GNU-stack,"",@progbits
