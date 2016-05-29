#include "HashTable.h"
#include "HashTable.cpp"
#include <fstream>
#include <string>

int HashFuncInt(const int& key_, int size_) {
  return key_ % size_;
}

int HashFuncStr(const string& key_, int size_) {
  const char* t = key_.c_str();
  int l = 0;
  int summ = 0;
  while (t[l] != 0) {
    summ += t[l];
    l++;
  }
  return summ % size_;
}

void HashTest(string in_file, string out_file) {
  char s[80];
  string path = "../files/";
  in_file = path + in_file;
  out_file = path + out_file;
  cout << "Out File is " << out_file.c_str() << endl;
  cout << "Operations from file " << in_file.c_str() << endl;
  ifstream in(in_file.c_str());
  if (in.good()) {
    in.getline(s, 80);
    int size;
    int step;
    char type_o[7];
    sscanf(s, "key=%s data=int (size = %d, step = %d )", &type_o, &size, &step);
    cout << "Type Table is " << type_o << " " << size << " " << step << endl;
    in.close();
    if (type_o[0] == 'c') {
      HashTable<string, int> tab(size, step, HashFuncStr);
      tab.doOperationFile(in_file, out_file);
    } else {
      HashTable<int, int> tab(size, step, HashFuncInt);
      tab.doOperationFile(in_file, out_file);
    }
  } else {
    cout << "Error File \n";
  }
}

char sample[] =
  "key=int, data=int (size = 13, step = 3)\n"
  "Add        2213        22734\n"
  "Add        23992       5052\n"
  "Add        29849       5559\n"
  "Add        16873       16032\n"
  "Add        29889       31999\n"
  "Add        5652        24668\n"
  "Add        34          10086\n"
  "Add        22149       28753\n"
  "Add        11168       9484\n"
  "Add        9840        19006\n"
  "Del        29889\n"
  "Del        9840";

int main(int argc, char* argv[]) {
  if (argc > 1) {
    HashTest(argv[1], argv[2]);
  } else {
    HashTable<int, int> tab(13, 3, HashFuncInt);
    ofstream test("test1.txt");
    test << sample;
    test.close();
    cout << "In operations \n\n";
    tab.doOperationFile("test1.txt", "test2.txt");
    cout << "\n\nOut state \n\n";
    ifstream test1("test2.txt");
    char buf[80];
    while (!test1.eof()) {
      test1.getline(buf, 80);
      cout << buf << endl;
    }
    test1.close();
  }
  return 0;
}
