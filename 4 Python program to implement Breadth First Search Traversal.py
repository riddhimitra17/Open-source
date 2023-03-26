from collections import defaultdict

def AdjacencyLst(edges):
    al = defaultdict(list)
    for x, y in edges:
        al[x].append(y)
        al[y].append(x)
    return al

edges = [['A', 'B'], ['A', 'C'], ['B', 'D'], ['B', 'E'], ['C', 'F'], ['C', 'G'], ['D', 'H'], ['D', 'I'], ['E', 'J'], ['E', 'K'], ['F', 'L'], ['F', 'M']]
al = AdjacencyLst(edges)
print(al)

def bfs(al, vertex):
    visitedSet = set()
    queue = []
    visitedSet.add(vertex)
    queue.append(vertex)
    
    result = []
    while queue:
        y = queue[0]
        result.append(y)
        queue = queue[1:]
        for neighbor in al[y]:
            if neighbor not in visitedSet:
                visitedSet.add(neighbor)
                queue.append(neighbor)
    return result

print(bfs(al, 'A'))