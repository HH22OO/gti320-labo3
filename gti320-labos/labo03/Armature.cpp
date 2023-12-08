#include "Armature.h"

using namespace gti320;

// Constructor
//
Link::Link(Link* _parent, const Vector3f& _eulerAng, const Vector3f& _trans) :
    eulerAng(_eulerAng), trans(_trans), parent(_parent)
{
    if (parent != nullptr)
    {
        parent->enfants.push_back(this);
    }
    M.setIdentity();
}

void Link::forward()
{
    // TODO Create a rotation matrix from the Euler angles
    //      of the current link.
    
    // TODO Create a local 4D rigid transformation matrix from the 
    //      3D rotation matrix and translation of the current link.

    // TODO Update the global transformation for the link using the
    //      parent's rigid transformation matrix and the local transformation.
    //      Hint : the parent matrix should be post-multiplied.
    //      Hint : the root does not have a parent. You must consider this case.

    // TODO Update the transformation of child links
    // by recursion.

}


Armature::Armature() : links(), root(nullptr)
{

}

Armature::~Armature()
{
    for (Link* l : links)
    {
        delete l;
    }
}

void Armature::updateKinematics()
{
    assert(root != nullptr);
    root->forward();
}

void Armature::pack(Vector<float, Dynamic>& _theta)
{
    // TODO Collect the Euler angles of each link and put them
    //      into the dense vector @a theta

}

void Armature::unpack(const Vector<float, Dynamic>& _theta)
{
    const int numLinks = links.size();
    assert(_theta.size() == 3 * numLinks);

    // TODO Extract the Euler angles contained in the 
    //      dense vector @a theta and update the angles
    //      for each link in the armature.
    // 

}
