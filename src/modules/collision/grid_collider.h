#pragma once
#include "box_collider.h"
#include "../../component.h"

typedef struct
{
    int entity_id;
    unsigned int grid_width;
    unsigned int grid_height;
    unsigned int cell_width;
    unsigned int cell_height;
    int *collision_ids;
} Grid_Collider;