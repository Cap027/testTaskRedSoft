#include <tuple>
#include <stdexcept>
#include <iostream>

using namespace std;

enum class MODE {
    STRING,
    FILE
};

tuple<MODE, string> scanInput(int argc, char* argv[]) {
    const char * invalidInputMsg = "Invalid Input";
    if (argc != 3) {
        throw invalid_argument(invalidInputMsg);
    }
    string mode = string(argv[1]);
    if (mode != "-f" && mode != "-s") {
        throw invalid_argument(invalidInputMsg);
    }
    string source = string(argv[2]);

    return { (mode == "-s" ? MODE::STRING : MODE::FILE), source };
}

void run(const MODE mode, const string& source) {
    string command;
    if (mode == MODE::STRING) {
        command = "echo \"" + source + "\" | xclip -sel clip";
    } else {
        command = "xclip \"" + source + "\" -sel clip -t \"$(file -b --mime-type \"" + source + "\")\"";
    }
    if (system(command.c_str()) != 0) {
        throw runtime_error("xclip error");
    }
    std::cout << (mode == MODE::STRING ? "String" : "Content of File") << " \"" << source << "\" copied to clipboard" << std::endl;
}

int main(int argc, char* argv[]) {
    MODE mode;
    string source;

    try {
        tie(mode, source) = scanInput(argc, argv);
    } catch (const std::invalid_argument& err) {
        cerr << err.what() << endl;
        return 1;
    }
    try {
        run(mode, source);
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
        return 2;
    }

    return 0;
}
