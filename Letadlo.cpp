#include "Letadlo.h"
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>

Letadlo::Letadlo(TerrainMap& m, std::string name_in, Point start_in, Point finish_in)
   : Path(m, name_in, start_in, finish_in)
{
}

bool Letadlo::find()
{
    std::queue<Point> fronta;
    Matrix<int> prosle(map.nx, map.ny);
    Matrix<Point> cesta(map.nx, map.ny);

    fronta.push(start);
    prosle.zero();

    while (!fronta.empty())
    {
        Point aktualni = fronta.front();
        fronta.pop();

        if (aktualni == finish)
        {
            Point aa = finish;
            while (aa != start)
            {
                path.push_back(aa);
                aa = cesta(aa.x, aa.y);
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return true;
        }

        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j <= 1; ++j)
            {
                if (i == 0 && j == 0) continue;
                Point sousedni = aktualni + Point(i, j);
                if (map.validCoords(sousedni) && prosle(sousedni.x, sousedni.y) == 0)
                {
                    prosle(sousedni.x, sousedni.y) = 1;
                    cesta(sousedni.x, sousedni.y) = aktualni;
                    fronta.push(sousedni);
                }
            }
        }
    }

    return false;
}
