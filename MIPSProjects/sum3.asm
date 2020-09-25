# Sum of three integers
#
# Objective:	Compute sum of three int
# Input:	Requests three int
# Output:	sum
####################DATA SEGMENT##################################
.data
prompt:		.asciiz		"Please enter three numbers: \n"
sum_msg:	.asciiz		"The sum is: "
####################CODE SEGMENT##################################
.text
.globl main
main:	la	$a0, prompt		#display prompt string
	li	$v0, 4	
	syscall
	li	$v0, 5
	syscall
	move	$t0, $v0
	li	$v0, 5
	syscall
	move	$t1, $v0
	li	$v0, 5
	syscall
	move	$t2, $v0
	addu	$t0, $t0, $t1
	addu	$t0, $t0, $t2
	la	$a0, sum_msg
	li	$v0, 4
	syscall
	move 	$a0, $t0
	li	$v0, 1
	syscall
	li	$v0, 10
	syscall