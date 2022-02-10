# # string concatenation (aka how to put strings together)
# # suppose we want to create a string that says "subscribe to _____ "
youtuber = "Kylie Ying" # some string variable

# a few ways to do this
print("subscribe to " + youtuber)
print("subscribe to {}".format(youtuber))
print(f"subscribe to {youtuber}")

adj = input("Adjective: ")
verb1 = input("Verb 1: ")
verb2 = input("Verb 2: ")
famous_person = input("Celebrity: ")

madlib = f"Computer programming is so {adj}! \
	It makes me {verb1}. Stay hydrated and {verb2} like you are {famous_person}"

print(madlib)