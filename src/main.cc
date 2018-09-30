#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "csv.cc"
#include "dijkstra.cc"

using namespace std;

int main() {
	string filename("matrix.csv");
	vector<string> vertex;
	vector<vector<double>> matrix;
	csv_tokenizer(vertex, matrix, filename);

	Graph g;
	g.setVertex(vertex);
	g.setMatrix(matrix);
	
	for_each(matrix.begin(), matrix.end(), [](const vector<double>& matrix) {
		copy(matrix.begin(), matrix.end(), ostream_iterator<double>(cout));
		cout << endl;
	});
	
    return 0;
}
