#include <fstream>
#include <iostream>
#include <unordered_set>
using namespace std;

const unordered_set<string> operators = {"+",  "-",  "*",  "/",
                                         "+=", "-=", "*=", "/="};

int main() {
  ifstream fs;
  fs.open("./example.c");

  size_t line_no = 1, char_no = 1;
  string str, op;
  while (getline(fs, str)) {
    for (auto ch : str) {
      if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
        op += ch;
      else if (operators.find(op) != operators.end()) {
        cout << "Line : " << line_no << ", char : " << char_no
             << " : op : " << op << endl;
        op.clear();
      } else
        op.clear();

      char_no++;
    }
    char_no = 1;
    line_no++;
  }
}