#!/usr/bin/python

def pentagonal(n):
	return n * (3 * n - 1) / 2


n = 0
LIMIT = 10000

pentagonals = [ pentagonal(i) for i in range(1, LIMIT) ]


def is_pentagonal(p):
	return p in pentagonals

diffs = [ pentagonals[i+1] - pentagonals[i] for i in range(0, LIMIT-2) ]

# print(F"pentagonals: {pentagonals}")
# print(F"diffs: {diffs}")

for i in range(1, LIMIT):
	for j in range(i+1, LIMIT):
		i_number = pentagonals[i - 1]
		j_number = pentagonals[j - 1]
		ij_sum = i_number + j_number
		ij_diff = abs(i_number - j_number)
		if(is_pentagonal(ij_sum) and is_pentagonal(ij_diff)):
			print(f"Candidate: | {i_number} - {j_number} | = {ij_diff}")
	# pentagonal = 
	# print(F"pentagonal {n} = {pentagonal}!")
	# n = n + 1

