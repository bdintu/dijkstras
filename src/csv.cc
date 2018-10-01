#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

typedef tokenizer<escaped_list_separator<char>> Tokenizer;

int csv_tokenizer(vector<string>& vertex, vector<vector<string>>& matrix, const string& filename) {

    ifstream in(filename.c_str());
    if (!in.is_open()) {
        cerr << "can't open file:" << filename << endl;
		return -1;
	}

	bool csv_head = true;
    string line;

    while (getline(in,line)) {
        Tokenizer tok(line);

		if (csv_head){
			csv_head = !csv_head;
        	vertex.assign(tok.begin(), tok.end());
		} else {
			vector<string> vec_str;
        	vec_str.assign(tok.begin(), tok.end());
			matrix.push_back(vec_str);
		}
    }

	return 0;
}
