#include "CLI/CLI.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    CLI::App app("yeah");
    app.set_help_all_flag("--help-all", "Expand all help");

    auto format = app.add_option_group("output_format", "formating type for output");
    auto target = app.add_option_group("output target", "target location for the output");

    bool csv{false};
    bool human{false};
    bool binary{false};

    format->add_flag("--csv", csv, "specify the output in csv format");
    format->add_flag("--human", human, "specify the output in human readable text format");
    format->add_flag("--binary", binary, "specify the output in binary format");

    format->require_option(1);
    std::string file_loc;
    std::string network_address;

    target->add_option("-o, --file", file_loc, "specify the file location of the output");
    target->add_option("--address", network_address, "specify a network address to send the file");

    format->require_option(0, 1);

    std::string txt;
    target->add_option("--text", txt, "text desc");
    format->require_option(0, 1);

    CLI11_PARSE(app, argc, argv);

    std::string format_type = (csv) ? std::string("CSV"): ((human) ? "human readable" : "binary");
    std::cout << "Selected " << format_type << "format" << std::endl;

    if (file_loc.empty()) {
        std::cout << " sent over network to " << file_loc << std::endl;
    }
    else if (network_address.empty()) {
        std::cout << " sent over network to " << network_address << std::endl;
    }
    else {
        std::cout << " sent to std::cout" << std::endl;
    }

    std::cout << "Txt: " << txt << std::endl;
    return 0;
}