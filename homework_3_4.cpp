// 找出 11~999 之间所有的回文数 m 使得 m m*m, m*m*m 均为回文数
// 回文数是各位数字左右对称的数例如：
// 11, 11*11 =121, 11*11*11 =1331
#include<iostream>
#include<vector>

using namespace std;

class Palindrome{

public:
    void display(){
        for(auto palindrome = _palindrome.begin(); palindrome!=_palindrome.end(); ++palindrome){
            cout<<(*palindrome)<<" ";
        }
        cout<<endl;
    }

    Palindrome(int low, int high){
        for(int i=low; i<high; ++i){
            if (_is_palindrome(i) && _is_palindrome(i*i) && _is_palindrome(i*i*i)){
                _palindrome.push_back(i);
            }
        }
    }

private:
    vector<int> _palindrome;

    bool _is_palindrome(long int num){
        int digits[9];
        long int reverse_num=0;
        long int backup_num = num;

        // init digits with -1
        for(int i=0; i<9; ++i){
            digits[i] = -1;
        }

        for(int i=0; num != 0; num = num / 10){
            digits[i] = num % 10;
            ++i;
        }

        for(int i=0; digits[i]!=-1; ++i){
            reverse_num = 10 * reverse_num + digits[i];
        }
        return reverse_num == backup_num;

    }
};

int main(){
    Palindrome p = Palindrome(11, 999);
    p.display();
}