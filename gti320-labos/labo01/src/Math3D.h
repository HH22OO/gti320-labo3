#pragma once

/**
 * @file Math3D.h
 *
 * @brief Fonctions pour l'intinialisation et la manipulation de matrices de
 * rotation, des matrices de transformations en coordonnées homogènes et les
 * vecteurs 3D.
 *
 * Nom: Nicolas Riopel
 * Code permanent : RION28079901
 * Email : nicolas.riopel.1@ens.etsmtl.ca
 *
 */

#include "Matrix.h"
#include "Vector.h"
#include "Operators.h"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <math.h>


namespace gti320 {

    // Deux types de vecteurs 3D considérés ici
    typedef Vector<double, 3> Vector3d;
    typedef Vector<float, 3> Vector3f;

    // Dans le cadre de ce projet, nous considérons seulement deux
    // transformations géométriques :
    //
    //  - les rotations
    //  - les translations
    //
    // Deux types de matrices en coordonnées homogèes :
    typedef Matrix<double, 4, 4, ColumnStorage> Matrix4d;
    typedef Matrix<float, 4, 4, ColumnStorage> Matrix4f;
    // 
    // Deux types de matrices pour les rotations
    typedef Matrix<double, 3, 3, ColumnStorage> Matrix3d;
    typedef Matrix<float, 3, 3, ColumnStorage> Matrix3f;


    /**
     * Calcul de la matrice inverse, SPÉCIALISÉ pour le cas d'une matrice de
     * transformation rigide en coordonnées homogènes.
     *
     * (vous pouvez supposer qu'il s'agit d'une matrice de transformation
     * rigide en coordonnées homogènes)
     */
    template<>
    inline Matrix4d Matrix4d::inverse() const
    {
        // TODO : implémenter
        
        // Creation de la matrice R et Vector T
        Matrix3d R;
        Vector3d T;
        for (int i = 0; i < R.rows(); i++) {
            for (int j = 0; j < (*this).cols(); j++) {
                // limite de R
                if (j != R.cols()) {
                    R(i, j) = (*this)(i, j);
                }
                // limite de T
                else {
                    T(i) = (*this)(i, j);
                }
            }
        }
        // Inverse de R
        Matrix3d Rinv;

        // DANS LE CAS OU MON CODE N'AURAIT PAS L'ERREUR C2908
        // voici l'implémentation qu'aurait cette fonction
        
        // Décommenter la ligne suivante 
        // Rinv = R.inverse();
        // Commmenter le bloc suivant : 
        for (int i = 0; i < R.cols(); i++)
        {
            for (int j = 0; j < R.rows(); j++)
            {
                Rinv(i, j) = R(j, i); // transpose
            }
        }
        // FIN du bloc a commenter 
        

        // -Rt
        Matrix3d Rinvopp = -1.0 * Rinv;

        // Inverse de T 
        Vector3d Tinv = (-1.0 * Rinv) * T;

        // Insertion de l'inverse de R dans Resultat
        Matrix4d Res;
        Res.setIdentity();
        Res.block(0, 0, 3, 3) = Rinv;
        Res(0, 3) = Tinv(0);
        Res(1, 3) = Tinv(1);
        Res(2, 3) = Tinv(2);

        return Res;
    }

    /**
     * Calcul de la matrice inverse, SPÉCIALISÉ pour le cas d'une matrice de rotation.
     *
     * (vous pouvez supposer qu'il s'agit d'une matrice de rotation)
     */
    template<>
    inline Matrix3d Matrix3d::inverse() const
    {
        // TODO : 
        
        // Creation Rinv
        Matrix3d Rinv;

        // On parcours Rinv col x row
        for (int i = 0; i < (*this).cols(); i++)
        {
            for (int j = 0; j < (*this).rows(); j++)
            {
                Rinv(i, j) = (*this)(j, i); // transpose
            }
        }
        
        return Rinv;
    }


    /**
     * Multiplication d'une matrice 4x4 avec un vecteur 3D où la matrice
     * représente une transformation en coordonnées homogène.
     */
    template <typename _Scalar>
    Vector<_Scalar, 3> operator*(const Matrix<_Scalar, 4, 4, ColumnStorage>& A, const Vector<_Scalar, 3>& v)
    {
        // TODO : implémenter

        // Création de la matrice 3d + instanciation
        Matrix<_Scalar, 3, 3, ColumnStorage> R;
        R = A.block(0, 0, 3, 3);

        // Création du vecteur de translation + instanciation
        Vector<_Scalar, 3> T(3);
        for (int i = 0; i < T.rows(); i++) {
            T(i) = A(i, 3);
        }

        // Création du vecteur résultant
        Vector<_Scalar, 3> res = R * v;

        return res + T;
    }


    /**
     * Initialise et retourne la matrice de rotation définie par les angles
     * d'Euler XYZ exprimés en radians.
     *
     * La matrice doit correspondre au produit : Rz*Ry*Rx.
     */
    template<typename _Scalar>
    static Matrix<_Scalar, 3, 3> makeRotation(_Scalar x, _Scalar y, _Scalar z)
    {
        // TODO : implémenter

        // rotation 1:
        Matrix<_Scalar, 3, 3> Rx;
        Rx.setIdentity();
        Rx(1, 1) = cos(x);
        Rx(1, 2) = -sin(x);
        Rx(2, 1) = sin(x);
        Rx(2, 2) = cos(x);

        // rotation 2:
        Matrix<_Scalar, 3, 3> Ry;
        Ry.setIdentity();
        Ry(0, 0) = cos(y);
        Ry(0, 2) = sin(y);
        Ry(2, 0) = -sin(y);
        Ry(2, 2) = cos(y);

        // rotation 2:
        Matrix<_Scalar, 3, 3> Rz;
        Rz.setIdentity();
        Rz(0, 0) = cos(z);
        Rz(0, 1) = -sin(z);
        Rz(1, 0) = sin(z);
        Rz(1, 1) = cos(z);


        return Rz * (Ry * Rx);
    }

}
