#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Graph {

private:
    unsigned n;
    vector<string> vertex;
    vector<vector<double>> matrix;

public:
    void setVertex(vector<string>& vertex) {
		vertex = vertex;
	}

	void setMatrix(vector<vector<double>>& matrix) {
		matrix = matrix;
	}

	void shorTestPath(string begin, string end) {}

};
