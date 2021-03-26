// 声明枚举类型 Weekday, 包括 SUNDAY 到 SATURDAY 七个元素。
// 声明 Weekday 类型变量，对其赋值。
// 声明 整型变量， 看看能否对其赋 Weekday 类型的值。

#include<iostream>

using namespace std;

int main(){
    enum Weekday {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};

    Weekday today = SUNDAY;
    cout<<"Today: "<<today<<endl;

    int tomorrow = MONDAY;

    cout<<"Tomorrow: "<<tomorrow<<endl;
}