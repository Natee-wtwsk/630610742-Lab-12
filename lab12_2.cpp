#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool Position[N][M])
{
    for(int i = 0;i < 72;i++) cout << "-";
    cout << endl;

    for(int j = 0;j < 30;j++)
    {
        cout << "|";
        for(int i = 0;i < 70;i++)
        {
            if(Position[j][i] == 1)  cout << "*";
            else cout << " ";
        }
        cout << "|";
        cout << endl;
    }

    for(int i = 0;i < 72;i++) cout << "-";
    cout << endl;
}

void updateImage(bool Position[N][M],int s,int x,int y)
{
    for(int i = 0;i < 30; i++)
    {
        for(int j = 0;j < 70;j++)
        {
            if(pow(pow(i-x,2)+pow(j-y,2),0.5) <= s-1) Position[i][j] = 1;
        }
    }
}