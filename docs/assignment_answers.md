# Cryptography laboratory — assignment answers

## Q1: Caesar cipher
**Input:** key `3`, plaintext `Hello, World!`.
**Output:** `Khoor, Zruog!`.
Letters use indices A=0 through Z=25 and formula `C=(P+k) mod26`. Case and nonletters are unchanged. Key 1 wraps `Zz` to `Aa`; only 1–25 are accepted.

## Q2: Monoalphabetic substitution
**Input:** `QWERTYUIOPASDFGHJKLZXCVBNM`, `Hello, World!`.
**Output:** `Itssg, Vgksr!`.
The 26-letter key must contain each A–Z exactly once. The one-to-one property prevents two plaintext letters colliding and allows unique decryption. Invalid keys are rejected.

## Q3: Playfair cipher
**Input:** keyword `MONARCHY`, plaintext `INSTRUMENTS`.
**Prepared plaintext:** `IN ST RU ME NT SX`.
**Output:** `GATLMZCLRQXA`.
Build a 5×5 matrix from unique keyword letters and remaining alphabet, merging J into I. Remove punctuation, create digraphs, insert X between repeated letters (Q for repeated X), and pad a final singleton. Same row: shift right; same column: shift down; rectangle: interchange columns.

## Q4: Polyalphabetic cipher
**Input:** keyword `LEMON`, plaintext `ATTACKATDAWN`.
**Output:** `LXFOPVEFRNHR`.
The keyword repeats across letters only; `C_i=(P_i+K_i) mod26`. Case and punctuation are preserved.

## Q5: Affine cipher
**Input:** `a=5`, `b=8`, `Hello, World!`.
**Encryption:** `Rclla, Oaplx!`.
**Decryption:** `Hello, World!`.
`C=(aP+b) mod26`, `P=a^-1(C-b) mod26`. b can be **any integer** because it is normalized modulo 26. a must satisfy gcd(a,26)=1, and its valid residues are **1,3,5,7,9,11,15,17,19,21,23,25**. All other residues are invalid. If a=2,b=3, then E(0)=3 and E(13)=29 mod26=3, so the mapping is not bijective.

## Q6: Break affine cipher
Only the two most frequent ciphertext letters B and U were supplied; no ciphertext was provided. Frequencies do **not** prove a plaintext, a mapping, or an affine key. English E and T are conventional assumptions, not guarantees.

**Directional distinction:** Assuming ciphertext B represents plaintext E and ciphertext U represents plaintext T means `4a+b ≡ 1`, `19a+b ≡ 20 (mod26)`. Subtraction gives `15a ≡ 19`; inverse 15 is 7, so `a=3,b=15` and the decryption inverse of 3 is 9. Alternatively, the other direction, B encrypts to E and U encrypts to T, gives `a+b=4`, `20a+b=19`; the result is `a=3,b=1`. **The assignment specifically requests this latter conditional candidate (3,1)**. The two interpretations cannot be conflated; neither key is verified without ciphertext and plausibility checks.

The program counts ranked letter frequencies and prints labeled candidate decryptions under both hypotheses.

## Q7: Simple substitution attack
The exact provided ciphertext is stored at `data/q7_ciphertext.txt`, preserving its distinctive symbols †, ‡, ¶ and —. The analyzer counts full UTF-8 glyphs and ranks frequencies, without pretending that unusual symbols are normal letters. A second optional mapping file with `symbol letter` lines prints testable mapping hypotheses. These are **not** a verified complete solution. Repeated symbols, word boundaries and word patterns may provide additional clues. Without a known language, source, or key, full recovery cannot be guaranteed.

**Note:** All seven examples demonstrate classical, insecure educational cryptography.
