#include <iostream>
#include <driver.hh>

int main(int argc, char** argv) {
    Driver driver;

    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            driver.trace_parsing = true;
        } else if (argv[i] == std::string("-s")) {
            driver.trace_scanning = true;
        } else if (!driver.parse(argv[i])) {
             driver.executeProgram();
        } else {

            driver.parse(argv[i]);
            std::cout << driver.executeProgram() << std::endl;
            ++i;
        }
    }
}

