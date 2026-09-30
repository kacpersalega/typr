# typer

A lightweight, terminal-based typing speed and accuracy tester written in C.

## Features

- **WPM Calculation:** Measures elapsed time in milliseconds using POSIX high-resolution timers (`CLOCK_MONOTONIC_RAW`).
- **Accuracy Score:** Calculates percentage accuracy by comparing typed characters directly against the reference prompt.
- **Word Counting:** Robust space-delimited word counter that handles arbitrary spacing.

## Build & Run

Requires a POSIX-compliant system (Linux/macOS) with `gcc` or `clang`.

```bash
# Compile
gcc main.c -o typr

# Run
./typr