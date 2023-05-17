#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <chrono>
#include <filesystem>
#include <mutex>
#include <vector>
#include <thread>

using namespace std;
namespace fs = std::filesystem;

const int NUM_THREADS = 4;

void processLines(ifstream &inputFile, ofstream &outputFile, unordered_set<string> &uniqueLines, mutex &mtx) {
    string line;

    while (true) {
        mtx.lock();
        if (!getline(inputFile, line)) {
            mtx.unlock();
            break;
        }
        mtx.unlock();

        if (uniqueLines.find(line) == uniqueLines.end()) {
            mtx.lock();
            outputFile << line << endl;
            uniqueLines.insert(line);
            mtx.unlock();
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    string inputFileName = argv[1];
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file: " << inputFileName << endl;
        return 1;
    }

    string outputFileName = argv[2];
    ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        cerr << "Unable to open output file: " << outputFileName << endl;
        inputFile.close();
        return 1;
    }

    unordered_set<string> uniqueLines;
    mutex mtx;
    vector<thread> threads;

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(processLines, ref(inputFile), ref(outputFile), ref(uniqueLines), ref(mtx));
    }

    for (auto &t : threads) {
        t.join();
    }

    inputFile.close();
    outputFile.close();

    return 0;
}