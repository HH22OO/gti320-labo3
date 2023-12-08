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
    Matrix3f rot = makeRotation(eulerAng(0), eulerAng(1), eulerAng(2));    

    
    // TODO Create a local 4D rigid transformation matrix from the 
    //      3D rotation matrix and translation of the current link.
    Matrix4f transRig;
    transRig.setIdentity();
    transRig.block(0, 0, 3, 3) = rot;
    transRig(0, 3) = trans(0);
    transRig(1, 3) = trans(1);
    transRig(2, 3) = trans(2);

    // TODO Update the global transformation for the link using the
    //      parent's rigid transformation matrix and the local transformation.
    //      Hint : the parent matrix should be post-multiplied.
    //      Hint : the root does not have a parent. You must consider this case.
    //  NOUVELLE FONCTION
    if ((*this).isRoot()) {
        M = transRig;
    }
    else {
        M = (*parent).M * transRig;
    }

    // TODO Update the transformation of child links
    // by recursion.
    int nbEnfants = (*this).enfants.size();
    for (int i = 0; i < nbEnfants; i++) {
        (*this).enfants[i]->forward();
    }

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
    
    // nb de links 
    int nbLinks = links.size();

    // ajustement de la taille de theta
    _theta.resize(nbLinks * 3);

    // Pour chaque links dans l'armature
    for (int i = 0; i < nbLinks; i++) {
        // ref au link
        Link* linkRef = links[i];
        _theta(i * 3) = (*linkRef).eulerAng(0);
        _theta(i * 3 + 1) = (*linkRef).eulerAng(1);
        _theta(i * 3 + 2) = (*linkRef).eulerAng(2);
    }
}

void Armature::unpack(const Vector<float, Dynamic>& _theta)
{
    const int numLinks = links.size();
    assert(_theta.size() == 3 * numLinks);

    // TODO Extract the Euler angles contained in the 
    //      dense vector @a theta and update the angles
    //      for each link in the armature.
    // 

    // Pour chaque links dans l'armature
    for (int i = 0; i < links.size(); i++) {
        // ref au link
        Link* linkRef = links[i];
        (*linkRef).eulerAng(0) = _theta(i * 3);
        (*linkRef).eulerAng(1) = _theta(i * 3 + 1);
        (*linkRef).eulerAng(2) = _theta(i * 3 + 2);
    }
}
