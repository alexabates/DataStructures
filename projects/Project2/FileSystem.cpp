#include "FileSystem.hpp"
#include <stdexcept>
#include <sstream>

//constructor to initialize the name and directory status
FileSystemNode::FileSystemNode(std::string name, bool isDir) 
    : name(name), isDirectory(isDir), parent(nullptr) {}

//destructor
FileSystemNode::~FileSystemNode() {
    for (auto child : children) {
        delete child;
    }
}

//constructor for FileSystem to initialize the root directory
FileSystem::FileSystem() {
    root = new FileSystemNode("/", true);
    currentDirectory = root;
}

//destructor for FileSystem
FileSystem::~FileSystem() {
    delete root;
}

//create a new directory node
void FileSystem::mkdir(const std::string& name) {
    //check if the directory already exists
    for(auto child : currentDirectory->children){
        if(child->name == name && child->isDirectory){
            throw std::runtime_error("Directory already exists");
        }
    }

    //create new node
    FileSystemNode* node = new FileSystemNode(name, true);

    //set as the current directory and update parent/child links
    node->parent = currentDirectory;
    currentDirectory->children.push_back(node);
}

//create a new file in the current directory
void FileSystem::touch(const std::string& name) {
    //check if file already exists
   for(auto child : currentDirectory->children){
    if(child->name == name && !child->isDirectory){
        throw std::runtime_error("File already exists");
    }
   }

   //create new node
   FileSystemNode* node = new FileSystemNode(name, false);

   //set as the current directory and update parent/child links
   node->parent = currentDirectory;
   currentDirectory->children.push_back(node);
}

//list all items in the current directory
std::string FileSystem::ls() {
    //using stringstream
    std::stringstream ss;
    for(auto child : currentDirectory->children){
        ss << child->name;
        if(child->isDirectory){
            //add "/" for directories, not files
            ss << "/";
        }
        //add a space if file, not directory
        ss << " ";
    }

    //return formatted string
    return ss.str();
}

//change directory to the specified path
void FileSystem::cd(const std::string& path) {
    // "/" case  
    if(path == "/"){
        currentDirectory = root;
        return;
    } 
    
    //split path by '/' and navigate step by step
    FileSystemNode* targetDir = (path[0] == '/') ? root : currentDirectory;
    std::istringstream ss(path);
    std::string part;

    //process each part of the path
    while(std::getline(ss, part, '/')){
        if(part.empty() || part == "."){
            //ignore empty parts and '.' (current directory)
            continue;
        } else if(part == ".."){
            if(targetDir->parent != nullptr){
                //move up one level
                targetDir = targetDir->parent;
            }
        } else {
            //find child directory
            bool found = false;
            for(auto child : targetDir->children){
                if(child->name == part && child->isDirectory){
                    targetDir = child;
                    found = true;
                    break;
                }
            }
            if(!found){
                //throw an error if the directory is not found
                throw std::runtime_error("Directory not found");
            }
        }
    }
    //update the current directory to the target directory
    currentDirectory = targetDir;
}

//remove a file or directory from the current directory
void FileSystem::rm(const std::string& name) {
    //find the target in the current directory
    for(auto it = currentDirectory->children.begin(); it != currentDirectory->children.end(); it++){
        if((*it)->name == name){
            delete *it; //delete the node
            //remove from list
            currentDirectory->children.erase(it);
            return;
        }
    }

    //throw an error if the file or directory is not found
    throw std::runtime_error("File or directory not found");
}

//retur the full path of the current directory
std::string FileSystem::pwd() {
    //build path by traversing up to the root
    std::string path;
    FileSystemNode* node = currentDirectory;
    while(node != nullptr && node != root){
        path = "/" + node->name + path;
        node = node->parent;
    }

    //ensure signle "/" at the start for the root directory
    return (path.empty()) ? "/" : "/" + path.substr(1) + "/";
}

//recursively find a node by name, starting from the given node
FileSystemNode* FileSystem::findNode(FileSystemNode* startNode, const std::string& name) {
    //return the node if it matches the search name
    if (startNode->name == name) {
        return startNode;
    }

    //recursively search each child node
    for (auto child : startNode->children) {
        FileSystemNode* found = findNode(child, name);
        if (found) {
            return found;
        }
    }
    //return nullptr if not found
    return nullptr;
}

FileSystemNode* FileSystem::find(const std::string& name) {
    return findNode(root, name);
}
std::string FileSystem::displayTree(FileSystemNode* node, std::string indent) {
    std::stringstream ss;
    ss << indent << node->name << (node->isDirectory ? "/" : "") << "\n";
    if (node->isDirectory) {
        for (auto child : node->children) {
            ss << displayTree(child, indent + "  ");
        }
    }
    return ss.str();
}

std::string FileSystem::tree() {
    return displayTree(root, "");
}