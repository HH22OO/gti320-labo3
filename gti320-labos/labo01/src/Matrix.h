#pragma once

/**
 * @file Matrix.h
 *
 * @brief Implémentation de matrices simples.
 *
 * Nom: Nicolas Riopel
 * Code permanent : RION28079901
 * Email : nicolas.riopel.1@ens.etsmtl.ca
 *
 */

/**
 * Ce fichier déclare et implémente les classes `Matrix` et `SubMatrix`.
 */


#include "MatrixBase.h"

namespace gti320
{
  enum StorageType
    {
      ColumnStorage = 0,
      RowStorage = 1
    };

  // Déclaration avancée
  template <typename _Scalar, int _RowsAtCompile, int _ColsAtCompile, int _StorageType> 
  class SubMatrix;

  /**
   * Classe Matrix spécialisée pour un stockage par colonnes.
   *
   * Le cas d'un stockage par ligne fait l'objet d'une spécialisation de patron, le cas général
   * (défini ici) considère donc uniquement le cas d'un stockage par colonnes.
   */
  template <typename _Scalar = double, int _RowsAtCompile = Dynamic, int _ColsAtCompile = Dynamic, int _StorageType = ColumnStorage>
  class Matrix : public MatrixBase<_Scalar, _RowsAtCompile, _ColsAtCompile> {
    public:

      /**
       * Constructeur par défaut
       */
      Matrix() : MatrixBase<_Scalar, _RowsAtCompile, _ColsAtCompile>() { }

      /**
       * Constructeur de copie
       */
      Matrix(const Matrix& other) : MatrixBase<_Scalar, _RowsAtCompile, _ColsAtCompile>(other) { }

      /**
       * Constructeur avec spécification du nombre de ligne et de colonnes
       */
      explicit Matrix(int _rows, int _cols) : MatrixBase<_Scalar, _RowsAtCompile, _ColsAtCompile>(_rows, _cols) {}

      /**
       * Destructeur
       */
      ~Matrix() { }

      /**
       * Opérateur de copie à partir d'une sous-matrice.
       *
       * Exemple :
       *    Matrix<...> A(...);
       *    Matrix<...> B(...);
       *    B = A.block(i,j,m,n);
       */
      template<typename _OtherScalar, int _OtherRows, int _OtherCols, int _OtherStorage>
      Matrix& operator= (const SubMatrix<_OtherScalar, _OtherRows, _OtherCols, _OtherStorage>& submatrix)
          {
            // TODO copier les données de la sous-matrice.
            // redimensionner tout le temps
            (*this).resize(submatrix.rows(), submatrix.cols());

            // Parcourir la matrice cols x rows
            for (int j = 0; j < (*this).cols(); j++)
            {
                for (int i = 0; i < (*this).rows(); i++)
                {
                    (*this)(i, j) = submatrix(i, j); // copie
                }
            }
            return *this;
          }

      /**
       * Accesseur à une entrée de la matrice (lecture seule)
       */
      _Scalar operator()(int i, int j) const
        {
          // TODO implementer
          // position à l'intérieur de la  matrice
          assert(i < (*this).rows());
          assert(j < (*this).cols());
          assert(i >= 0 && j >= 0);

          // calcul position
          int pos = (j * (*this).rows()) + i;
          return m_storage.data()[pos];
        }

      /**
       * Accesseur à une entrée de la matrice (lecture ou écriture)
       */
      _Scalar& operator()(int i, int j)
        {
          // TODO implementer
          // position à l'intérieur de la  matrice
          assert(i < (*this).rows());
          assert(j < (*this).cols());
          assert(i >= 0 && j >= 0);

          // calcul position
          int pos = (j * (*this).rows()) + i;

          return m_storage.data()[pos];
        }

      /**
       * Crée une sous-matrice pour un block de taille (rows, cols) à partir de l'index (i,j).
       */
      SubMatrix<_Scalar, _RowsAtCompile, _ColsAtCompile, _StorageType> block(int i, int j, int rows, int cols) const
        {
          return SubMatrix<_Scalar, _RowsAtCompile, _ColsAtCompile, _StorageType>(*this, i, j, rows, cols);
        }

      /**
       * Calcule l'inverse de la matrice
       */
      Matrix inverse() const
        {
          // Do nothing.
          return *this;
        }

      /**
       * Retourne la transposée de la matrice
       */
      template<int _OtherStorage = RowStorage>
      Matrix<_Scalar, _ColsAtCompile, _RowsAtCompile, _OtherStorage> transpose() const
          {
            // TODO calcule et retourne la transposée de la matrice.
            Matrix<_Scalar, _ColsAtCompile, _RowsAtCompile, _OtherStorage>copyMatrix((*this).cols(), (*this).rows());

            // parcourir rows x cols
            for (int i = 0; i < (*this).rows(); i++)
            {
                for (int j = 0; j < (*this).cols(); j++)
                {
                    copyMatrix(j, i) = (*this)(i, j);
                }
            }
            return  copyMatrix; 
          }

      /**
       * Affecte l'identité à la matrice
       */
      inline void setIdentity()
        {
          this->setZero();

          int maxIteration = (*this).rows();

          // determine quand il est nécessaire d'arreter la boucle
          if ((*this).rows() > (*this).cols()) {
              maxIteration = (*this).cols();
          }

          for (int i = 0; i < maxIteration; i++)
          {
              (*this)(i, i) = 1;
          }
        }

    };

  /**
   * Classe Matrix spécialisée pour un stockage par lignes
   */
  template <typename _Scalar, int _RowsAtCompile, int _ColsAtCompile>
    class Matrix< _Scalar, _RowsAtCompile, _ColsAtCompile, RowStorage> : public MatrixBase<_Scalar, _RowsAtCompile, _ColsAtCompile> {

    public:
      /**
       * Constructeur par défaut
       */
      Matrix() : MatrixBase<_Scalar, _RowsAtCompile, _ColsAtCompile>() { }

      /**
       * Constructeur de copie
       */
      Matrix(const Matrix& other) : MatrixBase<_Scalar, _RowsAtCompile, _ColsAtCompile>(other) { }

      /**
       * Constructeur avec spécification du nombre de ligne et de colonnes
       */
      explicit Matrix(int rows, int cols) : MatrixBase<_Scalar, _RowsAtCompile, _ColsAtCompile>(rows, cols) { }

      /**
       * Destructeur
       */
      ~Matrix() { }

      /**
       * Opérateur de copie à partir d'une sous-matrice.
       *
       * Exemple :
       *    Matrix<...> A(...);
       *    Matrix<...> B(...);
       *    B = A.block(i,j,m,n);
       */
      template<typename _OtherScalar, int _OtherRows, int _OtherCols, int _OtherStorage>
        Matrix& operator= (const SubMatrix<_OtherScalar, _OtherRows, _OtherCols, _OtherStorage>& submatrix)
          {
            // TODO copier les données de la sous-matrice.
            //   Note : si les dimensions ne correspondent pas, la matrice doit être redimensionnée.
            (*this).resize(submatrix.rows(), submatrix.cols());

            // Parcourir rows x cols
            for (int i = 0; i < (*this).rows(); i++)
            {
                for (int j = 0; j < (*this).cols(); j++)
                {
                    (*this)(i, j) = submatrix(i, j); // copie
                }
            }

            return *this;
          }

      /**
       * Accesseur à une entrée de la matrice (lecture seule)
       */
      _Scalar operator()(int i, int j) const
        {
          // TODO implementer
          // position à l'intérieur de la  matrice
          assert(i < (*this).rows());
          assert(j < (*this).cols());
          assert(i >= 0 && j >= 0);

          // calcul position
          int pos = (i * (*this).cols()) + j;
          return m_storage.data()[pos];
        }

      /**
       * Accesseur à une entrée de la matrice (lecture ou écriture)
       */
      _Scalar& operator()(int i, int j)
        {
          // TODO implementer
          // position à l'intérieur de la  matrice
          assert(i < (*this).rows());
          assert(j < (*this).cols());
          assert(i >= 0 && j >= 0);

          // calcul position
          int pos = (i * (*this).cols()) + j;
          return m_storage.data()[pos];
        }

      /**
       * Crée une sous-matrice pour un block de taille (rows, cols) à partir de l'index (i,j).
       */
      SubMatrix<_Scalar, _RowsAtCompile, _ColsAtCompile, RowStorage> block(int i, int j, int rows, int cols) const {
          return SubMatrix<_Scalar, _RowsAtCompile, _ColsAtCompile, RowStorage>(*this, i, j, rows, cols);
      }

      /**
       * Calcule l'inverse de la matrice
       */
      Matrix inverse() const
        {
          // Do nothing.
          return *this;
        }

      /**
       * Retourne la transposée de la matrice
       */
      template<int _OtherStorage = ColumnStorage>
        Matrix<_Scalar, _ColsAtCompile, _RowsAtCompile, _OtherStorage> transpose() const
          {
            // TODO calcule et retourne la transposée de la matrice.
            // Nouvelle matrice
            Matrix<_Scalar, _ColsAtCompile, _RowsAtCompile, _OtherStorage>copyMatrix((*this).cols(), (*this).rows());

            // parcourir la matrice cols x rows
            for (int i = 0; i < (*this).cols(); i++)
            {
                for (int j = 0; j < (*this).rows(); j++)
                {
                    copyMatrix(i, j) = (*this)(j, i); // transpose
                }
            }
            return  copyMatrix;
          }

      /**
       * Affecte l'identité à la matrice
       */
      inline void setIdentity()
        {
          // TODO affecter la valeur 0.0 partour, sauf sur la diagonale principale où c'est 1.0..
          //      Votre implémentation devrait aussi fonctionner pour des matrices qui ne sont pas carrées.
          this->setZero();

          int maxIteration = (*this).rows() ;
          
          // determine quand il est nécessaire d'arreter la boucle
          if ((*this).rows() > (*this).cols()) {
              maxIteration = (*this).cols() ;
          }

          for (int i = 0; i < maxIteration; i++)
          {
              (*this)(i, i) = 1; 
          }
        }

    };

  /**
   * Classe pour accéder à une sous-matrice.
   *
   * Un sous-matrice ne copie pas les données. Au lieu de cela, elle conserve une
   * référence à la matrice originale.
   */
  template <typename _Scalar, int _RowsAtCompile, int _ColsAtCompile, int _StorageType>
  class SubMatrix
      {
    private:
      // Référence à la matrice originale
      Matrix<_Scalar, _RowsAtCompile, _ColsAtCompile, _StorageType>& m_matrix;

      // Constructeur par défaut (privé)
      SubMatrix() {}

      // (i,j) est le coin supérieur gauche de la sous-matrice
      int m_i;        // Décalage en ligne 
      int m_j;        // Décalage en colonne

      // la sous-matrice est de dimension : m_rows x m_cols
      int m_rows;     // Hauteur de la sous-matrice (nombre de lignes)
      int m_cols;     // Largeur de la sous-matrice (nombre de colonnes)

    public:

      /**
       * Constructeur à partir d'une référence en lecture seule à une matrice.
       */
      SubMatrix(const Matrix<_Scalar, _RowsAtCompile, _ColsAtCompile, _StorageType>& _matrix, int _i, int _j, int _rows, int _cols) :
          m_matrix(const_cast<Matrix<_Scalar, _RowsAtCompile, _ColsAtCompile, _StorageType>&>(_matrix)),
          m_i(_i), m_j(_j), m_rows(_rows), m_cols(_cols)
        {
        }

      /**
       * Constructeur à partir d'une référence en lecture et écriture à une matrice.
       */
      explicit SubMatrix(Matrix<_Scalar, _RowsAtCompile, _ColsAtCompile, _StorageType>& _matrix, int _i, int _j, int _rows, int _cols) :
          m_matrix(_matrix),
          m_i(_i), m_j(_j), m_rows(_rows), m_cols(_cols)
        {
        }

      /**
       * Constructeur de copie
       */
      SubMatrix(const SubMatrix& other) :
          m_matrix(other.m_matrix),
          m_i(other.m_i), m_j(other.m_j), m_rows(other.m_rows), m_cols(other.m_cols)
        {
        }

      /**
       * Destructeur
       */
      ~SubMatrix() { }

      /**
       * Opérateur de copie (à partir d'une matrice)
       *
       * Copies toutes les entrées de la matrice dans la sous-matrice.
       *
       * Note : la taille de la matrice doit correspondre à la taille de la
       * sous-matrice.
       */
      template<typename _OtherScalar, int _OtherRows, int _OtherCols, int _OtherStorage>
        SubMatrix& operator= (const Matrix<_OtherScalar, _OtherRows, _OtherCols, _OtherStorage>& matrix)
          {
            // TODO Copie les valeurs de la matrice dans la sous-matrice.
            //      Note les dimensions de la matrice doivent correspondre à celle de
            //      la sous-matrice.
            
            //  matrices de même tailles
            assert((*this).rows() == matrix.rows());
            assert((*this).cols() == matrix.cols());

            // Parcourir rows x cols
            for (int i = 0; i < (*this).rows(); i++)
            {
                for (int j = 0; j < (*this).cols(); j++)
                {
                    (*this)(i, j) = matrix(i, j); // copie
                }
            }
            return *this;
          }

      /**
       * Accesseur aux entrées de la sous-matrice (lecture seule)
       *
       * Note : il faut s'assurer que les indices respectent la taille de la
       * sous-matrice
       */
      _Scalar operator()(int i, int j) const
        {
          // TODO implementer
          // position à l'intérieur de la  matrice
          assert(i < (*this).rows());
          assert(j < (*this).cols());
          assert(i >= 0 && j >= 0);

          // Calcul de la position
          int posI = m_i + i;
          int posJ = m_j + j;
          return m_matrix(posI, posJ);
        }

      /**
       * Accesseur aux entrées de la sous-matrice (lecture et écriture)
       *
       * Note : il faut s'assurer que les indices respectent la taille de la
       * sous-matrice
       */
      _Scalar& operator()(int i, int j)
        {
          // TODO implementer
          // position à l'intérieur de la  matrice
          assert(i < (*this).rows());
          assert(j < (*this).cols());
          assert(i >= 0 && j >= 0);

          // Calculs de la position
          int posI = m_i+ i;
          int posJ= m_j + j;
          return m_matrix(posI, posJ);
        }

      /**
       * Retourne la transposée de la sous-matrice sous la forme d'une matrice.
       */
      template<typename _OtherScalar, int _OtherRows, int _OtherCols, int _OtherStorage>
        Matrix<_OtherScalar, _OtherRows, _OtherCols, _OtherStorage> transpose() const
          {
            // TODO implementer
            Matrix<_OtherScalar, _OtherRows, _OtherCols, _OtherStorage>copyMatrix((*this).cols(), (*this).rows());

            // Parcourir la matrice rows x cols
            for (int i = 0; i < (*this).rows(); i++)
            {
                for (int j = 0; j < (*this).cols(); j++)
                {
                    copyMatrix(j, i) = (*this)(i, j); // copy
                }
            }
            return  copyMatrix;
          }

      inline int rows() const { return m_rows; }
      inline int cols() const { return m_cols; }

      };

}
