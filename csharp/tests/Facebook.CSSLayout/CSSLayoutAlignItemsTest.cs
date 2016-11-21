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
<div id="align_items_stretch" style="width: 100px; height: 100px;">
  <div style="height: 10px;"></div>
</div>

<div id="align_items_center" style="width: 100px; height: 100px; align-items: center;">
  <div style="height: 10px; width: 10px;"></div>
</div>

<div id="align_items_flex_start" style="width: 100px; height: 100px; align-items: flex-start;">
  <div style="height: 10px; width: 10px;"></div>
</div>

<div id="align_items_flex_end" style="width: 100px; height: 100px; align-items: flex-end;">
  <div style="height: 10px; width: 10px;"></div>
</div>
 *
 */

using System;
using NUnit.Framework;
// BEGIN-UNITY
using UnityEngine.CSSLayout;

// namespace Facebook.CSSLayout
namespace CSSLayoutTests
// END-UNITY
{
    [TestFixture]
    public class CSSLayoutAlignItemsTest
    {
        [Test]
        public void Test_align_items_stretch()
        {
            CSSNode root = new CSSNode();
            root.StyleWidth = 100;
            root.StyleHeight = 100;

            CSSNode root_child0 = new CSSNode();
            root_child0.StyleHeight = 10;
            root.Insert(0, root_child0);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0, root.LayoutX);
            Assert.AreEqual(0, root.LayoutY);
            Assert.AreEqual(100, root.LayoutWidth);
            Assert.AreEqual(100, root.LayoutHeight);

            Assert.AreEqual(0, root_child0.LayoutX);
            Assert.AreEqual(0, root_child0.LayoutY);
            Assert.AreEqual(100, root_child0.LayoutWidth);
            Assert.AreEqual(10, root_child0.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0, root.LayoutX);
            Assert.AreEqual(0, root.LayoutY);
            Assert.AreEqual(100, root.LayoutWidth);
            Assert.AreEqual(100, root.LayoutHeight);

            Assert.AreEqual(0, root_child0.LayoutX);
            Assert.AreEqual(0, root_child0.LayoutY);
            Assert.AreEqual(100, root_child0.LayoutWidth);
            Assert.AreEqual(10, root_child0.LayoutHeight);
        }

        [Test]
        public void Test_align_items_center()
        {
            CSSNode root = new CSSNode();
            root.AlignItems = CSSAlign.Center;
            root.StyleWidth = 100;
            root.StyleHeight = 100;

            CSSNode root_child0 = new CSSNode();
            root_child0.StyleWidth = 10;
            root_child0.StyleHeight = 10;
            root.Insert(0, root_child0);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0, root.LayoutX);
            Assert.AreEqual(0, root.LayoutY);
            Assert.AreEqual(100, root.LayoutWidth);
            Assert.AreEqual(100, root.LayoutHeight);

            Assert.AreEqual(45, root_child0.LayoutX);
            Assert.AreEqual(0, root_child0.LayoutY);
            Assert.AreEqual(10, root_child0.LayoutWidth);
            Assert.AreEqual(10, root_child0.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0, root.LayoutX);
            Assert.AreEqual(0, root.LayoutY);
            Assert.AreEqual(100, root.LayoutWidth);
            Assert.AreEqual(100, root.LayoutHeight);

            Assert.AreEqual(45, root_child0.LayoutX);
            Assert.AreEqual(0, root_child0.LayoutY);
            Assert.AreEqual(10, root_child0.LayoutWidth);
            Assert.AreEqual(10, root_child0.LayoutHeight);
        }

        [Test]
        public void Test_align_items_flex_start()
        {
            CSSNode root = new CSSNode();
            root.AlignItems = CSSAlign.FlexStart;
            root.StyleWidth = 100;
            root.StyleHeight = 100;

            CSSNode root_child0 = new CSSNode();
            root_child0.StyleWidth = 10;
            root_child0.StyleHeight = 10;
            root.Insert(0, root_child0);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0, root.LayoutX);
            Assert.AreEqual(0, root.LayoutY);
            Assert.AreEqual(100, root.LayoutWidth);
            Assert.AreEqual(100, root.LayoutHeight);

            Assert.AreEqual(0, root_child0.LayoutX);
            Assert.AreEqual(0, root_child0.LayoutY);
            Assert.AreEqual(10, root_child0.LayoutWidth);
            Assert.AreEqual(10, root_child0.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0, root.LayoutX);
            Assert.AreEqual(0, root.LayoutY);
            Assert.AreEqual(100, root.LayoutWidth);
            Assert.AreEqual(100, root.LayoutHeight);

            Assert.AreEqual(90, root_child0.LayoutX);
            Assert.AreEqual(0, root_child0.LayoutY);
            Assert.AreEqual(10, root_child0.LayoutWidth);
            Assert.AreEqual(10, root_child0.LayoutHeight);
        }

        [Test]
        public void Test_align_items_flex_end()
        {
            CSSNode root = new CSSNode();
            root.AlignItems = CSSAlign.FlexEnd;
            root.StyleWidth = 100;
            root.StyleHeight = 100;

            CSSNode root_child0 = new CSSNode();
            root_child0.StyleWidth = 10;
            root_child0.StyleHeight = 10;
            root.Insert(0, root_child0);
            root.StyleDirection = CSSDirection.LTR;
            root.CalculateLayout();

            Assert.AreEqual(0, root.LayoutX);
            Assert.AreEqual(0, root.LayoutY);
            Assert.AreEqual(100, root.LayoutWidth);
            Assert.AreEqual(100, root.LayoutHeight);

            Assert.AreEqual(90, root_child0.LayoutX);
            Assert.AreEqual(0, root_child0.LayoutY);
            Assert.AreEqual(10, root_child0.LayoutWidth);
            Assert.AreEqual(10, root_child0.LayoutHeight);

            root.StyleDirection = CSSDirection.RTL;
            root.CalculateLayout();

            Assert.AreEqual(0, root.LayoutX);
            Assert.AreEqual(0, root.LayoutY);
            Assert.AreEqual(100, root.LayoutWidth);
            Assert.AreEqual(100, root.LayoutHeight);

            Assert.AreEqual(0, root_child0.LayoutX);
            Assert.AreEqual(0, root_child0.LayoutY);
            Assert.AreEqual(10, root_child0.LayoutWidth);
            Assert.AreEqual(10, root_child0.LayoutHeight);
        }

    }
}
