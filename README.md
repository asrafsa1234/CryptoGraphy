# Cryptography Lab in C

Forty educational cryptography exercises, each with an independently runnable C program. Questions 1–7 are original lab exercises; Questions 8–40 cover keyword substitution, Hill cipher, DES/3DES, block modes, RSA, Diffie–Hellman, hashes/MACs, and frequency attacks. Certain questions ask for theoretical explanations: their C programs demonstrate the concept rather than claiming a complete production cryptographic implementation.

## Build and test

Requires a C11 compiler, `make`, a POSIX shell, and OpenSSL development headers/library (for Questions 19 and 33). In GitHub Codespaces, use a Linux environment with `gcc`, `make` and `libssl-dev` installed. From the repository root:

```sh
make all
make test
make clean
```

Run programs individually using `./bin/q1_caesar`, etc.; use `ls bin` to find the executable for each question, including `q08_keyword_substitution` through `q40_substitution_frequency_attack`. Some accept blank lines for documented example inputs. `make test` runs original tests and the 40-program output smoke tests.

## Structure

- `src/`: one standalone C11 file for every question (40 total), plus a small shared `lab_common.h` header
- `data/q7_ciphertext.txt`: the assignment ciphertext, preserving UTF-8 symbols
- `tests/test_all.sh`: initial known-answer and invalid-key tests; `tests/test_40.sh`: one runnable sample smoke test for every program
- `docs/assignment_answers.md`: formulas, theoretical answers, examples and cryptanalysis limitations
- `Makefile`: compilation, test, clean targets

## Output evidence

See the accompanying `Cryptography_40_Output_Screenshots.pdf` or `Cryptography_40_Output_PNGs.zip` download for 40 individually labeled renderings of **captured terminal output**. The image presentation recreates a readable terminal view from actually executed program output; it is not a literal GUI screenshot of a physical Codespaces window.

## Sample input and outputs

| Question | Input lines | Output excerpt |
|---|---|---|
| Caesar | `3`, `Hello, World!` | `Ciphertext: Khoor, Zruog!` |
| Substitution | `QWERTYUIOPASDFGHJKLZXCVBNM`, `Hello, World!` | `Ciphertext: Itssg, Vgksr!` |
| Playfair | `MONARCHY`, `INSTRUMENTS` | `Ciphertext: GATLMZCLRQXA` |
| Vigenere | `LEMON`, `ATTACKATDAWN` | `Ciphertext: LXFOPVEFRNHR` |
| Affine | `5`, `8`, `Hello, World!` | displays ciphertext and restored plaintext |
| Affine attack | `BU` | prints frequency ranking and conditional candidate decryptions |
| Symbol attack | `data/q7_ciphertext.txt` argument | ranks all distinct Unicode ciphertext symbols |

## Cryptographic notes

- Caesar: `C = (P + k) mod 26`, with `1 <= k <= 25`.
- Monoalphabetic: a permutation of A-Z guarantees a one-to-one substitution.
- Playfair: combine I/J and encrypt digraphs using same-row, same-column, and rectangle rules; repeated letters use filler X (Q after X).
- Vigenere: `C_i = (P_i + K_i) mod 26`; the key advances only on letters.
- Affine: `C = (aP+b) mod 26`, decryption `P = a^-1(C-b) mod 26`; `gcd(a,26)=1`, while any integer b is valid modulo 26.
- Frequency analysis provides hypotheses, not uniquely verified plaintext. Letter rankings alone cannot determine an affine plaintext.
- The Q7 program counts UTF-8 glyphs as distinct symbols. Optional mapping guesses can be passed as a second file with one `symbol letter` mapping per line. It is an interactive/manual-assisted analysis aid, not a complete solver.

**Educational use only.** These classical ciphers do not provide modern security.

## Important limitations

- **Q9:** The PT-109 ciphertext alone does not supply a key; the program decrypts with a user-supplied *hypothesis*, not a verified historical plaintext.
- **Q15/Q39:** English unigram chi-square ranking is a heuristic that can misrank very short ciphertexts.
- **Q16/Q37/Q40:** Automatic candidate generation is a simple unigram frequency heuristic; arbitrary monoalphabetic ciphertext is **not** reliably solved without more sophisticated language modeling.
- **Q19/Q33:** OpenSSL 3.x provides DES through its legacy provider; DES/3DES are obsolete; avoid in real applications.
- **Q22/Q23:** These select *affine mod 256* from the assignment's allowed ciphers; the S-DES ciphertext vectors therefore do not apply.
- **Q29:** Illustrates SHA-3 theta lane diffusion for a chosen initialized pattern; cannot establish a universal answer for all unspecified nonzero bits without additional assumptions.
- **Q32:** Uses toy DSA arithmetic to demonstrate nonce sensitivity. **Modern RSA-PSS signatures are randomized**, unlike deterministic textbook RSA.
- **Q33:** OpenSSL EVP provides actual DES, rather than a reimplementation of DES's entire permutation/S-box algorithm.

All programs and ciphers in this repository are **educational**.
