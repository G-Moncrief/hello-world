# String Search
#
# Objective:	Searches user input string for single char then 2 chars. Repeatable
# Input:	String and search character(s), if user wants to run program again
# Output:	Number of occurrences of character(s) in string
###############################DATA SEGMENT###########################################
.data
prompt:		.asciiz		"\n\nEnter a string of at most 100 characters: "
pchar:		.asciiz		"Enter a single character: "
p2char:		.asciiz		"\nEnter a string of two characters: "
repeat:		.asciiz		"\nRepeat (Y/N)? "
appears1:	.asciiz		"\nNumber of occurrences of "
appears2:	.asciiz		" = "	
in_str:		.space 101	
in_char:	.space 2
in_2char:	.space 3
###############################CODE SEGMENT##########################################
.text
.globl main
main:		li	$v0, 4		# system call code for print string
		la	$a0, prompt	# address of string to print
		syscall			# print prompt to enter string
		
		li	$v0, 8		# system call code for read string
		la	$a0, in_str	# a0 = address of string
		li	$a1, 101	# max str len
		syscall			# get input
		jal	toupper		# call toupper to conv to upper case
		move	$s4, $v0
		
		li	$v0, 4		# system call code for print string
		la	$a0, pchar	# address of string to print
		syscall			# print prompt to enter a single char	

		li	$v0, 8		# system call code for read string
		la	$a0, in_char	# a0 = address of string
		li	$a1, 2		# max str len
		syscall			# get input
		jal	toupper		# call toupper to conv to upper case
		
		and	$s0, $0, $0	# clear counter
		la	$t0, in_str	# load up to 100 char string
		la	$s1, in_char	# load single char
		lb	$s1, ($s1)	# load char
check1:		lb	$t1, ($t0)	# load string[i]
		beqz	$t1, exit_c1	# if NULL exit check1
		beq	$t1, $s1, found	# if string[i] = char branch to found
		addiu	$t0, $t0, 1	# i++
		j	check1		# repeat loop
found:		addiu	$t0, $t0, 1	# i++
		addiu	$s0, $s0, 1	# count++
		j	check1		# repeat loop
exit_c1:	la	$a1, in_char	# load char in a1
		jal	printres	# call printres

		li	$v0, 4		# syscall code for print string
		la	$a0, p2char	# address of string to print
		syscall			# print prompt to enter 2 chars	
		
		li	$v0, 8		# system call code for read string
		la	$a0, in_2char	# a0 = address of string
		li	$a1, 3		# max str len
		syscall			# get input
		jal	toupper		# call toupper to conv to upper case
		
		and	$s0, $0, $0	# clear counter
		la	$t0, in_str	# load up to 100 char string
		la	$t1, in_2char	# load 2 char string
		lb	$t2, 1($t1)	# t2 = char[1]
		lb	$t1, ($t1)	# t1 = char[0]
check2:		lb	$t3, ($t0)	# t3 = string[i]
		beqz	$t3, exit_c2	# if NULL exit check2
		bne	$t1, $t3, nope	# if string[i] != char[0] b to nope
		lb	$t3, 1($t0)	# t3 = string[i+1]
		bne	$t2, $t3, nope	# if string[i+1] != char[1] b to nope
		addiu	$s0, $s0, 1	# count++
		addiu	$t0, $t0, 1	# i++
		j	check2		# repeat loop
nope:		addiu	$t0, $t0, 1	# i++
		j	check2		# repeat loop
exit_c2:	la	$a1, in_2char	# load 2chars in a1
		jal	printres	# call printres
		
user_repeat:	li	$v0, 4		# syscall code for print string
		la	$a0, repeat	# address of string to print
		syscall			# print prompt to repeat
		li	$v0, 12		# syscall code for read char
		syscall			# read char
		beq	$v0, 'N', exit	# if user enters 'N' branch to exit
		beq	$v0, 'n', exit	# if user enters 'n' branch to exit
		beq	$v0, 'Y', main	# if user enters 'Y' branch to main
		beq	$v0, 'y', main	# if user enters 'y' branch to main
		j	user_repeat	# else repeat

toupper:	lb	$t0, ($a0)	# load string[i]
		beqz	$t0, exit_toup	# exit if null
		blt	$t0, 'a', no_c	# check if < a
		bgt	$t0, 'z', no_c	# check if > z
		addiu	$t0, $t0, -32	# else convert to uppercase
		sb	$t0, ($a0)	# save string[i]
no_c:		addiu	$a0, $a0, 1	# i++
		j	toupper		# repeat loop
exit_toup:	jr	$ra		# return to caller

printres:	li	$v0, 4		# syscall code for print string
		la	$a0, appears1	# address of string
		syscall			# print appears1
		
		move	$a0, $a1	# move a1 to a0
		li	$v0, 4		# syscall code for print
		syscall			# print char(s) being searched
		
		la	$a0, appears2	# address for string
		li	$v0, 4		# syscall code to print string
		syscall			# print appears2
		
		move	$a0, $s0	# move count to a0
		li	$v0, 1		# syscall code to print int
		syscall			# print count
		
		jr	$ra		# return to caller
		
exit:		li	$v0, 10		# syscall code for exit program
		syscall			# exit program
