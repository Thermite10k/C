	.file	"calc.c"
 # GNU C17 (Rev2, Built by MSYS2 project) version 14.1.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 14.1.0, GMP version 6.3.0, MPFR version 4.2.1, MPC version 1.3.1, isl version isl-0.26-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: -mtune=generic -march=nocona
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	pushq	%rbx	 #
	.seh_pushreg	%rbx
	subq	$56, %rsp	 #,
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp	 #,
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)	 # __format, __format
	movq	%rdx, 40(%rbp)	 #,
	movq	%r8, 48(%rbp)	 #,
	movq	%r9, 56(%rbp)	 #,
 # C:/msys64/mingw64/include/stdio.h:382:   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
	leaq	40(%rbp), %rax	 #, tmp102
	movq	%rax, -16(%rbp)	 # tmp102, MEM[(char * *)&__local_argv]
 # C:/msys64/mingw64/include/stdio.h:383:   __retval = __mingw_vfprintf( stdout, __format, __local_argv );
	movq	-16(%rbp), %rbx	 # __local_argv, __local_argv.0_1
	movl	$1, %ecx	 #,
	movq	__imp___acrt_iob_func(%rip), %rax	 #, tmp103
	call	*%rax	 # tmp103
	movq	%rax, %rcx	 #, _2
 # C:/msys64/mingw64/include/stdio.h:383:   __retval = __mingw_vfprintf( stdout, __format, __local_argv );
	movq	32(%rbp), %rax	 # __format, tmp104
	movq	%rbx, %r8	 # __local_argv.0_1,
	movq	%rax, %rdx	 # tmp104,
	call	__mingw_vfprintf	 #
	movl	%eax, -4(%rbp)	 # tmp105, __retval
 # C:/msys64/mingw64/include/stdio.h:385:   return __retval;
	movl	-4(%rbp), %eax	 # __retval, _10
 # C:/msys64/mingw64/include/stdio.h:386: }
	addq	$56, %rsp	 #,
	popq	%rbx	 #
	popq	%rbp	 #
	ret	
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "error: zero divisor\12\0"
.LC2:
	.ascii "\11%.8g\12\0"
.LC3:
	.ascii "%f\12\0"
.LC4:
	.ascii "error: unknown command => %s\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	subq	$176, %rsp	 #,
	.seh_stackalloc	176
	leaq	160(%rsp), %rbp	 #,
	.seh_setframe	%rbp, 160
	movups	%xmm6, 0(%rbp)	 #,
	.seh_savexmm	%xmm6, 160
	.seh_endprologue
 # calc.c:21: int main(void){
	call	__main	 #
 # calc.c:25:     double ans = 0.0;
	pxor	%xmm0, %xmm0	 # tmp123
	movsd	%xmm0, -8(%rbp)	 # tmp123, ans
 # calc.c:27:     while((type = getop(s)) != EOF){
	jmp	.L4	 #
.L24:
 # calc.c:29:         switch(type){
	movl	-12(%rbp), %eax	 # type, tmp125
	subl	$10, %eax	 #, tmp124
	cmpl	$105, %eax	 #, tmp124
	ja	.L5	 #,
	movl	%eax, %eax	 # tmp124, tmp126
	leaq	0(,%rax,4), %rdx	 #, tmp127
	leaq	.L7(%rip), %rax	 #, tmp128
	movl	(%rdx,%rax), %eax	 #, tmp129
	cltq
	leaq	.L7(%rip), %rdx	 #, tmp132
	addq	%rdx, %rax	 # tmp132, tmp131
	jmp	*%rax	 # tmp131
	.section .rdata,"dr"
	.align 4
.L7:
	.long	.L20-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L19-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L18-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L17-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L16-.L7
	.long	.L5-.L7
	.long	.L15-.L7
	.long	.L14-.L7
	.long	.L5-.L7
	.long	.L13-.L7
	.long	.L5-.L7
	.long	.L12-.L7
	.long	.L11-.L7
	.long	.L5-.L7
	.long	.L10-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L9-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L8-.L7
	.long	.L5-.L7
	.long	.L5-.L7
	.long	.L6-.L7
	.text
.L11:
 # calc.c:32:                 push(atof(s));
	leaq	-128(%rbp), %rax	 #, tmp133
	movq	%rax, %rcx	 # tmp133,
	call	atof	 #
	movq	%xmm0, %rax	 #, _1
 # calc.c:32:                 push(atof(s));
	movq	%rax, %xmm0	 # _1,
	call	push	 #
 # calc.c:33:                 break;
	jmp	.L4	 #
.L14:
 # calc.c:35:                 push(pop() + pop());
	call	pop	 #
	movapd	%xmm0, %xmm6	 #, _2
 # calc.c:35:                 push(pop() + pop());
	call	pop	 #
 # calc.c:35:                 push(pop() + pop());
	addsd	%xmm0, %xmm6	 # _3, _2
	movq	%xmm6, %rax	 # _2, _4
	movq	%rax, %xmm0	 # _4,
	call	push	 #
 # calc.c:36:                 break;
	jmp	.L4	 #
.L15:
 # calc.c:38:                 push(pop() * pop());
	call	pop	 #
	movapd	%xmm0, %xmm6	 #, _5
 # calc.c:38:                 push(pop() * pop());
	call	pop	 #
 # calc.c:38:                 push(pop() * pop());
	mulsd	%xmm0, %xmm6	 # _6, _5
	movq	%xmm6, %rax	 # _5, _7
	movq	%rax, %xmm0	 # _7,
	call	push	 #
 # calc.c:39:                 break;
	jmp	.L4	 #
.L13:
 # calc.c:41:                 op2 = pop();
	call	pop	 #
	movq	%xmm0, %rax	 #, tmp134
	movq	%rax, -24(%rbp)	 # tmp134, op2
 # calc.c:42:                 push(pop() - (op2));
	call	pop	 #
	movq	%xmm0, %rax	 #, _8
 # calc.c:42:                 push(pop() - (op2));
	movq	%rax, %xmm2	 # _8, _8
	subsd	-24(%rbp), %xmm2	 # op2, _8
	movq	%xmm2, %rax	 # _8, _9
	movq	%rax, %xmm0	 # _9,
	call	push	 #
 # calc.c:43:                 break;
	jmp	.L4	 #
.L12:
 # calc.c:45:                 op2 = pop();
	call	pop	 #
	movq	%xmm0, %rax	 #, tmp135
	movq	%rax, -24(%rbp)	 # tmp135, op2
 # calc.c:46:                 if(op2 != 0){
	pxor	%xmm0, %xmm0	 # tmp136
	ucomisd	-24(%rbp), %xmm0	 # op2, tmp136
	jp	.L26	 #,
	pxor	%xmm0, %xmm0	 # tmp137
	ucomisd	-24(%rbp), %xmm0	 # op2, tmp137
	je	.L21	 #,
.L26:
 # calc.c:47:                     push(pop() / op2);
	call	pop	 #
	movq	%xmm0, %rax	 #, _10
 # calc.c:47:                     push(pop() / op2);
	movq	%rax, %xmm3	 # _10, _10
	divsd	-24(%rbp), %xmm3	 # op2, _10
	movq	%xmm3, %rax	 # _10, _11
	movq	%rax, %xmm0	 # _11,
	call	push	 #
	jmp	.L4	 #
.L21:
 # calc.c:50:                     printf("error: zero divisor\n");
	leaq	.LC1(%rip), %rax	 #, tmp138
	movq	%rax, %rcx	 # tmp138,
	call	printf	 #
 # calc.c:52:                 break;
	jmp	.L4	 #
.L17:
 # calc.c:54:                 op2 = pop();
	call	pop	 #
	movq	%xmm0, %rax	 #, tmp139
	movq	%rax, -24(%rbp)	 # tmp139, op2
 # calc.c:55:                 push(((int)(pop())) % ((int)op2));
	call	pop	 #
 # calc.c:55:                 push(((int)(pop())) % ((int)op2));
	cvttsd2sil	%xmm0, %eax	 # _12, _13
 # calc.c:55:                 push(((int)(pop())) % ((int)op2));
	movsd	-24(%rbp), %xmm0	 # op2, tmp140
	cvttsd2sil	%xmm0, %ecx	 # tmp140, _14
 # calc.c:55:                 push(((int)(pop())) % ((int)op2));
	cltd
	idivl	%ecx	 # _14
	movl	%edx, %ecx	 # _15, _15
	movl	%ecx, %eax	 # _15, _15
 # calc.c:55:                 push(((int)(pop())) % ((int)op2));
	pxor	%xmm4, %xmm4	 # _16
	cvtsi2sdl	%eax, %xmm4	 # _15, _16
	movq	%xmm4, %rax	 # _16, _16
	movq	%rax, %xmm0	 # _16,
	call	push	 #
 # calc.c:56:                 break;
	jmp	.L4	 #
.L19:
 # calc.c:58:                 push(sin(pop()));
	call	pop	 #
	movq	%xmm0, %rax	 #, _17
 # calc.c:58:                 push(sin(pop()));
	movq	%rax, %xmm0	 # _17,
	call	sin	 #
	movq	%xmm0, %rax	 #, _18
 # calc.c:58:                 push(sin(pop()));
	movq	%rax, %xmm0	 # _18,
	call	push	 #
 # calc.c:59:                 break;
	jmp	.L4	 #
.L18:
 # calc.c:61:                 push(cos(pop()));
	call	pop	 #
	movq	%xmm0, %rax	 #, _19
 # calc.c:61:                 push(cos(pop()));
	movq	%rax, %xmm0	 # _19,
	call	cos	 #
	movq	%xmm0, %rax	 #, _20
 # calc.c:61:                 push(cos(pop()));
	movq	%rax, %xmm0	 # _20,
	call	push	 #
 # calc.c:62:                 break;
	jmp	.L4	 #
.L16:
 # calc.c:64:                 push(exp(pop()));
	call	pop	 #
	movq	%xmm0, %rax	 #, _21
 # calc.c:64:                 push(exp(pop()));
	movq	%rax, %xmm0	 # _21,
	call	exp	 #
	movq	%xmm0, %rax	 #, _22
 # calc.c:64:                 push(exp(pop()));
	movq	%rax, %xmm0	 # _22,
	call	push	 #
 # calc.c:65:                 break;
	jmp	.L4	 #
.L10:
 # calc.c:67:                 printf("\t%.8g\n", ans);
	movsd	-8(%rbp), %xmm0	 # ans, tmp143
	movq	-8(%rbp), %rax	 # ans, tmp144
	movapd	%xmm0, %xmm1	 # tmp143,
	movq	%rax, %rdx	 # tmp144,
	leaq	.LC2(%rip), %rax	 #, tmp145
	movq	%rax, %rcx	 # tmp145,
	call	printf	 #
 # calc.c:68:                 break;
	jmp	.L4	 #
.L20:
 # calc.c:70:                 ans = pop();
	call	pop	 #
	movq	%xmm0, %rax	 #, tmp146
	movq	%rax, -8(%rbp)	 # tmp146, ans
 # calc.c:71:                 printf("\t%.8g\n", ans);
	movsd	-8(%rbp), %xmm0	 # ans, tmp147
	movq	-8(%rbp), %rax	 # ans, tmp148
	movapd	%xmm0, %xmm1	 # tmp147,
	movq	%rax, %rdx	 # tmp148,
	leaq	.LC2(%rip), %rax	 #, tmp149
	movq	%rax, %rcx	 # tmp149,
	call	printf	 #
 # calc.c:72:                 break;
	jmp	.L4	 #
.L8:
 # calc.c:74:                 printf("%f\n", peek());
	call	peek	 #
 # calc.c:74:                 printf("%f\n", peek());
	movapd	%xmm0, %xmm1	 # _23, tmp150
	movapd	%xmm1, %xmm0	 # tmp150, tmp151
	movq	%xmm1, %rax	 # tmp150, tmp152
	movapd	%xmm0, %xmm1	 # tmp151,
	movq	%rax, %rdx	 # tmp152,
	leaq	.LC3(%rip), %rax	 #, tmp153
	movq	%rax, %rcx	 # tmp153,
	call	printf	 #
 # calc.c:75:                 break;
	jmp	.L4	 #
.L9:
 # calc.c:77:                 duplicate();
	call	duplicate	 #
 # calc.c:78:                 break;
	jmp	.L4	 #
.L6:
 # calc.c:80:                 swap();
	call	swap	 #
 # calc.c:81:                 break;
	jmp	.L4	 #
.L5:
 # calc.c:83:                 printf("error: unknown command => %s\n", s);
	leaq	-128(%rbp), %rax	 #, tmp154
	movq	%rax, %rdx	 # tmp154,
	leaq	.LC4(%rip), %rax	 #, tmp155
	movq	%rax, %rcx	 # tmp155,
	call	printf	 #
 # calc.c:84:                 break;
	nop	
.L4:
 # calc.c:27:     while((type = getop(s)) != EOF){
	leaq	-128(%rbp), %rax	 #, tmp156
	movq	%rax, %rcx	 # tmp156,
	call	getop	 #
	movl	%eax, -12(%rbp)	 # tmp157, type
 # calc.c:27:     while((type = getop(s)) != EOF){
	cmpl	$-1, -12(%rbp)	 #, type
	jne	.L24	 #,
	movl	$0, %eax	 #, _32
 # calc.c:87: }
	movups	0(%rbp), %xmm6	 #,
	addq	$176, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.globl	sp
	.bss
	.align 4
sp:
	.space 4
	.globl	val
	.align 32
val:
	.space 800
	.section .rdata,"dr"
.LC5:
	.ascii "error: stack is full\12\0"
	.text
	.globl	push
	.def	push;	.scl	2;	.type	32;	.endef
	.seh_proc	push
push:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$32, %rsp	 #,
	.seh_stackalloc	32
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)	 # f, f
 # calc.c:96:     if(sp < MAXVAL){
	movl	sp(%rip), %eax	 # sp, sp.1_1
 # calc.c:96:     if(sp < MAXVAL){
	cmpl	$99, %eax	 #, sp.1_1
	jg	.L28	 #,
 # calc.c:97:         val[sp++] = f;
	movl	sp(%rip), %eax	 # sp, sp.2_2
	leal	1(%rax), %edx	 #, _4
	movl	%edx, sp(%rip)	 # _4, sp
 # calc.c:97:         val[sp++] = f;
	cltq
	leaq	0(,%rax,8), %rdx	 #, tmp102
	leaq	val(%rip), %rax	 #, tmp103
	movsd	16(%rbp), %xmm0	 # f, tmp104
	movsd	%xmm0, (%rdx,%rax)	 # tmp104, val[sp.3_3]
 # calc.c:101: }
	jmp	.L30	 #
.L28:
 # calc.c:99:         printf("error: stack is full\n");
	leaq	.LC5(%rip), %rax	 #, tmp105
	movq	%rax, %rcx	 # tmp105,
	call	printf	 #
.L30:
 # calc.c:101: }
	nop	
	addq	$32, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.section .rdata,"dr"
.LC6:
	.ascii "error: stack is empty\12\0"
	.text
	.globl	pop
	.def	pop;	.scl	2;	.type	32;	.endef
	.seh_proc	pop
pop:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$32, %rsp	 #,
	.seh_stackalloc	32
	.seh_endprologue
 # calc.c:104:     if(sp > 0){
	movl	sp(%rip), %eax	 # sp, sp.4_1
 # calc.c:104:     if(sp > 0){
	testl	%eax, %eax	 # sp.4_1
	jle	.L32	 #,
 # calc.c:105:         return val[--sp];
	movl	sp(%rip), %eax	 # sp, sp.5_2
	subl	$1, %eax	 #, _3
 # calc.c:105:         return val[--sp];
	movl	%eax, sp(%rip)	 # _3, sp
 # calc.c:105:         return val[--sp];
	movl	sp(%rip), %eax	 # sp, sp.6_4
 # calc.c:105:         return val[--sp];
	cltq
	leaq	0(,%rax,8), %rdx	 #, tmp105
	leaq	val(%rip), %rax	 #, tmp106
	movsd	(%rdx,%rax), %xmm0	 # val[sp.6_4], _5
	jmp	.L33	 #
.L32:
 # calc.c:107:         printf("error: stack is empty\n");
	leaq	.LC6(%rip), %rax	 #, tmp107
	movq	%rax, %rcx	 # tmp107,
	call	printf	 #
 # calc.c:108:         return 0.0;
	pxor	%xmm0, %xmm0	 # _5
.L33:
 # calc.c:110: }
	addq	$32, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.section .rdata,"dr"
.LC7:
	.ascii "error: stak is empty\12\0"
	.text
	.globl	peek
	.def	peek;	.scl	2;	.type	32;	.endef
	.seh_proc	peek
peek:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$32, %rsp	 #,
	.seh_stackalloc	32
	.seh_endprologue
 # calc.c:114:     if(sp > 0 ){
	movl	sp(%rip), %eax	 # sp, sp.7_1
 # calc.c:114:     if(sp > 0 ){
	testl	%eax, %eax	 # sp.7_1
	jle	.L35	 #,
 # calc.c:115:         return val[(sp - 1)];
	movl	sp(%rip), %eax	 # sp, sp.8_2
	subl	$1, %eax	 #, _3
 # calc.c:115:         return val[(sp - 1)];
	cltq
	leaq	0(,%rax,8), %rdx	 #, tmp104
	leaq	val(%rip), %rax	 #, tmp105
	movsd	(%rdx,%rax), %xmm0	 # val[_3], _4
	jmp	.L36	 #
.L35:
 # calc.c:117:         printf("error: stak is empty\n");
	leaq	.LC7(%rip), %rax	 #, tmp106
	movq	%rax, %rcx	 # tmp106,
	call	printf	 #
 # calc.c:118:         return 0.0;
	pxor	%xmm0, %xmm0	 # _4
.L36:
 # calc.c:120: }
	addq	$32, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.globl	swap
	.def	swap;	.scl	2;	.type	32;	.endef
	.seh_proc	swap
swap:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
 # calc.c:123:     if(sp >= 2){
	movl	sp(%rip), %eax	 # sp, sp.9_1
 # calc.c:123:     if(sp >= 2){
	cmpl	$1, %eax	 #, sp.9_1
	jle	.L39	 #,
 # calc.c:124:         s = pop();
	call	pop	 #
	movq	%xmm0, %rax	 #, tmp99
	movq	%rax, -8(%rbp)	 # tmp99, s
 # calc.c:125:         f = pop();
	call	pop	 #
	movq	%xmm0, %rax	 #, tmp100
	movq	%rax, -16(%rbp)	 # tmp100, f
 # calc.c:126:         push(s);
	movq	-8(%rbp), %rax	 # s, tmp101
	movq	%rax, %xmm0	 # tmp101,
	call	push	 #
 # calc.c:127:         push(f);
	movq	-16(%rbp), %rax	 # f, tmp102
	movq	%rax, %xmm0	 # tmp102,
	call	push	 #
.L39:
 # calc.c:129: }
	nop	
	addq	$48, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.globl	duplicate
	.def	duplicate;	.scl	2;	.type	32;	.endef
	.seh_proc	duplicate
duplicate:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$32, %rsp	 #,
	.seh_stackalloc	32
	.seh_endprologue
 # calc.c:132:     if(sp > 0){
	movl	sp(%rip), %eax	 # sp, sp.10_1
 # calc.c:132:     if(sp > 0){
	testl	%eax, %eax	 # sp.10_1
	jle	.L42	 #,
 # calc.c:133:         push(peek());
	call	peek	 #
	movq	%xmm0, %rax	 #, _2
 # calc.c:133:         push(peek());
	movq	%rax, %xmm0	 # _2,
	call	push	 #
.L42:
 # calc.c:135: }
	nop	
	addq	$32, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.globl	input
	.bss
	.align 32
input:
	.space 100
	.globl	j
	.align 4
j:
	.space 4
	.text
	.globl	getop
	.def	getop;	.scl	2;	.type	32;	.endef
	.seh_proc	getop
getop:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # s, s
 # calc.c:147:     int i=0, c,m, type;
	movl	$0, -4(%rbp)	 #, i
 # calc.c:148:     if(j == 0 || input[j] == '\0'){ /* if the input is empty, get a new input array */
	movl	j(%rip), %eax	 # j, j.11_1
 # calc.c:148:     if(j == 0 || input[j] == '\0'){ /* if the input is empty, get a new input array */
	testl	%eax, %eax	 # j.11_1
	je	.L44	 #,
 # calc.c:148:     if(j == 0 || input[j] == '\0'){ /* if the input is empty, get a new input array */
	movl	j(%rip), %eax	 # j, j.12_2
	cltq
	leaq	input(%rip), %rdx	 #, tmp162
	movzbl	(%rax,%rdx), %eax	 # input[j.12_2], _3
 # calc.c:148:     if(j == 0 || input[j] == '\0'){ /* if the input is empty, get a new input array */
	testb	%al, %al	 # _3
	jne	.L60	 #,
.L44:
 # calc.c:149:     getline(input, MAXOP);
	movl	$100, %edx	 #,
	leaq	input(%rip), %rax	 #, tmp163
	movq	%rax, %rcx	 # tmp163,
	call	getline	 #
 # calc.c:150:     j = 0;
	movl	$0, j(%rip)	 #, j
.L60:
 # calc.c:152:     while((s[0] = c = input[j++]) == ' ' || c == '\t'){ // skipping whitespaces
	nop	
.L46:
 # calc.c:152:     while((s[0] = c = input[j++]) == ' ' || c == '\t'){ // skipping whitespaces
	movl	j(%rip), %eax	 # j, j.13_4
	leal	1(%rax), %edx	 #, _6
	movl	%edx, j(%rip)	 # _6, j
 # calc.c:152:     while((s[0] = c = input[j++]) == ' ' || c == '\t'){ // skipping whitespaces
	cltq
	leaq	input(%rip), %rdx	 #, tmp165
	movzbl	(%rax,%rdx), %eax	 # input[j.14_5], _7
 # calc.c:152:     while((s[0] = c = input[j++]) == ' ' || c == '\t'){ // skipping whitespaces
	movsbl	%al, %eax	 # _7, tmp166
	movl	%eax, -8(%rbp)	 # tmp166, c
 # calc.c:152:     while((s[0] = c = input[j++]) == ' ' || c == '\t'){ // skipping whitespaces
	movl	-8(%rbp), %eax	 # c, tmp167
	movl	%eax, %edx	 # tmp167, _8
	movq	16(%rbp), %rax	 # s, tmp168
	movb	%dl, (%rax)	 # _8, *s_94(D)
 # calc.c:152:     while((s[0] = c = input[j++]) == ' ' || c == '\t'){ // skipping whitespaces
	movq	16(%rbp), %rax	 # s, tmp169
	movzbl	(%rax), %eax	 # *s_94(D), _9
 # calc.c:152:     while((s[0] = c = input[j++]) == ' ' || c == '\t'){ // skipping whitespaces
	cmpb	$32, %al	 #, _9
	je	.L46	 #,
 # calc.c:152:     while((s[0] = c = input[j++]) == ' ' || c == '\t'){ // skipping whitespaces
	cmpl	$9, -8(%rbp)	 #, c
	je	.L46	 #,
 # calc.c:157:     s[1] = '\0';
	movq	16(%rbp), %rax	 # s, tmp170
	addq	$1, %rax	 #, _10
 # calc.c:157:     s[1] = '\0';
	movb	$0, (%rax)	 #, *_10
 # calc.c:158:     i=0;
	movl	$0, -4(%rbp)	 #, i
 # calc.c:159:     m = c; // m is used to decide if - is operator or sign.
	movl	-8(%rbp), %eax	 # c, tmp171
	movl	%eax, -12(%rbp)	 # tmp171, m
 # calc.c:160:     if(isalpha(c)){ // used to get stuff like sin, cos, ans etc
	movl	-8(%rbp), %eax	 # c, tmp172
	movl	%eax, %ecx	 # tmp172,
	movq	__imp_isalpha(%rip), %rax	 #, tmp173
	call	*%rax	 # tmp173
 # calc.c:160:     if(isalpha(c)){ // used to get stuff like sin, cos, ans etc
	testl	%eax, %eax	 # _11
	je	.L47	 #,
 # calc.c:162:         while(isalpha(s[++i] = c = input[j++])){
	nop	
.L48:
 # calc.c:162:         while(isalpha(s[++i] = c = input[j++])){
	movl	j(%rip), %eax	 # j, j.15_12
	leal	1(%rax), %edx	 #, _14
	movl	%edx, j(%rip)	 # _14, j
 # calc.c:162:         while(isalpha(s[++i] = c = input[j++])){
	cltq
	leaq	input(%rip), %rdx	 #, tmp175
	movzbl	(%rax,%rdx), %eax	 # input[j.16_13], _15
 # calc.c:162:         while(isalpha(s[++i] = c = input[j++])){
	movsbl	%al, %eax	 # _15, tmp176
	movl	%eax, -8(%rbp)	 # tmp176, c
 # calc.c:162:         while(isalpha(s[++i] = c = input[j++])){
	addl	$1, -4(%rbp)	 #, i
 # calc.c:162:         while(isalpha(s[++i] = c = input[j++])){
	movl	-4(%rbp), %eax	 # i, tmp177
	movslq	%eax, %rdx	 # tmp177, _16
 # calc.c:162:         while(isalpha(s[++i] = c = input[j++])){
	movq	16(%rbp), %rax	 # s, tmp178
	addq	%rdx, %rax	 # _16, _17
 # calc.c:162:         while(isalpha(s[++i] = c = input[j++])){
	movl	-8(%rbp), %edx	 # c, tmp179
	movb	%dl, (%rax)	 # _18, *_17
 # calc.c:162:         while(isalpha(s[++i] = c = input[j++])){
	movzbl	(%rax), %eax	 # *_17, _19
 # calc.c:162:         while(isalpha(s[++i] = c = input[j++])){
	movsbl	%al, %eax	 # _19, _20
	movl	%eax, %ecx	 # _20,
	movq	__imp_isalpha(%rip), %rax	 #, tmp180
	call	*%rax	 # tmp180
	testl	%eax, %eax	 # _21
	jne	.L48	 #,
 # calc.c:167:         s[i] = '\0';
	movl	-4(%rbp), %eax	 # i, tmp181
	movslq	%eax, %rdx	 # tmp181, _22
	movq	16(%rbp), %rax	 # s, tmp182
	addq	%rdx, %rax	 # _22, _23
 # calc.c:167:         s[i] = '\0';
	movb	$0, (%rax)	 #, *_23
 # calc.c:168:         type = optype(s);
	movq	16(%rbp), %rax	 # s, tmp183
	movq	%rax, %rcx	 # tmp183,
	call	optype	 #
	movl	%eax, -16(%rbp)	 # tmp184, type
 # calc.c:169:         if(c != EOF && type != ANS){ // if type is ANS, we want to get rid of the \n so it does not clear the ANS after showing it as \n triggers an ANS update and a pop().
	cmpl	$-1, -8(%rbp)	 #, c
	je	.L49	 #,
 # calc.c:169:         if(c != EOF && type != ANS){ // if type is ANS, we want to get rid of the \n so it does not clear the ANS after showing it as \n triggers an ANS update and a pop().
	cmpl	$50, -16(%rbp)	 #, type
	je	.L49	 #,
 # calc.c:170:             j--; // same as ungetch;
	movl	j(%rip), %eax	 # j, j.17_24
	subl	$1, %eax	 #, _25
	movl	%eax, j(%rip)	 # _25, j
.L49:
 # calc.c:173:         return type;
	movl	-16(%rbp), %eax	 # type, _76
	jmp	.L50	 #
.L47:
 # calc.c:177:     if(c == '-' && (isdigit(c = s[++i] = input[j++]))){ // this is just a stupid if that get's the next char if c == '-' to see if - is a sign or an operator.
	cmpl	$45, -8(%rbp)	 #, c
	jne	.L51	 #,
 # calc.c:177:     if(c == '-' && (isdigit(c = s[++i] = input[j++]))){ // this is just a stupid if that get's the next char if c == '-' to see if - is a sign or an operator.
	movl	j(%rip), %edx	 # j, j.18_26
	leal	1(%rdx), %eax	 #, _28
	movl	%eax, j(%rip)	 # _28, j
 # calc.c:177:     if(c == '-' && (isdigit(c = s[++i] = input[j++]))){ // this is just a stupid if that get's the next char if c == '-' to see if - is a sign or an operator.
	addl	$1, -4(%rbp)	 #, i
 # calc.c:177:     if(c == '-' && (isdigit(c = s[++i] = input[j++]))){ // this is just a stupid if that get's the next char if c == '-' to see if - is a sign or an operator.
	movl	-4(%rbp), %eax	 # i, tmp185
	movslq	%eax, %rcx	 # tmp185, _29
 # calc.c:177:     if(c == '-' && (isdigit(c = s[++i] = input[j++]))){ // this is just a stupid if that get's the next char if c == '-' to see if - is a sign or an operator.
	movq	16(%rbp), %rax	 # s, tmp186
	addq	%rcx, %rax	 # _29, _30
 # calc.c:177:     if(c == '-' && (isdigit(c = s[++i] = input[j++]))){ // this is just a stupid if that get's the next char if c == '-' to see if - is a sign or an operator.
	movslq	%edx, %rdx	 # j.18_26, tmp187
	leaq	input(%rip), %rcx	 #, tmp188
	movzbl	(%rdx,%rcx), %edx	 # input[j.19_27], _31
 # calc.c:177:     if(c == '-' && (isdigit(c = s[++i] = input[j++]))){ // this is just a stupid if that get's the next char if c == '-' to see if - is a sign or an operator.
	movb	%dl, (%rax)	 # _31, *_30
 # calc.c:177:     if(c == '-' && (isdigit(c = s[++i] = input[j++]))){ // this is just a stupid if that get's the next char if c == '-' to see if - is a sign or an operator.
	movzbl	(%rax), %eax	 # *_30, _32
 # calc.c:177:     if(c == '-' && (isdigit(c = s[++i] = input[j++]))){ // this is just a stupid if that get's the next char if c == '-' to see if - is a sign or an operator.
	movsbl	%al, %eax	 # _32, tmp189
	movl	%eax, -8(%rbp)	 # tmp189, c
.L51:
 # calc.c:180:     if(m == '-' && (c =='\n' || c == ' ')){ // '-' is an operator if it's followed by \n or ' '. here, 'm' is the n-1 getch.
	cmpl	$45, -12(%rbp)	 #, m
	jne	.L52	 #,
 # calc.c:180:     if(m == '-' && (c =='\n' || c == ' ')){ // '-' is an operator if it's followed by \n or ' '. here, 'm' is the n-1 getch.
	cmpl	$10, -8(%rbp)	 #, c
	je	.L53	 #,
 # calc.c:180:     if(m == '-' && (c =='\n' || c == ' ')){ // '-' is an operator if it's followed by \n or ' '. here, 'm' is the n-1 getch.
	cmpl	$32, -8(%rbp)	 #, c
	jne	.L52	 #,
.L53:
 # calc.c:181:         s[i] = '\0';
	movl	-4(%rbp), %eax	 # i, tmp190
	movslq	%eax, %rdx	 # tmp190, _35
	movq	16(%rbp), %rax	 # s, tmp191
	addq	%rdx, %rax	 # _35, _36
 # calc.c:181:         s[i] = '\0';
	movb	$0, (%rax)	 #, *_36
 # calc.c:182:         j--;
	movl	j(%rip), %eax	 # j, j.21_37
	subl	$1, %eax	 #, _38
	movl	%eax, j(%rip)	 # _38, j
 # calc.c:183:         return m;
	movl	-12(%rbp), %eax	 # m, _76
	jmp	.L50	 #
.L52:
 # calc.c:186:     if((!isdigit(c) && c != '.' )){
	movl	-8(%rbp), %eax	 # c, c.22_39
 # calc.c:186:     if((!isdigit(c) && c != '.' )){
	subl	$48, %eax	 #, _40
 # calc.c:186:     if((!isdigit(c) && c != '.' )){
	cmpl	$9, %eax	 #, _40
	jbe	.L54	 #,
 # calc.c:186:     if((!isdigit(c) && c != '.' )){
	cmpl	$46, -8(%rbp)	 #, c
	je	.L54	 #,
 # calc.c:188:         return c;
	movl	-8(%rbp), %eax	 # c, _76
	jmp	.L50	 #
.L54:
 # calc.c:194:     if(isdigit(c)){
	movl	-8(%rbp), %eax	 # c, c.23_41
	subl	$48, %eax	 #, _42
 # calc.c:194:     if(isdigit(c)){
	cmpl	$9, %eax	 #, _42
	ja	.L55	 #,
 # calc.c:195:         while(isdigit(s[++i] = c = input[j++])){
	nop	
.L56:
 # calc.c:195:         while(isdigit(s[++i] = c = input[j++])){
	movl	j(%rip), %eax	 # j, j.24_43
	leal	1(%rax), %edx	 #, _45
	movl	%edx, j(%rip)	 # _45, j
 # calc.c:195:         while(isdigit(s[++i] = c = input[j++])){
	cltq
	leaq	input(%rip), %rdx	 #, tmp193
	movzbl	(%rax,%rdx), %eax	 # input[j.25_44], _46
 # calc.c:195:         while(isdigit(s[++i] = c = input[j++])){
	movsbl	%al, %eax	 # _46, tmp194
	movl	%eax, -8(%rbp)	 # tmp194, c
 # calc.c:195:         while(isdigit(s[++i] = c = input[j++])){
	addl	$1, -4(%rbp)	 #, i
 # calc.c:195:         while(isdigit(s[++i] = c = input[j++])){
	movl	-4(%rbp), %eax	 # i, tmp195
	movslq	%eax, %rdx	 # tmp195, _47
 # calc.c:195:         while(isdigit(s[++i] = c = input[j++])){
	movq	16(%rbp), %rax	 # s, tmp196
	addq	%rdx, %rax	 # _47, _48
 # calc.c:195:         while(isdigit(s[++i] = c = input[j++])){
	movl	-8(%rbp), %edx	 # c, tmp197
	movb	%dl, (%rax)	 # _49, *_48
 # calc.c:195:         while(isdigit(s[++i] = c = input[j++])){
	movzbl	(%rax), %eax	 # *_48, _50
 # calc.c:195:         while(isdigit(s[++i] = c = input[j++])){
	movsbl	%al, %eax	 # _50, _51
	subl	$48, %eax	 #, _52
	cmpl	$9, %eax	 #, _52
	jbe	.L56	 #,
.L55:
 # calc.c:199:     if(c == '.'){
	cmpl	$46, -8(%rbp)	 #, c
	jne	.L57	 #,
 # calc.c:200:         while(isdigit(s[++i] = c = input[j++])){
	nop	
.L58:
 # calc.c:200:         while(isdigit(s[++i] = c = input[j++])){
	movl	j(%rip), %eax	 # j, j.26_53
	leal	1(%rax), %edx	 #, _55
	movl	%edx, j(%rip)	 # _55, j
 # calc.c:200:         while(isdigit(s[++i] = c = input[j++])){
	cltq
	leaq	input(%rip), %rdx	 #, tmp199
	movzbl	(%rax,%rdx), %eax	 # input[j.27_54], _56
 # calc.c:200:         while(isdigit(s[++i] = c = input[j++])){
	movsbl	%al, %eax	 # _56, tmp200
	movl	%eax, -8(%rbp)	 # tmp200, c
 # calc.c:200:         while(isdigit(s[++i] = c = input[j++])){
	addl	$1, -4(%rbp)	 #, i
 # calc.c:200:         while(isdigit(s[++i] = c = input[j++])){
	movl	-4(%rbp), %eax	 # i, tmp201
	movslq	%eax, %rdx	 # tmp201, _57
 # calc.c:200:         while(isdigit(s[++i] = c = input[j++])){
	movq	16(%rbp), %rax	 # s, tmp202
	addq	%rdx, %rax	 # _57, _58
 # calc.c:200:         while(isdigit(s[++i] = c = input[j++])){
	movl	-8(%rbp), %edx	 # c, tmp203
	movb	%dl, (%rax)	 # _59, *_58
 # calc.c:200:         while(isdigit(s[++i] = c = input[j++])){
	movzbl	(%rax), %eax	 # *_58, _60
 # calc.c:200:         while(isdigit(s[++i] = c = input[j++])){
	movsbl	%al, %eax	 # _60, _61
	subl	$48, %eax	 #, _62
	cmpl	$9, %eax	 #, _62
	jbe	.L58	 #,
.L57:
 # calc.c:204:     s[i] = '\0';
	movl	-4(%rbp), %eax	 # i, tmp204
	movslq	%eax, %rdx	 # tmp204, _63
	movq	16(%rbp), %rax	 # s, tmp205
	addq	%rdx, %rax	 # _63, _64
 # calc.c:204:     s[i] = '\0';
	movb	$0, (%rax)	 #, *_64
 # calc.c:206:     if(c != EOF){
	cmpl	$-1, -8(%rbp)	 #, c
	je	.L59	 #,
 # calc.c:208:         j--;
	movl	j(%rip), %eax	 # j, j.28_65
	subl	$1, %eax	 #, _66
	movl	%eax, j(%rip)	 # _66, j
.L59:
 # calc.c:211:     return NUMBER;
	movl	$48, %eax	 #, _76
.L50:
 # calc.c:212: }
	addq	$48, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.globl	optype
	.def	optype;	.scl	2;	.type	32;	.endef
	.seh_proc	optype
optype:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$64, %rsp	 #,
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # s, s
 # calc.c:298:     int numop = 4;
	movl	$4, -8(%rbp)	 #, numop
 # calc.c:299:     char sin[] = "sin";
	movl	$7235955, -12(%rbp)	 #, sin
 # calc.c:300:     char cos[] = "cos";
	movl	$7565155, -16(%rbp)	 #, cos
 # calc.c:301:     char pow[] = "exp";
	movl	$7370853, -20(%rbp)	 #, pow
 # calc.c:302:     char ans[] = "ans";
	movl	$7564897, -24(%rbp)	 #, ans
 # calc.c:303:     int operations[] = {1, 1, 1, 1}; // eventually, 
	movl	$1, -48(%rbp)	 #, operations[0]
	movl	$1, -44(%rbp)	 #, operations[1]
	movl	$1, -40(%rbp)	 #, operations[2]
	movl	$1, -36(%rbp)	 #, operations[3]
 # calc.c:304:     int definitions[] = {SIN , COS, EXP, ANS};
	movl	$20, -64(%rbp)	 #, definitions[0]
	movl	$30, -60(%rbp)	 #, definitions[1]
	movl	$40, -56(%rbp)	 #, definitions[2]
	movl	$50, -52(%rbp)	 #, definitions[3]
 # calc.c:305:     int i = 0;
	movl	$0, -4(%rbp)	 #, i
 # calc.c:306:     while(s[i] != '\0'){
	jmp	.L62	 #
.L67:
 # calc.c:307:         if(operations[0] && i<3 &&(s[i] != sin[i])){
	movl	-48(%rbp), %eax	 # operations[0], _1
 # calc.c:307:         if(operations[0] && i<3 &&(s[i] != sin[i])){
	testl	%eax, %eax	 # _1
	je	.L63	 #,
 # calc.c:307:         if(operations[0] && i<3 &&(s[i] != sin[i])){
	cmpl	$2, -4(%rbp)	 #, i
	jg	.L63	 #,
 # calc.c:307:         if(operations[0] && i<3 &&(s[i] != sin[i])){
	movl	-4(%rbp), %eax	 # i, tmp124
	movslq	%eax, %rdx	 # tmp124, _2
	movq	16(%rbp), %rax	 # s, tmp125
	addq	%rdx, %rax	 # _2, _3
	movzbl	(%rax), %edx	 # *_3, _4
 # calc.c:307:         if(operations[0] && i<3 &&(s[i] != sin[i])){
	movl	-4(%rbp), %eax	 # i, tmp127
	cltq
	movzbl	-12(%rbp,%rax), %eax	 # sin[i_25], _5
 # calc.c:307:         if(operations[0] && i<3 &&(s[i] != sin[i])){
	cmpb	%al, %dl	 # _5, _4
	je	.L63	 #,
 # calc.c:308:             operations[0] = 0;
	movl	$0, -48(%rbp)	 #, operations[0]
.L63:
 # calc.c:310:         if(operations[1] && i<3 &&(s[i] != cos[i])){
	movl	-44(%rbp), %eax	 # operations[1], _6
 # calc.c:310:         if(operations[1] && i<3 &&(s[i] != cos[i])){
	testl	%eax, %eax	 # _6
	je	.L64	 #,
 # calc.c:310:         if(operations[1] && i<3 &&(s[i] != cos[i])){
	cmpl	$2, -4(%rbp)	 #, i
	jg	.L64	 #,
 # calc.c:310:         if(operations[1] && i<3 &&(s[i] != cos[i])){
	movl	-4(%rbp), %eax	 # i, tmp128
	movslq	%eax, %rdx	 # tmp128, _7
	movq	16(%rbp), %rax	 # s, tmp129
	addq	%rdx, %rax	 # _7, _8
	movzbl	(%rax), %edx	 # *_8, _9
 # calc.c:310:         if(operations[1] && i<3 &&(s[i] != cos[i])){
	movl	-4(%rbp), %eax	 # i, tmp131
	cltq
	movzbl	-16(%rbp,%rax), %eax	 # cos[i_25], _10
 # calc.c:310:         if(operations[1] && i<3 &&(s[i] != cos[i])){
	cmpb	%al, %dl	 # _10, _9
	je	.L64	 #,
 # calc.c:311:             operations[1] = 0;
	movl	$0, -44(%rbp)	 #, operations[1]
.L64:
 # calc.c:313:         if(operations[2] && i<3 &&(s[i] != pow[i])){
	movl	-40(%rbp), %eax	 # operations[2], _11
 # calc.c:313:         if(operations[2] && i<3 &&(s[i] != pow[i])){
	testl	%eax, %eax	 # _11
	je	.L65	 #,
 # calc.c:313:         if(operations[2] && i<3 &&(s[i] != pow[i])){
	cmpl	$2, -4(%rbp)	 #, i
	jg	.L65	 #,
 # calc.c:313:         if(operations[2] && i<3 &&(s[i] != pow[i])){
	movl	-4(%rbp), %eax	 # i, tmp132
	movslq	%eax, %rdx	 # tmp132, _12
	movq	16(%rbp), %rax	 # s, tmp133
	addq	%rdx, %rax	 # _12, _13
	movzbl	(%rax), %edx	 # *_13, _14
 # calc.c:313:         if(operations[2] && i<3 &&(s[i] != pow[i])){
	movl	-4(%rbp), %eax	 # i, tmp135
	cltq
	movzbl	-20(%rbp,%rax), %eax	 # pow[i_25], _15
 # calc.c:313:         if(operations[2] && i<3 &&(s[i] != pow[i])){
	cmpb	%al, %dl	 # _15, _14
	je	.L65	 #,
 # calc.c:314:             operations[2]  = 0;
	movl	$0, -40(%rbp)	 #, operations[2]
.L65:
 # calc.c:316:         if(operations[3] && i<3 &&(s[i] != ans[i])){
	movl	-36(%rbp), %eax	 # operations[3], _16
 # calc.c:316:         if(operations[3] && i<3 &&(s[i] != ans[i])){
	testl	%eax, %eax	 # _16
	je	.L66	 #,
 # calc.c:316:         if(operations[3] && i<3 &&(s[i] != ans[i])){
	cmpl	$2, -4(%rbp)	 #, i
	jg	.L66	 #,
 # calc.c:316:         if(operations[3] && i<3 &&(s[i] != ans[i])){
	movl	-4(%rbp), %eax	 # i, tmp136
	movslq	%eax, %rdx	 # tmp136, _17
	movq	16(%rbp), %rax	 # s, tmp137
	addq	%rdx, %rax	 # _17, _18
	movzbl	(%rax), %edx	 # *_18, _19
 # calc.c:316:         if(operations[3] && i<3 &&(s[i] != ans[i])){
	movl	-4(%rbp), %eax	 # i, tmp139
	cltq
	movzbl	-24(%rbp,%rax), %eax	 # ans[i_25], _20
 # calc.c:316:         if(operations[3] && i<3 &&(s[i] != ans[i])){
	cmpb	%al, %dl	 # _20, _19
	je	.L66	 #,
 # calc.c:317:             operations[3]  = 0;
	movl	$0, -36(%rbp)	 #, operations[3]
.L66:
 # calc.c:319:         i++;
	addl	$1, -4(%rbp)	 #, i
.L62:
 # calc.c:306:     while(s[i] != '\0'){
	movl	-4(%rbp), %eax	 # i, tmp140
	movslq	%eax, %rdx	 # tmp140, _21
	movq	16(%rbp), %rax	 # s, tmp141
	addq	%rdx, %rax	 # _21, _22
	movzbl	(%rax), %eax	 # *_22, _23
 # calc.c:306:     while(s[i] != '\0'){
	testb	%al, %al	 # _23
	jne	.L67	 #,
 # calc.c:321:     for(i=0; i < numop; i++){
	movl	$0, -4(%rbp)	 #, i
 # calc.c:321:     for(i=0; i < numop; i++){
	jmp	.L68	 #
.L71:
 # calc.c:322:         if(operations[i]){
	movl	-4(%rbp), %eax	 # i, tmp143
	cltq
	movl	-48(%rbp,%rax,4), %eax	 # operations[i_26], _24
 # calc.c:322:         if(operations[i]){
	testl	%eax, %eax	 # _24
	je	.L69	 #,
 # calc.c:323:             return definitions[i];
	movl	-4(%rbp), %eax	 # i, tmp145
	cltq
	movl	-64(%rbp,%rax,4), %eax	 # definitions[i_26], _56
	jmp	.L61	 #
.L69:
 # calc.c:321:     for(i=0; i < numop; i++){
	addl	$1, -4(%rbp)	 #, i
.L68:
 # calc.c:321:     for(i=0; i < numop; i++){
	movl	-4(%rbp), %eax	 # i, tmp146
	cmpl	-8(%rbp), %eax	 # numop, tmp146
	jl	.L71	 #,
.L61:
 # calc.c:328: }
	addq	$64, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.globl	getline
	.def	getline;	.scl	2;	.type	32;	.endef
	.seh_proc	getline
getline:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # s, s
	movl	%edx, 24(%rbp)	 # lim, lim
 # calc.c:331:     int i = 0, c;
	movl	$0, -4(%rbp)	 #, i
 # calc.c:333:     while(lim-- > 0 && (c = getchar()) != EOF && c != '\n'){
	jmp	.L73	 #
.L75:
 # calc.c:334:         s[i++] = c;
	movl	-4(%rbp), %eax	 # i, i.29_1
	leal	1(%rax), %edx	 #, tmp111
	movl	%edx, -4(%rbp)	 # tmp111, i
	movslq	%eax, %rdx	 # i.29_1, _2
 # calc.c:334:         s[i++] = c;
	movq	16(%rbp), %rax	 # s, tmp112
	addq	%rdx, %rax	 # _2, _3
 # calc.c:334:         s[i++] = c;
	movl	-8(%rbp), %edx	 # c, tmp113
	movb	%dl, (%rax)	 # _4, *_3
.L73:
 # calc.c:333:     while(lim-- > 0 && (c = getchar()) != EOF && c != '\n'){
	movl	24(%rbp), %eax	 # lim, lim.30_5
	leal	-1(%rax), %edx	 #, tmp114
	movl	%edx, 24(%rbp)	 # tmp114, lim
 # calc.c:333:     while(lim-- > 0 && (c = getchar()) != EOF && c != '\n'){
	testl	%eax, %eax	 # lim.30_5
	jle	.L74	 #,
 # calc.c:333:     while(lim-- > 0 && (c = getchar()) != EOF && c != '\n'){
	call	getchar	 #
	movl	%eax, -8(%rbp)	 # tmp115, c
 # calc.c:333:     while(lim-- > 0 && (c = getchar()) != EOF && c != '\n'){
	cmpl	$-1, -8(%rbp)	 #, c
	je	.L74	 #,
 # calc.c:333:     while(lim-- > 0 && (c = getchar()) != EOF && c != '\n'){
	cmpl	$10, -8(%rbp)	 #, c
	jne	.L75	 #,
.L74:
 # calc.c:336:     if(c == '\n'){
	cmpl	$10, -8(%rbp)	 #, c
	jne	.L76	 #,
 # calc.c:337:         s[i++] = c;
	movl	-4(%rbp), %eax	 # i, i.31_6
	leal	1(%rax), %edx	 #, tmp116
	movl	%edx, -4(%rbp)	 # tmp116, i
	movslq	%eax, %rdx	 # i.31_6, _7
 # calc.c:337:         s[i++] = c;
	movq	16(%rbp), %rax	 # s, tmp117
	addq	%rdx, %rax	 # _7, _8
 # calc.c:337:         s[i++] = c;
	movl	-8(%rbp), %edx	 # c, tmp118
	movb	%dl, (%rax)	 # _9, *_8
.L76:
 # calc.c:339:     s[i] = '\0';
	movl	-4(%rbp), %eax	 # i, tmp119
	movslq	%eax, %rdx	 # tmp119, _10
	movq	16(%rbp), %rax	 # s, tmp120
	addq	%rdx, %rax	 # _10, _11
 # calc.c:339:     s[i] = '\0';
	movb	$0, (%rax)	 #, *_11
 # calc.c:340:     return i;
	movl	-4(%rbp), %eax	 # i, _33
 # calc.c:341: }
	addq	$48, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.globl	buf
	.bss
	.align 32
buf:
	.space 100
	.globl	bufp
	.align 4
bufp:
	.space 4
	.text
	.globl	getch
	.def	getch;	.scl	2;	.type	32;	.endef
	.seh_proc	getch
getch:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$32, %rsp	 #,
	.seh_stackalloc	32
	.seh_endprologue
 # calc.c:350:     if(bufp > 0){
	movl	bufp(%rip), %eax	 # bufp, bufp.32_1
 # calc.c:350:     if(bufp > 0){
	testl	%eax, %eax	 # bufp.32_1
	jle	.L79	 #,
 # calc.c:351:         return buf[--bufp];
	movl	bufp(%rip), %eax	 # bufp, bufp.33_2
	subl	$1, %eax	 #, _3
 # calc.c:351:         return buf[--bufp];
	movl	%eax, bufp(%rip)	 # _3, bufp
 # calc.c:351:         return buf[--bufp];
	movl	bufp(%rip), %eax	 # bufp, bufp.34_4
 # calc.c:351:         return buf[--bufp];
	cltq
	leaq	buf(%rip), %rdx	 #, tmp106
	movzbl	(%rax,%rdx), %eax	 # buf[bufp.34_4], _5
	movsbl	%al, %eax	 # _5, _6
	jmp	.L80	 #
.L79:
 # calc.c:353:         return getchar();
	call	getchar	 #
.L80:
 # calc.c:357: }
	addq	$32, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.section .rdata,"dr"
.LC8:
	.ascii "ungetch: too many characters\12\0"
	.text
	.globl	ungetch
	.def	ungetch;	.scl	2;	.type	32;	.endef
	.seh_proc	ungetch
ungetch:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$32, %rsp	 #,
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)	 # ch, ch
 # calc.c:360:     if (bufp >= BUFFSIZE){
	movl	bufp(%rip), %eax	 # bufp, bufp.35_1
 # calc.c:360:     if (bufp >= BUFFSIZE){
	cmpl	$99, %eax	 #, bufp.35_1
	jle	.L82	 #,
 # calc.c:361:         printf("ungetch: too many characters\n");
	leaq	.LC8(%rip), %rax	 #, tmp104
	movq	%rax, %rcx	 # tmp104,
	call	printf	 #
 # calc.c:362:         return(0);
	movl	$0, %eax	 #, _6
	jmp	.L83	 #
.L82:
 # calc.c:366:     buf[bufp++] = ch;
	movl	bufp(%rip), %eax	 # bufp, bufp.36_2
	leal	1(%rax), %edx	 #, _4
	movl	%edx, bufp(%rip)	 # _4, bufp
 # calc.c:366:     buf[bufp++] = ch;
	movl	16(%rbp), %edx	 # ch, tmp105
	movl	%edx, %ecx	 # tmp105, _5
	cltq
	leaq	buf(%rip), %rdx	 #, tmp107
	movb	%cl, (%rax,%rdx)	 # _5, buf[bufp.37_3]
 # calc.c:368:     return(1);
	movl	$1, %eax	 #, _6
.L83:
 # calc.c:369: }
	addq	$32, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.globl	ungets
	.def	ungets;	.scl	2;	.type	32;	.endef
	.seh_proc	ungets
ungets:
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # s, s
 # calc.c:376:     int i = 0, state = 1;
	movl	$0, -4(%rbp)	 #, i
 # calc.c:376:     int i = 0, state = 1;
	movl	$1, -8(%rbp)	 #, state
 # calc.c:378:     while(state && s[i] != '\0'){
	jmp	.L85	 #
.L87:
 # calc.c:379:         state = ungetch(s[i++]);
	movl	-4(%rbp), %eax	 # i, i.38_1
	leal	1(%rax), %edx	 #, tmp113
	movl	%edx, -4(%rbp)	 # tmp113, i
	movslq	%eax, %rdx	 # i.38_1, _2
 # calc.c:379:         state = ungetch(s[i++]);
	movq	16(%rbp), %rax	 # s, tmp114
	addq	%rdx, %rax	 # _2, _3
	movzbl	(%rax), %eax	 # *_3, _4
 # calc.c:379:         state = ungetch(s[i++]);
	movsbl	%al, %eax	 # _4, _5
	movl	%eax, %ecx	 # _5,
	call	ungetch	 #
	movl	%eax, -8(%rbp)	 # tmp115, state
.L85:
 # calc.c:378:     while(state && s[i] != '\0'){
	cmpl	$0, -8(%rbp)	 #, state
	je	.L86	 #,
 # calc.c:378:     while(state && s[i] != '\0'){
	movl	-4(%rbp), %eax	 # i, tmp116
	movslq	%eax, %rdx	 # tmp116, _6
	movq	16(%rbp), %rax	 # s, tmp117
	addq	%rdx, %rax	 # _6, _7
	movzbl	(%rax), %eax	 # *_7, _8
 # calc.c:378:     while(state && s[i] != '\0'){
	testb	%al, %al	 # _8
	jne	.L87	 #,
.L86:
 # calc.c:381:     if(state && s[i] == '\0'){
	cmpl	$0, -8(%rbp)	 #, state
	je	.L89	 #,
 # calc.c:381:     if(state && s[i] == '\0'){
	movl	-4(%rbp), %eax	 # i, tmp118
	movslq	%eax, %rdx	 # tmp118, _9
	movq	16(%rbp), %rax	 # s, tmp119
	addq	%rdx, %rax	 # _9, _10
	movzbl	(%rax), %eax	 # *_10, _11
 # calc.c:381:     if(state && s[i] == '\0'){
	testb	%al, %al	 # _11
	jne	.L89	 #,
 # calc.c:382:         ungetch(s[i]);
	movl	-4(%rbp), %eax	 # i, tmp120
	movslq	%eax, %rdx	 # tmp120, _12
	movq	16(%rbp), %rax	 # s, tmp121
	addq	%rdx, %rax	 # _12, _13
	movzbl	(%rax), %eax	 # *_13, _14
 # calc.c:382:         ungetch(s[i]);
	movsbl	%al, %eax	 # _14, _15
	movl	%eax, %ecx	 # _15,
	call	ungetch	 #
.L89:
 # calc.c:384: }
	nop	
	addq	$48, %rsp	 #,
	popq	%rbp	 #
	ret	
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev2, Built by MSYS2 project) 14.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	atof;	.scl	2;	.type	32;	.endef
	.def	sin;	.scl	2;	.type	32;	.endef
	.def	cos;	.scl	2;	.type	32;	.endef
	.def	exp;	.scl	2;	.type	32;	.endef
	.def	getchar;	.scl	2;	.type	32;	.endef
