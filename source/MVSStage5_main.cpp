 /*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */

#include "Iw2D.h"
#include "input.h"
#include "audio.h"

int main()
{
    // Initialise the 2D graphics system
    Iw2DInit();

    // Set up input systems
    g_pInput = new Input();

    // Set up audio systems
    g_pAudio = new Audio();

    // Create an image from a PNG file
    CIw2DImage* image = Iw2DCreateImage("textures/venetie.png");
    CIwFVec2    image_position = CIwFVec2::g_Zero;

    // Play some background music
    Audio::PlayMusic("audio/bejo.mp3", true);

    // Loop forever, until the user or the OS performs some action to quit the app
    while (!s3eDeviceCheckQuitRequest())
    {
        // Update input system
        g_pInput->Update();

        // Update audio system
        g_pAudio->Update();

        // Clear the drawing surface
        Iw2DSurfaceClear(0xff000000);

        // Draw an image
        Iw2DDrawImage(image, image_position);

        // Check for user tapping screen
        if (!g_pInput->m_Touched && g_pInput->m_PrevTouched)
        {
            // Move image to touched position
            image_position.x = (float)g_pInput->m_X;
            image_position.y = (float)g_pInput->m_Y;

            // Reset input
            g_pInput->Reset();

            // Play a sound effect
            g_pAudio->PlaySound("audio/gem_destroyed.wav");
        }

        // Show the drawing surface
        Iw2DSurfaceShow();

        // Yield to the OS
        s3eDeviceYield(0);
    }

    // Clean-up
    delete image;
    delete g_pAudio;
    delete g_pInput;
    Iw2DTerminate();

    return 0;
}
