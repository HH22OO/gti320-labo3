#include "IKSolver.h"
#include "Armature.h"
#include "SVD.h"


using namespace gti320;

namespace
{
}

IKSolver::IKSolver(Armature* _armature, Vector3f& _targetPos) : m_armature(_armature), m_targetPos(_targetPos), m_J()
{
}


float IKSolver::getError(Vector3f& dx) const
{
    // TODO Compute the error between the current end effector 
    //      position and the target position 
    dx.setZero();
    return 1e9;
}

void IKSolver::solve()
{
    const int numLinks = m_armature->links.size();
    const int dim = 3 * (numLinks);
    m_J.resize(3, dim);

    // We assume that the last link is the "end effector"
    //
    Link* endEffector = m_armature->links[numLinks - 1];

    // TODO Build the Jacobian matrix m_J.
    //      Each column corresponds to a separate 

    // TODO Compute the error between the current end effector 
    //      position and the target position by calling getError()
    // 

    // TODO Compute the change in the joint angles by solving:
    //    df/dtheta * delta_theta = delta_x
    //  where df/dtheta is the Jacobian matrix.
    //    
    //

    // TODO Perform gradient descent method with line search
    //      to move the end effector toward the target position.
    //
    //   Hint: use the Armature::unpack() and Armature::pack() functions
    //   to set and get the joint angles of the armature.
    // 
    //   Hint: whenever you change the joint angles, you must also call
    //   armature->updateKinematics() to compute the global position.
    //    

}
