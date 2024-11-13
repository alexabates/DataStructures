#include <deque>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution{
    public:
        bool isPalindrome(string s){
            deque<char> charDeque;

            //clean the string and push characters to deque
            for(char c : s){
                if(isalnum(c)){
                    charDeque.push_back(tolower(c));
                }
            }

            //compare characters from both ends
            while(charDeque.size() > 1){
                if(charDeque.front() != charDeque.back()){
                    return false;
                }
                charDeque.pop_front();
                charDeque.pop_back();
            }
            return true;
        }
};

int main(){
    Solution solution;

    cout << boolalpha;

    //test cases
    cout << "A man, a plan, a canal: Panama : " << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << "race a car : " << solution.isPalindrome("race a car") << endl;
    cout << "\" \" : " << solution.isPalindrome(" ") << endl;
    cout << "Madam, I'm Adam : " << solution.isPalindrome("Madam, I'm Adam") << endl;

    return 0;
}