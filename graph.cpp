#include<bits/stdc++.h>
using namespace std;

int power_matrix[20][20][20];
int all_length_matrix[20][20];
int path_matrix[20][20];
int is_stringly_connected = 1;

int main()
{
    int n;
    cout << "Enetr the number of nodes: ";
    cin >> n;
    int matrix[n][n];
    cout << "Enter the matrix: " << endl;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "The adjacency matrix is:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << i << "--> ";
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j])
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(i == 0)
                {
                    for(int p = 0; p < n; p++)
                    {
                        for(int q = 0; q < n; q++)
                        {
                            power_matrix[i][p][q] = matrix[p][q];
                        }
                    }
                }
                else
                {
                    for(int l = 0; l < n; l++)
                    {
                        power_matrix[i][j][k] += power_matrix[i-1][j][l] * matrix[l][k];
                    }
                }
            }
        }

        for(int p = 0; p < n; p++)
        {
            for(int q = 0; q < n; q++)
            {
                if(power_matrix[i][p][q])
                {
                    cout<<power_matrix[i][p][q] << " path(s) between " << p << " and " << q << " of length " << i + 1 << endl;
                    all_length_matrix[p][q] += power_matrix[i][p][q];
                }
                else
                {
                    cout << "There is no path between " << p << " and " << q << " of length " << i + 1 << endl;
                }
            }
        }
        cout << endl << endl;
    }

    cout << endl << endl;

    cout << "Total length matrix" << endl;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << all_length_matrix[i][j] << " ";
            if(all_length_matrix[i][j])
            {
                path_matrix[i][j] = 1;
            }

            if(all_length_matrix[i][j] == 0 && is_stringly_connected)
            {
                is_stringly_connected = 0;
            }
        }
        cout << endl;
    }

    cout << endl << endl;

    cout << "Path matrix is:" << endl;
    for(int i =0; i <  n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << path_matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    if(is_stringly_connected)
    {
        cout << "The graph is strongly connected.";
    }
    else
    {
        cout<< "The graph is no stringly connected.";
    }

    return 0;


}