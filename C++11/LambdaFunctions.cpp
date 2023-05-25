
#include <iostream>
#include <vector>
int main()
{

    [] { cout << "Hello lambda";} (); //automatic call

    auto p = [] {cout << "Goodbye lambda";}
    p();

    //add params
    auto r = [] (int a, int b) {cout << a + b << endl;}
    r(1,2);

    //lambdas ret val

    auto q = [](int a, int b) {return a + b;} //implict type of ret val

    int x = q(1,2);

    //set explicit return type

    auto s = [](int a, int b) -> int {return a + b;}

    x = s(1,2);



    //sort vector
    vector<int> v {1,2,5,8,4,2,3,9,56,41,20};
    sort(v.begin(), v.end(), [] (int a, int b) -> bool {return a < b;});

    //captures, access to outer scope

    int x = 4, y = 5;
    auto t = [x, &y]
    {   
        y++;
        return x + y;
    }
    t();
}