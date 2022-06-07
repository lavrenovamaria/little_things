from datetime import datetime


def timeit(method):
    def wrapper():
        start_time = datetime.now()
        res = method()
        print(datetime.now() - start_time)
        return res
    return wrapper


@timeit
def list_generator():
    res = []
    for i in range(10**4):
        if i % 2 == 0:
            res.append(i)
        print("List_generator")
        return res


@timeit
def for_loop():
    l = [x for x in range(10**4) if x % 2 == 0]
    print("For loop")
    return l


l2 = list_generator()
l1 = for_loop()
