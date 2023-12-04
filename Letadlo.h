#ifndef LETADLO_H
#define LETADLO_H

#include "Path.h"
#include "TerrainMap.h"
#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <set>

// Abstract class which needs to be extended to contain the actual path finding algorithm

class Letadlo : public Path {

public:
    Letadlo(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
    virtual bool find();     // Implement this method to find the route and save it in vector<Point> path

private:

};





#endif // LETADLO_H_INCLUDED
