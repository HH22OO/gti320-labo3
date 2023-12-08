#pragma once

/**
 * @file Operators.h
 *
 * @brief Opérateurs arithmétiques pour les matrices et les vecteurs.
 *
 * Nom: Nicolas Riopel  
 * Code permanent : RION28079901    
 * Email : nicolas.riopel.1@ens.etsmtl.ca
 *
 */

#include "Matrix.h"
#include "Vector.h"

/**
 * Implémentation de divers opérateurs arithmétiques pour les matrices et les vecteurs.
 */
namespace gti320 {

    /**
     * Multiplication : Matrice * Matrice (générique)
     */
    template <typename _Scalar, int RowsA, int ColsA, int StorageA, int RowsB, int ColsB, int StorageB>
      Matrix<_Scalar, RowsA, ColsB> operator*(const Matrix<_Scalar, RowsA, ColsA, StorageA>& A, const Matrix<_Scalar, RowsB, ColsB, StorageB>& B)
        {
          // TODO implémenter question : est ce que générique implique un type de storage? voir test 1

          // validation de la taille
          assert(A.cols() == B.rows());

          // init matrice M
          Matrix<_Scalar, RowsA, ColsB> M(A.rows(), B.cols());
          M.setZero();

          // Parcours matrice M row x col
          for (int i = 0; i < A.rows(); i++) {
              for (int j = 0; j < B.cols(); j++) {
                  // Pour chaque colonne de A
                  for (int k = 0; k < A.cols(); k++) {
                      M(i, j) = M(i, j) + A(i, k) * B(k, j);
                  }
              }
          }

          return M;
        }

    /**
     * Multiplication : Matrice (colonne) * Matrice (ligne)
     *
     * Spécialisation de l'opérateur de multiplication pour le cas où les matrices
     * ont un stockage à taille dynamique et où la matrice de gauche utilise un
     * stockage par colonnes et celle de droite un stockage par lignes.
     */
    template <typename _Scalar>
      Matrix<_Scalar, Dynamic, Dynamic> operator*(const Matrix<_Scalar, Dynamic, Dynamic, ColumnStorage>& A, const Matrix<_Scalar, Dynamic, Dynamic, RowStorage>& B)
        {
          // TODO implémenter Question quell est la différence entre les deux implémentation

          // validation de la taille
          assert(A.cols() == B.rows());

          // init matrice M
          Matrix<_Scalar, Dynamic, Dynamic> M(A.rows(), B.cols());
          M.setZero();

          // Parcours matrice A col x row
          for (int j = 0; j < A.cols(); j++) {
              for (int i = 0; i < A.rows(); i++) {
                  // parcours les colonnes de B
                  for (int k = 0; k < B.cols(); k++) {
                      // addition sur chaque colonne de la ligne i de la matrice M
                      M(i, k) = M(i, k) + A(i, j) * B(j, k);
                  }
              }
          }

          return M;
        }

    /**
     * Multiplication : Matrice (ligne) * Matrice (colonne)
     *
     * Spécialisation de l'opérateur de multiplication pour le cas où les matrices
     * ont un stockage à taille dynamique et où la matrice de gauche utilise un
     * stockage par lignes et celle de droite un stockage par colonnes.
     */
    template <typename _Scalar>
      Matrix<_Scalar, Dynamic, Dynamic> operator*(const Matrix<_Scalar, Dynamic, Dynamic, RowStorage>& A, const Matrix<_Scalar, Dynamic, Dynamic, ColumnStorage>& B)
        {
          // TODO : implémenter

          // validation de la taille
          assert(A.cols() == B.rows());

          // init matrice M
          Matrix<_Scalar, Dynamic, Dynamic> M(A.rows(), B.cols());
          M.setZero();

          // Parcours matrice M row x col
          for (int i = 0; i < A.rows(); i++) {
              for (int j = 0; j < B.cols(); j++) {
                  // Pour chaque colonne de A
                  for (int k = 0; k < A.cols(); k++) {
                      M(i, j) = M(i, j) + A(i, k) * B(k, j);
                  }
              }
          }

          return M;
        }


    /**
     * Addition : Matrice + Matrice (générique)
     */
    template <typename _Scalar, int Rows, int Cols, int StorageA, int StorageB>
      Matrix<_Scalar, Rows, Cols> operator+(const Matrix<_Scalar, Rows, Cols, StorageA>& A, const Matrix<_Scalar, Rows, Cols, StorageB>& B)
        {
          // TODO : implémenter

          // Validation taille matrices
          assert(A.rows() == B.rows());
          assert(A.cols() == B.cols());

          // init matrice M
          Matrix<_Scalar, Rows, Cols>M(A.rows(), A.cols());

          // Parcourir row x col
          for (int i = 0; i < A.rows(); i++) {
              for (int j = 0; j < A.cols(); j++) {
                  M(i, j) = A(i, j) + B(i, j);
              }
          }
          return M;
        }

    /**
     * Addition : Matrice (colonne) + Matrice (colonne)
     *
     * Spécialisation de l'opérateur d'addition pour le cas où les deux matrices
     * sont stockées par colonnes.
     */
    template <typename _Scalar>
      Matrix<_Scalar, Dynamic, Dynamic> operator+(const Matrix<_Scalar, Dynamic, Dynamic, ColumnStorage>& A, const Matrix<_Scalar, Dynamic, Dynamic, ColumnStorage>& B)
        {
          // TODO : implémenter

          // Validation taille matrices
          assert(A.rows() == B.rows());
          assert(A.cols() == B.cols());

          // init matrice M
          Matrix<_Scalar, Dynamic, Dynamic> M(A.rows(), A.cols());

          // Parcourir  col x row
          for (int j = 0; j < A.cols(); j++) {
              for (int i = 0; i < A.rows(); i++) {
                  M(i, j) = A(i, j) + B(i, j);
              }
          }
          return M;
        }

    /**
     * Addition : Matrice (ligne) + Matrice (ligne)
     *
     * Spécialisation de l'opérateur d'addition pour le cas où les deux matrices
     * sont stockées par lignes.
     */
    template <typename _Scalar>
      Matrix<_Scalar, Dynamic, Dynamic, RowStorage> operator+(const Matrix<_Scalar, Dynamic, Dynamic, RowStorage>& A, const Matrix<_Scalar, Dynamic, Dynamic, RowStorage>& B)
        {
          // TODO : implémenter

          // Validation taille matrices
          assert(A.rows() == B.rows());
          assert(A.cols() == B.cols());

          // init matrice M
          Matrix<_Scalar, Dynamic, Dynamic, RowStorage> M(A.rows(), A.cols());

          // Parcourir rows x cols
          for (int i = 0; i < A.rows(); i++) {
              for (int j = 0; j < A.cols(); j++) {
                  M(i, j) = A(i, j) + B(i, j);
              }
          }
          return M;
        }


    /**
     * Soustraction : Matrice - Matrice (générique)
     */
    template <typename _Scalar, int Rows, int Cols, int StorageA, int StorageB>
      Matrix<_Scalar, Rows, Cols> operator-(const Matrix<_Scalar, Rows, Cols, StorageA>& A, const Matrix<_Scalar, Rows, Cols, StorageB>& B) 
      {
          // TODO : implémenter

          // Validation taille matrices
          assert(A.rows() == B.rows());
          assert(A.cols() == B.cols());

          // init matrice M
          Matrix<_Scalar, Rows, Cols>M(A.rows(), A.cols());

          // Parcourir 
          for (int i = 0; i < A.rows(); i++) {
              for (int j = 0; j < A.cols(); j++) {
                  M(i, j) = A(i, j) - B(i, j);
              }
          }
          return M;
      }



    /**
     * Soustraction : Matrice (colonne) - Matrice (colonne)
     *
     * Spécialisation de l'opérateur de soustraction pour le cas où les deux matrices
     * sont stockées par colonne.
     */
    template <typename _Scalar>
      Matrix<_Scalar, Dynamic, Dynamic> operator-(const Matrix<_Scalar, Dynamic, Dynamic, ColumnStorage>& A, const Matrix<_Scalar, Dynamic, Dynamic, ColumnStorage>& B) 
        {
          // TODO : implémenter

          // Validation taille matrices
          assert(A.rows() == B.rows());
          assert(A.cols() == B.cols());

          // init matrice M
          Matrix<_Scalar, Dynamic, Dynamic> M(A.rows(), A.cols());

          // Parcourir col x row
          for (int j = 0; j < A.cols(); j++) {
              for (int i = 0; i < A.rows(); i++) {
                  M(i, j) = A(i, j) - B(i, j);
              }
          }
          return M;
        }

    /**
     * Soustraction : Matrice (ligne) - Matrice (ligne)
     *
     * Spécialisation de l'opérateur de soustraction pour le cas où les deux matrices
     * sont stockées par lignes.
     */
    template <typename _Scalar>
      Matrix<_Scalar, Dynamic, Dynamic> operator-(const Matrix<_Scalar, Dynamic, Dynamic, RowStorage>& A, const Matrix<_Scalar, Dynamic, Dynamic, RowStorage>& B) 
        {
          // TODO : implémenter

          // Validation taille matrices
          assert(A.rows() == B.rows());
          assert(A.cols() == B.cols());

          // init matrice M
          Matrix<_Scalar, Dynamic, Dynamic, RowStorage> M(A.rows(), A.cols());

          // Parcourir rows x cols
          for (int i = 0; i < A.rows(); i++) {
              for (int j = 0; j < A.cols(); j++) {
                  M(i, j) = A(i, j) - B(i, j);
              }
          }
          return M;
        }


    /**
     * Multiplication  : Scalaire * Matrice (colonne)
     *
     * Spécialisation de l'opérateur de multiplication par un scalaire pour le
     * cas d'une matrice stockée par colonnes.
     */
    template <typename _Scalar, int _Rows, int _Cols>
      Matrix<_Scalar, _Rows, _Cols, ColumnStorage> operator*(const _Scalar& a, const Matrix<_Scalar, _Rows, _Cols, ColumnStorage>& A)
        {
          // TODO : implémenter

          // init matrice M
          Matrix<_Scalar, _Rows, _Cols> M(A.rows(), A.cols());
          M.setZero();

          // parcourir col x row
          for (int j = 0; j < M.cols(); j++) {
              for (int i = 0; i < M.rows(); i++) {
                  M(i, j) = A(i, j) * a;
              }
          }

          return M;
        }

    /**
     * Multiplication  : Scalaire * Matrice (ligne)
     *
     * Spécialisation de l'opérateur de multiplication par un scalaire pour le
     * cas d'une matrice stockée par lignes.
     */
    template <typename _Scalar, int _Rows, int _Cols>
      Matrix<_Scalar, _Rows, _Cols, RowStorage> operator*(const _Scalar& a, const Matrix<_Scalar, _Rows, _Cols, RowStorage>& A)
        {
          // TODO : implémenter
           
          // init matrice M
          Matrix<_Scalar, Dynamic, Dynamic, RowStorage> M(A.rows(), A.cols());
          M.setZero();

          // parcourir row x col
          for (int i = 0; i < M.rows(); i++) {
              for (int j = 0; j < M.cols(); j++) {
                  M(i, j) = A(i, j) * a;
              }
          }

          return M;
        }

    /**
     * Multiplication : Matrice (ligne) * Vecteur
     *
     * Spécialisation de l'opérateur de multiplication matrice*vecteur pour le
     * cas où la matrice est représentée par lignes.
     */
    template <typename _Scalar, int _Rows, int _Cols>
      Vector<_Scalar, _Rows> operator*(const Matrix<_Scalar, _Rows, _Cols, RowStorage>& A, const Vector<_Scalar, _Cols>& v)
        {
          // TODO : implémenter
          
          // validation taille vector et matrice
          assert(v.rows() == A.cols());

          // init vector resultant
          Vector<_Scalar, _Rows> R(A.rows());
          R.setZero();

          for (int i = 0; i < A.rows(); i++) {
              for (int j = 0; j < A.cols(); j++) {
                  R(i) = R(i) + A(i, j) * v(j);
              }
          }

          return R;
        }

    /**
     * Multiplication : Matrice (colonne) * Vecteur
     *
     * Spécialisation de l'opérateur de multiplication matrice*vecteur pour le
     * cas où la matrice est représentée par colonnes.
     */
    template <typename _Scalar, int _Rows, int _Cols>
      Vector<_Scalar, _Rows> operator*(const Matrix<_Scalar, _Rows, _Cols, ColumnStorage>& A, const Vector<_Scalar, _Cols>& v)
        {
          // TODO : implémenter

          // validation taille vector et matrice
          assert(v.rows() == A.cols());

          // init vector resultant
          Vector<_Scalar, _Rows> R(A.rows());
          R.setZero();

          // parcourir col x row
          for (int j = 0; j < A.cols(); j++) {
              for (int i = 0; i < A.rows(); i++) {
                  R(i) = R(i) + A(i, j) * v(j);
              }
          }

          return R;
        }

    /**
     * Multiplication : Scalaire * Vecteur
     */
    template <typename _Scalar, int _Rows>
      Vector<_Scalar, _Rows> operator*(const _Scalar& a, const Vector<_Scalar, _Rows>& v)
        {
          // TODO : implémenter

          // Initialization du vecteur Résultat
          Vector<_Scalar, _Rows> R(v.rows());
          R.setZero();

          // multiplication
          for (int i = 0; i < v.rows(); i++) {
              R(i) = v(i) * a;
          }

          return R;
        }


    /**
     * Addition : Vecteur + Vecteur
     */
    template <typename _Scalar, int _RowsA, int _RowsB>
      Vector<_Scalar, _RowsA> operator+(const Vector<_Scalar, _RowsA>& a, const Vector<_Scalar, _RowsB>& b)
        {
          // TODO : implémenter

          // validation des tailles des vecteurs
          assert(a.rows() == b.rows());

          // Initialization du vecteur Résultat
          Vector<_Scalar, _RowsA> R(a.rows());
          R.setZero();

          // addition
          for (int i = 0; i < a.rows(); i++) {
              R(i) = a(i) + b(i);
          }

          return R;
        }

    /**
     * Soustraction : Vecteur - Vecteur
     */
    template <typename _Scalar, int _RowsA, int _RowsB>
      Vector<_Scalar, _RowsA> operator-(const Vector<_Scalar, _RowsA>& a, const Vector<_Scalar, _RowsB>& b)
        {
          // validation des tailles des vecteurs
          assert(a.rows() == b.rows());

          // Initialization du vecteur Résultat
          Vector<_Scalar, _RowsA> R(a.rows());
          R.setZero();

          // addition
          for (int i = 0; i < a.rows(); i++) {
              R(i) = a(i) - b(i);
          }

          return R;
        }


}



