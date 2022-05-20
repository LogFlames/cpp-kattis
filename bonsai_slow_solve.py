#!/usr/bin/env python3

N = int(input())

nodes = [list(map(int, input().split()))[1:] for n in range(N)]

steps = 0

haveLeafs = set()
leafs = {}

for n in range(N):
    if len(nodes[n]) == 1:
        haveLeafs.add(nodes[n][0])
        leafs[nodes[n][0]] = n

steps = 0

while len(haveLeafs) > 0:
    nextHaveLeafs = set()
    newLeafs = {}

    for n in haveLeafs:
        nodes[n].remove(leafs[n])

        newLeaf = -1
        for m in nodes[n]:
            if len(nodes[m]) == 1:
                newLeaf = m
                break
        if len(nodes[n]) == 1:
            nextHaveLeafs.add(nodes[n][0])
            newLeafs[nodes[n][0]] = n
        if newLeaf != -1:
            nextHaveLeafs.add(n)
            newLeafs[n] = newLeaf

    haveLeafs = nextHaveLeafs
    leafs = newLeafs
    steps += 1

print(steps)
