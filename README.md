#  Zero-Knowledge Proof Authentication System (Schnorr Protocol)

##  Project Overview
This project is a **console-based Zero-Knowledge Proof (ZKP) Authentication System** implemented in **C++**, based on the **Schnorr Identification Protocol**.  
It demonstrates how a prover can authenticate themselves **without revealing their secret key**, using modular arithmetic and cryptographic principles.

The program is designed as a **university-level cryptography project**, with added **visual enhancements**, **128-bit arithmetic**, and **security audits** for educational clarity.

---

##  Key Features
-  Implements **Schnorr Zero-Knowledge Proof**
-  Supports **128-bit unsigned integers**
-  Secure **modular exponentiation & multiplication**
-  **Miller–Rabin primality test** for modulus validation
-  Strength analysis of modulus and secret key
-  Colorized Windows console UI
-  Step-by-step cryptographic calculations

---

##  Cryptographic Flow (Schnorr Protocol)

1. **System Setup**
   - Select a prime modulus `m`
   - Choose generator `g = 2`
   - Prover selects secret key `x`
   - Public key computed as  
     ```
     y = g^x mod m
     ```

2. **Commitment**
   - Prover selects random session secret `k`
   - Computes  
     ```
     R = g^k mod m
     ```

3. **Challenge**
   - Verifier sends a random challenge `e`

4. **Response**
   - Prover computes  
     ```
     s = (k + e·x) mod (m − 1)
     ```

5. **Verification**
   - Verifier checks:
     ```
     g^s mod m == (R · y^e) mod m
     ```
   - If equal → ✅ Authentication successful

---

## 🛠 Technologies Used
- **Language:** C++
- **Compiler:** GCC / MinGW
- **Platform:** Windows
- **Libraries:**
  - `<iostream>`
  - `<string>`
  - `<algorithm>`
  - `<iomanip>`
  - `<cmath>`
  - `<ctime>`
  - `<windows.h>`

---

##  Key Implementation Highlights

###  128-bit Integer Handling
```cpp
typedef unsigned __int128 uint128;
