#include "FileSystem.hpp"

// **************************************************************************************
// **********************************   FILESYSTEMNODE   ********************************
// **************************************************************************************

FileSystemNode::FileSystemNode(string n) : name{n} {}


// **************************************************************************************
// *************************************    FILE    *************************************
// **************************************************************************************


void File::display() {
    display(0);
}

void File::display(int indent) const {
    std::cout << std::string(indent, ' ') << name << "\n";
}

size_t File::getSize(){
    return size;
}

size_t File::getSize(unordered_set<const FileSystemNode*>& visited){
    return size;
}


File::File(std::string n, size_t s): FileSystemNode(n) , size{s} {}

File::File(const File& oth) : FileSystemNode(oth.name), size{oth.size} {}

File& File::operator=(const File& oth){
    if(this != &oth){
        name = oth.name;
        size = oth.size;
    }
    return *this;
}
File::File(File&& oth)noexcept : FileSystemNode(std::move(oth.name)), size{std::move(oth.size)} {
    oth.size = 0;
}

File& File::operator=(File&& oth) noexcept {
    if(this != &oth){
        name = std::move(oth.name);
        size = std::move(oth.size);
        oth.size = 0;
    }
    return *this;
}



// ****************************************************************************************
// ************************************   DIRECTORY  **************************************
// ****************************************************************************************

void Directory::display() {
    display(0);
}

void Directory::display(int indent) const {
    std::cout << std::string(indent, ' ') << name << "\n";
    for (const auto& child : children) {
        child->display(indent + 4);
    }
}

size_t Directory::getSize(){
        unordered_set<const FileSystemNode*> visited; 
        return getSize(visited);        
}  

size_t Directory::getSize(unordered_set<const FileSystemNode*>& visited){
        if(visited.find(this) != visited.end()) return 0;

        visited.insert(this);
        size_t total = 0;
        for(auto& child : children)
            total += child->getSize(visited);

        return total;
} 

Directory::Directory(std::string name) : FileSystemNode(name) {}

Directory::Directory(Directory&& oth) noexcept : FileSystemNode(std::move(oth.name)), children{std::move(oth.children)}{}

Directory& Directory::operator=(Directory&& oth) noexcept {
    if (this != &oth) { 
        name = std::move(oth.name);            
        children = std::move(oth.children);    
    }
    return *this;
}

void Directory::addChild(std::unique_ptr<FileSystemNode>&& child){
        children.push_back(std::move(child));
}