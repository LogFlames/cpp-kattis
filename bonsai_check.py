#!/usr/bin/env python3

import subprocess
import random

def getr(n, roots):
    if roots[n] == n:
        return n
    a = getr(roots[n], roots)
    roots[n] = a
    return a

for i in range(3,101):
    print("{}{}%               ".format(" " if i < 10 else "", i), end = "\r")
    root = [l for l in range(i)]
    graph = [[] for n in range(i)]
    for n in range(i - 1):
        a = random.randrange(0,i)
        while a == n or getr(a, root) == getr(n, root):
            a = random.randrange(0,i)

        root[n] = max(root[n], root[a])
        root[a] = max(root[n], root[a])

        graph[n].append(a)
        graph[a].append(n)

    with open("temp.txt", "w+") as f:
        f.writelines([str(len(graph)) + '\n', *[f"{len(graph[j])} {' '.join(map(str, graph[j]))}\n" for j in range(len(graph))]])

    a = subprocess.check_output("./o.out < temp.txt", shell=True)
    b = subprocess.check_output("python bonsai_slow_solve.py < temp.txt", shell=True)

    if a != b:
        print()
        print(graph)
        print("a")
        print(a)
        print("b")
        print(b)
        break
