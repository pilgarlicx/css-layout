/**
 * Copyright (c) 2014-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

/**
 * @Generated by gentest/gentest.sh with the following input
 *
<div id="max_width" style="width: 100px; height: 100px;">
  <div style="height: 10px; max-width: 50px;"></div>
</div>

<div id="max_height" style="width: 100px; height: 100px; flex-direction: row;">
  <div style="width: 10px; max-height: 50px;"></div>
</div>

<div id="min_height" style="width: 100px; height: 100px;">
  <div style="flex-grow: 1; min-height: 60px;"></div>
  <div style="flex-grow: 1;"></div>
</div>

<div id="min_width" style="width: 100px; height: 100px; flex-direction: row">
  <div style="flex-grow: 1; min-width: 60px;"></div>
  <div style="flex-grow: 1;"></div>
</div>

<div id="justify_content_min_max" style="max-height: 200px; min-height: 100px; width: 100px; justify-content: center;">
  <div style="width: 60px; height: 60px;"></div>
</div>

<div id="align_items_min_max" style="max-width: 200px; min-width: 100px; height: 100px; align-items: center;">
  <div style="width: 60px; height: 60px;"></div>
</div>

<div id="justify_content_overflow_min_max" style="min-height: 100px; max-height: 110px; justify-content: center;">
  <div style="width: 50px; height: 50px;"></div>
  <div style="width: 50px; height: 50px;"></div>
  <div style="width: 50px; height: 50px;"></div>
</div>

<div id="flex_grow_within_max_width" style="width: 200px; height: 100px;">
  <div style="flex-direction: row; max-width: 100px;">
    <div style="height: 20px; flex-grow: 1;"></div>
  </div>
</div>

<div id="flex_grow_within_constrained_max_width" style="width: 200px; height: 100px;">
  <div style="flex-direction: row; max-width: 300px;">
    <div style="height: 20px; flex-grow: 1;"></div>
  </div>
</div>
 *
 */

#include <CSSLayout/CSSLayout.h>
#include <gtest/gtest.h>

TEST(CSSLayoutTest, max_width) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetMaxWidth(root_child0, 50);
  CSSNodeStyleSetHeight(root_child0, 10);
  CSSNodeInsertChild(root, root_child0, 0);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(50, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(50, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(50, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(10, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, max_height) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetFlexDirection(root, CSSFlexDirectionRow);
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child0, 10);
  CSSNodeStyleSetMaxHeight(root_child0, 50);
  CSSNodeInsertChild(root, root_child0, 0);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(50, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(90, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(10, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(50, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, min_height) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetFlexGrow(root_child0, 1);
  CSSNodeStyleSetMinHeight(root_child0, 60);
  CSSNodeInsertChild(root, root_child0, 0);

  const CSSNodeRef root_child1 = CSSNodeNew();
  CSSNodeStyleSetFlexGrow(root_child1, 1);
  CSSNodeInsertChild(root, root_child1, 1);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(80, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_EQ(80, CSSNodeLayoutGetTop(root_child1));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_EQ(20, CSSNodeLayoutGetHeight(root_child1));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(80, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_EQ(80, CSSNodeLayoutGetTop(root_child1));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_EQ(20, CSSNodeLayoutGetHeight(root_child1));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, min_width) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetFlexDirection(root, CSSFlexDirectionRow);
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetFlexGrow(root_child0, 1);
  CSSNodeStyleSetMinWidth(root_child0, 60);
  CSSNodeInsertChild(root, root_child0, 0);

  const CSSNodeRef root_child1 = CSSNodeNew();
  CSSNodeStyleSetFlexGrow(root_child1, 1);
  CSSNodeInsertChild(root, root_child1, 1);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(80, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_EQ(80, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child1));
  ASSERT_EQ(20, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root_child1));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(20, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(80, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child1));
  ASSERT_EQ(20, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root_child1));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, justify_content_min_max) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetJustifyContent(root, CSSJustifyCenter);
  CSSNodeStyleSetWidth(root, 100);
  CSSNodeStyleSetMinHeight(root, 100);
  CSSNodeStyleSetMaxHeight(root, 200);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child0, 60);
  CSSNodeStyleSetHeight(root_child0, 60);
  CSSNodeInsertChild(root, root_child0, 0);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(20, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(60, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(60, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(40, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(20, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(60, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(60, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, align_items_min_max) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetAlignItems(root, CSSAlignCenter);
  CSSNodeStyleSetMinWidth(root, 100);
  CSSNodeStyleSetMaxWidth(root, 200);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child0, 60);
  CSSNodeStyleSetHeight(root_child0, 60);
  CSSNodeInsertChild(root, root_child0, 0);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(20, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(60, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(60, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(20, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(60, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(60, CSSNodeLayoutGetHeight(root_child0));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, justify_content_overflow_min_max) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetJustifyContent(root, CSSJustifyCenter);
  CSSNodeStyleSetMinHeight(root, 100);
  CSSNodeStyleSetMaxHeight(root, 110);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child0, 50);
  CSSNodeStyleSetHeight(root_child0, 50);
  CSSNodeInsertChild(root, root_child0, 0);

  const CSSNodeRef root_child1 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child1, 50);
  CSSNodeStyleSetHeight(root_child1, 50);
  CSSNodeInsertChild(root, root_child1, 1);

  const CSSNodeRef root_child2 = CSSNodeNew();
  CSSNodeStyleSetWidth(root_child2, 50);
  CSSNodeStyleSetHeight(root_child2, 50);
  CSSNodeInsertChild(root, root_child2, 2);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(50, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(110, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(-20, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(50, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(50, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_EQ(30, CSSNodeLayoutGetTop(root_child1));
  ASSERT_EQ(50, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_EQ(50, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_EQ(80, CSSNodeLayoutGetTop(root_child2));
  ASSERT_EQ(50, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_EQ(50, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(50, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(110, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(-20, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(50, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(50, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child1));
  ASSERT_EQ(30, CSSNodeLayoutGetTop(root_child1));
  ASSERT_EQ(50, CSSNodeLayoutGetWidth(root_child1));
  ASSERT_EQ(50, CSSNodeLayoutGetHeight(root_child1));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child2));
  ASSERT_EQ(80, CSSNodeLayoutGetTop(root_child2));
  ASSERT_EQ(50, CSSNodeLayoutGetWidth(root_child2));
  ASSERT_EQ(50, CSSNodeLayoutGetHeight(root_child2));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, flex_grow_within_max_width) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetWidth(root, 200);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetFlexDirection(root_child0, CSSFlexDirectionRow);
  CSSNodeStyleSetMaxWidth(root_child0, 100);
  CSSNodeInsertChild(root, root_child0, 0);

  const CSSNodeRef root_child0_child0 = CSSNodeNew();
  CSSNodeStyleSetFlexGrow(root_child0_child0, 1);
  CSSNodeStyleSetHeight(root_child0_child0, 20);
  CSSNodeInsertChild(root_child0, root_child0_child0, 0);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(200, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(20, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0_child0));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root_child0_child0));
  ASSERT_EQ(20, CSSNodeLayoutGetHeight(root_child0_child0));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(200, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(100, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(20, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0_child0));
  ASSERT_EQ(100, CSSNodeLayoutGetWidth(root_child0_child0));
  ASSERT_EQ(20, CSSNodeLayoutGetHeight(root_child0_child0));

  CSSNodeFreeRecursive(root);
}

TEST(CSSLayoutTest, flex_grow_within_constrained_max_width) {
  const CSSNodeRef root = CSSNodeNew();
  CSSNodeStyleSetWidth(root, 200);
  CSSNodeStyleSetHeight(root, 100);

  const CSSNodeRef root_child0 = CSSNodeNew();
  CSSNodeStyleSetFlexDirection(root_child0, CSSFlexDirectionRow);
  CSSNodeStyleSetMaxWidth(root_child0, 300);
  CSSNodeInsertChild(root, root_child0, 0);

  const CSSNodeRef root_child0_child0 = CSSNodeNew();
  CSSNodeStyleSetFlexGrow(root_child0_child0, 1);
  CSSNodeStyleSetHeight(root_child0_child0, 20);
  CSSNodeInsertChild(root_child0, root_child0_child0, 0);
  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionLTR);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(200, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(200, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(20, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0_child0));
  ASSERT_EQ(200, CSSNodeLayoutGetWidth(root_child0_child0));
  ASSERT_EQ(20, CSSNodeLayoutGetHeight(root_child0_child0));

  CSSNodeCalculateLayout(root, CSSUndefined, CSSUndefined, CSSDirectionRTL);

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root));
  ASSERT_EQ(200, CSSNodeLayoutGetWidth(root));
  ASSERT_EQ(100, CSSNodeLayoutGetHeight(root));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0));
  ASSERT_EQ(200, CSSNodeLayoutGetWidth(root_child0));
  ASSERT_EQ(20, CSSNodeLayoutGetHeight(root_child0));

  ASSERT_EQ(0, CSSNodeLayoutGetLeft(root_child0_child0));
  ASSERT_EQ(0, CSSNodeLayoutGetTop(root_child0_child0));
  ASSERT_EQ(200, CSSNodeLayoutGetWidth(root_child0_child0));
  ASSERT_EQ(20, CSSNodeLayoutGetHeight(root_child0_child0));

  CSSNodeFreeRecursive(root);
}
