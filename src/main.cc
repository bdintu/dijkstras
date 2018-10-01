#include <iostream>
#include <vector>
#include <string>

#include "csv.cc"
#include "dijkstra.cc"

using namespace std;

int main(int argc, char** argv) {
	string filename(argv[1]);
	vector<string> vertex;
	vector<vector<string>> matrix;
	csv_tokenizer(vertex, matrix, filename);

	Graph g;
	g.setGraph(vertex, matrix);

    if (!g.checkVertex()) {
        return 1;
    }

	string start, stop;
	cout << "Begin: ";
	getline(cin, start);
	cout << "End: ";
	getline(cin, stop);
	g.shorTestPath(start, stop);

	for (const string vertex : g.getPath()) {
		cout << vertex << endl;
	}

    return 0;
}
