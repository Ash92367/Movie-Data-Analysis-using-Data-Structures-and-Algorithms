#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <limits>

using namespace std;

// Structure to represent a movie
struct Movie {
    string directorName;
    int numCriticReviews;
    int duration;
    int directorFbLikes;
};

// BST Node
struct Node {
    Movie data;
    Node* left;
    Node* right;
};

// BST Class
class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert a movie into the BST
    void insertMovie(const Movie& movie) {
        Node* newNode = new Node;
        newNode->data = movie;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* current = root;
            while (true) {
                if (movie.directorName <= current->data.directorName) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                }
                else {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }


    // Inorder traversal of the BST
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << "Director Name: " << node->data.directorName << endl;
            cout << "Num Critic Reviews: " << node->data.numCriticReviews << endl;
            cout << "Duration: " << node->data.duration << endl;
            cout << "Director FB Likes: " << node->data.directorFbLikes << endl;
            cout << endl;
            inorderTraversal(node->right);
        }
    }

    // Sorting
    void inorderTraversal(Node* node, vector<Movie>& movies) {
        if (node != nullptr) {
            inorderTraversal(node->left, movies);
            movies.push_back(node->data);
            inorderTraversal(node->right, movies);
        }
    }

    // Get sorted movies based on a specified field
    vector<Movie> getSortedMovies(const string& field) {
        vector<Movie> movies;
        inorderTraversal(root, movies);

        if (field == "directorName") {
            sort(movies.begin(), movies.end(), [](const Movie& movie1, const Movie& movie2) {
                return movie1.directorName < movie2.directorName;
                });
        }
        else if (field == "numCriticReviews") {
            sort(movies.begin(), movies.end(), [](const Movie& movie1, const Movie& movie2) {
                return movie1.numCriticReviews < movie2.numCriticReviews;
                });
        }
        else if (field == "duration") {
            sort(movies.begin(), movies.end(), [](const Movie& movie1, const Movie& movie2) {
                return movie1.duration < movie2.duration;
                });
        }
        else if (field == "directorFbLikes") {
            sort(movies.begin(), movies.end(), [](const Movie& movie1, const Movie& movie2) {
                return movie1.directorFbLikes < movie2.directorFbLikes;
                });
        }

        return movies;
    }
};
Node* findNode(Node* node, const string& directorName) {
    if (node == nullptr || node->data.directorName == directorName) {
        return node;
    }

    if (directorName < node->data.directorName) {
        return findNode(node->left, directorName);
    } else {
        return findNode(node->right, directorName);
    }
}

// Wrapper method for findNode
Node* findNode(const string& directorName) {
    BST b;
    return findNode(b.root, directorName);
}

// Heap class
class Heap {
public:
    vector<Movie> heapArray;

    // Compare two movies based on the given field
    bool compareMovies(const Movie& movie1, const Movie& movie2, const string& field) {
        if (field == "directorName")
            return movie1.directorName > movie2.directorName;
        else if (field == "numCriticReviews")
            return movie1.numCriticReviews > movie2.numCriticReviews;
        else if (field == "duration")
            return movie1.duration > movie2.duration;
        else if (field == "directorFbLikes")
            return movie1.directorFbLikes > movie2.directorFbLikes;
        return false;
    }

    // Heapify the array based on the given field
    void heapify(int index, int heapSize, const string& field) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heapSize && compareMovies(heapArray[leftChild], heapArray[largest], field))
            largest = leftChild;

        if (rightChild < heapSize && compareMovies(heapArray[rightChild], heapArray[largest], field))
            largest = rightChild;

        if (largest != index) {
            swap(heapArray[index], heapArray[largest]);
            heapify(largest, heapSize, field);
        }
    }

    // Build heap from the array based on the given field
    void buildHeap(const string& field) {
        int heapSize = heapArray.size();
        for (int i = heapSize / 2 - 1; i >= 0; i--)
            heapify(i, heapSize, field);
    }

    // Heap sort based on the given field
    void heapSort(const string& field) {
        int heapSize = heapArray.size();
        buildHeap(field);

        for (int i = heapSize - 1; i >= 1; i--) {
            swap(heapArray[0], heapArray[i]);
            heapify(0, i, field);
        }
    }
};

// BFS Traversal
void bfsTraversal(const BST& bst) {
    if (bst.root == nullptr)
        return;

    queue<Node*> nodeQueue;
    nodeQueue.push(bst.root);

    while (!nodeQueue.empty()) {
        Node* current = nodeQueue.front();
        nodeQueue.pop();

        cout << "Director Name: " << current->data.directorName << endl;
        cout << "Num Critic Reviews: " << current->data.numCriticReviews << endl;
        cout << "Duration: " << current->data.duration << endl;
        cout << "Director FB Likes: " << current->data.directorFbLikes << endl;
        cout << endl;

        if (current->left != nullptr)
            nodeQueue.push(current->left);

        if (current->right != nullptr)
            nodeQueue.push(current->right);
    }
}

// DFS Traversal (Inorder)
void dfsTraversalInorder(const Node* node) {
    if (node != nullptr) {
        dfsTraversalInorder(node->left);
        cout << "Director Name: " << node->data.directorName << endl;
        cout << "Num Critic Reviews: " << node->data.numCriticReviews << endl;
        cout << "Duration: " << node->data.duration << endl;
        cout << "Director FB Likes: " << node->data.directorFbLikes << endl;
        cout << endl;
        dfsTraversalInorder(node->right);
    }
}

// Dijkstra's Algorithm
void dijkstraAlgorithm(const BST& bst) {
    // Map to store the minimum distance from a node to the source node
    map<string, int> distanceMap;

    // Initialize the distance map with infinity values for all nodes except the root
    distanceMap[bst.root->data.directorName] = 0;
    Node* rootNode = bst.root;
    if (rootNode->left != nullptr)
        distanceMap[rootNode->left->data.directorName] = numeric_limits<int>::max();
    if (rootNode->right != nullptr)
        distanceMap[rootNode->right->data.directorName] = numeric_limits<int>::max();

    // Priority queue to store the nodes based on their minimum distance
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push(make_pair(0, bst.root->data.directorName));

    while (!pq.empty()) {
        string currentDirectorName = pq.top().second;
        pq.pop();

        Node* currentNode = nullptr;
        if (currentDirectorName == bst.root->data.directorName)
            currentNode = bst.root;
        else
            currentNode = findNode(bst.root, currentDirectorName);

        if (currentNode == nullptr)
            continue;

        // Process the neighbors of the current node
        if (currentNode->left != nullptr) {
            int newDistance = distanceMap[currentDirectorName] + 1; // Assuming the edge weight as 1
            if (newDistance < distanceMap[currentNode->left->data.directorName]) {
                distanceMap[currentNode->left->data.directorName] = newDistance;
                pq.push(make_pair(newDistance, currentNode->left->data.directorName));
            }
        }

        if (currentNode->right != nullptr) {
            int newDistance = distanceMap[currentDirectorName] + 1; // Assuming the edge weight as 1
            if (newDistance < distanceMap[currentNode->right->data.directorName]) {
                distanceMap[currentNode->right->data.directorName] = newDistance;
                pq.push(make_pair(newDistance, currentNode->right->data.directorName));
            }
        }
    }

    // Print the minimum distance for each node
    cout << "Dijkstra's Algorithm: Minimum Distance from Root Node" << endl;
    for (const auto& entry : distanceMap) {
        cout << "Director Name: " << entry.first << ", Minimum Distance: " << entry.second << endl;
    }
}

// Prim's Algorithm
void primAlgorithm(const BST& bst) {
    // Map to store the minimum weight from a node to the MST
    map<string, int> weightMap;

    // Initialize the weight map with infinity values for all nodes except the root
    weightMap[bst.root->data.directorName] = 0;
    Node* rootNode = bst.root;
    if (rootNode->left != nullptr)
        weightMap[rootNode->left->data.directorName] = numeric_limits<int>::max();
    if (rootNode->right != nullptr)
        weightMap[rootNode->right->data.directorName] = numeric_limits<int>::max();

    // Priority queue to store the nodes based on their minimum weight
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push(make_pair(0, bst.root->data.directorName));

    while (!pq.empty()) {
        string currentDirectorName = pq.top().second;
        pq.pop();

        Node* currentNode = findNode(bst.root, currentDirectorName);

        if (currentNode == nullptr)
            continue;

        // Process the neighbors of the current node
        if (currentNode->left != nullptr) {
            int newWeight = currentNode->left->data.duration; // Assuming the edge weight as the duration of the movie
            if (newWeight < weightMap[currentNode->left->data.directorName]) {
                weightMap[currentNode->left->data.directorName] = newWeight;
                pq.push(make_pair(newWeight, currentNode->left->data.directorName));
            }
        }

        if (currentNode->right != nullptr) {
            int newWeight = currentNode->right->data.duration; // Assuming the edge weight as the duration of the movie
            if (newWeight < weightMap[currentNode->right->data.directorName]) {
                weightMap[currentNode->right->data.directorName] = newWeight;
                pq.push(make_pair(newWeight, currentNode->right->data.directorName));
            }
        }
    }

    // Print the minimum weight for each node
    cout << "Prim's Algorithm: Minimum Weight from Root Node" << endl;
    for (const auto& entry : weightMap) {
        cout << "Director Name: " << entry.first << ", Minimum Weight: " << entry.second << endl;
    }
}
//Graph struct
struct GraphNode {
    string directorName;
    vector<GraphNode*> neighbors;
};

//Graph class
class Graph {
public:
    map<string, GraphNode*> nodes;

    // Add a director to the graph
    void addDirector(const string& directorName) {
        if (nodes.find(directorName) == nodes.end()) {
            GraphNode* newNode = new GraphNode;
            newNode->directorName = directorName;
            nodes[directorName] = newNode;
        }
    }

    // Add an edge between two directors in the graph
    void addEdge(const string& director1, const string& director2) {
        addDirector(director1);
        addDirector(director2);

        GraphNode* node1 = nodes[director1];
        GraphNode* node2 = nodes[director2];

        node1->neighbors.push_back(node2);
        node2->neighbors.push_back(node1);
    }

    // Perform breadth-first search traversal of the graph
    void bfsTraversal(const string& startDirector) {
        if (nodes.find(startDirector) == nodes.end()) {
            cout << "Director not found in the graph." << endl;
            return;
        }

        cout << "BFS Traversal:" << endl;
        queue<GraphNode*> nodeQueue;
        map<string, bool> visited;

        GraphNode* startNode = nodes[startDirector];
        nodeQueue.push(startNode);
        visited[startDirector] = true;

        while (!nodeQueue.empty()) {
            GraphNode* current = nodeQueue.front();
            nodeQueue.pop();

            cout << "Director Name: " << current->directorName << endl;
            cout << "Neighbors: ";
            for (const auto& neighbor : current->neighbors) {
                cout << neighbor->directorName << " ";
                if (!visited[neighbor->directorName]) {
                    nodeQueue.push(neighbor);
                    visited[neighbor->directorName] = true;
                }
            }
            cout << endl << endl;
        }
    }
};
void readMoviesFromCSV(const string& fileName, BST& movieBST, Heap& movieHeap, Graph& movieGraph) {
    ifstream file(fileName);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    int lineCount = 0;
    while (getline(file, line)) {
        lineCount++;
        stringstream ss(line);
        string data[4];

        for (int i = 0; i < 4; i++) {
            if (!getline(ss, data[i], ',')) {
                cout << "Error parsing line " << lineCount << ", skipping." << endl;
                break;
            }
        }

        if (ss.fail()) {
            cout << "Error parsing line " << lineCount << ", skipping." << endl;
            continue;
        }

        try {
            Movie movie;
            movie.directorName = data[0];
            movie.numCriticReviews = stoi(data[1]);
            movie.duration = stoi(data[2]);
            movie.directorFbLikes = stoi(data[3]);

            movieBST.insertMovie(movie);
            movieHeap.heapArray.push_back(movie);
            movieGraph.addDirector(movie.directorName);
            GraphNode node;
            int i = 0;
            if (i != 0)
                movieGraph.addEdge(node.directorName, movie.directorName);
            i++;
        }
        catch (const invalid_argument& e) {
            cout << "Error parsing line " << lineCount << ", skipping." << endl;
        }
    }

    file.close();
}

int main() {
    BST movieBST;
    Heap movieHeap;
    Graph movieGraph;
    string fileName = "IMDB_5000.csv";

    // Read movies from the CSV file and store them in the BST and heap
    readMoviesFromCSV(fileName, movieBST, movieHeap, movieGraph);

    cout << "Inorder Traversal (BST):" << endl;
    // Perform inorder traversal of the BST
    movieBST.inorderTraversal(movieBST.root);

    // Sort the heap based on director's name
    movieHeap.heapSort("directorName");

    cout << "Sorted Heap (Director Name):" << endl;
    // Display sorted heap
    for (const Movie& movie : movieHeap.heapArray) {
        cout << "Director Name: " << movie.directorName << endl;
        cout << "Num Critic Reviews: " << movie.numCriticReviews << endl;
        cout << "Duration: " << movie.duration << endl;
        cout << "Director FB Likes: " << movie.directorFbLikes << endl;
        cout << endl;
    }

    cout << "BFS Traversal:" << endl;
    // Perform BFS traversal
    bfsTraversal(movieBST);

    cout << "DFS Traversal (Inorder):" << endl;
    // Perform DFS traversal (inorder)
    dfsTraversalInorder(movieBST.root);

    cout << "Dijkstra's Algorithm:" << endl;
    // Apply Dijkstra's algorithm
    dijkstraAlgorithm(movieBST);

    cout << "\n\nPrim's Algorithm:" << endl;
    // Apply Prim's algorithm
    primAlgorithm(movieBST);

    cout << "Sorting";
    vector<Movie> sortedMovies = movieBST.getSortedMovies("directorName");

    // Perform operations on the graph
    cout << "Graph";
    string startDirector = "Christopher Nolan";
    movieGraph.bfsTraversal(startDirector);

    return 0;
}