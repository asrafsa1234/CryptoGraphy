#!/bin/sh
set -eu
check(){ label=$1; expected=$2; actual=$3; case "$actual" in *"$expected"*) printf 'PASS %s\n' "$label";; *) printf 'FAIL %s\nExpected: %s\nActual: %s\n' "$label" "$expected" "$actual";exit 1;;esac; }
check caesar 'Ciphertext: Khoor, Zruog!' "$(printf '3\nHello, World!\n' | bin/q1_caesar)"
check wrap 'Ciphertext: Aa' "$(printf '1\nZz\n' | bin/q1_caesar)"
if printf '26\nHi\n' | bin/q1_caesar >/dev/null 2>&1;then echo 'FAIL invalid caesar';exit 1;else echo 'PASS invalid caesar';fi
check substitution 'Ciphertext: Itssg, Vgksr!' "$(printf 'QWERTYUIOPASDFGHJKLZXCVBNM\nHello, World!\n' | bin/q2_monoalphabetic)"
if printf 'AAAAAAAAAAAAAAAAAAAAAAAAAA\nHi\n' | bin/q2_monoalphabetic >/dev/null 2>&1;then echo 'FAIL duplicate substitution';exit 1;else echo 'PASS duplicate substitution';fi
check playfair 'Ciphertext: GATLMZCLRQXA' "$(printf 'MONARCHY\nINSTRUMENTS\n' | bin/q3_playfair)"
check repeated 'Prepared: BALXLOON' "$(printf 'MONARCHY\nBALLOON\n' | bin/q3_playfair)"
check vigenere 'Ciphertext: LXFOPVEFRNHR' "$(printf 'LEMON\nATTACKATDAWN\n' | bin/q4_polyalphabetic)"
if printf 'A1\nTEXT\n' | bin/q4_polyalphabetic >/dev/null 2>&1;then echo 'FAIL invalid vigenere';exit 1;else echo 'PASS invalid vigenere';fi
check affine 'Decrypted: Hello, World!' "$(printf '5\n8\nHello, World!\n' | bin/q5_affine)"
if printf '2\n3\nTEXT\n' | bin/q5_affine >/dev/null 2>&1;then echo 'FAIL invalid affine';exit 1;else echo 'PASS invalid affine';fi
check attack 'Candidate (a=3,b=15)' "$(printf 'BU\n' | bin/q6_affine_attack)"
check symbols '‡ :' "$(bin/q7_substitution_attack data/q7_ciphertext.txt)"
echo 'All automated tests passed.'
