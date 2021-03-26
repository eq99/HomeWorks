// 2-28
// 实现一个简单的菜单程序：
// 运行时显示： Menu: A(dd) D(elete) S(ort) Q(uit), Select one:
// 提示用户输入：
// 输入 A 时输出：数据已增加
// 输入 D 时输出：数据已删除
// 输入 S 时输出：数据已排序
// 输入 Q 时输出：程序结束
// (1) 用 if...else, continue, break 实现
// (2) 用 switch 实现


#include<iostream>

using namespace std;

void menu1(){
    char option = 'A';
    cout<<"Menu: A(dd) D(elete) S(ort) Q(uit), Select one:"<<endl;
    while(1){
        cin>>option;
        if(option == 'A'){
            cout<<"数据已增加"<<endl;
            continue;
        }

        if(option == 'D'){
            cout<<"数据已删除"<<endl;
            continue;
        }

        if(option == 'S'){
            cout<<"数据已排序"<<endl;
            continue;
        }

        if(option == 'Q'){
            break;
        }
    }
    
}

void menu2(){
    char option = 'A';
    cout<<"Menu: A(dd) D(elete) S(ort) Q(uit), Select one:"<<endl;
    while(1){
        cin>>option;
        switch (option){
            case 'A':
                cout<<"数据已增加"<<endl;
                break;
            case 'D':
                cout<<"数据已删除"<<endl;
                break;
            case 'S':
                cout<<"数据已排序"<<endl;
                break;
        }
        if (option == 'Q') break;
    }
}

int main(){
    // menu1();
    menu2();
}