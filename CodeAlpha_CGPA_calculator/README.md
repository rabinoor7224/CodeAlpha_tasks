# 🎓 CGPA Calculator (C++)

A clean, interactive, and user-friendly console application written in **C++** to calculate a student's Semester Grade Point Average (GPA) or Cumulative Grade Point Average (CGPA). 

This tool dynamically processes course inputs, converts letter grades to corresponding grade points, and calculates the overall academic score accurately.

---

## 📄 Overview & How It Works

The program works through a simple sequence of steps:

1. **Input Courses:** Asks the user for the total number of subjects/courses taken.
2. **Collect Data:** Iterates through each course to record its **Credit Hours** and the **Grade Obtained** (`A`, `B`, `C`, `D`, `F`).
3. **Grade Point Mapping:** Converts the letter grade into standard grade points using a 4.0 scale.
4. **Weighted Calculation:** Multiplies each course's grade point by its credit hours to determine the total weighted grade points.
5. **Final Computation:** Divides total grade points by total credit hours to output the final CGPA along with a clean summary table.

---

## ⚙️ Grade Mapping System

| Letter Grade | Grade Point | Performance |
| :---: | :---: | :--- |
| **A** | **4.0** | Excellent |
| **B** | **3.0** | Good |
| **C** | **2.0** | Average |
| **D** | **1.0** | Below Average |
| **F** | **0.0** | Fail |

---

## 🧮 Mathematical Formula

The CGPA is calculated using the weighted average formula:

$$\text{CGPA} = \frac{\sum (\text{Grade Point}_i \times \text{Credit Hours}_i)}{\sum \text{Credit Hours}_i}$$

---
