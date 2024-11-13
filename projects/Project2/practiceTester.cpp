// FileSystemTester.cpp
#include "FileSystem.hpp"
#include <cassert>
#include <iostream>
#include <sstream>

class FileSystemTester {
private:
    int totalScore = 0;
    int totalTests = 0;
    int passedTests = 0;
    std::stringstream testOutput;

    void logTest(const std::string& testName, bool passed, int points) {
        totalTests++;
        if (passed) {
            passedTests++;
            totalScore += points;
            testOutput << "✓ " << testName << " [+" << points << " points]\n";
        } else {
            testOutput << "✗ " << testName << " [+0/" << points << " points]\n";
        }
    }

    bool testMkdir(FileSystem& fs, int points = 10) {
    bool success = true;
    try {
        std::cout << "Creating test directory...\n";
        fs.mkdir("test_dir");

        std::string result = fs.ls();
        if (result.find("test_dir/") == std::string::npos) {
            std::cout << "Failed to find test_dir in ls output.\n";
            success = false;
        }

        std::cout << "Navigating to test directory...\n";
        fs.cd("test_dir");
        std::string pwd_result = fs.pwd();
        if (pwd_result != "/test_dir/") {
            std::cout << "Expected /test_dir/, got: " << pwd_result << "\n";
            success = false;
        }
        // Continue adding checks similarly...
        } catch (const std::exception& e) {
            std::cout << "Exception in mkdir test: " << e.what() << "\n";
            success = false;
        }
        logTest("mkdir functionality", success, points);
        return success;
    }

    bool testTouch(FileSystem& fs, int points = 10) {
        bool success = true;
        try {
            fs.touch("test.txt");
            std::string result = fs.ls();
            if (result.find("test.txt") == std::string::npos) {
                success = false;
            }

            fs.mkdir("docs");
            fs.cd("docs");
            fs.touch("doc1.txt");
            fs.touch("doc2.txt");
            result = fs.ls();
            if (result.find("doc1.txt") == std::string::npos || 
                result.find("doc2.txt") == std::string::npos) {
                success = false;
            }
            fs.cd("..");

            try {
                fs.touch("test.txt");
                success = false;
            } catch (const std::runtime_error&) {
                // Expected behavior
            }
        } catch (const std::exception& e) {
            success = false;
        }
        logTest("touch functionality", success, points);
        return success;
    }

    bool testCd(FileSystem& fs, int points = 20) {
    bool success = true;
    try {
        std::cout << "Creating and navigating into dir1...\n";
        fs.mkdir("dir1");
        fs.cd("dir1");

        std::cout << "Creating and navigating into dir2 inside dir1...\n";
        fs.mkdir("dir2");
        fs.cd("dir2");

        std::string pwd_result = fs.pwd();
        if (pwd_result != "/dir1/dir2/") {
            std::cout << "Error: Expected /dir1/dir2/, got: " << pwd_result << "\n";
            success = false;
        }

        std::cout << "Navigating up one level to dir1...\n";
        fs.cd("..");
        pwd_result = fs.pwd();
        if (pwd_result != "/dir1/") {
            std::cout << "Error: Expected /dir1/, got: " << pwd_result << "\n";
            success = false;
        }

        std::cout << "Navigating back to root directory...\n";
        fs.cd("/");
        pwd_result = fs.pwd();
        if (pwd_result != "/") {
            std::cout << "Error: Expected /, got: " << pwd_result << "\n";
            success = false;
        }

        // Testing navigation to nonexistent directory
        std::cout << "Attempting to navigate to nonexistent directory...\n";
        try {
            fs.cd("nonexistent");
            std::cout << "Error: Navigated to a nonexistent directory (unexpected behavior).\n";
            success = false;
        } catch (const std::runtime_error&) {
            std::cout << "Caught expected exception for nonexistent directory.\n";
        }

        // Trying to cd into a file (should fail)
        std::cout << "Creating a file and trying to navigate into it...\n";
        fs.touch("file.txt");
        try {
            fs.cd("file.txt");
            std::cout << "Error: Navigated into a file (unexpected behavior).\n";
            success = false;
        } catch (const std::runtime_error&) {
            std::cout << "Caught expected exception when trying to cd into a file.\n";
        }
        } catch (const std::exception& e) {
            std::cout << "Exception in cd test: " << e.what() << "\n";
            success = false;
        }
        logTest("cd functionality", success, points);
        return success;
    }

    bool testLs(FileSystem& fs, int points = 10) {
        bool success = true;
        try {
            fs.mkdir("test_ls");
            fs.cd("test_ls");
            fs.touch("file1.txt");
            fs.touch("file2.txt");
            fs.mkdir("subdir");

            std::string result = fs.ls();
            if (result.find("file1.txt") == std::string::npos ||
                result.find("file2.txt") == std::string::npos ||
                result.find("subdir/") == std::string::npos) {
                success = false;
            }
            fs.cd("/");
        } catch (const std::exception& e) {
            success = false;
        }
        logTest("ls functionality", success, points);
        return success;
    }

    bool testPwd(FileSystem& fs, int points = 15) {
        bool success = true;
        try {
            std::cout << "Checking initial pwd at root...\n";
            std::string pwd_result = fs.pwd();
            if (pwd_result != "/") {
                std::cout << "Error: Expected /, got: " << pwd_result << "\n";
                success = false;
            }

            std::cout << "Creating and navigating into level1 directory...\n";
            fs.mkdir("level1");
            fs.cd("level1");

            pwd_result = fs.pwd();
            if (pwd_result != "/level1/") {
                std::cout << "Error: Expected /level1/, got: " << pwd_result << "\n";
                success = false;
            }

            std::cout << "Creating and navigating into level2 directory inside level1...\n";
            fs.mkdir("level2");
            fs.cd("level2");

            pwd_result = fs.pwd();
            if (pwd_result != "/level1/level2/") {
                std::cout << "Error: Expected /level1/level2/, got: " << pwd_result << "\n";
                success = false;
            }

            std::cout << "Navigating back to root directory...\n";
            fs.cd("/");
            pwd_result = fs.pwd();
            if (pwd_result != "/") {
                std::cout << "Error: Expected /, got: " << pwd_result << "\n";
                success = false;
            }
        } catch (const std::exception& e) {
            std::cout << "Exception in pwd test: " << e.what() << "\n";
            success = false;
        }
        logTest("pwd functionality", success, points);
        return success;
        }

    bool testRm(FileSystem& fs, int points = 25) {
        bool success = true;
        try {
            fs.touch("rm_test_file.txt");
            fs.rm("rm_test_file.txt");
            std::string result = fs.ls();
            if (result.find("rm_test_file.txt") != std::string::npos) {
                success = false;
            }

            fs.mkdir("rm_test_dir");
            fs.rm("rm_test_dir");
            result = fs.ls();
            if (result.find("rm_test_dir") != std::string::npos) {
                success = false;
            }

            try {
                fs.rm("nonexistent");
                success = false;
            } catch (const std::runtime_error&) {
                // Expected behavior
            }
        } catch (const std::exception& e) {
            success = false;
        }
        logTest("rm functionality", success, points);
        return success;
    }

public:
    void runTests() {
        std::cout << "Starting FileSystem Tests...\n\n";
        
        FileSystem fs;
        
        testMkdir(fs);    // 10 points
        testTouch(fs);    // 10 points
        testCd(fs);       // 20 points
        testLs(fs);       // 10 points
        testPwd(fs);      // 15 points
        testRm(fs);       // 25 points
        
        std::cout << testOutput.str() << "\n";
        std::cout << "Test Summary:\n";
        std::cout << "============\n";
        std::cout << "Total Tests: " << totalTests << "\n";
        std::cout << "Passed Tests: " << passedTests << "\n";
        std::cout << "Total Score: " << totalScore << "/90 points\n";
    }
};

int main() {
    FileSystemTester tester;
    tester.runTests();
    return 0;
}