// pair is used to store data in key value pair
// the syntax for pair declaratiion is pair<typ1,type2>variablename;
// the first element of the pair is accesed using first and the second element is accessed using second.
//<pair<int,int>a;
#include <iostream>
using namespace std;

int main()
{
    pair<int, int> a;
    a.first = 10;
    a.second = 20;
    cout << a.first << " " << a.second << endl;
}

// pair<int,int>a(10,20);
// pair<int,int>a-{10,20};
// pair<int,int>a=makepair(10,20);
// pair can also be used to store different data types in the same pair.
// pair<int,string>a(10,"abc");
// nested pair(pair ke andar pair)
// pair<int,pair<string,string>>student(1,{"abc","def"});