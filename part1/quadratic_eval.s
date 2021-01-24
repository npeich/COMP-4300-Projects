#
# Code to evaluate a quadratic
# Natalie Eichorn
#

	.text
	
main:
	# setting values to variables
	lw $t0, X
	lw $t1, A
	lw $t2, B
	lw $t3, C

	# mul $t0, $t0, $t4 - incorrect, this actually multiples t0 and t4 and saves to t0
    mul $t4, $t0, $t0  # X**2

	# mul $t1, $t4, $t4 - incorrect, this multiplies t4 times itself and saves to t1
    mul $t4, $t1, $t4  # A*X**2

	# mul $t0, $t2, $t5 - incorrect, this multiplies t2 to an empty register t5 and saves it to t0
    mul $t5, $t2, $t0  # B*X

	add $t4, $t5, $t4  # A*X**2 + B*X, this is correct

	# add $t3, $t4, $t4 - incorrect, this adds A*X**2 + B*X to itself and saves to t3
    add $t4, $t4, $t3  # A*X**2 + B*X + C

	la $a0, ans        # print a string
	li $v0, 4
	syscall

	move $a0, $t4      # now the result
	li $v0, 1
	syscall

	la $a0, nl         # and a newline
	li $v0, 4
	syscall

	li $v0, 10         # g'bye
	syscall

	.data
X:	.word 3
A:	.word 7
B:	.word 5
C:	.word 4
ans:	.asciiz "Answer = "
nl:	.asciiz "\n"
