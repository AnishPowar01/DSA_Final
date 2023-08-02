#include<bits/stdc++.h>
#include"bird.h"
using namespace std;

void birdDoesSomething(Bird *&bird)
{
    bird->eat();
    bird->fly();
    bird->eat();

    bird->fly();

}
int main()
{
    // Bird*bird = new sparrow();
    // birdDoesSomething(bird);

    Bird*bird = new eagle();
    birdDoesSomething(bird);
    return 0;
}