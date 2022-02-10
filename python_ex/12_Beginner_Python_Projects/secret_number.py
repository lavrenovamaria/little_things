import random

def guess(x=int(input('You will be guessing from 1 to: '))):
	rand_nbr = random.randint(1, x)
	guess = 0
	while guess != rand_nbr:
		guess = int(input(f'Guess a number between 1 and {x}: '))
		if guess < rand_nbr:
			print('Too low')
		elif guess > rand_nbr:
			print('Too high')
	print('Yay, you have guessed!')
guess()