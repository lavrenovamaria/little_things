from datetime import datetime


def for_loop():
    start_time = datetime.now()
    res = []
    for i in range(10**4):
        if i % 2 == 0:
            res.append(i)
        print(datetime.now() - start_time)
        return res


def list_generator():
    start_time = datetime.now()
    l = [x for x in range(10**4) if x % 2 == 0]
    print(datetime.now() - start_time)
    return l


l1 = for_loop()
l2 = list_generator()
