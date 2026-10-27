# Cryptography Lab in C

Seven standalone, portable C11 classical cryptography programs with tests and documentation.

## Build and test

Requires a C11 compiler, GNU Make (or compatible make), and a POSIX shell:

```sh
make all
make test
make clean
```

Run individually as `bin/q1_caesar`, `bin/q2_monoalphabetic`, `bin/q3_playfair`, `bin/q4_polyalphabetic`, `bin/q5_affine`, `bin/q6_affine_attack` and `bin/q7_substitution_attack data/q7_ciphertext.txt`.

## Project files

- Seven programs: `src/q1_caesar.c` through `src/q7_substitution_attack.c`
- Exact supplied ciphertext: `data/q7_ciphertext.txt`
- Test script: `tests/test_all.sh`
- Worked solutions: `docs/assignment_answers.md`
- Build instructions: `Makefile`

## Examples

| Program | Input lines | Expected output excerpt |
|---|---|---|
| Caesar | `3`, `Hello, World!` | `Khoor, Zruog!` |
| Monoalphabetic | `QWERTYUIOPASDFGHJKLZXCVBNM`, `Hello, World!` | `Itssg, Vgksr!` |
| Playfair | `MONARCHY`, `INSTRUMENTS` | `GATLMZCLRQXA` |
| Vigenere | `LEMON`, `ATTACKATDAWN` | `LXFOPVEFRNHR` |
| Affine | `5`, `8`, `Hello, World!` | `Rclla, Oaplx!`, followed by original |
| Affine attack | `BU` | Frequency ranking and conditional key candidates |
| Substitution attack | File argument | Symbol frequencies in descending order |

## Mathematical summary

Caesar: `C=(P+k)%26` for k in 1..25.
Monoalphabetic: valid key is a permutation of A-Z.
Playfair: keyed 5x5 square, merge I/J, digraph padding; same row shift right, same column down, rectangle swaps columns.
Vigenere: `C_i=(P_i+K_i)%26` and key advances only for alphabetic plaintext.
Affine: `C=(aP+b)%26`, `P=a^-1(C-b)%26`. Require gcd(a,26)=1; b is any integer modulo 26.
Frequency rankings are statistical clues only and cannot prove a key or plaintext.
For Q7, the executable counts distinct UTF-8 glyphs; an optional second file can list tentative `symbol letter` mappings.

These classical systems are for education, **not** modern information security.
