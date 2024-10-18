#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

//Exercice1

void countFrequencyBruteForce(const std::vector<int>& numbers) {
    for(int i = 0;i<numbers.size();i++){
        int value = 0;
        for(int y = 0;y<numbers.size();y++){
            if(numbers[i]==numbers[y]){
                value = value+1;
            }
            
        }
        cout << numbers[i] << " : " << value << "\n";
    }

}

unordered_map<int , int> countFrequencyOptimal ( const vector <int>& numbers ) {
    unordered_map<int, int> frequencyMap;
    
    for (int i = 0; i < numbers.size(); ++i) {
        frequencyMap[numbers[i]]++;
    }
    
    return frequencyMap;

}

void ex1 ( ) {
    cout << "-----------------------Exercice 1---------------------"<< "\n";
    vector <int> numbers = { 1 , 2 , 3 , 2 , 4 , 1 , 5 , 5 , 6 } ;

    // Test countFrequencyBruteForce
    cout << " Frequency ( Brute Force ) : " << endl;

    countFrequencyBruteForce ( numbers ) ;

    // Test countFrequencyOptimal
    cout << "\nFrequency ( Optimal ) : " << endl;
    unordered_map<int , int> frequencyMapOptimal = countFrequencyOptimal ( numbers ) ;
    for ( const auto& entry : frequencyMapOptimal ) {
        cout << entry.first << " : " << entry.second << " times" << endl;
    }
}

//Exercice 2


vector <int> twoSumBruteForce ( const vector <int>& nums , int target) {
    vector<int> v ={-1,-1};
    for(int i = 0;i<nums.size();i++){
        int value = 0;
        for(int y = 0;y<nums.size();y++){
            if(nums[i]+nums[y] == target){
                v[0]=i;
                v[1]=y;
                return v;
            }
            
        }
    }
    return v;

}

vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> map; 
    vector<int> v = {-1, -1}; 

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i]; 

        if (map.find(complement) != map.end()) {
            v[0] = map[complement]; 
            v[1] = i;               
            return v; 
        }
        
        map[nums[i]] = i;
    }

    return v; 
}

void ex2(){
    cout << "-----------------------Exercice 2---------------------"<< "\n";
    vector <int> nums = { 2 , 7 , 11 , 15 } ;
    int target = 9 ;
    vector <int> indicesBruteForce = twoSumBruteForce ( nums , target ) ;
    cout << " Brute Force Solution : [ "
        << indicesBruteForce[ 0 ]
        << " , "
        << indicesBruteForce [ 1 ]
        << " ] "
        << endl;

        vector <int> indicesOptimal = twoSumOptimal ( nums , target ) ;
        cout << " Optimal Solution : [ "
        << indicesOptimal[ 0 ]
        << " , "
        << indicesOptimal[ 1 ]
        << " ] "
        << endl;
}

//Exercice3

#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

bool isPalindrome_alban ( const string& input ) {
    for(int i = 0;i<input.size()/2;i++){
        if(input.at(i)!=input.at(input.size()-i-1)){
            return false;
        }
    }
    return true;
}

bool isPalindrome(const string& input) {
    queue<char> q;
    stack<char> s;

    for (char c : input) {
        if (isalnum(c)) {
            char C = tolower(c);
            q.push(C);
            s.push(C);
        }
    }

    while (!q.empty()) {
        if (q.front() != s.top()) {
            return false; 
        }
        q.pop();
        s.pop();
    }

    return true; 
}

void ex3(){
    cout << "-----------------------Exercice 3---------------------"<< "\n";
    cout << boolalpha ;
    cout << " Is ’ hallo ’ a palindrome ? "
    << isPalindrome ( " hallo " ) << endl ;
    cout << " Is ’ elle ’ a palindrome ? "
    << isPalindrome ( " elle " ) << endl ;
}

//Main

int main(){
    ex1();
    ex2();
    ex3();

    return 0;
}