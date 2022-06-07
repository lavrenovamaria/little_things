# упаковка всех входящих элементов в кортеж это *args
# упаковка в словарь это **kwargs(keyword arguments)

a = [1, 2, 3]
b = [*a, 4, 5, 6]
print(b)
"""
[1,2,3,4,5,6]
"""


def print_scores(student, *scores):
    print(f"Student Name: {student}")
    for score in scores:
        print(score)


print_scores("Jonathan", 100, 95, 88, 92, 99)
"""
Student Name: Jonathan
100
95
88
92
99
"""


def print_pet_names(owner, **pets):
    print(f"Owner Name: {owner}")
    for pet, name in pets.items():
        print(f"{pet}: {name}")


print_pet_names("Jonathan", dog="Brock", fish=["Larry", "Curly", "Moe"], turtle="Shelldon")
"""
Owner Name: Jonathan
dog: Brock
fish: ['Larry', 'Curly', 'Moe']
turtle: Shelldon
"""