#pragma once
#include <vector>
#include <memory>
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class FileSystemNode{
public:
    std::string name;
    FileSystemNode() = default;
    FileSystemNode(string n);
    virtual size_t getSize() = 0;
    virtual size_t getSize(unordered_set<const FileSystemNode*>&) = 0;
    virtual void display() = 0;
    virtual void display(int) const = 0;
    virtual ~FileSystemNode() noexcept = default;
};

class File : public FileSystemNode {
private:
    size_t size;

    virtual size_t getSize(unordered_set<const FileSystemNode*>&) override;
    void display(int) const override;

public:
    File() = delete;
    File(std::string,size_t); 
    File(const File&);
    File& operator=(const File&);
    File(File&&) noexcept;
    File& operator=(File&&) noexcept;

    ~File() noexcept override = default;

    void display() override;
    virtual size_t getSize() override;
};



class Directory : public FileSystemNode{
private:
    vector<unique_ptr<FileSystemNode>> children;

    void display(int indent) const override;
    size_t getSize(unordered_set<const FileSystemNode*>&);
    
public:
    size_t getSize() override;
    void display() override;
 
    Directory(std::string name);
    Directory(Directory&&) noexcept ;
    Directory& operator=(Directory&&) noexcept;

    Directory(const Directory&) = delete;
    ~Directory() noexcept override = default;
    Directory& operator=(const Directory&) = delete;

    void addChild(std::unique_ptr<FileSystemNode>&&);

};