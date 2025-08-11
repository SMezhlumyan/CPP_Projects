#include "FileSystem.hpp"
#include <string>
template <typename T>



int main() {
    auto root = make_unique<Directory>("root");
    root->addChild(make_unique<File>("a.txt", 100));
    
    auto sub = make_unique<Directory>("sub");
    sub->addChild(make_unique<File>("b.txt", 200));
    
    root->addChild(std::move(sub));
    
    root->display();
    cout << "Total size: " << root->getSize() << " bytes" << endl;
}
