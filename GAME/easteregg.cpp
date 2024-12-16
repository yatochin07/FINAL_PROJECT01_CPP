#include <iostream>
#include <cmath>
#include <cstring>
#include <windows.h>  
#include "easteregg.h"

using namespace std;

// An implementation of gotoxy() function for smoother animation in Windows
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void easterEgg()
{
    // R1 is taken as 1, since it is only multiplied with terms,
    // we can neglect it in this program.

    // A, B
    float A = 0, B = 0;

    // phi, theta
    float i, j;
    
    // K1
    int k;

    // z-buffer
    float z[1760];
    char b[1760];
    cout << "\x1b[2J";  // Clear screen (Note: This may work in some Windows terminals, or can be skipped)

    while (true)
    {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        
        for (j = 0; j < 6.28; j += 0.07)
        {
            for (i = 0; i < 6.28; i += 0.02)
            {
                // We will calculate the position and luminance of each point.
                float c = sin(i); // sin(phi)
                float d = cos(j); // cos(theta)
                float e = sin(A); // sin(A)
                float f = sin(j); // sin(theta)
                float g = cos(A); // cos(A)
                float h = d + 2;  // (R2 + R1cos(theta)) // R2 is taken as 2 here
                float D = 1 / (c * h * e + f * g + 5); // 1/(z + K2) // K2 is taken as 5
                float l = cos(i); // cos(phi)
                float m = cos(B); // cos(B)
                float n = sin(B); // sin(B)
              
                float t = c * h * g - f * e;

                // Calculating x (x' since we are multiplying by D) (K1 is 1)
                int x = 40 + 30 * D * (l * h * m - t * n);

                // Calculating y (y' specifically since we are multiplying by D)
                int y = 12 + 15 * D * (l * h * n + t * m);
                
                // Variable to store rendered ASCII character in the buffer.
                int o = x + 80 * y;

                // Luminance
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o])
                {
                    // String D in z-buffer
                    z[o] = D;

                    // Choosing ASCII character based on Luminance and storing it in buffer
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        // Move cursor to top-left
        gotoxy(0, 0);
        
        // Print the frame
        for (k = 0; k < 1761; k++)
        {
            putchar(k % 80 ? b[k] : 10); // Print the frame
        }
        
        // Update angles for the animation
        A += 0.04;
        B += 0.02;

        // Sleep for a short period to slow down the animation
        Sleep(10); // Sleep for 10 milliseconds (Windows Sleep() takes milliseconds)
    }
}
