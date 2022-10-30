#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_

struct fvec3d{
    float x; float y; float z;
};
struct Line{
    fvec3d a; fvec3d b;
};
struct fray3d{
   fvec3d pos; fvec3d dir; 
};
struct Box{
    fvec3d pos; float w; float l; float h;
};

#endif