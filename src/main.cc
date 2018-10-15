#include <iostream>
#include <vector>
#include <string>

#include "csv.cc"
#include "dijkstra.cc"

using namespace std;

int main(int argc, char** argv) {
	string file(argv[1]);
    string begin(argv[2]);
    string end(argv[3]);

	vector<string> vertex;
	vector<vector<string>> matrix;
	csv_tokenizer(vertex, matrix, file);

	Graph g;
	g.setGraph(vertex, matrix);

    if (!g.checkVertex())
        return 1;
    
    g.shorTestPath(begin, end);

    cout << endl << "shorTestPath:" << endl
        << "\tS = (a";
	for (const string vertex : g.getPath())
		cout << ", " << vertex;
    cout << ")" << endl;
    cout << "\tL(" << end << ") = "  << g.getWeight(end) << endl;

    return 0;
}
