from collections import defaultdict


def process_path(path):
    for i in range(len(path)):
        if i == len(path) - 1:
            break
        used_vertices.update(vertices_counter[(path[i], path[i+1])])


def solve(u, d, path):
    visited[u] = True
    path.append(u)
    pathlen = len(path) - 1

    if u == d and pathlen >= minlen and pathlen <= maxlen:
        process_path(path)

    for i in graph[u]:
        if not visited[i]:
            solve(i, d, path)
    path.pop()
    visited[u] = False


n, m = (int(x) for x in input().split(' '))
s, t = (int(x) for x in input().split(' '))
minlen, maxlen = (int(x) for x in input().split(' '))
d = int(input())

visited = [False] * (n + 1)
graph = defaultdict(set)
vertices_counter = defaultdict(set)
used_vertices = set()

for i in range(m):
    l, a, b = (int(x) for x in input().split(' '))
    graph[a].add(b)
    vertices_counter[(a, b)].add(l)
    if d == 0:
        graph[b].add(a)
        vertices_counter[(b, a)].add(l)

solve(s, t, [])

used_vertices = sorted(list(used_vertices))
print(len(used_vertices))
output = ''
for i in range(len(used_vertices)):
    output += str(used_vertices[i]) + ' '
print(output)
