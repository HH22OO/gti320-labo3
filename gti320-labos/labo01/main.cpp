/**
 * @file main.cpp
 *
 * @brief Execute unit tests for a simple linear algebra library.
 *
 * Nom:
 * Code permanent :
 * Email :
 *
 */

#include <gtest/gtest.h>

int main(int argc, char** argv)
{
  // Executer tous les tests unitaires.
  // 
  // Les tests sont écrites dans les fichiers:
  //   tests/Tests1a.cpp
  //   tests/Tests1b.cpp
  //   tests/TestsSupplementaire1a.cpp
  //   tests/TestsSupplementaire1b.cpp
  //
  ::testing::InitGoogleTest(&argc, argv);

  //::testing::GTEST_FLAG(filter) = "TestLabo1a.StaticVectorAccess";
  //::testing::GTEST_FLAG(filter) = "TestLabo1a.*ElementAccess";
  //::testing::GTEST_FLAG(filter) = "TestLabo1a.*";
  //::testing::GTEST_FLAG(filter) = "TestLabo1b.*";
  //::testing::GTEST_FLAG(filter) = "TestSupLabo1a.*";
  //::testing::GTEST_FLAG(filter) = "TestSupLabo1b.*";

  const int ret = RUN_ALL_TESTS();

  return ret;
}
