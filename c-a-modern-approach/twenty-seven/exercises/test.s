	.file	"test.c"
	.text
	.section	.rodata
.LC0:
	.string	"TEST AREA FOR PREPROCESSOR"
	.align 8
.LC2:
	.string	"END TEST AREA FOR PREPROCESSOR"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$.LC0, %edi
	call	puts
	pxor	%xmm0, %xmm0
	cvtsi2sdl	-4(%rbp), %xmm0
	pxor	%xmm2, %xmm2
	cvtss2sd	-8(%rbp), %xmm2
	movq	%xmm2, %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	remainder
	pxor	%xmm0, %xmm0
	cvtsi2sdl	-4(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	call	atan2
	movl	$.LC2, %edi
	call	puts
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.5.0 20240719 (Red Hat 11.5.0-14)"
	.section	.note.GNU-stack,"",@progbits
