#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n1, n2, f = 0; 
    int num = -1;
    int p, q;
    cin >> n1 >> n2;
    vector <pair <int, int>> link;
    vector <vector<int>> matrix;
    matrix.resize(n1);
    for (int i = 0; i < n1; i++) {
        matrix[i].resize(n1);
    }
    link.resize(n1, make_pair(0, 0));
    for (int i = 0; i < n2; i++) {
        cin >> p >> q;
        matrix[p][q] = 1;
        matrix[q][p] = 1;
        link[p].first++;
        link[q].first++;
        link[p].second = p;
        link[q].second = q;
    }
    sort(link.begin(), link.end());
    vector <int> obj;
    for (int i = n1 - 1; i > -1; i--){
        obj.push_back(link[i].second);
    }
    vector <int> color(n1, -1);
    for (int it : obj) {
        int i = it;
        vector <bool> c(n1, false);
        for (int j = 0; j < n1; j++){
            if (matrix[i][j] == 1){
                if (color[j] > -1){
                    c[color[j]] = true;
                }
            }
        }
        for (int k = 0; k < n1; k++){
            if (c[k] == false){
                color[i] = k;
                break;
            }
        }
    }
    for (int i = 0; i < n1; i++){
        if (color[i] > num){
            num = color[i];
        }
    }
    cout << num + 1;
 
}