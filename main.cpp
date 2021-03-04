#include <iostream>
#include <driver.hh>

int main(int argc, char** argv) {
    int exit_code;
    Driver driver;

    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            driver.trace_parsing = true;
        } else if (argv[i] == std::string("-s")) {
            driver.trace_scanning = true;
        } else if (!driver.parse(argv[i])) {
             exit_code = driver.executeProgram();
             std::cout << "\nProgram finished with code " << exit_code << ".\n";
        } else {
            return 1;
        }
    }

    return 0;
}
