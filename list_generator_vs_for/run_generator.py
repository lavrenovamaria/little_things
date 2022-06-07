from datetime import datetime


def timeit(method):
    def wrapper(*args, **kwargs):
        start_time = datetime.now()
        res = method(*args, **kwargs)
        print(datetime.now() - start_time)
        return res
    return wrapper


@timeit
def list_generator(n):
    res = []
    for i in range(n):
        if i % 2 == 0:
            res.append(i)
        print("List_generator")
        return res


@timeit
def for_loop(n):
    l = [x for x in range(n) if x % 2 == 0]
    print("For loop")
    return l


l2 = list_generator(10**4)
l1 = for_loop(10**4)
