#include <iostream>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

        void setMatA();
        void setMatB();
        void solve();
        void setRowCol();
        bool pivotZero(int row);
        void normalize(int row);
        void exchangeRow(int row);
        void makeBelowPivotZero(int row);
        void substitute();

        void display();
        
        double a[5][5],x[5];
        int rowA,colA;


void setRowCol()
{
    cout << "Enter row of Matrix A: ";
    cin >> rowA;
    cout << "Enter column of Matrix A: ";
    cin >> colA;
}
void setMatA()
{
    cout << "For Matrix A : " << endl;
    for(int i =  0; i < rowA; i++ )
    {
        for(int j = 0; j < colA; j++)
        {

            cout << "Enter A[" << i << "]" << "[" << j << "] : " ;
            cin >> a[i][j];
        }
    }
}
void setMatB()
{
    cout << "For Matrix B: " << endl;
    for(int i =  0; i < rowA; i++ )
    {

            cout << "Enter B[" << i << "]" << "[" << 0 << "] : " ;
            cin >> a[i][colA];
    }
}
void solve()
{
    for(int i = 0; i < rowA; i++)
    {
        if(!pivotZero(i)) 
        {
            normalize(i);
        }
        else
        {
            exchangeRow(i);
            normalize(i);
        }
        makeBelowPivotZero(i);
    }
    substitute();
}
void substitute()
{
    x[rowA-1] = a[rowA-1][colA];


    for(int i = rowA-2; i>=0 ;i--)
    {
        double s = 0;
        for(int j = i+1; j < colA; j++)
        {
            s+= a[i][j] * x[j];
        }
        x[i] = a[i][colA] - s;
    }
    cout << endl << "The Required values are:\n";
    for(int i = 0; i < rowA;i++)
    cout << "X["<<i<<"]: "<< x[i] << endl;

}
bool pivotZero(int row)
{
    if(a[row][row] == 0)
    {
        return true;
    }
    else
        return false;
}

void exchangeRow(int row)
{
    int k = row+1;
    int great = row+1;
    while (k<rowA)
    {
        if(a[great][row]<a[k][row])
            great  = k;
        k++;
    }
    cout << great << endl;

    for (int j = 0; j < colA+1; j++)
    {
        double temp;
        temp = a[row][j];
        a[row][j] = a[great][j];
        a[great][j] = temp;
    }
    display();
}
void normalize(int row)
{
    double normal = a[row][row];
    for(int j = 0; j < colA+1; j++)
    {
        a[row][j] /= normal;
    }
    display();
}
void makeBelowPivotZero(int row)
{
    for(int i = row+1; i < rowA; i++)
    {
        double zeroFactor = a[i][row];
        for(int j = 0; j < colA+1; j++)
        {
            a[i][j] -= zeroFactor*a[row][j];
        }
        display();
    }

}

void display()
{
    cout << setprecision(4) << endl;
    for(int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA+1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

 cout << endl << endl;
}

int main()
{
    setRowCol();
    setMatA();
    setMatB();
    solve();
    getch();
    return 0;
}
