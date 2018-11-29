#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {

private:
    unordered_map<string, const unordered_map<string, unsigned>> adj_list;
    unordered_map<string, double> weight;
    unordered_map<string, string> previous;
	vector<string> unvisit, path;

public:
    void setGraph(vector<string>& vertex, vector<vector<string>>& matrix) {
        for (unsigned i=0; i<vertex.size(); ++i) {
            unordered_map<string, unsigned> l;
            for (unsigned j=0; j<matrix[i].size(); ++j) {
				unsigned num = stoi(matrix[i][j]);
                if (num != 0) {
                    l.insert({vertex[j], num});
                }
            }
            adj_list.insert({vertex[i], l});
        }
	}

    bool checkVertex() {
        if (adj_list.size() < 3 && adj_list.size() > 20) {
            cerr << "vertex not size [3,20]" << endl;
            return false;
        }

        return true;
    }

    void shorTestPath(const string& begin, const string& end) {
        
        auto comparator = [&](const string& left,const string& right) {
            return weight[left] > weight[right]; };

        cout << "set weight " << begin << " to 0 and other to inf." << endl
            << "add all node to unvisit." << endl << endl;
        for (auto& vertex : adj_list) {
            weight[vertex.first] = (vertex.first == begin) ? 0 : numeric_limits<unsigned>::max();
            unvisit.push_back(vertex.first);
            push_heap(unvisit.begin(), unvisit.end(), comparator);
        }
        
        while (!unvisit.empty()) {

            cout << "\nunvisit: { ";
            for(const auto& vertex : unvisit) {
                cout << vertex << ":";
                if (weight[vertex] == numeric_limits<unsigned>::max())
                    cout << "inf, ";
                else 
                    cout << weight[vertex] << ", ";
            }
            cout << "}" << endl;

            cout << "prev: { ";
            for(const auto& vertex : previous) {
                cout << vertex.first << ":";
                cout << vertex.second << ", ";
            }
            cout << "}" << endl;

            pop_heap(unvisit.begin(), unvisit.end(), comparator);
            string smallest = unvisit.back();
            unvisit.pop_back();
 
			cout << "find minimum weight of vertex in set unvisit" << endl;

            string str;
            getline(cin, str);

            cout << "\tselect vertex: " << smallest << ", weight: " << weight[smallest] << endl
                << "\tremove vertex: " << smallest << " from set unvisit" << endl;

            if (smallest == end) {
                cout << "\tfound vertex: " << endl;
                while (previous.find(smallest) != previous.end()) {
                    path.insert(path.begin(), smallest);
                    cout << "\t\tprev[" << smallest << "]: ";
                    smallest = previous[smallest];
                    cout << smallest << endl;
                }

                break;
            }


            cout << "\tfind neighbor: " << endl;
            for (const auto& neighbor : adj_list[smallest]) {
				if (find(unvisit.begin(), unvisit.end(), neighbor.first) != unvisit.end()) {
					int alt = weight[smallest] + neighbor.second;
					cout << "\t\tform " << smallest << " to " << neighbor.first 
						<< ": " << weight[smallest] << " + " <<  neighbor.second
						<< " = " << alt << endl;

					if (alt < weight[neighbor.first]) {
						cout << "\t\t\tset weight[" << neighbor.first << "]: " << alt
							<< ", prev[" << neighbor.first << "]: " << smallest << endl;
						weight[neighbor.first] = alt;
						previous[neighbor.first] = smallest;
						make_heap(unvisit.begin(), unvisit.end(), comparator);
					}
				}
            }
        }
    }

    double getWeight(string& vertex) {
        return weight[vertex];
    }

    vector<string>& getPath() {
        return path;
    }
};
