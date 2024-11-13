#include <string>
#include <vector>
#include <sstream>
using namespace std;

class FileSystemNode{
    public:
        string name;
        bool isDirectory;
        vector<FileSystemNode*> children;
        FileSystemNode* parent;

        FileSystemNode(string name, bool isDir) : name(name), isDirectory(isDir), parent(nullptr) {}

        ~FileSystemNode(){
            for(auto child : children){
                delete child;
            }
        }
};

class FileSystem{
    private:
        FileSystemNode* root;
        FileSystemNode* currentDirectory;

        FileSystemNode* FileSystem::findNode(FileSystemNode* startNode, const std::string& name) {
            if (startNode->name == name) {
                return startNode;
            }
            for (auto child : startNode->children) {
                FileSystemNode* found = findNode(child, name);
                if (found) {
                    return found;
                }
            }
            return nullptr;
        }

    public:
        FileSystem();
        ~FileSystem();

        void mkdir(const string& name){
            //check if the directory already exists
            for(auto child : currentDirectory->children){
                if(child->name == name && child->isDirectory){
                    throw std::runtime_error("Directory already exists");
                }
            }

            //create new node
            FileSystemNode* node = new FileSystemNode(name, true);

            //update parent/child links
            node->parent = currentDirectory;
            currentDirectory->children.push_back(node);
        }
};