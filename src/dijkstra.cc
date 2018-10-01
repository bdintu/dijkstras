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

        for (auto& vertex : adj_list) {
            weight[vertex.first] = (vertex.first == begin) ? 0 : numeric_limits<unsigned>::max();
            unvisit.push_back(vertex.first);
            push_heap(unvisit.begin(), unvisit.end(), comparator);
        }
        cout << "Set all weight vertex to infinity but begin vertex" << endl;
        
        while (!unvisit.empty()) {
            pop_heap(unvisit.begin(), unvisit.end(), comparator);
            string smallest = unvisit.back();
            unvisit.pop_back();
			cout << "select " << smallest << endl;

            if (smallest == end) {
                cout << "\tfound vertex: " << end << endl;
                while (previous.find(smallest) != previous.end()) {
                    path.push_back(smallest);
                    smallest = previous[smallest];
                }

                break;
            }
            
            if (weight[smallest] == numeric_limits<unsigned>::max()) {
                cout << "\tweight " << smallest << " is infinity." << endl;
                break;
            }
            
            for (auto& neighbor : adj_list[smallest]) {
                int alt = weight[smallest] + neighbor.second;
				cout << "\tform " << smallest << " to " << neighbor.first << ", weight: " << alt <<endl;
                if (alt < weight[neighbor.first]) {
                    weight[neighbor.first] = alt;
                    previous[neighbor.first] = smallest;
                    make_heap(unvisit.begin(), unvisit.end(), comparator);
                }
            }
        }
    }

    vector<string>& getPath() {
        return path;
    }
};
