#include <fstream>
#include <vector>
#include <string>
#include <iterator>

#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

typedef tokenizer<escaped_list_separator<char>> Tokenizer;

int csv_tokenizer(vector<string>& vertex, vector<vector<double>>& matrix, const string& filename) {

    ifstream in(filename.c_str());
    if (!in.is_open()) {
		return -1;
	}

	bool head = true;
    string line;

    while (getline(in,line)) {
        Tokenizer tok(line);

		if (head){
			head = !head;
        	vertex.assign(tok.begin(), tok.end());
		} else {
			vector<string> vec_str;
        	vec_str.assign(tok.begin(), tok.end());
			
			vector<double> vec;
		    transform(vec_str.begin(), vec_str.end(), back_inserter(vec),
				[](const string& str) {
					return stod(str);
				});

			matrix.push_back(vec);
		}
    }

	return 0;
}
