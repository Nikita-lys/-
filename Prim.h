#ifndef Prim_h
#define Prim_h

#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;

const int INF = 1000000000; // значение "бесконечность"

// Тестовый граф с 4мя вершинами
vector<vector<pair<int, int>>> test_graph1()
{
    vector<vector<pair<int, int>>> res(4);
    
    res[0].push_back(make_pair(1,6));
    res[0].push_back(make_pair(2,8));
    res[0].push_back(make_pair(3,7));
    
    res[1].push_back(make_pair(0,6));
    res[1].push_back(make_pair(2,10));
    
    res[2].push_back(make_pair(0,8));
    res[2].push_back(make_pair(1,10));
    res[2].push_back(make_pair(3,13));
    
    res[3].push_back(make_pair(0,7));
    res[3].push_back(make_pair(2,13));
    
    return res;
}

// Тестовый граф с 7ю вершинами (Википедиа: https://ru.wikipedia.org/wiki/Алгоритм_Прима)
vector<vector<pair<int, int>>> test_graph2()
{
    vector<vector<pair<int, int>>> res(7);
    
    res[0].push_back(make_pair(1,7));
    res[0].push_back(make_pair(3,5));
    
    res[1].push_back(make_pair(0,7));
    res[1].push_back(make_pair(2,8));
    res[1].push_back(make_pair(3,9));
    res[1].push_back(make_pair(4,7));
    
    res[2].push_back(make_pair(1,8));
    res[2].push_back(make_pair(4,5));
    
    res[3].push_back(make_pair(0,5));
    res[3].push_back(make_pair(1,9));
    res[3].push_back(make_pair(4,15));
    res[3].push_back(make_pair(5,6));
    
    res[4].push_back(make_pair(1,7));
    res[4].push_back(make_pair(2,5));
    res[4].push_back(make_pair(3,15));
    res[4].push_back(make_pair(5,8));
    res[4].push_back(make_pair(6,9));
                     
    res[5].push_back(make_pair(3,6));
    res[5].push_back(make_pair(4,8));
    res[5].push_back(make_pair(6,11));
    
    res[6].push_back(make_pair(4,9));
    res[6].push_back(make_pair(5,11));
    
    return res;
}

void algorithm_prima(vector<vector<pair<int, int>>> graph , int n)
{
    int weigh = 0;
    vector<int> min_e (n, INF), sel_e (n, -1);
    std::vector<bool> used(n + 1, false);
    min_e[0] = 0;
    set<pair<int,int>> q; // список всех рёбер, исходящих из вершины i
    q.insert (make_pair (0, 0));
    
    for (size_t i = 0; i < n; ++i)
    {
        if (q.empty())
        {
            cout << "No MST!";
            exit(0);
        }
        int v = q.begin()->second; // вершина с наименьшим весом
        int wi= q.begin()->first; // её вес
        weigh += q.begin()->first;
        q.erase (q.begin());
        used[v] = true;
        
        if (sel_e[v] != -1)
        {
            cout << sel_e[v] + 1 << " -> " << v + 1 << ":" << wi << endl;
        }
        for (size_t j = 0; j < graph[v].size(); ++j)
        {
            int to = graph[v][j].first,
            cost = graph[v][j].second;
            if (cost < min_e[to] && !used[to])
            {
                q.erase (make_pair (min_e[to], to));
                min_e[to] = cost;
                sel_e[to] = v;
                q.insert (make_pair (min_e[to], to));
            }
        }
    }
    cout << endl;
    cout << "Мин вес: " << weigh << endl;
}

// Печать списка смежности.
void print(vector<vector<pair<int, int>>> graph)
{
    int i = 1;
    for (auto x : graph)
    {
        cout << i << ": ";
        for (auto xx : x)
            cout << xx.first + 1 << ";" << xx.second << " ";
        cout << endl;
        ++i;
    }
    cout << endl;
}

#endif /* Prim_h */
