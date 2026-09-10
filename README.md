# Calculator

A C++ calculator project that evaluates mathematical expressions and explores basic parsing, object-oriented design, and data structure usage.

---

## Overview

<img width="1699" height="1302" alt="image" src="https://github.com/user-attachments/assets/7ac41275-0b07-4f1e-a36b-b035b0805db1" />

This project is a work-in-progress calculator that will be able to take in string input and evaluate or simplify it. Eventually I will try to implement a file reading system so it can work in tandem with other projects that need simple calculations.

---

## Features

- `+ - * / ^` with correct precedence and right-associative `^`
- Parentheses, including nested
- Unary minus
- Basic validity checks (balanced parens, no adjacent binary operators)
- Division-by-zero and malformed-input handled as errors, not crashes
- REPL loop in `main.cpp` with a `quit`/`exit` command


##  Goals

This project is still being developed. Planned improvements include:

History system: Use History and ExprNode to store and recall past expressions

Tokenizer: Tokenizes strings, gearing up for more complex evaluations

std::expected: Swap solve's error to modern expected protocol

Symbolic constants: pi, e, golden ratio, etc.

---

