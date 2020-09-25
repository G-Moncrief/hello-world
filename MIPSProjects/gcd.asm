# Greatest Common Divisor (GCD)
#
# Objective:	Finds largest int that will evenly divide into two numbers
# Input:	Requests two ints and prompts user if they want to run program again
# Output:	outputs GCD
###############################DATA SEGMENT###########################################
.data
prompt:		.asciiz		"\n\nPlease enter two integers: \n"
gcd_msg:	.asciiz		" is the greatest common divisor.\n "
repeat:		.asciiz		"\nEnter \"0\" to quit: "
###############################CODE SEGMENT##########################################
.text
.globl main
main:		li	$v0, 4		# syscall code for print string
		la	$a0, prompt	# address of string to print
		syscall			# print prompt to enter two ints
		
		li	$v0, 5		# syscall code for read int		
		syscall			# read int	
		move	$a0, $v0	# store int in a0 (X)
		
		li	$v0, 5		# syscall code for read int
		syscall			# read int	
		move	$a1, $v0	# store int in a1 (Y)
	
		bge	$a0, $0, absY	# if X is positive branch to check Y
		sub	$a0, $0, $a0	# else get abs value by 0 - (-x)
absY:		bge	$a1, $0, loop	# if Y is positive branch to loop
		sub	$a1, $0, $a1	# else get abs value by 0 - (-y)	

loop:		remu	$t0, $a0, $a1	# N = X % Y
		move	$a0, $a1	# X = previous Y value
		move	$a1, $t0	# Y = N
		bgt	$a1, $0, loop	# if Y > 0 repeat loop
	
		li	$v0, 1		# syscall for print int
		syscall			# print int that broke loop
		
		li	$v0, 4		# syscall code for print string
		la	$a0, gcd_msg	# address of string to print
		syscall			# print gcd_msg string
	
		li	$v0, 4		# syscall code for print string
		la	$a0, repeat	# address of string to print
		syscall			# print prompt to repeat
		
		li	$v0, 12		# syscall code for read char
		syscall			# read char
		subi	$v0, $v0, 0x30	# convert to int	
		beq	$v0, $0, exit	# if user enters '0' branch to exit
		j	main		# else repeat

exit:		li	$v0, 10		# syscall code for exit program
		syscall			# exit program
