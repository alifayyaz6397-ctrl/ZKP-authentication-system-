#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>
#include <windows.h>
#include <ctime>

using namespace std;

// Using unsigned for 128-bit headroom to prevent overflow
typedef unsigned __int128 uint128;

// --- AESTHETIC CONSTANTS ---
#define WHITE 15
#define BLUE 11 

void set_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// --- 1. Custom 128-bit Input Handler ---
uint128 stringTo128(string s) {
    uint128 res = 0;
    for (char c : s) {
        if (isdigit(c)) res = res * 10 + (c - '0');
    }
    return res;
}

// --- 2. Custom 128-bit Output Handler ---
string int128ToString(uint128 n) {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) {
        s += (char)((n % 10) + '0');
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

// --- 3. Safe Modular Multiplication ---
uint128 mulmod(uint128 a, uint128 b, uint128 m) {
    uint128 res = 0;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) res = (res + a) % m;
        a = (a * 2) % m;
        b /= 2;
    }
    return res;
}

// --- 4. Modular Exponentiation ---
uint128 power(uint128 base, uint128 exp, uint128 mod) {
    uint128 res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = mulmod(res, base, mod);
        base = mulmod(base, base, mod);
        exp /= 2;
    }
    return res;
}

// --- 5. Miller-Rabin Primality Test ---
bool millerRabin(uint128 n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    uint128 d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }
    uint128 bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (uint128 a : bases) {
        if (n <= a) break;
        uint128 x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int j = 0; j < r - 1; j++) {
            x = mulmod(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

void clearScreen() {
    system("cls");
}

void pause() {
    set_color(BLUE);
    cout << "\n  >> Press Enter to continue...";
    set_color(WHITE);
    cin.ignore();
    cin.get();
}

// --- NEW VISUAL HEADER (Universal Stacked Style) ---
void main_header(string title) {
    clearScreen();
    set_color(BLUE);
    cout << "  ____________________________________________________________" << endl;
    cout << " |                                                            |" << endl;
    cout << " |             ______  _  __ _____                            |" << endl;
    cout << " |            |___  / | |/ /|  __ \\                           |" << endl;
    cout << " |               / /  | ' / | |__) |                          |" << endl;
    cout << " |              / /   |  <  |  ___/                           |" << endl;
    cout << " |             / /__  | . \\ | |                               |" << endl;
    cout << " |            /_____| |_|\\_\\|_|                               |" << endl;
    cout << " |                                                            |" << endl;
    cout << " |   A U T H E N T I C A T I O N   S Y S T E M                |" << endl;
    cout << " |____________________________________________________________|" << endl;
    
    
    set_color(BLUE);
    cout << "\n   " << title << endl;
    cout << "  " << string(60, '-') << endl;
    set_color(WHITE);
}

int main() {
    // Maximize window for best effect
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    srand(time(0));

    uint128 m, x, g = 2;
    string inM, inX, inK, inE;
    bool setupValid = false;

    while (!setupValid) {
        main_header("1: SYSTEM CONFIGURATION");

        cout << "  [INPUT] Enter Prime Modulus (m): ";
        cin >> inM;
        m = stringTo128(inM);

        double mBits = 0;
        uint128 tempM = m;
        while (tempM > 0) {
            tempM >>= 1;
            mBits++;
        }
        double mSeconds = (double)m / 100000000.0;

        set_color(BLUE);
        cout << "\n  --- MODULUS STRENGTH AUDIT ---" << endl;
        set_color(WHITE);
        cout << "  [+] Size: " << fixed << setprecision(1) << mBits << " bits" << endl;
        cout << "  [+] Brute Force Time: " << mSeconds << " seconds" << endl;
        cout << "  [+] Status: "; 
        
        if (mSeconds < 10) cout << "WEAK";
        else if (mSeconds < 3600) cout << "MEDIUM";
        else cout << "STRONG";
        cout << endl;

        if (!millerRabin(m)) {
            set_color(BLUE); // Using Blue for consistency as requested
            cout << "  [!] WARNING: Modulus is COMPOSITE!" << endl;
            cout << "      Note: ZKP requires a Prime Modulus for math stability." << endl;
            set_color(WHITE);
        } else {
            set_color(BLUE);
            cout << "  [OK] AUDIT PASSED: Modulus is Prime." << endl;
            set_color(WHITE);
        }

        cout << "\n  [INPUT] Enter 128-bit Secret Key (x): ";
        cin >> inX;
        x = stringTo128(inX);

        set_color(BLUE);
        cout << "\n  --- SECRET STRENGTH AUDIT ---" << endl;
        set_color(WHITE);

        if (x >= m) {
            set_color(BLUE);
            cout << "  CRITICAL ERROR: x must be < m!" << endl;
            set_color(WHITE);
            pause();
            continue;
        }

        double xSeconds = (double)x / 100000000.0;
        cout << "  [+] DATA INTEGRITY: x < m (No Collisions)." << endl;
        cout << "  [+] Secret Complexity: " << int128ToString(x) << " combinations." << endl;
        cout << "  [+] Time to Guess Secret: " << fixed << setprecision(6) << xSeconds << " seconds" << endl;

        if (x < 1000000) cout << "  [!] WARNING: Your secret is too small!" << endl;

        cout << "\n  Proceed with these parameters? (1: Yes / 2: Re-enter): ";
        int choice;
        cin >> choice;
        if (choice == 1) setupValid = true;
    }

    uint128 y = power(g, x, m);
    set_color(BLUE);
    cout << "\n  --- CALCULATION: PUBLIC IDENTITY ---" << endl;
    set_color(WHITE);
    cout << "  Formula: y = g^x mod m" << endl;
    cout << "  Step:    " << int128ToString(g) << " ^ " << int128ToString(x) << " mod " << int128ToString(m) << endl;
    cout << "  Public Identity (y) generated: " << int128ToString(y) << endl;
    pause();

    main_header("2: PROVER'S COMMITMENT");
    cout << "  Prover, enter session secret (k): ";
    cin >> inK;
    uint128 k = stringTo128(inK);
    uint128 R = power(g, k, m);
    set_color(BLUE);
    cout << "\n  --- CALCULATION: PROVER'S COMMITMENT ---" << endl;
    set_color(WHITE);
    cout << "  Formula: R = g^k mod m" << endl;
    cout << "  Step:    " << int128ToString(g) << " ^ " << int128ToString(k) << " mod " << int128ToString(m) << endl;
    cout << "  Commitment (R) generated: " << int128ToString(R) << endl;
    pause();

    main_header("3: VERIFIER'S CHALLENGE");
    cout << "  The Prover has sent Commitment: " << int128ToString(R) << endl;
    cout << "  Verifier, enter Challenge (e): ";
    cin >> inE;
    uint128 e = stringTo128(inE);
    pause();

    main_header("4: PROVER'S RESPONSE");
    uint128 s = (k + mulmod(e, x, m - 1)) % (m - 1);
    set_color(BLUE);
    cout << "\n  --- CALCULATION: PROVER'S RESPONSE ---" << endl;
    set_color(WHITE);
    cout << "  Formula: s = (k + e*x) mod (m-1)" << endl;
    cout << "  Response (s) to be sent: " << int128ToString(s) << endl;
    pause();

    main_header("5: FINAL VERIFICATION");
    uint128 left = power(g, s, m);
    uint128 right = mulmod(R, power(y, e, m), m);
    cout << "  Left Hand Side (g^s mod m):       " << int128ToString(left) << endl;
    cout << "  Right Hand Side (R * y^e mod m):  " << int128ToString(right) << endl;

    cout << "\n  " << string(60, '=') << endl;
    if (left == right) {
        set_color(BLUE);
        cout << "   RESULT: SUCCESS - Identity Verified!" << endl;
    } else {
        set_color(BLUE);
        cout << "   RESULT: FAILED " << endl;
    }
    set_color(WHITE);
    cout << "  " << string(60, '=') << endl;

    pause();
    return 0;
}