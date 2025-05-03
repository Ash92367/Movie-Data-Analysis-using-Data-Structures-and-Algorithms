# Movie-Data-Analysis-using-Data-Structures-and-Algorithms
Movie Data Analysis using Data Structures and Algorithms uses key data structures like Binary Search Tree (BST), Heap, and Graph, combined with algorithms like Dijkstra’s and Prim’s, to manage and analyze movie data. The project focuses on sorting, searching, and traversing data based on director names, movie durations, and critic reviews.
Project Overview:
This project aims to demonstrate the application of various data structures and algorithms in managing and manipulating movie data. The project involves implementing a Binary Search Tree (BST), Heap, Graph, and several algorithms such as Dijkstra’s Algorithm and Prim’s Algorithm to model and analyze movie-related information. The primary goal is to simulate operations like sorting, searching, and traversal based on different fields such as director name, critic reviews, and movie duration.

Key Features:
Binary Search Tree (BST): The BST stores movie data (including director names, critic reviews, and director’s Facebook likes) and allows for efficient insertion, traversal, and sorting of movies based on different attributes.

Heap: A max-heap is used to efficiently sort the movies based on their director names, critic reviews, movie duration, and director Facebook likes.

Graph Representation: A graph structure is used to represent relationships between different directors and their movies. The project includes breadth-first search (BFS) and depth-first search (DFS) traversal of the graph.

Algorithms:

Dijkstra’s Algorithm: Finds the minimum distance from a source director to all other directors in the BST.

Prim’s Algorithm: Finds the minimum spanning tree (MST) based on the duration of the movies.

Functionality:
Movie Data Structure: Each movie is represented by a structure containing details such as director name, number of critic reviews, movie duration, and director's Facebook likes.

Sorting and Traversal: The BST enables an inorder traversal for sorted movie output based on director name, while heap sort is used to organize movies by different attributes.

Graph Operations: The graph allows for BFS traversal of directors, displaying their neighbors (related directors) and ensuring a connection between them.

File Handling: Movie data is read from a CSV file (IMDB_5000.csv), and the data is processed and stored in the BST, Heap, and Graph data structures.

Data Structures:
BST: Used for storing movie data in a sorted manner.

Heap: Used for sorting movies based on specific fields (director name, critic reviews, etc.).

Graph: Represents relationships between directors and allows for graph-based operations like BFS.

Algorithms Implemented:
Dijkstra’s Algorithm: Used to calculate the minimum distance from a given director (root) to all other directors.

Prim’s Algorithm: Computes the minimum spanning tree based on movie durations.

Conclusion:
This project demonstrates how data structures like BST, Heap, and Graph can be applied to real-world problems, such as analyzing and managing movie data. The combination of sorting, traversal, and graph algorithms enables efficient handling and analysis of large datasets.

