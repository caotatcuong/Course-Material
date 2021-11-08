import pygame
import graphUI
from node_color import white, yellow, black, red, blue, purple, orange, green
from collections import deque
import math
from queue import PriorityQueue

"""
Feel free print graph, edges to console to get more understand input.
Do not change input parameters
Create new function/file if necessary
"""


# Get path from start to goal
def backtrace(parent, start, goal):
    path = [goal]
    while path[-1] != start:
        path.append(parent[path[-1]])
    path.reverse()
    return path


def BFS(graph, edges, edge_id, start, goal):
    """
    BFS search
    """
    # TODO: your code
    # Check exception value
    n = len(graph)
    if start > n or goal > n or start < 0 or goal < 0:
        return

    # Check special case
    if start == goal:
        graph[goal][3] = purple
        graphUI.updateUI()
        print("Implement BFS algorithm.")
        return

    # Initialize the parent nodes
    parent = {}
    # Initialize the visited nodes
    visited = set()
    # Initialize the queue nodes
    queue = deque()
    # Add add start to visited nodes
    queue.append(start)
    visited.add(start)
    # Set color of start is yellow
    graph[start][3] = yellow
    graphUI.updateUI()

    while queue:
        # Dequeue a vertex from queue
        vertex = queue.popleft()
        graph[vertex][3] = yellow

        # If not visited, mark it as visited, and enqueue it
        for adjacent in graph[vertex][1]:
            if adjacent not in visited:
                # Set edge from vertex to adjacency node of vertex is while edge and color of adjacent is red.
                edges[edge_id(vertex, adjacent)][1] = white
                graph[adjacent][3] = red
                graphUI.updateUI()
                visited.add(adjacent)
                queue.append(adjacent)
                parent[adjacent] = vertex
                # If goal exists in queue then stop
                if goal == adjacent:
                    break

        # Tracing the path from start to goal and color it green
        if goal in queue:
            path = backtrace(parent, start, goal)
            for i in range(len(path) - 1):
                edges[edge_id(path[i], path[i + 1])][1] = green
            break
        # Set color of visited is blue
        graph[vertex][3] = blue
        graphUI.updateUI()

    # Set color of start is orange and goal is purple
    graph[start][3] = orange
    graph[goal][3] = purple
    graphUI.updateUI()
    print("Implement BFS algorithm.")
    pass


def DFS(graph, edges, edge_id, start, goal):
    """
    DFS search
    """
    # TODO: your code
    # Check exception value
    n = len(graph)
    if start > n or goal > n or start < 0 or goal < 0:
        return
    # Check special case
    if start == goal:
        graph[goal][3] = purple
        graphUI.updateUI()
        print("Implement DFS algorithm.")
        return
    # Initialize the parent nodes
    parent = {}
    # Initialize the queue nodes
    stack = deque()
    # Initialize the visited nodes
    visited = set()
    stack.append(start)
    # Set color of start is yellow
    graph[start][3] = yellow
    graphUI.updateUI()

    while stack:
        # Pop a vertex from stack
        vertex = stack.pop()
        if vertex in visited:
            continue
        visited.add(vertex)
        graph[vertex][3] = yellow
        adjacents = []
        # If not visited, mark it as visited, and append it
        for adjacent in graph[vertex][1]:
            if adjacent not in visited:
                edges[edge_id(vertex, adjacent)][1] = white
                graph[adjacent][3] = red
                graphUI.updateUI()
                adjacents.append(adjacent)
                parent[adjacent] = vertex
                if goal == adjacent:
                    break
        adjacents.reverse()
        stack.extend(adjacents)

        # Tracing the path from start to goal and color it green
        if goal in stack:
            path = backtrace(parent, start, goal)
            for i in range(len(path) - 1):
                edges[edge_id(path[i], path[i + 1])][1] = green
            break

        # Set color of visited is blue
        graph[vertex][3] = blue
        graphUI.updateUI()

    # Set color of start is orange and goal is purple
    graph[start][3] = orange
    graph[goal][3] = purple
    graphUI.updateUI()
    print("Implement DFS algorithm.")
    pass


# Euclidean distance
def Distance2Vertex(vertex1, vertex2):
    return int(math.sqrt((vertex1[0][0] - vertex2[0][0]) ** 2 + (vertex1[0][1] - vertex2[0][1]) ** 2))


# Cost list of edges in graph
def EdgesCost(graph, edges):
    cost = {}
    for edge in edges:
        cost[edge] = Distance2Vertex(graph[edges[edge][0][0]], graph[edges[edge][0][1]])
    return cost


def UCS(graph, edges, edge_id, start, goal):
    """
    Uniform Cost Search search
    """
    # TODO: your code
    # Check exception value
    n = len(graph)
    if start > n or goal > n or start < 0 or goal < 0:
        return
    # Get costs in graph
    cost = EdgesCost(graph, edges)
    # Initialize the visited nodes
    visited = set()
    # Initialize the priority queue nodes(cost, vertex, path)
    queue = PriorityQueue()
    queue.put((0, start, [start]))
    # Set color of start is yellow
    graph[start][3] = yellow
    graphUI.updateUI()

    while queue:
        # Pop a vertex from queue
        f, vertex, path = queue.get()
        if vertex in visited:
            continue
        visited.add(vertex)
        graph[vertex][3] = yellow

        # If vertex = goal then stop and color the path
        if vertex == goal:
            for i in range(len(path) - 1):
                edges[edge_id(path[i], path[i + 1])][1] = green
            break

        # If not visited, mark it as visited, and enqueue it
        for adjacent in graph[vertex][1]:
            if adjacent not in visited:
                edges[edge_id(vertex, adjacent)][1] = white
                graph[adjacent][3] = red
                graphUI.updateUI()
                if (vertex, adjacent) not in cost:
                    cost1 = cost[(adjacent, vertex)]
                else:
                    cost1 = cost[(vertex, adjacent)]
                # Update cost and path
                queue.put((f + cost1, adjacent, path + [adjacent]))

        # Set color of visited is blue
        graph[vertex][3] = blue
        graphUI.updateUI()

    # Set color of start is orange and goal is purple
    graph[start][3] = orange
    graph[goal][3] = purple
    graphUI.updateUI()
    print("Implement Uniform Cost Search algorithm.")
    pass


# Heuristic of each vertex
def HeuristicFunction(graph, goal):
    h = {}
    for i in range(len(graph)):
        h[i] = Distance2Vertex(graph[i], graph[goal])
    return h


def AStar(graph, edges, edge_id, start, goal):
    """
    A star search
    """
    # TODO: your code
    # Check exception value
    n = len(graph)
    if start > n or goal > n or start < 0 or goal < 0:
        return
    # Get Heuristic of each vertex
    h = HeuristicFunction(graph, goal)
    # Get costs in graph
    cost = EdgesCost(graph, edges)
    # Initialize the visited nodes
    visited = set()
    # Initialize the priority queue nodes(cost, vertex, path)
    queue = PriorityQueue()
    queue.put((h[start], start, [start]))
    graph[start][3] = yellow
    graphUI.updateUI()
    flag = False

    while queue:
        # Pop a vertex from queue
        f, vertex, path = queue.get()
        if vertex in visited:
            continue
        visited.add(vertex)
        graph[vertex][3] = yellow

        # If vertex = goal then stop and color the path
        if vertex == goal:
            for i in range(len(path) - 1):
                edges[edge_id(path[i], path[i + 1])][1] = green
            break

        # If not visited, mark it as visited, and enqueue it
        for adjacent in graph[vertex][1]:
            if adjacent not in visited:
                edges[edge_id(vertex, adjacent)][1] = white
                graph[adjacent][3] = red
                graphUI.updateUI()
                if (vertex, adjacent) not in cost:
                    cost1 = cost[(adjacent, vertex)]
                else:
                    cost1 = cost[(vertex, adjacent)]
                # Update cost and path
                queue.put((f + cost1 + h[adjacent] - h[vertex], adjacent, path + [adjacent]))
                if goal == adjacent:
                    flag = True

        # Set color of visited is blue
        if not flag:
            graph[vertex][3] = blue
        graphUI.updateUI()

    # Set color of start is orange and goal is purple
    graph[start][3] = orange
    graph[goal][3] = purple
    graphUI.updateUI()
    print("Implement A* algorithm.")
    pass


def GreedyBestFirst(graph, edges, edge_id, start, goal):
    """
      Greedy Best First
    """
    # TODO: your code
    # Check exception value
    n = len(graph)
    if start > n or goal > n or start < 0 or goal < 0:
        return

    # Get Heuristic of each vertex
    h = HeuristicFunction(graph, goal)
    # Initialize the visited nodes
    visited = set()
    # Initialize the priority queue nodes(cost, vertex, path)
    queue = PriorityQueue()
    queue.put((h[start], start, [start]))
    graph[start][3] = yellow
    graphUI.updateUI()
    flag = False

    while queue:
        # Pop a vertex from queue
        f, vertex, path = queue.get()
        if vertex in visited:
            continue
        visited.add(vertex)
        graph[vertex][3] = yellow

        # If vertex = goal then stop and color the path
        if vertex == goal:
            for i in range(len(path) - 1):
                edges[edge_id(path[i], path[i + 1])][1] = green
            break

        # If not visited, mark it as visited, and enqueue it
        for adjacent in graph[vertex][1]:
            if adjacent not in visited:
                graph[adjacent][3] = red
                edges[edge_id(vertex, adjacent)][1] = white
            graphUI.updateUI()
            # Update cost and path
            queue.put((h[adjacent], adjacent, path + [adjacent]))
            if goal == adjacent:
                flag = True
                break

        # Set color of visited is blue
        if not flag:
            graph[vertex][3] = blue
        graphUI.updateUI()

    # Set color of start is orange and goal is purple
    graph[start][3] = orange
    graph[goal][3] = purple
    graphUI.updateUI()
    print("Implement Greedy Best First algorithm.")
    pass


def example_func(graph, edges, edge_id, start, goal):
    """
    This function is just show some basic feature that you can use your project.
    @param graph: list - contain information of graph (same value as global_graph)
                    list of object:
                     [0] : (x,y) coordinate in UI
                     [1] : adjacent node indexes
                     [2] : node edge color
                     [3] : node fill color
                Ex: graph = [
                                [
                                    (139, 140),             # position of node when draw on UI
                                    [1, 2],                 # list of adjacent node
                                    (100, 100, 100),        # grey - node edged color
                                    (0, 0, 0)               # black - node fill color
                                ],
                                [(312, 224), [0, 4, 2, 3], (100, 100, 100), (0, 0, 0)],
                                ...
                            ]
                It means this graph has Node 0 links to Node 1 and Node 2.
                Node 1 links to Node 0,2,3 and 4.
    @param edges: dict - dictionary of edge_id: [(n1,n2), color]. Ex: edges[edge_id(0,1)] = [(0,1), (0,0,0)] : set color
                    of edge from Node 0 to Node 1 is black.
    @param edge_id: id of each edge between two nodes. Ex: edge_id(0, 1) : id edge of two Node 0 and Node 1
    @param start: int - start vertices/node
    @param goal: int - vertices/node to search
    @return:
    """

    # Ex1: Set all edge from Node 1 to Adjacency node of Node 1 is green edges.
    node_1 = graph[1]
    for adjacency_node in node_1[1]:
        edges[edge_id(1, adjacency_node)][1] = green
    graphUI.updateUI()

    # Ex2: Set color of Node 2 is Red
    graph[2][3] = red
    graphUI.updateUI()

    # Ex3: Set all edge between node in a array.
    path = [4, 7, 9]  # -> set edge from 4-7, 7-9 is blue
    for i in range(len(path) - 1):
        edges[edge_id(path[i], path[i + 1])][1] = blue
    graphUI.updateUI()
