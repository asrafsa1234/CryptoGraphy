#!/bin/sh
set -eu
cd "$(dirname "$0")/.."
echo "Smoke testing all 40 question programs"
printf '%s' '3
Hello, World!
' | ./bin/q1_caesar >/dev/null
echo 'PASS Q01 q1_caesar'
printf '%s' 'QWERTYUIOPASDFGHJKLZXCVBNM
Hello!
' | ./bin/q2_monoalphabetic >/dev/null
echo 'PASS Q02 q2_monoalphabetic'
printf '%s' 'MONARCHY
INSTRUMENTS
' | ./bin/q3_playfair >/dev/null
echo 'PASS Q03 q3_playfair'
printf '%s' 'LEMON
ATTACKATDAWN
' | ./bin/q4_polyalphabetic >/dev/null
echo 'PASS Q04 q4_polyalphabetic'
printf '%s' '5
8
Affine Cipher
' | ./bin/q5_affine >/dev/null
echo 'PASS Q05 q5_affine'
printf '%s' 'BU BU BUBU
' | ./bin/q6_affine_attack >/dev/null
echo 'PASS Q06 q6_affine_attack'
printf '%s' '


' | ./bin/q7_substitution_attack >/dev/null
echo 'PASS Q07 q7_substitution_attack'
printf '%s' '


' | ./bin/q08_keyword_substitution >/dev/null
echo 'PASS Q08 q08_keyword_substitution'
printf '%s' 'MONARCHY
' | ./bin/q09_pt109_playfair >/dev/null
echo 'PASS Q09 q09_pt109_playfair'
printf '%s' '


' | ./bin/q10_playfair_fixed_matrix >/dev/null
echo 'PASS Q10 q10_playfair_fixed_matrix'
printf '%s' '


' | ./bin/q11_playfair_keyspace >/dev/null
echo 'PASS Q11 q11_playfair_keyspace'
printf '%s' '


' | ./bin/q12_hill_encrypt_decrypt >/dev/null
echo 'PASS Q12 q12_hill_encrypt_decrypt'
printf '%s' '


' | ./bin/q13_hill_chosen_plaintext >/dev/null
echo 'PASS Q13 q13_hill_chosen_plaintext'
printf '%s' '


' | ./bin/q14_otp_vigenere_reuse >/dev/null
echo 'PASS Q14 q14_otp_vigenere_reuse'
printf '%s' '


' | ./bin/q15_additive_frequency_attack >/dev/null
echo 'PASS Q15 q15_additive_frequency_attack'
printf '%s' '


' | ./bin/q16_substitution_frequency_attack >/dev/null
echo 'PASS Q16 q16_substitution_frequency_attack'
printf '%s' '


' | ./bin/q17_des_decryption_schedule >/dev/null
echo 'PASS Q17 q17_des_decryption_schedule'
printf '%s' '


' | ./bin/q18_des_subkey_independence >/dev/null
echo 'PASS Q18 q18_des_subkey_independence'
printf '%s' '


' | ./bin/q19_triple_des_cbc >/dev/null
echo 'PASS Q19 q19_triple_des_cbc'
printf '%s' '


' | ./bin/q20_cbc_error_propagation >/dev/null
echo 'PASS Q20 q20_cbc_error_propagation'
printf '%s' '


' | ./bin/q21_bit_padding >/dev/null
echo 'PASS Q21 q21_bit_padding'
printf '%s' '


' | ./bin/q22_affine256_cbc >/dev/null
echo 'PASS Q22 q22_affine256_cbc'
printf '%s' '


' | ./bin/q23_affine256_ctr >/dev/null
echo 'PASS Q23 q23_affine256_ctr'
printf '%s' '


' | ./bin/q24_rsa_private_key >/dev/null
echo 'PASS Q24 q24_rsa_private_key'
printf '%s' '


' | ./bin/q25_rsa_gcd_leak >/dev/null
echo 'PASS Q25 q25_rsa_gcd_leak'
printf '%s' '


' | ./bin/q26_rsa_leaked_private_key >/dev/null
echo 'PASS Q26 q26_rsa_leaked_private_key'
printf '%s' '


' | ./bin/q27_rsa_codebook_attack >/dev/null
echo 'PASS Q27 q27_rsa_codebook_attack'
printf '%s' '


' | ./bin/q28_dh_bad_exponentiation >/dev/null
echo 'PASS Q28 q28_dh_bad_exponentiation'
printf '%s' '


' | ./bin/q29_sha3_diffusion >/dev/null
echo 'PASS Q29 q29_sha3_diffusion'
printf '%s' '


' | ./bin/q30_cbc_mac_length_extension >/dev/null
echo 'PASS Q30 q30_cbc_mac_length_extension'
printf '%s' '


' | ./bin/q31_cmac_subkeys >/dev/null
echo 'PASS Q31 q31_cmac_subkeys'
printf '%s' '


' | ./bin/q32_dsa_nonce_implications >/dev/null
echo 'PASS Q32 q32_dsa_nonce_implications'
printf '%s' '


' | ./bin/q33_des_block_cipher >/dev/null
echo 'PASS Q33 q33_des_block_cipher'
printf '%s' '


' | ./bin/q34_bit_padding >/dev/null
echo 'PASS Q34 q34_bit_padding'
printf '%s' '


' | ./bin/q35_otp_letter_stream >/dev/null
echo 'PASS Q35 q35_otp_letter_stream'
printf '%s' '


' | ./bin/q36_affine_key_restrictions >/dev/null
echo 'PASS Q36 q36_affine_key_restrictions'
printf '%s' '


' | ./bin/q37_substitution_frequency_attack >/dev/null
echo 'PASS Q37 q37_substitution_frequency_attack'
printf '%s' '


' | ./bin/q38_hill_known_plaintext_attack >/dev/null
echo 'PASS Q38 q38_hill_known_plaintext_attack'
printf '%s' '


' | ./bin/q39_additive_frequency_attack >/dev/null
echo 'PASS Q39 q39_additive_frequency_attack'
printf '%s' '


' | ./bin/q40_substitution_frequency_attack >/dev/null
echo 'PASS Q40 q40_substitution_frequency_attack'
echo "All 40 smoke tests passed."
