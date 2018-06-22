// Лысенко Никита 2.8
// 6. Алгоритм Прима, списки смежных вершин.
// Алгоритм Прима — алгоритм поиска минимального остовного дерева в связном графе.

#include "Prim.h"

int main(int argc, const char * argv[])
{
    vector<vector<pair<int, int>>> graph = test_graph2();
    
    print(graph);
    
    algorithm_prima(graph, 7);
}
