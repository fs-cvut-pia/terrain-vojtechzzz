#ifndef LOD_H
#define LOD_H

#include "Path.h"
#include "TerrainMap.h"
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <set>

// Abstract class which needs to be extended to contain the actual path finding algorithm

class Lod : public Path {

public:
    Lod(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
    virtual bool find();     // Implement this method to find the route and save it in vector<Point> path

private:

};





#endif // LOD_H_INCLUDED
