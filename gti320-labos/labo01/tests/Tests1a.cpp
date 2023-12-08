/**
 * @file Tests1a.cpp
 *
 * @brief Tests unitaires de la partie 1b
 *
 * Nom:
 * Code permanent :
 * Email :
 *
 */

#include "Matrix.h"
#include "Vector.h"

#include <gtest/gtest.h>
#include <chrono>

using namespace gti320;

/**
 * Test d'allocation de mémoire et d'accès aux éléments d'un vecteur.
 */
TEST(TestLabo1a, StaticVectorElementAccess)
{
    {
      // Taille fixe avec des doubles
      Vector<double,3> u;
      u(0) = 0.0;
      u(1) = 1.1;
      u(2) = 2.2;
      EXPECT_EQ(u(0), 0.0);
      EXPECT_EQ(u(1), 1.1);
      EXPECT_EQ(u(2), 2.2);
    }

    {
      // Taille fixe avec des int
      Vector<int,4> u;
      u(0) = 0;
      u(1) = 1;
      u(2) = 2;
      u(3) = 3;
      EXPECT_EQ(u(0), 0);
      EXPECT_EQ(u(1), 1);
      EXPECT_EQ(u(2), 2);
      EXPECT_EQ(u(3), 3);
    }
}

/**
 * Test d'allocation de mémoire et d'accès aux éléments d'un vecteur.
 */
TEST(TestLabo1a, DynamicVectorElementAccess)
{
    {
      // Taille dynamique avec des doubles
      Vector<double, Dynamic> u(3);
      u(0) = 1.2;
      u(1) = 2.3;
      u(2) = 3.4;
      EXPECT_EQ(u(0), 1.2);
      EXPECT_EQ(u(1), 2.3);
      EXPECT_EQ(u(2), 3.4);

      u.resize(5);
      u(0) = 9.9;
      u(1) = 8.8;
      u(2) = 7.7;
      u(3) = 6.6;
      u(4) = 5.5;
      EXPECT_EQ(u(0), 9.9);
      EXPECT_EQ(u(1), 8.8);
      EXPECT_EQ(u(2), 7.7);
      EXPECT_EQ(u(3), 6.6);
      EXPECT_EQ(u(4), 5.5);
    }
}



/**
 * Test du produit scalaire
 */
TEST(TestLabo1a, VectorScalarProduct)
{
    {
      Vector<double, 1> u; u(0) = 6.6;
      Vector<double, 1> v; v(0) = 2.5;
      EXPECT_NEAR(u.dot(v), 16.500000, 1e-3) << "Produit scalaire des vecteur (6.6) et (2.5) devrait être 16.500000.";
    }
    {
      Vector<double, 2> u; u(0) = -9.3; u(1) = -2.0;
      Vector<double, 2> v; v(0) = 1.7; v(1) = 3.5;
      EXPECT_NEAR(u.dot(v), -22.810000, 1e-3) << "Produit scalaire des vecteur (-9.3, -2.0) et (1.7, 3.5) devrait être -22.810000.";
    }
    {
      Vector<double, 3> u; u(0) = 4.8; u(1) = 7.9; u(2) = 0.5;
      Vector<double, 3> v; v(0) = -2.5; v(1) = -5.2; v(2) = -7.3;
      EXPECT_NEAR(u.dot(v), -56.730000, 1e-3) << "Produit scalaire des vecteur (4.8, 7.9, 0.5) et (-2.5, -5.2, -7.3) devrait être -56.730000.";
    }
    {
      Vector<double, 4> u; u(0) = 3.2; u(1) = 3.1; u(2) = -8.9; u(3) = 6.4;
      Vector<double, 4> v; v(0) = 3.5; v(1) = 5.4; v(2) = 1.7; v(3) = 7.2;
      EXPECT_NEAR(u.dot(v), 58.890000, 1e-3) << "Produit scalaire des vecteur (3.2, 3.1, -8.9, 6.4) et (3.5, 5.4, 1.7, 7.2) devrait être 58.890000.";
    }
}

/**
 * Test de la norme d'un vecteur
 */
TEST(TestLabo1a, VectorNorm)
{
  // Allocation statique
    {
      Vector<double, 1> u; u(0) = -8.0;
      EXPECT_NEAR(u.norm(), 8.000000, 1e-3) << "Norme du vecteur (-8.0) devrait être 8.000000.";
    }
    {
      Vector<double, 2> u; u(0) = -5.2; u(1) = 8.8;
      EXPECT_NEAR(u.norm(), 10.221546, 1e-3) << "Norme du vecteur (-5.2, 8.8) devrait être 10.221546.";
    }
    {
      Vector<double, 3> u; u(0) = 7.9; u(1) = 8.3; u(2) = 3.4;
      EXPECT_NEAR(u.norm(), 11.952406, 1e-3) << "Norme du vecteur (7.9, 8.3, 3.4) devrait être 11.952406.";
    }
    {
      Vector<double, 4> u; u(0) = 4.3; u(1) = -3.6; u(2) = 2.9; u(3) = -2.9;
      EXPECT_NEAR(u.norm(), 6.947661, 1e-3) << "Norme du vecteur (4.3, -3.6, 2.9, -2.9) devrait être 6.947661.";
    }

  // Allocation dynamique
    {
      Vector<double, Dynamic> u(1); u(0) = -8.0;
      EXPECT_NEAR(u.norm(), 8.000000, 1e-3) << "Norme du vecteur (-8.0) devrait être 8.000000.";
    }
    {
      Vector<double, Dynamic> u(2); u(0) = -5.2; u(1) = 8.8;
      EXPECT_NEAR(u.norm(), 10.221546, 1e-3) << "Norme du vecteur (-5.2, 8.8) devrait être 10.221546.";
    }
    {
      Vector<double, Dynamic> u(3); u(0) = 7.9; u(1) = 8.3; u(2) = 3.4;
      EXPECT_NEAR(u.norm(), 11.952406, 1e-3) << "Norme du vecteur (7.9, 8.3, 3.4) devrait être 11.952406.";
    }
    {
      Vector<double, Dynamic> u(4); u(0) = 4.3; u(1) = -3.6; u(2) = 2.9; u(3) = -2.9;
      EXPECT_NEAR(u.norm(), 6.947661, 1e-3) << "Norme du vecteur (4.3, -3.6, 2.9, -2.9) devrait être 6.947661.";
    }
}


/**
 * Test l'accès aux éléments d'une matrice allouée de manière statique
 */
TEST(TestLabo1a, StaticStaticMatrixElementAccess)
{
    {
      // Crée une matrice à taille fixe
      Matrix<double, 3, 5> M;
      EXPECT_EQ(M.cols(), 5);
      EXPECT_EQ(M.rows(), 3);

      // Redimensionne la matrice (la taille ne doit pas changer). 
      M.resize(100, 1000);
      EXPECT_EQ(M.cols(), 5);
      EXPECT_EQ(M.rows(), 3);
    }

    {
      // Test - stockage par colonnes
      Matrix<double, 100, 4, ColumnStorage> ColM;
      ColM.setZero();
      ColM(0, 0) = 1.1;
      ColM(99, 3) = -2.2;
      ColM(20, 1) = 3.3;
      EXPECT_EQ(ColM.rows(), 100);
      EXPECT_EQ(ColM.cols(), 4);
      EXPECT_EQ(ColM(0, 0), 1.1);
      EXPECT_EQ(ColM(99, 3), -2.2);
      EXPECT_EQ(ColM(20, 1), 3.3);
      EXPECT_EQ(ColM(0, 1), 0.0);
      EXPECT_EQ(ColM(1, 0), 0.0);
      EXPECT_EQ(ColM(99, 2), 0.0);
      EXPECT_EQ(ColM(21, 0), 0.0);

      // Test - stockage par lignes
      Matrix<double, 100, 4, RowStorage> RowM;
      RowM.setZero();
      RowM(0, 0) = 1.1;
      RowM(99, 3) = -2.2;
      RowM(20, 1) = 3.3;
      EXPECT_EQ(RowM.rows(), 100);
      EXPECT_EQ(RowM.cols(), 4);
      EXPECT_EQ(RowM(0, 0), 1.1);
      EXPECT_EQ(RowM(99, 3), -2.2);
      EXPECT_EQ(RowM(20, 1), 3.3);
      EXPECT_EQ(RowM(0, 1), 0.0);
      EXPECT_EQ(RowM(1, 0), 0.0);
      EXPECT_EQ(RowM(99, 2), 0.0);
      EXPECT_EQ(RowM(21, 0), 0.0);

      // Transposée pour stockage par colonnes
      const auto ColMT = ColM.transpose();
      EXPECT_EQ(ColMT.rows(), 4);
      EXPECT_EQ(ColMT.cols(), 100);
      EXPECT_EQ(ColMT(0, 0), 1.1);
      EXPECT_EQ(ColMT(3, 99), -2.2);
      EXPECT_EQ(ColMT(1, 20), 3.3);
      EXPECT_EQ(ColMT(1, 0), 0.0);
      EXPECT_EQ(ColMT(0, 1), 0.0);
      EXPECT_EQ(ColMT(2, 99), 0.0);
      EXPECT_EQ(ColMT(0, 21), 0.0);

      // Transposée
      const auto RowMT = RowM.transpose();
      EXPECT_EQ(RowMT.rows(), 4);
      EXPECT_EQ(RowMT.cols(), 100);
      EXPECT_EQ(RowMT(0, 0), 1.1);
      EXPECT_EQ(RowMT(3, 99), -2.2);
      EXPECT_EQ(RowMT(1, 20), 3.3);
      EXPECT_EQ(RowMT(1, 0), 0.0);
      EXPECT_EQ(RowMT(0, 1), 0.0);
      EXPECT_EQ(RowMT(2, 99), 0.0);
      EXPECT_EQ(RowMT(0, 21), 0.0);
    }
}


/**
 * Test les matrice avec redimensionnement dynamique
 */
TEST(TestLabo1a, DynamicDynamicMatrixElementAccess)
{

    {
      Matrix<double> M(3, 5);
      EXPECT_EQ(M.rows(), 3);
      EXPECT_EQ(M.cols(), 5);

      // Redimensionne la matrice
      M.resize(100, 1000);
      EXPECT_EQ(M.rows(), 100);
      EXPECT_EQ(M.cols(), 1000);
    }

    {
      // Test - stockage par colonnes
      Matrix<double, Dynamic, Dynamic, ColumnStorage> ColM(100, 4);
      ColM.setZero();
      ColM(0, 0) = 1.1;
      ColM(99, 3) = -2.2;
      ColM(20, 1) = 3.3;
      EXPECT_EQ(ColM.rows(), 100);
      EXPECT_EQ(ColM.cols(), 4);
      EXPECT_EQ(ColM(0, 0), 1.1);
      EXPECT_EQ(ColM(99, 3), -2.2);
      EXPECT_EQ(ColM(20, 1), 3.3);
      EXPECT_EQ(ColM(0, 1), 0.0);
      EXPECT_EQ(ColM(1, 0), 0.0);
      EXPECT_EQ(ColM(99, 2), 0.0);
      EXPECT_EQ(ColM(21, 0), 0.0);

      // Test - stockage par lignes
      Matrix<double, Dynamic, Dynamic, RowStorage> RowM(100, 4);
      RowM.setZero();
      RowM(0, 0) = 1.1;
      RowM(99, 3) = -2.2;
      RowM(20, 1) = 3.3;
      EXPECT_EQ(RowM.rows(), 100);
      EXPECT_EQ(RowM.cols(), 4);
      EXPECT_EQ(RowM(0, 0), 1.1);
      EXPECT_EQ(RowM(99, 3), -2.2);
      EXPECT_EQ(RowM(20, 1), 3.3);
      EXPECT_EQ(RowM(0, 1), 0.0);
      EXPECT_EQ(RowM(1, 0), 0.0);
      EXPECT_EQ(RowM(99, 2), 0.0);
      EXPECT_EQ(RowM(21, 0), 0.0);

      // Transposée pour stockage par colonnes
      const auto ColMT = ColM.transpose();
      EXPECT_EQ(ColMT.rows(), 4);
      EXPECT_EQ(ColMT.cols(), 100);
      EXPECT_EQ(ColMT(0, 0), 1.1);
      EXPECT_EQ(ColMT(3, 99), -2.2);
      EXPECT_EQ(ColMT(1, 20), 3.3);
      EXPECT_EQ(ColMT(1, 0), 0.0);
      EXPECT_EQ(ColMT(0, 1), 0.0);
      EXPECT_EQ(ColMT(2, 99), 0.0);
      EXPECT_EQ(ColMT(0, 21), 0.0);

      // Transposée
      const auto RowMT = RowM.transpose();
      EXPECT_EQ(RowMT.rows(), 4);
      EXPECT_EQ(RowMT.cols(), 100);
      EXPECT_EQ(RowMT(0, 0), 1.1);
      EXPECT_EQ(RowMT(3, 99), -2.2);
      EXPECT_EQ(RowMT(1, 20), 3.3);
      EXPECT_EQ(RowMT(1, 0), 0.0);
      EXPECT_EQ(RowMT(0, 1), 0.0);
      EXPECT_EQ(RowMT(2, 99), 0.0);
      EXPECT_EQ(RowMT(0, 21), 0.0);
    }
}

TEST(TestLabo1a, MatrixCopyOperator) 
{
  // Stockage statique, par colonnes
    {
      Matrix<double, 4, 5, ColumnStorage> ColM;
      Matrix<double, 4, 5, ColumnStorage> CpyM;
      for (int i=0; i<4; i++)
        {
          for (int j=0; j<5; j++)
            {
              ColM(i, j) = 10*i + j;
            }
        }
      CpyM = ColM;
      for (int i=0; i<4; i++)
        {
          for (int j=0; j<5; j++)
            {
              EXPECT_EQ(CpyM(i, j), 10*i + j);
            }
        }
    }

  // Stockage statique, par lignes
    {
      Matrix<double, 4, 5, RowStorage> RowM;
      Matrix<double, 4, 5, RowStorage> CpyM;
      for (int i=0; i<4; i++)
        {
          for (int j=0; j<5; j++)
            {
              RowM(i, j) = 10*i + j;
            }
        }
      CpyM = RowM;
      for (int i=0; i<4; i++)
        {
          for (int j=0; j<5; j++)
            {
              EXPECT_EQ(CpyM(i, j), 10*i + j);
            }
        }
    }
}


TEST(TestLabo1a, AffectationBySubMatrix)
{
    {
      Matrix<double, 4, 4, ColumnStorage> m;
      m.setIdentity();
      EXPECT_EQ(m(0, 0), 1); EXPECT_EQ(m(0, 1), 0); EXPECT_EQ(m(0, 2), 0); EXPECT_EQ(m(0, 3), 0); 
      EXPECT_EQ(m(1, 0), 0); EXPECT_EQ(m(1, 1), 1); EXPECT_EQ(m(1, 2), 0); EXPECT_EQ(m(1, 3), 0); 
      EXPECT_EQ(m(2, 0), 0); EXPECT_EQ(m(2, 1), 0); EXPECT_EQ(m(2, 2), 1); EXPECT_EQ(m(2, 3), 0); 
      EXPECT_EQ(m(3, 0), 0); EXPECT_EQ(m(3, 1), 0); EXPECT_EQ(m(3, 2), 0); EXPECT_EQ(m(3, 3), 1);

      Matrix<double, 4, 1, RowStorage> c;
      c(0, 0) = 1.0; c(1, 0) = 2.0; c(2, 0) = 3.0; c(3, 0) = 4.0;
      m.block(0, 0, 4, 1) = c;
      m.block(0, 1, 4, 1) = c;
      m.block(0, 2, 4, 1) = c;
      m.block(0, 3, 4, 1) = c;
      EXPECT_EQ(m(0, 0), 1); EXPECT_EQ(m(0, 1), 1); EXPECT_EQ(m(0, 2), 1); EXPECT_EQ(m(0, 3), 1);
      EXPECT_EQ(m(1, 0), 2); EXPECT_EQ(m(1, 1), 2); EXPECT_EQ(m(1, 2), 2); EXPECT_EQ(m(1, 3), 2); 
      EXPECT_EQ(m(2, 0), 3); EXPECT_EQ(m(2, 1), 3); EXPECT_EQ(m(2, 2), 3); EXPECT_EQ(m(2, 3), 3); 
      EXPECT_EQ(m(3, 0), 4); EXPECT_EQ(m(3, 1), 4); EXPECT_EQ(m(3, 2), 4); EXPECT_EQ(m(3, 3), 4);

      Matrix<double, 2, 2, ColumnStorage> b;
      b(0, 0) = 0.0; b(1, 0) = 1.0; b(0, 1) = 2.0; b(1, 1) = 3.0;
      m.block(0, 0, 2, 2) = b;
      m.block(2, 0, 2, 2) = b;
      m.block(0, 2, 2, 2) = b;
      m.block(2, 2, 2, 2) = b;
      EXPECT_EQ(m(0, 0), 0); EXPECT_EQ(m(0, 1), 2); EXPECT_EQ(m(0, 2), 0); EXPECT_EQ(m(0, 3), 2); 
      EXPECT_EQ(m(1, 0), 1); EXPECT_EQ(m(1, 1), 3); EXPECT_EQ(m(1, 2), 1); EXPECT_EQ(m(1, 3), 3);
      EXPECT_EQ(m(2, 0), 0); EXPECT_EQ(m(2, 1), 2); EXPECT_EQ(m(2, 2), 0); EXPECT_EQ(m(2, 3), 2);
      EXPECT_EQ(m(3, 0), 1); EXPECT_EQ(m(3, 1), 3); EXPECT_EQ(m(3, 2), 1); EXPECT_EQ(m(3, 3), 3);
    }

    {
      Matrix<double, 4, 4, RowStorage> m;
      m.setIdentity();
      EXPECT_EQ(m(0, 0), 1); EXPECT_EQ(m(0, 1), 0); EXPECT_EQ(m(0, 2), 0); EXPECT_EQ(m(0, 3), 0);
      EXPECT_EQ(m(1, 0), 0); EXPECT_EQ(m(1, 1), 1); EXPECT_EQ(m(1, 2), 0); EXPECT_EQ(m(1, 3), 0);
      EXPECT_EQ(m(2, 0), 0); EXPECT_EQ(m(2, 1), 0); EXPECT_EQ(m(2, 2), 1); EXPECT_EQ(m(2, 3), 0);
      EXPECT_EQ(m(3, 0), 0); EXPECT_EQ(m(3, 1), 0); EXPECT_EQ(m(3, 2), 0); EXPECT_EQ(m(3, 3), 1);

      Matrix<double, 4, 1, RowStorage> c;
      c(0, 0) = 1.0; c(1, 0) = 2.0; c(2, 0) = 3.0; c(3, 0) = 4.0;
      m.block(0, 0, 4, 1) = c;
      m.block(0, 1, 4, 1) = c;
      m.block(0, 2, 4, 1) = c;
      m.block(0, 3, 4, 1) = c;
      EXPECT_EQ(m(0, 0), 1); EXPECT_EQ(m(0, 1), 1); EXPECT_EQ(m(0, 2), 1); EXPECT_EQ(m(0, 3), 1);
      EXPECT_EQ(m(1, 0), 2); EXPECT_EQ(m(1, 1), 2); EXPECT_EQ(m(1, 2), 2); EXPECT_EQ(m(1, 3), 2);
      EXPECT_EQ(m(2, 0), 3); EXPECT_EQ(m(2, 1), 3); EXPECT_EQ(m(2, 2), 3); EXPECT_EQ(m(2, 3), 3);
      EXPECT_EQ(m(3, 0), 4); EXPECT_EQ(m(3, 1), 4); EXPECT_EQ(m(3, 2), 4); EXPECT_EQ(m(3, 3), 4);

      Matrix<double, 2, 2, ColumnStorage> b;
      b(0, 0) = 0.0; b(1, 0) = 1.0; b(0, 1) = 2.0; b(1, 1) = 3.0;
      m.block(0, 0, 2, 2) = b;
      m.block(2, 0, 2, 2) = b;
      m.block(0, 2, 2, 2) = b;
      m.block(2, 2, 2, 2) = b;
      EXPECT_EQ(m(0, 0), 0); EXPECT_EQ(m(0, 1), 2); EXPECT_EQ(m(0, 2), 0); EXPECT_EQ(m(0, 3), 2);
      EXPECT_EQ(m(1, 0), 1); EXPECT_EQ(m(1, 1), 3); EXPECT_EQ(m(1, 2), 1); EXPECT_EQ(m(1, 3), 3);
      EXPECT_EQ(m(2, 0), 0); EXPECT_EQ(m(2, 1), 2); EXPECT_EQ(m(2, 2), 0); EXPECT_EQ(m(2, 3), 2);
      EXPECT_EQ(m(3, 0), 1); EXPECT_EQ(m(3, 1), 3); EXPECT_EQ(m(3, 2), 1); EXPECT_EQ(m(3, 3), 3);
    }

}
