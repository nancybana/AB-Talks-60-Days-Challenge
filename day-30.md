# Week 5 Sprint Challenge

## Overview

This repository contains solutions for two medium-level algorithm problems completed as part of the Week 5 Sprint Challenge.

The objective was not only to solve the problems but also to analyze complexity, justify optimization choices, and explain scalability.

---

# Problem 1: Two Sum

## Problem Statement

Given an array of integers and a target value, find the indices of two numbers whose sum equals the target.

## Approach

Instead of checking every possible pair, a Hash Map is used to store previously visited elements and their indices.

For each element:

1. Calculate the required complement.
2. Check whether the complement already exists in the Hash Map.
3. If found, return the indices.
4. Otherwise, store the current element.

## Complexity Analysis

### Time Complexity

O(n)

Each element is processed exactly once.

### Space Complexity

O(n)

Additional space is required for the Hash Map.

## Optimization Decision

### Brute Force

* Time: O(n²)
* Space: O(1)

### Optimized Solution

* Time: O(n)
* Space: O(n)

The optimized approach trades extra memory for significantly faster execution.

## Why It Scales

For large datasets, quadratic solutions become inefficient. Using constant-time Hash Map lookups allows the solution to handle large inputs efficiently while maintaining linear performance.

---

# Problem 2: Longest Substring Without Repeating Characters

## Problem Statement

Given a string, find the length of the longest substring that contains no repeating characters.

## Approach

A Sliding Window technique is used.

Two pointers maintain a valid substring:

* Expand the window when characters are unique.
* Shrink the window when duplicates are encountered.
* Continuously track the maximum window length.

## Complexity Analysis

### Time Complexity

O(n)

Each character enters and leaves the window at most once.

### Space Complexity

O(n)

A Hash Set is used to store characters currently inside the window.

## Optimization Decision

### Brute Force

* Time: O(n²) to O(n³)
* Space: O(1)

### Optimized Solution

* Time: O(n)
* Space: O(n)

The Sliding Window approach eliminates repeated work and significantly improves efficiency.

## Why It Scales

The algorithm processes each character a limited number of times, making it suitable for very large strings. Performance grows linearly with input size.

---

# Tradeoffs

| Technique      | Benefit                       | Cost                                 |
| -------------- | ----------------------------- | ------------------------------------ |
| Hash Map       | Fast lookup                   | Extra memory                         |
| Hash Set       | Efficient duplicate detection | Extra memory                         |
| Sliding Window | Linear-time processing        | Slightly more complex implementation |

The chosen optimizations prioritize execution speed and scalability, which are critical for technical interviews and real-world applications.

---

# Key Learnings

* Choosing the right data structure can drastically improve performance.
* Time complexity is often more important than minimizing memory usage.
* Explaining optimization decisions is as important as writing working code.
* Scalable solutions focus on reducing unnecessary computations.

---

# Technologies Used

* C++
* STL (Vector, Hash Map, Hash Set)
* VS Code
* Git & GitHub

---


