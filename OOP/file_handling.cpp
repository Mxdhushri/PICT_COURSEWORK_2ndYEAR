#include <iostream>
#include <fstream>

using namespace std;

class TextFile {
string path;

public:
TextFile(string fileName) {
this->path = "./store/" + fileName;
}

void printFile() {
ifstream file;

file.open(this->path);
string line;

if (file) {
while (getline(file, line)) { //taking inputs
cout<<line<<endl;
}
} else {
cout<<"File Does not exist.\n";
}

file.close();
}

void createFile() {
ofstream file;
file.open(this->path, std::ofstream::out | std::ofstream::trunc);
file.close();
}

void writeToFile(string content) {
ofstream file;
file.open(this->path);
file<<content;
file.close();
}

void appendToFile(string content) {
ofstream file;
file.open(this->path, std::ios_base::app);
file << content;
file.close();
}
};

int main() {
TextFile scratchPad("stratchPad.txt");
scratchPad.appendToFile("\nLine4");
scratchPad.printFile();

}

