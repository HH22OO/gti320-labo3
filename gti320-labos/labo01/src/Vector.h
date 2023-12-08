#pragma once

/**
 * @file Vector.h
 *
 * @brief Implémentation de vecteurs simples
 *
 * Nom: Nicolas Riopel  
 * Code permanent : RION28079901
 * Email : nicolas.riopel.1@ens.etsmtl.ca
 *
 */

/**
 * Ce fichier déclare et implémente la classe `Vector`.
 */

#include <cmath>
#include "MatrixBase.h"
#include <cmath>

namespace gti320 {

    /**
     * Classe vecteur générique.
     *
     * Cette classe réutilise la classe `MatrixBase` et ses spécialisations de
     * templates pour les manipulation bas niveau.
     */
    template <typename _Scalar = double, int _Rows = Dynamic>
      class Vector : public MatrixBase<_Scalar, _Rows, 1> {
      public:

        /**
         * Constructeur par défaut
         */
        Vector() : MatrixBase<_Scalar, _Rows, 1>() { }

        /**
         * Contructeur à partir d'un taille (rows).
         */
        explicit Vector(int rows) : MatrixBase<_Scalar, _Rows, 1>(rows, 1) { }

        /**
         * Constructeur de copie
         */
        Vector(const Vector& other) : MatrixBase<_Scalar, _Rows, 1>(other) { }

        /**
         * Destructeur
         */
        ~Vector() { }

        /**
         * Opérateur de copie
         */
        Vector& operator=(const Vector& other)
          {
            // TODO implémenter
            if (this == &other) {
                return *this; 
            }

            MatrixBase<_Scalar, _Rows, 1>::operator=(other);

            return *this; 
          }

        /**
         * Accesseur à une entrée du vecteur (lecture seule)
         */
        _Scalar operator()(int i) const
          {
            // TODO implémenter 
            const _Scalar& x = m_storage.data()[i];
            return x;
          }

        /**
         * Accesseur à une entrée du vecteur (lecture et écriture)
         */
        _Scalar& operator()(int i)
          {
            // TODO implémenter
            _Scalar& x = m_storage.data()[i];
            
            return x;
          }

        /**
         * Modifie le nombre de lignes du vecteur
         */
        void resize(int _rows)
          {
            MatrixBase<_Scalar, _Rows, 1>::resize(_rows, 1);
          }

        /**
         * Produit scalaire de *this et other.
         */
        inline _Scalar dot(const Vector& other) const
        {
            // TODO implémenter
            int size1 = m_storage.size();
            int size2 = other.m_storage.size();

            // check vecteur de meme tailles et taille > 0
            assert(size1 = size2);
            assert(size1 > 0);

            _Scalar result = 0;
            for (int i = 0; i < size1; i++)
            {
                result += (*this)(i) * other(i);
            }

            return result;
          }

        /**
         * Retourne la norme euclidienne du vecteur
         */
        inline _Scalar norm() const
          {
            // TODO implémenter
            int size1 = m_storage.size();
            _Scalar sommeCarres = 0;

            // check taille > 0
            assert(size1 > 0);

            for (int i = 0; i < size1; i++)
            {
                sommeCarres += (*this)(i) * (*this)(i);
            }

            return std::sqrt(sommeCarres);
          }
      };
}
