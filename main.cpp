#include <ctime>
#include <fstream>

#include "SimpleWeb/server.hpp"

std::string get_date() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    return std::to_string(now -> tm_mon + 1) + "-" + std::to_string(now -> tm_mday) + "-" + std::to_string(now -> tm_year + 1900);
}

int main() {
    WebServer server(8080);

    std::ofstream file;
    while (1) {
        server.serve("content/");

        if (server.recentPost.content != "") {
            std::cout << "content" + server.recentPost.directory << std::endl;
            file.open("content" + server.recentPost.directory);
            file << server.recentPost.content;
            file.flush();
            file.close();
        }
    }

    return 0;
}