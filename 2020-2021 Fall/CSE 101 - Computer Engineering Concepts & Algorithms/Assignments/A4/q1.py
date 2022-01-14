import random
N = random.randint(0, 100)
attempt = 0
while True:
    guess = int(input("Guess a number: "))
    if guess < N:
        print("Guess higher")
        attempt += 1
    elif guess > N:
        print("Guess lower")
        attempt += 1
    else:
        break
print("The number of guesses:", attempt)

