# Computer Network Simulation using Graph and Stack

## Overview

This project is a menu-driven C application that simulates packet transmission in a computer network using Graph and Stack data structures.

The network topology is represented using an adjacency matrix, where devices are modeled as vertices and connections between devices are modeled as edges. Depth-First Search (DFS) is used to find a route between a source and destination device, while a stack is used to store and trace the packet path.

## Features

* Create a network by specifying devices and connections
* Represent network topology using an adjacency matrix
* Display the network topology
* Simulate packet transmission between devices
* Find a route using Depth-First Search (DFS)
* Track and display the packet path using a stack
* Menu-driven user interface

## Data Structures Used

### Graph

* Represents the computer network
* Implemented using an adjacency matrix
* Devices are vertices
* Connections are edges

### Stack

* Stores the path followed by a packet
* Supports path tracing and backtracking during DFS

## Algorithm

### Network Creation

1. Read the number of devices.
2. Initialize the adjacency matrix.
3. Read network connections.
4. Update the adjacency matrix for each connection.

### Packet Routing

1. Read source and destination devices.
2. Perform DFS traversal from the source.
3. Push visited devices onto the stack.
4. Stop when the destination is reached.
5. Display the path stored in the stack.

## Sample Input

Number of Devices: 5

Connections:
0 1
0 2
1 3
2 4
3 4

Source Device: 0

Destination Device: 4

## Sample Output

Path Found:

0 -> 1 -> 3 -> 4

## Time Complexity

| Operation        | Time Complexity |
| ---------------- | --------------- |
| Create Network   | O(n² + e)       |
| Display Topology | O(n²)           |
| DFS Routing      | O(n²)           |
| Stack Push/Pop   | O(1)            |

Where:

* n = number of devices
* e = number of connections

## Concepts Demonstrated

* Graphs
* Adjacency Matrix
* Stacks
* Depth-First Search (DFS)
* Recursion
* Packet Routing Simulation

## Applications

* Computer Network Modeling
* Routing Simulation
* Data Structures Laboratory Projects
* Educational Demonstration of Graph Traversal

## Future Improvements

* Implement shortest-path routing using BFS
* Add weighted edges
* Support larger networks using dynamic memory allocation
* Add graphical visualization
* Simulate multiple packet transmissions

## Author

Data Structures Laboratory Mini Project

Computer Network Simulation using Graph and Stack Data Structures

Language: C
