#include "SepSet.h"

#include <gtest.h>

TEST(SepSet, can_add_element) {
  SepSet t(2);
  EXPECT_EQ(t.whereI(1), -1);
  t.add(1);
  EXPECT_NE(t.whereI(1), -1);
}

TEST(SepSet, error_when_wrong_index_add_element) {
  SepSet t(2);
  EXPECT_ANY_THROW(t.whereI(-1));
  EXPECT_ANY_THROW(t.whereI(3));
}

TEST(SepSet, can_merge) {
  SepSet t(2);
  t.add(0);
  t.add(1);
  EXPECT_NE(t.whereI(1), t.whereI(0));
  t.merge(0,1);
  EXPECT_EQ(t.whereI(1), t.whereI(0));
}

